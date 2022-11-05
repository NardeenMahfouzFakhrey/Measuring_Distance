 /******************************************************************************
 * File Name: main.c
 * Author: Nardeen
 *******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>

int main(){
	Ultrasonic_init();//initialize ultrasonic sensor
	LCD_init(); // make initialization to lcd
	LCD_displayString("Distance=    cm");
	uint16 distance=0;
	SREG |= (1<<7); // enable global interrupts

	while(1) {

		LCD_moveCursor(0,9);
		distance=Ultrasonic_readDistance();// get value of measured distance

		if(distance<100){

				LCD_intgerToString(distance);
				LCD_displayString("  ");

		}
		else LCD_intgerToString(distance); // display the distance on lcd
	}

}

