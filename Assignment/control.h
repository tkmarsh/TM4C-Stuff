/* 
* control.h
*
* contains definitions for registers
* and declarations for functions
*
* Author: Thomas Marshall (B00705297)
* Date: 04/12/17
*
*/

#define SYSCTL_RCGCGPIO_R	(*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTF_LOCK_R (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R   (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_PUR_R  (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC))
#define RED (1U<<1)
#define BLUE (1U<<2)
#define GREEN (1U<<3)
#define YELLOW (RED && GREEN)
void setup();
void delay(int time);
void flashled();
void listen();
