# LED-Light-bar-sequencer
STM32 controls 12 10w LEDs, running several sequenses as well as one that is like Knight Rider.
This is sort of a work in progress.  I say that because I have a bug that I have found a work around for, but want to figure out what going wrong.
The problem: When using the pwmWrite() statement, some of the PWM pins (as defined in the board.cpp file for the stm32f103c8t6) don't seem to operate the way that they 
