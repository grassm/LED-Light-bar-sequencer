//sequence  right to left all on, then right to left all off



#define T 15
#define NUMBER_OF_LOOPS  5

void sequence_b()
{
#ifdef PRINT_INFO 
SERIAL.print("b  T=");  SERIAL.println(T);    
#endif
for (int counter = 0; counter <= NUMBER_OF_LOOPS; counter ++)  
   {   
 //turn all LEDs on
   for (int inDex = LAST_LED; inDex >= FIRST_LED; inDex--)
        {
          pwmWrite(boardPWMPins[ inDex ],POWER_B);
          delay(T);
        }
//turn them all off
   for (int inDex =LAST_LED; inDex >= FIRST_LED; inDex --)
        {
          pwmWrite(boardPWMPins[inDex],POWER_OFF);
          delay(T);
        }        
   }//end of number of loops 
z_all_off();
}



