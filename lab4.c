#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

#define LED_1 PTDD_PTDD4
#define LED_2 PTDD_PTDD5
#define LED_3 PTDD_PTDD6
#define LED_4 PTDD_PTDD7

#define button_1 PTAD_PTAD2
#define button_2 PTAD_PTAD3
#define button_3 PTAD_PTAD4
#define button_4 PTAD_PTAD5
interrupt VectorNumber_Vtpm1ch0 void step(void)
{
	if(TPM1C0SC_CH0F) TPM1C0SC_CH0F = 0;
	LED_1 = !LED_1; 
	TPM1SC_TOF = 0;
}
interrupt VectorNumber_Vkeyboard1 void click(void)
{
	KBISC_KBACK = 1;
    
	if(button_1 == 0) 
	{
		TPM1SC_PS2 = TPM1SC_PS1 = TPM1SC_PS0 = 1;
		TPM1C0SC = 0;
		TPM1C0SC_CH0IE = TPM1C0SC_MS0A = 1;
		TPM1SC_CLKSA = 1;
		TPM1SC_TOIE = 1;
	}
	else if(button_2 == 0)
	{
		TPM1SC_CLKSA = 0;
		TPM1C0SC = 0;
		LED_1 = 1;
	}
	else if (button_3 == 0)
	{
		int fd = TPM1SC & 0b00000111; 
		if(fd != 0b00000111) fd += 1;			
		TPM1SC_PS0 = fd & 1;
		TPM1SC_PS1 = (fd >> 1) & 1;
		TPM1SC_PS2 = (fd >> 2) & 1;
	}
	else if (button_4 == 0)
	{
		int fd = TPM1SC & 0b00000111;
		if(fd) fd -= 1; 
		TPM1SC_PS0 = fd & 1;
		TPM1SC_PS1 = (fd >> 1) & 1;
		TPM1SC_PS2 = (fd >> 2) & 1;
	}
}
void main(void) {
  EnableInterrupts;
  PTDDD = 0b11110000;
  PTDD = ~0;
  PTAPE_PTAPE2 = 1;
  PTAPE_PTAPE3 = 1; 
  PTAPE_PTAPE4 = 1;
  PTAPE_PTAPE5 = 1;

  KBIPE_KBIPE5 = 1;
  KBIPE_KBIPE4 = 1;
  KBIPE_KBIPE3 = 1;
  KBIPE_KBIPE2 = 1;
  KBISC_KBIE = 1;
  KBISC_KBF = 1;
  TPM1SC = 0; 
  TPM1C0V = 0; 
  TPM1MOD = 50000;
  TPM1CNTH = 0; 
    __RESET_WATCHDOG();
  } 
}
