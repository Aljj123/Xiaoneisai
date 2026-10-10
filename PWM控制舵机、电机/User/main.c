#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Motor.h"

uint8_t flag = 0;
float Angle;
int16_t Speed;

int main(void)
{
	OLED_Init();
	Servo_Init();
	Motor_Init();
	OLED_ShowString(1, 1, "Angle:");

	while (1)
	{	
//		if (Angle == 0) { flag = 1 ; }
//		if (Angle == 180) { flag = 0 ; }
//		
//		switch(flag)
//		{
//			case 1 : Angle ++;
//			break;
//			case 0 : Angle --;
//			break;
//		}
//		Servo_SetAngle(Angle);
//		OLED_ShowNum(1, 7, Angle, 5);
		if (Speed <= 0) { flag = 1 ; }
		if (Speed >= 199) { flag = 0 ; }
		
		switch(flag)
		{
			case 1 : Speed ++;
			break;
			case 0 : Speed --;
			break;
		}
		Motor_SetSpeed(Speed);
		OLED_ShowNum(1, 7, Speed, 5);
		Delay_ms(10);
	}
}
