#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#define button_1 !PTAD_PTAD2
#define button_2 !PTAD_PTAD3
#define button_3 !PTAD_PTAD4
#define button_4 !PTAD_PTAD5

#define Led1 PTDD_PTDD4
#define Led2 PTDD_PTDD5
#define Led3 PTDD_PTDD6
#define Led4 PTDD_PTDD7

#define OFF 1
#define ON 0
#define Flash 2


int Led1_Step = OFF;
int Led2_Step = OFF;
int Led3_Step = OFF;
int Led4_Step = OFF;

int min_Delay = 10;
int button_Delay = 4;

void WatchdogDelay(int);
void Raptor(void);

void main(void) 
{
  EnableInterrupts;
  
  PTAPE = 0b00111100;
  PTDDD = 0b11110000;
  PTDD =  0b11110000;
  
  
  KBIPE_KBIPE5 = 1;
  KBIPE_KBIPE4 = 1;
  KBIPE_KBIPE3 = 1;
  KBIPE_KBIPE2 = 1;
  KBISC_KBIE = 1;	
  KBISC_KBF = 1;	
  
  
  while(1) 
  {
    if(Led1_Step == Flash)
      Led1 = !Led1;
    if(Led2_Step == Flash)
      Led2 = !Led2;
    if(Led3_Step == Flash)
      Led3 = !Led3;
    if(Led4_Step == Flash)
      Led4 = !Led4;
	WatchdogDelay(min_Delay);
    __RESET_WATCHDOG();  
  } 
  
}

interrupt 22U void Raptor(void) {
	WatchdogDelay(100);
	KBISC_KBACK = 1; 
	if (button_1)
	{
		switch (Led1_Step)
		{
			case 0: Led1 = ON;
					Led1_Step =  1;
					break;
			case 1: Led1_Step = Flash;
					break;
			case 2: Led1 = OFF;
					Led1_Step = 0;
					break;
			default:
					break;
		}
		WatchdogDelay(button_Delay);
	}
	WatchdogDelay(100);
	if (button_2)
	{
		switch (Led2_Step)
		{
			case 0: Led2 = ON;
					Led2_Step =  1;
					break;
			case 1: Led2_Step = Flash;
					break;
			case 2: Led2 = OFF;
					Led2_Step = 0;
					break;
			default:
					break;
		}
		WatchdogDelay(button_Delay);
	}
	WatchdogDelay(100);
	if (button_3)
	{
		switch (Led3_Step)
		{
			case 0: Led3 = ON;
					Led3_Step =  1;
					break;
			case 1: Led3_Step = Flash;
					break;
			case 2: Led3 = OFF;
					Led3_Step = 0;
					break;
			default:
					break;
		}
		WatchdogDelay(button_Delay);
	}
	WatchdogDelay(100);
	if (button_4)
	{
		switch (Led4_Step)
		{
			case 0: Led4 = ON;
					Led4_Step =  1;
					break;
			case 1: Led4_Step = Flash;
					break;
			case 2: Led4 = OFF;
					Led4_Step = 0;
					break;
			default:
					break;
		}
		WatchdogDelay(button_Delay);
	}
}

void WatchdogDelay(int delays)
{
	int i = 0;
	int k = 0;
	for(; i < delays; i++)
		for(; k < 10000; k++)
		{
			__RESET_WATCHDOG();
		}
}


