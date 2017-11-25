/* 1. Set up GPIO Clock (RCGCGPIO)
	  Base = 0x400FE000
		Offset = 0x608
		required address = 0x4000FE608

 2. Set up Direction Register (GPIODIR)
	  Base = 0x40025000
		Offset = 0x400
		required address = 0x40025400

 3. Setup Digital Enable register (GPIODEN)
	   Base = 0x40025000
		Offset = 0x51C
		required address = 0x4002551C

 4. Write data to GPIO pin (GPIODATA)
	   Base = 0x40025000
		Offset = 0x000
		required address = 0x40025000
*/

int main()
	{
		//1. Set up GPIO Clock
		unsigned int *pt;
		pt=(unsigned int *)0x400FE608U;
		*pt  = 0x00000020U ; //0b 0000 0000 0000 0000 0000 0000 0010 0000    Port F = Bit 5
			
		// 2. Set up Direction Register (GPIODIR)
		pt=(unsigned int *)0x40025400U;
		*pt  = 0x0000000EU ; //0b 0000 0000 0000 0000 0000 0000 0000 1110    Port F = Bit 1,2 & 3 outputs connected to LED
		
		//3. Setup Digital Enable register (GPIODEN)
		pt=(unsigned int *)0x4002551CU;
		*pt  = 0x0000000EU ; //0b 0000 0000 0000 0000 0000 0000 0000 1110    Port F = enable function for Bits 1,2 & 3
		
		// 4. Write data to GPIO pin (GPIODATA)
		pt=(unsigned int *)0x400253FCU;										//Port F = mask bits set for 9:2
		*pt  = 0x00000002U ; //0b 0000 0000 0000 0000 0000 0000 0000 0010    
	}
