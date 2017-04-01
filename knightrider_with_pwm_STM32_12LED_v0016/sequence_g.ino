/* Sequence g  
 *  This sequence strobes all 6 LEDs on left side
 *  and then strobes all 6 LEDs on the right side
 */

 void    sequence_g()   
 {
#define NUMBER_OF_LOOPS  5
#define NUMBER_OF_STROBES   3
#define T 50 
#ifdef PRINT_INFO   
SERIAL.print("f  T=");  SERIAL.println(T); 
#endif
 for (int counter=0;counter <= NUMBER_OF_LOOPS;counter++)
       {//start of the loop for how many times to repeat              
       //flash  left LEDS  
       for (int cnt =0; cnt < NUMBER_OF_STROBES; cnt ++)
                   {
                   for(int index=0; index<= 5;index++)
                          {
                            pwmWrite(boardPWMPins[index],MAX_LEVEL); //turn them on 
                          }//end of turning left side on
                  delay(T);                   
                  for(int index=0; index<= 5;index++)
                          {
                            pwmWrite(boardPWMPins[index],POWER_OFF); //turn them on 
                          } //end of turning left side off           
                   delay(T);
                   }// end of strobing left side               
//flash right LEDS 
       for (int cnt=0; cnt < NUMBER_OF_STROBES; cnt++)
                   {
                   for(int index=6; index<= LAST_LED; index++)
                          {
                            pwmWrite(boardPWMPins[index],MAX_LEVEL); //turn them on 
                          }
                  delay(T);                   
                  for(int index=6; index<= LAST_LED; index++)
                          {
                            pwmWrite(boardPWMPins[index],POWER_OFF); //turn them off 
                          }            
                   delay(T);
                   } //end of strobe right side LEDs                                 
       }// ---  end of counting  loop
z_all_off();
}//-------------------end of function sequence_f()


