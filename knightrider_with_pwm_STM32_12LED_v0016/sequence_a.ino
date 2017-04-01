//sequence  left to right  all on then left to right all off
#define T 15
#define NUMBER_OF_LOOPS  5
void sequence_a()
{
#ifdef PRINT_INFO
SERIAL.print("a  T=");  SERIAL.println(T);      
#endif
for (int counter = 0;counter <= NUMBER_OF_LOOPS; counter ++)  
   {  
 //turn all LEDs on
   for (inDex = FIRST_LED; inDex <=LAST_LED; inDex ++)
        {
          pwmWrite(boardPWMPins[inDex],POWER_A);
          delay(T);
        }//end of turn them all on
//   turn them all off
   for (inDex = FIRST_LED; inDex <= LAST_LED; inDex ++)
        {
          pwmWrite(boardPWMPins[ inDex ],POWER_OFF);
          delay(T);
        } //end of turn all off      
   }//end of number of loops  
z_all_off();
}//end of function



