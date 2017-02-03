#include <xc.h>
#include <stdio.h>
#include "..\Common\osc.h"            // library for set_osc_32MHz()
#include "..\Common\configureUSART.h" // library for configureUSART(baud)
#include "..\Common\configuration_bits.h"
#include "..\buttons.h"  // has monitor_switch1_for_edges()
# define _XTAL_FREQ 32000000

void main(void) 
{ 
    
    set_osc_32MHz();
    configureUSART(9300ul, 32);
    _delay(100000ul);
    _delay(100000ul);
    _delay(100000ul);
    _delay(100000ul);
    _delay(100000ul);
    __delay_ms(1000);
    char has_switch1_changed = 0;
    char has_switch2_changed = 0;
    signed char blinkrate = 0;
    signed char button = 0;
    TRISDbits.RD1 = 1; // set RD1 as input (switch 1)
    TRISDbits.RD2 = 0;
    TRISDbits.RD0 = 1;
    TRISDbits.RD3 = 0;
    while(1) 
    { 
        has_switch1_changed = monitor_switch1_for_edges(PORTDbits.RD1);
        has_switch2_changed = monitor_switch2_for_edges(PORTDbits.RD0);
        //happens every cycle of while loop

        if (has_switch1_changed == 1)
            {  
             //anything that should happen occasionally should be in here 
             blinkrate++;                      //increment counter 
             if (blinkrate > 3) blinkrate = 0; //cycle back to 0
            }
        if (has_switch2_changed == 1)
            {  
             //anything that should happen occasionally should be in here 
             blinkrate--;                      //increment counter 
             if (blinkrate < 0) blinkrate = 3; //cycle back to 0
            }
        if (has_switch1_changed == 1 && has_switch2_changed == 1)
            {  
            if(blinkrate = 0) blinkrate == 4;
            if(blinkrate = 1) blinkrate == 5;
            if(blinkrate = 2) blinkrate == 6;
            if(blinkrate = 3) blinkrate == 7;
            
            if(blinkrate = 4) blinkrate == 0;
            if(blinkrate = 5) blinkrate == 1;
            if(blinkrate = 6) blinkrate == 2;
            if(blinkrate = 7) blinkrate == 3;
            }
        //happens every cycle of while loop 
        switch(blinkrate) // switch between blink rates
        {
            case 0: // code here for pin on, delay, pin off, delay
                PORTDbits.RD2 = 0;
                PORTDbits.RD3 = 0;
                printf("%c%c",0xFE,0x01);   
                printf("SYNC OFF");
                break;
            case 1: // code here for pin on, delay, pin off, delay
                  PORTDbits.RD2 = 1;
                  PORTDbits.RD3 = 1;
                  __delay_ms(79.2);
                  PORTDbits.RD2 = 0;
                  PORTDbits.RD3 = 0;
                  __delay_ms(160.8);
                printf("%c%c",0xFE,0x01);   
                printf("SYNC SLOW");
                if (has_switch1_changed == 1 && has_switch2_changed == 1)
                    
                break; 
            case 2: // code here for pin on, delay, pin off, delay
                  PORTDbits.RD2 = 1;
                  PORTDbits.RD3 = 1;
                  __delay_ms(52.8);
                  PORTDbits.RD2 = 0;
                  PORTDbits.RD3 = 0;
                  __delay_ms(35.2);
                printf("%c%c",0xFE,0x01);   
                printf("SYNC MODERATE");
                break; 
            case 3: // code here for pin on, delay, pin off, delay
                PORTDbits.RD2 = 1;
                PORTDbits.RD3 = 1;
                printf("%c%c",0xFE,0x01);   
                printf("SYNC ON");
                break;
            case 4: // code here for pin on, delay, pin off, delay
                PORTDbits.RD2 = 0;
                PORTDbits.RD3 = 0;
                printf("%c%c",0xFE,0x01);   
                printf("ALT OFF");
                break;
            case 5: // code here for pin on, delay, pin off, delay
                  PORTDbits.RD2 = 1;
                  PORTDbits.RD3 = 0;
                  __delay_ms(79.2);
                  PORTDbits.RD2 = 0;
                  PORTDbits.RD3 = 1;
                  __delay_ms(160.8);
                printf("%c%c",0xFE,0x01);   
                printf("ALT SLOW");
                break; 
            case 6: // code here for pin on, delay, pin off, delay
                  PORTDbits.RD2 = 1;
                  PORTDbits.RD3 = 0;
                  __delay_ms(52.8);
                  PORTDbits.RD2 = 0;
                  PORTDbits.RD3 = 1;
                  __delay_ms(35.2);
                printf("%c%c",0xFE,0x01);   
                printf("ALT MODERATE");
                break; 
            case 7: // code here for pin on, delay, pin off, delay
                PORTDbits.RD2 = 1;
                PORTDbits.RD3 = 1;
                printf("%c%c",0xFE,0x01);   
                printf("ALT ON");
                break; 
        }
        
    } 
} 
