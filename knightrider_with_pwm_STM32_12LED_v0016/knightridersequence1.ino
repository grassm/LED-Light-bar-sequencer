/*boardPWMPins[inDex]
 * 
 */

#define T 40    //normal value is 10
#define NUMBER_OF_LOOPS  3
void knightridersequence1()
{ 
#ifdef PRINT_INFO  
SERIAL.print("nightrider T=");  SERIAL.println(T);      
#endif
for (int counter=0; counter <= NUMBER_OF_LOOPS; counter++)  
   {
   for ( inDex = FIRST_LED; inDex <= LAST_LED;  inDex++)
        {
          
//          SERIAL.print(boardPWMPins[inDex]); SERIAL.print(",  "); SERIAL.print(boardPWMPins[inDex+1]); SERIAL.print(",  "); SERIAL.println(boardPWMPins[inDex+2]);
//        SERIAL.print("  "); SERIAL.print(inDex);SERIAL.print("=C");
        pwmWrite(boardPWMPins[inDex],POWER_C);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex+1);SERIAL.print("=B");
        pwmWrite(boardPWMPins[inDex+1],POWER_B);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex+2);SERIAL.print("=A");
        pwmWrite(boardPWMPins[inDex+2],POWER_A);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex);SERIAL.println("OFF");
        pwmWrite(boardPWMPins[inDex],POWER_OFF);
        delay(T);     
        }
        pwmWrite(boardPWMPins[LAST_LED-2],0);
//  this reverses the direction of the LED sweep             
//??   for ( inDex=LAST_LED+1;inDex>FIRST_LED;inDex--)
        {
//         SERIAL.print(boardPWMPins[inDex]); SERIAL.print(",  "); SERIAL.print(boardPWMPins[inDex-1]); SERIAL.print(",  "); SERIAL.println(boardPWMPins[inDex-2]);
//        SERIAL.print("  "); SERIAL.print(inDex);SERIAL.print("=C");
        pwmWrite(boardPWMPins[inDex],POWER_C);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex-1);SERIAL.print("=B");
        pwmWrite(boardPWMPins[inDex-1],POWER_B);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex-2);SERIAL.print("=A");
        pwmWrite(boardPWMPins[inDex-2],POWER_A);
        delay(T);
//        SERIAL.print("  "); SERIAL.print(inDex);SERIAL.println("=OFF");
        pwmWrite(boardPWMPins[inDex],POWER_OFF);
        delay(T);
   //     SERIAL.print("  "); SERIAL.print(inDex-1);SERIAL.println("=C");
   //     pwmWrite(boardPWMPins[inDex-1],POWER_C);
   //     delay(T);     
        }//end of reverse direction
   }//end of number of loops
z_all_off();      
}//end of function

