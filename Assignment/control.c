/*
* control.c
*
* contains code for reading buttons
* and writing data to LEDs
*
* Author: Thomas Marshall (B00705297)
* Date: 04/12/17
*
*/
 
#include "control.h"

int ledtoggleTime=2500000;
int colour=GREEN;
void setup()
{
    SYSCTL_RCGCGPIO_R=0x20U;
    GPIO_PORTF_LOCK_R=0x4C4F434BU;
    GPIO_PORTF_CR_R=0xFF;
    GPIO_PORTF_DIR_R=RED|GREEN|BLUE;
    GPIO_PORTF_PUR_R=0x11U;
    GPIO_PORTF_DEN_R=0x1FU;
}
void listen()
{
    switch(GPIO_PORTF_DATA_R & 0x11U)
		{
		    case 0x00: //Both Buttons
				    colour=RED;
				    break;
			
			    case 0x01: //Right Button
				    if(ledtoggleTime>2500000)
				    {
					    colour=GREEN;
					    ledtoggleTime/=1.25;
				    }
			  	break;
			
		  	case 0x10: //Left Button
				  if(ledtoggleTime<12500000)
				  {
					  colour=GREEN;
				  	ledtoggleTime*=1.25;
			  	}
				
				  break;
				
			  default:
			  	colour=GREEN;
		  	break;
		}
		  flashled(ledtoggleTime, colour);
}
void flashled(int speed, int colour)
{
	  GPIO_PORTF_DATA_R&=(~0x0EU);
	  delay(speed);
	  GPIO_PORTF_DATA_R=colour;
	  delay(speed);
}

void delay(int time)
{
    int delay=0;
	  while (delay < time)
	  {
		  delay++;
	  }
}
