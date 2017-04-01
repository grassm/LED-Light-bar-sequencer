/*Diagnostic2() is a slow sequencial fade of all the PWM pins in the boardPWMPin[] array
 * 
 */
 #define T 500  // This allows for a slow fade, so this slow human can make sure what's happening on each pin
void diagnostic2()
{
for(int index=0; index <= 11; index++)
      {
      output(index);  
      }
//next line was replaced by the for loop above      
//output(0);output(1);output(2);output(3);output(4);output(5);output(6);output(7);output(8);output(9);output(10);output(11);
//now reset the output for each pwm pin
  for (uint8  index=0; index <=11 ; index++)
         {
          pwmWrite(boardPWMPins[index],       POWER_OFF);
         }    
}//end of function   -----------------------------------------  diagnostic2() ------------------------------------------------------------------------


//+++++++++++++++++++++++++++++++++++++++++++++  start of function diagnostic2()  +++++++++++++++++++++++
void output(uint8  index)
{
  
#ifdef PRINT_INFO   
SERIAL.print("input=");  SERIAL.print(index); SERIAL.print(", associated pin="); SERIAL.println(boardPWMPins[index]);
#endif

pwmWrite(boardPWMPins[index],POWER_A);
delay(T);
pwmWrite(boardPWMPins[index],POWER_B);
delay(T);
pwmWrite(boardPWMPins[index],POWER_C);
delay(T);
pwmWrite(boardPWMPins[index],POWER_D);
delay(T);
z_all_off(); 
}//----------------------------------------------------------------------------   end of function output()  ---------------------------------------------------

