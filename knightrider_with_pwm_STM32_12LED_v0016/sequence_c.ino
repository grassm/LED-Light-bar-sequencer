/*Sequence c:  going from center 2 LEDs  to outside
 * act like a peak level meter. 5:6 on, then 4:7 on, then 3:8,  2:9,  1:10,  0:11
 * Then turn off in opposite order
 */

#define NUMBER_OF_LOOPS  5
#define T 30
 void    sequence_c()
 {
#ifdef PRINT_INFO 
SERIAL.print("d  T=");  SERIAL.println(T);   
#endif
int indexA=0;
int indexB=11;  
 for (int counter=0;counter <= NUMBER_OF_LOOPS;counter++)
       {//start of the loop for how many times to repeat
       for (int insideCounter=0; insideCounter<=1; insideCounter++)
               {
               indexB=CENTER_RIGHT_LED;        
               for (indexA=CENTER_LEFT_LED ; indexA >= FIRST_LED; indexA--)//going outside to inside ON OFF incr
                           {
                           pwmWrite(boardPWMPins[indexA],POWER_A);
                           pwmWrite(boardPWMPins[indexB],POWER_A);
                           indexB++; 
                           delay(T/2);                  
                           }
                  
//now turn them off in reverse order from outside to center
               indexB=LAST_LED;        
               for (indexA= FIRST_LED; indexA <= CENTER_LEFT_LED; indexA++)//going outside to inside ON OFF incr
                           {
                           pwmWrite(boardPWMPins[indexA],POWER_OFF);
                           pwmWrite(boardPWMPins[indexB],POWER_OFF);
                           indexB--; 
                           delay(T/2);                  
                           }
               }//end of inside loop counter            
       delay(4*T);          
       }// ---  end of counting  loop
z_all_off();
}//-------------------end of function sequence_c()




