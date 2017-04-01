/* Sequence e   is the opposite of sequence d. It starts at the inboard pair  
 *      duaAl LED  middle to outside all ON then turn OFF from outside to inside
 *       so  on then off of each of these pairs     5:6   4:7    3:8   2:9    1:10   0:11
 */

 #define NUMBER_OF_LOOPS  5
#define T 20
 void    sequence_e()
 {
#ifdef PRINT_INFO   
SERIAL.print("e  T=");  SERIAL.println(T); 
#endif
int indexA=0;
int indexB=0;  
 for (int counter=0;counter <= NUMBER_OF_LOOPS;counter++)
       {//start of the loop for how many times to repeat
       indexB=CENTER_RIGHT_LED;
               
//from inside center going to outside,  turn each on 
       for (indexA=CENTER_LEFT_LED; indexA >= FIRST_LED;indexA--)//going outside to inside ON OFF incr
                   {
                   pwmWrite(boardPWMPins[indexA],POWER_A); //turn them on from center to outside and leave on.
                   pwmWrite(boardPWMPins[indexB],POWER_A); //
                   delay(T);
                   pwmWrite(boardPWMPins[indexA],POWER_OFF);
                   pwmWrite(boardPWMPins[indexB],POWER_OFF);
                   delay(T);
                   indexB++;                   
                   }
/* ?? I think this block was supposed to be removed.
//from outside to inside center,  turn each off
       indexB=LAST_LED; 
       for (indexA=FIRST_LED; indexA <= CENTER_LEFT_LED; indexA++)//going outside to inside ON OFF incr
                   {
                   pwmWrite(boardPWMPins[indexA],POWER_OFF);
                   pwmWrite(boardPWMPins[indexB],POWER_OFF);
                   delay(T);
                   indexB--;                   
                   }                   
*/
       }// ---  end of counting  loop
z_all_off();       
}//-------------------end of function sequence_e()


