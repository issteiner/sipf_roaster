#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>

#define EOS     0x0   // End of string
#define EOL     0x0
#define CR      0xD
#define LF      0xA
#define SEPARATOR ';'
#define BUFFERSIZE 15
#define ERROR 255

const uint24_t powerBitTable[] = {
    0x000000,
    0x000001,
    0x001001,
    0x010101,
    0x041041,
    0x084211,
    0x111111,
    0x122449,
    0x249249,
    0x252525,
    0x295295,
    0x2AA555,
    0x555555,
    0x555AAB,
    0x56B56B,
    0x5B5B5B,
    0x6DB6DB,
    0x6DDBB7,
    0x777777,
    0x77BDEF,
    0x7DF7DF,
    0x7F7F7F,
    0x7FF7FF,
    0x7FFFFF,
    0xFFFFFF
};

const uint16_t pwmLevel[] = {
    0x000000,
    0x0000AB,
    0x000155,
    0x000200,
    0x0002AB,
    0x000355,
    0x0003FF
};

enum ArtisanCommand {
    READ, CHAN, DCFAN, OT1, ELSE //, FILT, UNITS
};

enum ArtisanCommand getCommandAndParams(char *, char *);
uint8_t getParams(char *, char *);

uint8_t getOt1Param(char *);
uint8_t getDcFanParam(char *);
void getChanParam(char *, char *);

void sendTemperature(uint8_t);
void sendChannelsReply(char *);

uint8_t convert2Celsius(adc_result_t);
uint8_t getBeanTemperature();

void setDcFanSpeed(uint8_t);
void setHeaterPower(uint8_t);

void sendString2Serial(char *);
void sendLf2Serial(void);

uint8_t isEqual(char *, char *);
uint8_t startsWith(char *, char *);
void int2string(uint8_t, char *);
uint8_t string2int(char *);

uint8_t isEqual(char *str1, char *str2) {
    while (*str1 != EOS && *str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str1 == EOS && *str2 == EOS) return true;
    else return false;
}

uint8_t startsWith(char *str1, char *str2) { // str1: what, str2: in what
    while (*str1 != EOS && *str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str1 == EOS) return true;
    else return false;
}

void int2string(uint8_t number, char *numberStr) {
    uint8_t index = 0;
    uint8_t hundreds = (number / 100) % 10;
    uint8_t tenths = (number / 10) % 10;
    if (hundreds != 0) {
        numberStr[index++] = hundreds + '0';
        numberStr[index++] = tenths + '0';
    } else if (tenths != 0) {
        numberStr[index++] = tenths + '0';
    };
    numberStr[index++] = number % 10 + '0';
    numberStr[index] = EOS;
}

uint8_t string2int(char *numberStr) { //Only for numbers 0..100 & strip right from dot
    uint8_t result = 0;
    uint8_t index = 0;
    while (*numberStr != EOS && *numberStr != '.' && index != 3) {
        result = 10 * result + *numberStr - '0';
        index++;
        numberStr++;
    }
    if ((*numberStr == EOS || *numberStr == '.') && result <= 100) return result;
    else return ERROR;
}

enum ArtisanCommand getCommandAndParams(char *readLine, char *params) {
    if (isEqual("READ", readLine)) return READ;
    uint8_t lengthOfParams = getParams(readLine, params);
    if (startsWith("CHAN;", readLine)) {
        if (lengthOfParams == 4) return CHAN;
    }
    if (startsWith("DCFAN;", readLine)) return DCFAN;
    if (startsWith("OT1;", readLine)) return OT1;
    return ELSE;
}

uint8_t getParams(char *readLine, char *params) {
    uint8_t length = 0;
    while (*readLine != SEPARATOR && *readLine != EOL) readLine++;
    if (*readLine == EOL) return 0;
    readLine++;
    while (*readLine != EOL) {
        *params = *readLine;
        params++;
        readLine++;
        length++;
    }
    *params = EOS;
    return length;
}

void sendTemperature(uint8_t temp) {
    char tempStr[4];
    int2string(temp, tempStr);
    sendString2Serial("25,80,");
    sendString2Serial(tempStr);
    sendString2Serial(",0,0");
    sendLf2Serial();
}

void sendChannelsReply(char *chans) {
    sendString2Serial("# Active channels set to ");
    sendString2Serial(chans);
    sendLf2Serial();
}

void setDcFanSpeed(uint8_t speed) {
    uint16_t level;
    level = pwmLevel[6 * (speed + 8) / 100]; // convert 0-100 to 0-1023, 6 steps
    PWM3_LoadDutyValue(level);
    char tempStr[4];
    int2string(speed, tempStr);
    sendString2Serial("# DC fan speed is now ");
    sendString2Serial(tempStr);
    sendLf2Serial();
}

void setHeaterPower(uint8_t power) {
    uint24_t newPowerBits;
    uint8_t newLevel;
    newLevel = 24 * (power + 2) / 100; // convert 0-100 to 0-24
    newPowerBits = powerBitTable[newLevel];
    setPowerBits(newPowerBits);
    char tempStr[4];
    int2string(newLevel, tempStr);
    sendString2Serial("# Heater power is now ");
    sendString2Serial(tempStr);
    sendLf2Serial();
}

void sendString2Serial(char *str) {
    while (*str != 0) {
        EUSART1_Write(*str);
        str++;
    }
}

void sendLf2Serial() {
    EUSART1_Write(LF);
}

uint8_t convert2Celsius(adc_result_t avg_result) {
    return (uint8_t) (avg_result >> 2);
}

uint8_t getBeanTemperature() {
    adc_result_t result = 0;
    for (uint8_t i = 0; i < TEMP_BUFFER_SIZE; i++) {
        result = result + tempBuffer[i];
    }
    return convert2Celsius(result / TEMP_BUFFER_SIZE);
}

void main(void) {
    uint8_t readByte;
    uint8_t index;
    uint8_t beanTemp;
    uint8_t dcFanSpeed;
    uint8_t heaterPower;

    char parameters[5];
    char readBuffer[BUFFERSIZE];
    char channels[5];
    volatile enum ArtisanCommand aCommand; // Fails to return the value of function getCommand... if not volatile!
    uint8_t c = 0x40;

    SYSTEM_Initialize();

    setHeaterPower(10);
    setDcFanSpeed(20);

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    index = 0;

    while (1) {
        readByte = EUSART1_Read();
        if (readByte != LF && readByte != CR) {
            readBuffer[index++] = readByte;
            if (index >= BUFFERSIZE) index = 0; // Handling buffer overflow during garbage
        } else if (readByte == CR) {
            index = 0;
            if (startsWith("+DISC:", readBuffer)) {  // Handling client disconnect from the BT module
                    setHeaterPower(10);
                    setDcFanSpeed(50);
                }
        } else {
            readBuffer[index] = EOS;
            aCommand = getCommandAndParams(readBuffer, parameters);
            switch (aCommand) {
                case READ:
                    beanTemp = getBeanTemperature();
                    sendTemperature(beanTemp);
                    break;
                case CHAN:
                    sendChannelsReply(parameters);
                    break;
                case DCFAN:
                    dcFanSpeed = string2int(parameters);
                    if (dcFanSpeed != ERROR) setDcFanSpeed(dcFanSpeed);
                    break;
                case OT1:
                    heaterPower = string2int(parameters);
                    if (heaterPower != ERROR) setHeaterPower(heaterPower);
                    break;
                case ELSE: // Getting rid of BT module messages
                    break;
            }
            index = 0;
        }
    }
}
