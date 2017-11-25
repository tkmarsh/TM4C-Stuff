#include "control.h"
void increaseToggle(){
}
void decreaseToggle(){
}
void listen(){
	GPIO_PORTF_DATA_R&=(~0x0EU);
		switch(GPIO_PORTF_DATA_R & 0x11U){
			case 0x00:
				GPIO_PORTF_DATA_R |=RED;
				break;
			
			case 0x01:
				GPIO_PORTF_DATA_R |=BLUE;
				break;
			
			case 0x10:
				GPIO_PORTF_DATA_R |=GREEN;
				break;
		}
}
void setLED(){
	GPIO_PORTF_DATA_R |=GREEN;
}