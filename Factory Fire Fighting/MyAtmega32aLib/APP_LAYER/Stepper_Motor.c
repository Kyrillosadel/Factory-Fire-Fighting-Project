#include <util/delay.h>

#define FULL_WAVE_STEPS 8

int main()
{
	unsigned char motor_steps[FULL_WAVE_STEPS] = {9,1,3,2,6,4,12,8};
	unsigned char count = 0;
	DDRA &= ~(1<<PA2); // configure PA2 as input pin
	DDRC |= 0x0F; //configure first 4 pins in PORTC as output pins
	PORTC &= 0xF0; // clear first four bits in PORTC
	while(1)
	{
		
				// move the motor to the next step
				PORTC = (motor_steps[count] & 0x0F) | (PORTC & 0xF0);
				count++;
				if(count == FULL_WAVE_STEPS)
				{
					//start from the beginning after finish the full motor rotation.
					count = 0;
				}
			
			
		
	}
}
