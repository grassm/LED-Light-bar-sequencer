/*
 * this turns all of the LEDs off
 */

void z_all_off()
{
  for(int index = 0; index <= 11; index++)
         {
          pwmWrite(boardPWMPins[index],POWER_OFF); //turn them on 
         }
  
}
