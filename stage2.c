/***********************************************************
*  Program to create a 8-led sequence 
*  This sequence consists in some terms of Fibonacci sequence (sequence 1)
*  and a counting from 0 to 255 (sequence 2)
*  Micro: Atmega328P
*  Date: 24-02-2022
************************************************************/

//*************** Macros **********************************
#define F_CPU 16000000UL // 16 MHz clock speed


//*************** Librerias *******************************
#include <avr/io.h> // avr library
#include <util/delay.h>  //delay library


//*************** Functions and subroutines ******************



/************************************************************** 
 *  Pin-reading definition throught a macro #define
 *  PD2 depict pin D2
 *  #define <nombremacro> (puerto & (1<<pinpuerto))>>pinpuerto
 ***************************************************************/

#define pulsador0 (PINC & (1<<PC5))>>PC5

//********** Global variables definition  ***********

const int time=50;
const int n = 8; // number of led/bits
 
//*************** Main Program **********************
int main(void)
{

  //**********Ports Setting **********************
  //Port D as output
  //0xFF = 0b11111111
  //PORT C as input
  // 0b00010000 = 0x10 

  DDRD |= 0xFF;
  DDRC |= 0x00;
  
  int counting = 0;
  while(1) // endless loop
  {
	  PORTC = 0x00;
	  PORTD = 0x00;
	
	
	  if (pulsador0)
	  {
		  counting++;
	  }
	  
	  if (counting == 0)
	  {
		seq1();  
	  }
	  if (counting == 1)
	  {
		  seq2();
		  counting = 0;
		  if(pulsador0)
		  {
			  couting=0;
		  }
	  }
  }
  return 0;
}//** End of Program

void seq1(){
	int FibTerms[14] ={0,1,1,2,3,5,8,13,21,34,55,89,144,233};
	for (int i = 0; i < 14; i++)
	{
		PORTD = FibTerms[i];
		_delay_ms(time);
	}	
}
void seq2(){
	for (int i = 0; i < pow(2.0,n); i++)
	{
		PORTD = i;
		_delay_ms(time);//1seg delay
	}
}
