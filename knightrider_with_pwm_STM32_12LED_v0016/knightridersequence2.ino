/*
 * Nightrider 2....fixing problems with knightridersequence2
 */

#define T 7  //normal value is 10
#define NUMBER_OF_LOOPS  5   // NORMAL 10
int temp;
void knightridersequence2()
{ 
#ifdef PRINT_INFO  
SERIAL.print("nightrider2 T=");  SERIAL.println(T);      
#endif

       
for (int counter=0; counter <= NUMBER_OF_LOOPS; counter++)  
      {    
       //  Sweep from FIRST_LED  to LAST_LED
       for(int i = FIRST_LED; i <= LAST_LED+4; i++)
               {
                
//                SERIAL.print("i="); SERIAL.print(i);                 
                if( (i) >= FIRST_LED &&  (i) <= LAST_LED  )  pwmWrite(boardPWMPins[(i)],MAX_LEVEL);
                delay(T);
//                SERIAL.print(", i-1="); SERIAL.print(i-1);
                if( (i-1) >= FIRST_LED &&  (i-1) <= LAST_LED  )  pwmWrite(boardPWMPins[(i-1)],POWER_B);
                delay(T);
//                SERIAL.print(", i-2="); SERIAL.print(i-2);
                if( (i-2) >= FIRST_LED &&  (i-2) <= LAST_LED  ) pwmWrite(boardPWMPins[(i-2)],POWER_C);
                delay(T);
//                SERIAL.print(", i-3="); SERIAL.print(i-3);
                if( (i-3) >= FIRST_LED &&  (i-3) <= LAST_LED  )  pwmWrite(boardPWMPins[(i-3)],POWER_D);
                delay(T);      
 //               SERIAL.print(", i-4="); SERIAL.print(i-4);          
                if( (i-4) >= FIRST_LED &&  (i-4) <= LAST_LED  )  pwmWrite(boardPWMPins[(i-4)],POWER_OFF);
                delay(T);
//                SERIAL.println();              
               }
       //  Sweep from LAST_LED  to FIRST_LED 
       for(int i =  LAST_LED; i >= FIRST_LED-4 ; i--)
               {
 //               SERIAL.print("i="); SERIAL.print(i);                 
                if( (i) >= FIRST_LED &&  (i) <= LAST_LED  )  pwmWrite(boardPWMPins[(i)],POWER_A);
                delay(T);
 //               SERIAL.print(", i+1="); SERIAL.print(i+1);
                if( (i+1) >= FIRST_LED &&  (i+1) <= LAST_LED  )  pwmWrite(boardPWMPins[(i+1)],POWER_B);
                delay(T);
//                SERIAL.print(", i+2="); SERIAL.print(i+2);
                if( (i+2) >= FIRST_LED &&  (i+2) <= LAST_LED  ) pwmWrite(boardPWMPins[(i+2)],POWER_C);
                delay(T);
//                SERIAL.print(", i+3="); SERIAL.print(i+3);
                if( (i+3) >= FIRST_LED &&  (i+3) <= LAST_LED  )  pwmWrite(boardPWMPins[(i+3)],POWER_D);
                delay(T);      
 //               SERIAL.print(", i+4="); SERIAL.print(i+4);          
                if( (i+4) >= FIRST_LED &&  (i+4) <= LAST_LED  )  pwmWrite(boardPWMPins[(i+4)],POWER_OFF);
                delay(T);
 //               SERIAL.println();
               }//end of sweep from last to first   
      }//end of number of loops 
// SERIAL.println("leaving knightridersequence2");          
 z_all_off();
 }//----------------------------------------    end of knightrider2() ------------------------------


