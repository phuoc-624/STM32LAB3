/*
 * global.c
 *
 *  Created on: Oct 16, 2025
 *      Author: Admin
 */
#include "global.h"

int led_buffer1[2] = {1, 2};
int led_buffer2[2] = {3, 4};

int timer_red = 35;
int timer_yellow = 5;
int timer_green = 30;

int t_red = 35;
int t_yellow = 5;
int t_green = 30;


void updateClockBuffer1(int time)
{
	led_buffer1[0] = time / 10;
	led_buffer1[1] = time % 10;
}

void updateClockBuffer2(int time)
{
	led_buffer2[0] = time / 10;
	led_buffer2[1] = time % 10;
}
void set_timer_default()
{
	t_red = timer_red;
	t_yellow = timer_yellow;
	t_green = timer_yellow;
}

void set_timer_led(int mode)
{
	switch (mode)
	{
		case MODIFY_RED:
			t_red = (t_red % 99) + 1;
			break;
		case MODIFY_YELLOW:
			t_yellow = (t_yellow % 99) + 1;
			break;
		case MODIFY_GREEN:
			t_green = (t_green % 99) + 1;
			break;
		default:
			break;
	}
}

void set_led(int mode)
{
	if (timer4_flag == 1)
	{
		switch (mode)
		{
			case MODIFY_RED:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5|GPIO_PIN_8);
				break;
			case MODIFY_YELLOW:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6|GPIO_PIN_9);
				break;
			case MODIFY_GREEN:
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7|GPIO_PIN_10);
				break;
			default:
				break;
		}
	}
	setTimer4(2000);
}
void light_traffic_run()
{
	if (timer1_flag == 1)
	{

	}
}

void Confirm_action()
{
	timer_red = t_red;
	timer_yellow = t_yellow;
	timer_green = t_green;
}

/*void update7SEG(int index)
{
	switch (index)
	{
		case 0:
			HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
			display7SEG(led_buffer[0]);
			HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
			break;
		case 1:
			HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
			display7SEG(led_buffer[1]);
			HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
			break;
		case 2:
			HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
			display7SEG(led_buffer[2]);
			HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
			break;
		case 3:
			HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
			display7SEG(led_buffer[3]);
			HAL_GPIO_TogglePin(EN3_GPIO_Port, EN3_Pin);
			break;
		default:
			break;
	}
}*/

void display7SEG(int num, uint32_t GPIO_Pin)
{
	if(num < 0 || num > 9) return;
	char segNumber[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	for (int i = 0; i < 7; i++)
	HAL_GPIO_WritePin(GPIOB, GPIO_Pin << i, (segNumber[num] >> i) & 1);
}
