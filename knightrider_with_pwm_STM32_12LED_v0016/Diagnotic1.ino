/*Diagnostic1 uses analogWrite() statements
 * 
 */
#define T 10 //this is the mSec delay used in the function
void diagnostic1()
{
#ifdef PRINT_INFO 
  SERIAL.println("diagnostics");
#endif  
  for (int ledPos=FIRST_LED; ledPos <= LAST_LED; ledPos++)
         {
          #ifdef PRINT_INFO 
          SERIAL.print(ledPos);   SERIAL.print(" pin number= "); SERIAL.println(  boardPWMPins[ledPos]   );
          #endif
          for(int level=0; level < MAX_LEVEL; level=+255) //255 is the incr amount NOT THE %DC/POWER LEVEL
                {
                 pwmWrite(boardPWMPins[ledPos],level);
                 delay(T); 
                } //end of fade loop
           pwmWrite(boardPWMPins[ledPos],0);     
         }//end of inDex loop
z_all_off();  
}//end of function

