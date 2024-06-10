

#include "lm35_sensor.h"
#include"LCD.h"
#include "ADC.h"
#include "DcMotor.h"



int main(void)
{
	ADC_ConfigType ADC_Configurations = {Vint,F_CPU_8};

	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configurations); /* initialize ADC driver */
	DcMotor_Init();


	LCD_displayString("Fan is ");
	/* Display this string "ADC Value = " only once on LCD at the second row */
	LCD_moveCursor(1,0);
	LCD_displayString("  Temp = ");

	while(1)
	{
		LCD_moveCursor(1,10);

		temp=LM35_getTemperature();

		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayString("  ");
		}
		LCD_moveCursor(0,7);
		if(temp >= 120)
		{
			LCD_displayString("On");
			LCD_displayString(" ->100%");
			DcMotor_Rotate(CW,Fourth_Speed);
		}
		else if(temp >= 90)
		{
			LCD_displayString("On");
			LCD_displayString(" -> 75%");
			DcMotor_Rotate(CW,Third_Speed);
		}
		else if(temp >= 60)
		{
			LCD_displayString("On");
			LCD_displayString(" -> 50%");
			DcMotor_Rotate(CW,Second_Speed);
		}
		else if(temp >= 30)
		{
			LCD_displayString("On");
			LCD_displayString(" -> 25%");
			DcMotor_Rotate(CW,First_Speed);
		}
		else
		{
			LCD_displayString("OFF");
			LCD_displayString("  -> 0% ");
			DcMotor_Rotate(Stop,No_Speed);
		}

	}

}




