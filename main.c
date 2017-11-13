#include "include/tm4c123gh6pm.h"
#include "include/delay.h"
#define RED (1U<<1)
#define BLUE (1U<<2)
#define GREEN (1U<<3)


int main()
	{
		SYSCTL_RCGCGPIO_R=0x20U;
		GPIO_PORTF_DIR_R=RED|BLUE|GREEN;
		GPIO_PORTF_DEN_R=RED|BLUE|GREEN;
		GPIO_PORTF_DATA_R=GREEN|BLUE;
		
		while(1){
			for(int i=0; i<2; i++){
				GPIO_PORTF_DATA_R=GREEN|BLUE;
				delay(250000);
				GPIO_PORTF_DATA_R &= (~RED&~GREEN&~BLUE) ;
				delay(250000);
			}
			delay(500000);
			
			for(int i=0; i<2; i++){
				GPIO_PORTF_DATA_R=RED;
				delay(250000);
				GPIO_PORTF_DATA_R &= (~RED&~GREEN&~BLUE) ;
				delay(250000);
			}
			delay(500000);
	}
}
	
