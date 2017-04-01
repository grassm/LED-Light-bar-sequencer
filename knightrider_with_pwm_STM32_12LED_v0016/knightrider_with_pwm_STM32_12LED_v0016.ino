/* LIGHT BAR CONTROLLER     STM32F103C  BLUE PILL 
 *  see tab  A_NOTES!
 */
//I prefer using the ST-LINK for uploading the program to the Blue Pill, because it doesn't use the two PWM pin A9 and A10.
//and you don't have to keep changing the programming shunt for Boot0 to change the mode

//To use serial monitor the print commands need to be "Serial1.print( );". If using the USB to serial, then you need to use 
// "Serial.print();" for the serial monitor. It does mess up the PWM use of A9 and A10, while you are debugging

//if using ST-LINK uncomment the next line and the USB to serial module for serial monitor
#define ST-LINK-NOT_USB2SERIAL

//? If using PRINT_INFO for debugging, remember to switch IDE Tools> Port to the USB2Serial com port after programming
//? You have to switch it back to the ST-LINK com port to upload the program.
//#define PRINT_INFO

//takes care of which USART I'm using for serial debugging when using ST-LINK vs USB2SERIAL
#ifdef ST-LINK-NOT_USB2SERIAL
    #define SERIAL    Serial1
        #else    SERIAL    Serial
#endif

//#define  BETTER_WIRING_LAYOUT // was using my own array for accessing the PWM pins and had some problems with that.
#define FIRST_LED                  0  // so 12 LED channels
#define CENTER_LEFT_LED     5
#define CENTER_RIGHT_LED  6
#define LAST_LED                 11
#define OUTPUT_HIGH            1  //I defined _HIGH and _LOW so if I need to reverse the logic, I can do it by reversing the value
#define OUTPUT_LOW             0  //   of these two #defines

//These next defines set the values that I use for the trailing/fading LEDs in the Knight Rider sequence
#define MAX_LEVEL  65535
#define POWER_A   MAX_LEVEL
#define POWER_B       49087
#define POWER_C       32898
#define POWER_D       16448
#define POWER_OFF          0
int inDex=0;   //yes I know that index is not two words; so don't ask why inDex!
/* This comment block is just info left over from the original code and will be removed later
//SILKSCREEN ON BLUE PILL FOR PINS
//The first array better for wiring/pc layout.  This second array lists the PWM outputs in numerical order. 
#ifdef BETTER_WIRING_LAYOUT
//THIS PIN CONFIGURATION GIVES A BETTER LAYOUT OF THE WIRING
//                        A8,  A11,  B1,  B0,   A7,   A6,   A3,  A2,  A1, A0,   B6,  B7
int ledPin[] =   {     8,    11,  17,  16,      7,     6,     3,     2,    1,   0,   22,   23,  4, 4,4,4,4  }; //organize all PWM pins best layout order.

#else
//                        A0,  A1, A2, A3,  A6, A7, A8,  A11, B0, B1,   B6,  B7
int ledPin[] =   {     0,    1,    2,   3,    6,   7,   8,    11,  16, 17,   22,  23, 4, 4, 4, 4}; //organize all PWM pins in numerical order.

#endif
* using the board defined pwm pin array the sequence is 
* 16    7    6    3    2     1    0    23  22   10     9     8
* B0  A7  A6  A3  A2  A1  A0   B7  B6  A10  A9   A8
*/

void setup() { 
#ifdef PRINT_INFO   
       SERIAL.begin(57600); 
       SERIAL.println("starting");  
#endif
//this just flashes the board LED for about 1 second. 
//it just shows that the program is running and also a delay before the 12 sequence LEDs are turned on.
//The delay is required because the 30v power supply needs to come on and stabilize before the LEDs are used.
//I let some magic smoke out!
  pinMode(PC13,OUTPUT);
  for (int cntr=0; cntr<=20; cntr++)
       {
       digitalWrite(PC13,1);
       delay(50);
       digitalWrite(PC13,0);
       delay(50);
       }
//analogWrite() takes care of configuring the PWM pins for you automatically. You have to intiallize them yourself
//if using pwmWrite()       
//Configure the  PWM pins  for pwmWrite statements
for (inDex =FIRST_LED; inDex<= LAST_LED; inDex++) 
       {
       pinMode(inDex, PWM );
#ifdef PRINT_INFO       
       SERIAL.println( boardPWMPins[inDex] );
#endif       
       }
//This is the work around for my bug.        
//I have found out that if I don't address each of the pwm pins as analogWrite at least once, certain pwm pins
//do not respond properly.  8bit PWM resolution is really all I need for this and may go back to just analogWrite()    
for (inDex =FIRST_LED; inDex<= LAST_LED; inDex++) 
       {
       analogWrite(boardPWMPins[inDex],255);  //255 is the max count for  analogWrite 100% DC 
       delay(10);//I don't remember why I put this delay here. It may not be needed
       analogWrite(boardPWMPins[inDex],0);   //set the DC to 0%
       }

z_all_off();    //this call just makes sure all of the pwm pins are set to 0 duty cycle     
}////---------------- end of setup() ------------


//++++++++++++++++++++++++++++ loop() ++++++++++++
void loop(){
//Now call the LED sequence functions in the order that you want. 
//dianostic1(); 
//diagnostic2();  //this is a sequencial slow fade of all the PWM pins 
knightridersequence2(); 
sequence_a();
sequence_g();
sequence_f(); 
knightridersequence2(); 
sequence_b();
sequence_f();  
sequence_c();
knightridersequence2(); 
sequence_d();
sequence_e();
sequence_f();    
}//---------------------------------------end of main loop

