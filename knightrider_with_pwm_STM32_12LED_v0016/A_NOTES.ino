/* Note: single question marks "? " followed by at least one space just indicate a note that I need to remember.
 *           Two question marks followed by a space "?? " indicate something I changed for testing and need to be changed
 *            after testing.
 * This code works on the STM32 BLUE PILL
 * The one that has the reset button and two programming shunts that set Boot0 and Boot1
 *I'm using the stm32 pmwWrite(pinname, value)
 * The pinMode( pin,PWM) and pwmWrite(pin,value) has a 16bit resolution resolution 65535.
 * There are 12 PWM outputs on the STM32F103  (there are actually at least two more but not covered in the 
 *     boardPWMPin[] array.  Not sure why.
 * All 12 of them are used to drive the Knightrider LEDs
 * The STM32 outputs go to a FAN3214 chip(dual non-inverting  gate driver).\
 * The FAN3214 outputs drive IRF1405 MOSFETS N,55v,75A pkg limit, .0053 ohms or similar.
 * I use the FAN3214, because the 3.3v output to my logic level MOSFETS didn't give me the lowest Vds.
 * 
 * 10w Green LED  Vf=15 gives about  2 Amps.  17v gives about 3 Amps
 * I'm only pulsing the LEDs at 2-3 amps.   2 LEDs are in series and the anode is connected to 30v. So 15v /LED
 * 2 amps at 15v=30w, 16v at 2.5amp = 40w,  17v at 3amps = 51w 
 * If the LED string is going to be on steady state, I need to keep the duty cycle at about 20%
 *  20% of 51w is 10.2w
 * 
 * If   PRINT_INFO is defined and using the Serial monitor for debugging, the pins A9 and A10 (pwm pins) 
 * are also used for the serial communication.  This causes the signal to the LEDs that are on A9 and A10 to 
 * work incorrectly and one of the two is almost always on.  
 * 
 * The initial code wasn't being saved to flash; I'm still not sure why, but it had something to do with not 
 * accessing the PWM pins via boardPWMPin[ ] array.   Further more, if I have not used the statement analogWrite( pin, value), 
 * at least once for each of the pwm pins, some of the pins do not operate properly. Not sure why.
 * 
 * I'm driving the LEDs at about 2x their rated power with out a current limiting resistor in series with each LED.
 * Therefore, I can not turn them on at 100%DC and leave them on very long.  Well I could be it would really shorten their life! 
 * If they are going to be on for more than about 1 or 2 seconds, make sure the power level/Duty Cycle is about 50% 
 * Wiring to the 10w LEDs.   The max current that is less than 3amps.  20 awg wire has a resistance of  .010 ohms/ft. 
 * If the wire is 4' long, R is .04 ohm, and at 3 amps, the voltage drop across the wire is 0.12 volts. 
 * So the wire does partially act as a current limiting resistor.  Four feet of  22 awg would have a voltage drop of approx.
 * .2volts.  I'm using  24 Green 10w LEDs, in 12 groups of 2 in series. Using 30V as B+ gives somewhere between 2 and 3 amps. 
 * Each series string of 2 is used as 1 on the front of the light bar and 1 directly behind it. The 
 * 
 */
