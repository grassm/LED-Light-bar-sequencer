/* Sequence f   
 *  This sequence strobes groups of 3 LEDs 
 */

 void    sequence_f()   
 {
#define NUMBER_OF_LOOPS  5
#define T 50   //10
#ifdef PRINT_INFO   
SERIAL.print("f  T=");  SERIAL.println(T); 
#endif
//int indexA=0;
int indexB=0;  
 for (int counter=0;counter <= NUMBER_OF_LOOPS;counter++)
       {//start of the loop for how many times to repeat
       indexB=CENTER_RIGHT_LED;
               
//flash  LEDS 0,1, and 2 
       for (int i=0; i<3; i++)
                   {
                   pwmWrite(boardPWMPins[0],POWER_A); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[1],POWER_A); //
                   pwmWrite(boardPWMPins[2],POWER_A); //                 
                   delay(T);
                   pwmWrite(boardPWMPins[0],POWER_OFF); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[1],POWER_OFF); //
                   pwmWrite(boardPWMPins[2],POWER_OFF); //                
                   delay(T);
                   }               
//flash right LEDS 11,10,9     3 times
       for (int i=0; i<3; i++)
                   {
                   pwmWrite(boardPWMPins[11],POWER_A); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[10],POWER_A); //
                   pwmWrite(boardPWMPins[9],POWER_A); //                 
                   delay(T);
                   pwmWrite(boardPWMPins[11],POWER_OFF); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[10],POWER_OFF); //
                   pwmWrite(boardPWMPins[9],POWER_OFF); //                
                   delay(T);
                   } 
//now do it for LEDs 3,4,5 and 6,7,8
       for (int i=0; i<3; i++)
                   {
                   pwmWrite(boardPWMPins[3],POWER_A); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[4],POWER_A); //
                   pwmWrite(boardPWMPins[5],POWER_A); //                 
                   delay(T);
                   pwmWrite(boardPWMPins[3],POWER_OFF); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[4],POWER_OFF); //
                   pwmWrite(boardPWMPins[5],POWER_OFF); //                
                   delay(T);
                   }               

       for (int i=0; i<3; i++)
                   {
                   pwmWrite(boardPWMPins[8],POWER_A); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[7],POWER_A); //
                   pwmWrite(boardPWMPins[6],POWER_A); //                 
                   delay(T);
                   pwmWrite(boardPWMPins[8],POWER_OFF); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[7],POWER_OFF); //
                   pwmWrite(boardPWMPins[6],POWER_OFF); //                
                   delay(T);
                   }                                   
       }// ---  end of counting  loop
z_all_off();       
}//-------------------end of function sequence_f()


