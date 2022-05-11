/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF15323
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Heat_Ctrl aliases
#define Heat_Ctrl_TRIS                 TRISAbits.TRISA0
#define Heat_Ctrl_LAT                  LATAbits.LATA0
#define Heat_Ctrl_PORT                 PORTAbits.RA0
#define Heat_Ctrl_WPU                  WPUAbits.WPUA0
#define Heat_Ctrl_OD                   ODCONAbits.ODCA0
#define Heat_Ctrl_ANS                  ANSELAbits.ANSA0
#define Heat_Ctrl_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Heat_Ctrl_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Heat_Ctrl_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Heat_Ctrl_GetValue()           PORTAbits.RA0
#define Heat_Ctrl_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Heat_Ctrl_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Heat_Ctrl_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Heat_Ctrl_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Heat_Ctrl_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Heat_Ctrl_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Heat_Ctrl_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define Heat_Ctrl_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set Temp1_Sens aliases
#define Temp1_Sens_TRIS                 TRISAbits.TRISA4
#define Temp1_Sens_LAT                  LATAbits.LATA4
#define Temp1_Sens_PORT                 PORTAbits.RA4
#define Temp1_Sens_WPU                  WPUAbits.WPUA4
#define Temp1_Sens_OD                   ODCONAbits.ODCA4
#define Temp1_Sens_ANS                  ANSELAbits.ANSA4
#define Temp1_Sens_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Temp1_Sens_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Temp1_Sens_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Temp1_Sens_GetValue()           PORTAbits.RA4
#define Temp1_Sens_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Temp1_Sens_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define Temp1_Sens_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define Temp1_Sens_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define Temp1_Sens_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define Temp1_Sens_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define Temp1_Sens_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define Temp1_Sens_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set Dummy aliases
#define Dummy_TRIS                 TRISCbits.TRISC0
#define Dummy_LAT                  LATCbits.LATC0
#define Dummy_PORT                 PORTCbits.RC0
#define Dummy_WPU                  WPUCbits.WPUC0
#define Dummy_OD                   ODCONCbits.ODCC0
#define Dummy_ANS                  ANSELCbits.ANSC0
#define Dummy_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Dummy_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Dummy_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Dummy_GetValue()           PORTCbits.RC0
#define Dummy_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Dummy_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Dummy_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Dummy_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Dummy_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Dummy_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Dummy_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define Dummy_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/