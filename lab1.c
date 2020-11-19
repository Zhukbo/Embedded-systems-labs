#include "derivative.h" // Include peripheral declarations 
#include <hidef.h> //EnableInterrupts macro

void
main(void) {
  EnableInterrupts;
  EnableInterrupts;
  
  //Ex1
  PTDDD = 0b11110100;
  PTDD =  0b00000000;  
  
  //Ex2 
  PTDDD = 0b00000100; //hooter
  PTDD = 0b00000100;
  PTCD = 0b00010000; //green color
  PTCD = 0b00000000;   
  
  //Ex3
  PTDDD = 0b10100000; //red color
  PTDD = 0b00000000;
  PTCDD = 0b00010000; //green color
  PTCD = 0b00000000; 
  
  while(1) {
    __RESET_WATCHDOG();
  }
}