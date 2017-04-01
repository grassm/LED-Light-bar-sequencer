/* Sequence d   
 *      dual LED  outside to middle ON then OFF
 *      On then off of each pair   0 and 11 on then off,   1 and 10 on then off,  2 and 9,    3 and 8,  4 and 7,  5 and 6,  
 */


 #define NUMBER_OF_LOOPS  5
#define T 30
 void    sequence_d()
 {
#ifdef PRINT_INFO   
SERIAL.print("d  T=");  SERIAL.println(T); 
#endif
int indexA=0;
int indexB=11;  
 for (int counter=0;counter <= NUMBER_OF_LOOPS;counter++)
       {//start of the loop for how many times to repeat
       indexB=LAST_LED;        
       for (indexA=FIRST_LED ; indexA <= CENTER_LEFT_LED; indexA++)//going outside to inside ON OFF incr
                   {
                   pwmWrite(boardPWMPins[indexA],POWER_A);
                   pwmWrite(boardPWMPins[indexB],POWER_A);
                   delay(T);
                   pwmWrite(boardPWMPins[indexA],POWER_OFF);
                   pwmWrite(boardPWMPins[indexB],POWER_OFF);
                   delay(T);
                   indexB--;                   
                   }
       }// ---  end of counting  loop
z_all_off();       
}//-------------------end of function sequence_d()



