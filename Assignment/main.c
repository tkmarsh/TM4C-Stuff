/*
* main.c
*
* calls the control.c listen
* function in a loop
*
* Author: Thomas Marshall (B00705297)
* Date: 04/12/17
*
*/

#include "control.h"

int main()
{
    setup();
	    while(1)
	    {
		    listen();
	    }
}