#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#define ON 1
#define OFF 0
#define LED_1 PTDD_PTDD4
#define LED_2 PTDD_PTDD5
#define LED_3 PTDD_PTDD6
#define LED_4 PTDD_PTDD7
#define button_1 PTAD_PTAD2
#define button_2 PTAD_PTAD3
#define button_3 PTAD_PTAD4
#define button_4 PTAD_PTAD5

int Led_1_Step = 0;
int Led_2_Step = 0;
int Led_3_Step = 0;
int Led_4_Step = 0;
int counter = 0;

void main(void)
{
	EnableInterrupts;
	PTAPE = 0b00111100;
	PTDDD = 0b11110000;
	PTDD = 0b11110000;
	while (1)
	{
		if (Led_1_Step == 2)
		{
			LED_1 = !LED_1;
		}
		if (Led_2_Step == 2)
		{
			LED_2 = !LED_2;
		}
		if (Led_3_Step == 2)
		{
			LED_3 = !LED_3;
		}
		if (Led_4_Step == 2)
		{
			LED_4 = !LED_4;
		}
		if (!button_1) //condition for button 1
		{
			switch (Led_1_Step)
			{
			case 0: LED_1 = ON; //turn on LED 1
				Led_1_Step =  1;
				break;
			case 1: Led_1_Step = 2;
				break;
			case 2: LED_1 = OFF;//turn off LED 1
				Led_1_Step = 0;
				break;
			default:
				break;
			}
			for (counter = 0; counter < 1000; counter++)
			{
				__RESET_WATCHDOG();
			}
		}
		if (!button_2) //condition for button 2
		{
			switch (Led_2_Step)
			{
			case 0: LED_2 = ON; //turn on LED 2
				Led_2_Step = 1;
				break;
			case 1: Led_2_Step = 2;
				break;
			case 2: LED_2 = OFF; //turn off LED 2
				Led_2_Step = 0;
				break;
			default:
				break;
			}
			for (counter = 0; counter < 1000; counter++)
			{
				__RESET_WATCHDOG();
			}
		}
		if (!button_3) //condition for button 3
		{
			switch (Led_3_Step)
			{
			case 0: LED_3 = ON; //turn on LED 3
				Led_3_Step = 1;
				break;
			case 1: Led_3_Step = 2;
				break;
			case 2: LED_3 = OFF; //turn off LED 3
				Led_3_Step = 0;
				break;
			default:
				break;
			}
			for (counter = 0; counter < 1000; counter++)
			{
				__RESET_WATCHDOG();
			}
		}
		if (!button_4) //condition for button 4
		{
			switch (Led_4_Step)
			{
			case 0: LED_4 = ON; //turn on LED 4
				Led_4_Step = 1;
				break;
			case 1: Led_4_Step = 2;
				break;
			case 2: LED_4 = OFF; //turn off LED 4
				Led_4_Step = 0;
				break;
			default:
				break;
			}
			for (counter = 0; counter < 1000; counter++)
			{
				__RESET_WATCHDOG();
			}
		}
		for (i = counter; counter < 10000; counter++)
		{
			__RESET_WATCHDOG();
		}
	}
}