#include "thermal1.h"
#include "thermal2.h"
#include "thermal3.h"
#include "thermal4.h"

int main(void)
{
    uint16_t temp;
    
    while(1)
    {
        if(thermal1_LED()==1) //Check if both the switches are pressed
        {
           
            TurnLED_ON();//Turn LED ON
            temp=thermal2_GetADC(); //Get the ADC value
            thermal3_PWM(temp); //PWM output based on temperature
		    thermal4_USARTWrite(temp); //To Serial monitor to print Temperature
            

        }
        else  //in all other cases
        {
            TurnLED_OFF();//Turn LED OFF
		    _delay_ms(200);
        }

    }
    return 0;
}
