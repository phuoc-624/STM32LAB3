/*
 * global.c
 *
 *  Created on: Oct 16, 2025
 *      Author: Admin
 */
#include "global.h"

int led_buffer1[2] = {1, 2};
int led_buffer2[2] = {3, 4};

int timer_red = 15;
int timer_yellow = 5;
int timer_green = 10;

int t_red = 15;
int t_yellow = 5;
int t_green = 10;

int index_led1 = 0;
int index_led2 = 2;

int flag_red = 0;
int flag_yellow = 0;
int flag_green = 0;

int isCross = 1;

void display2(int num)
{
	updateClockBuffer2(num);
	if (timer4_flag == 1)
	{
		update7SEG(index_led2);
		index_led2++;
		if (index_led2 > 3) index_led2 = 2;
		setTimer4(50);
	}
}

void display1(int num)// hien thi mode
{
	updateClockBuffer1(num);
	if (timer3_flag == 1)
	{
		update7SEG(index_led1);
		index_led1 = (index_led1 + 1) % 2;
		setTimer3(50);
	}
}
void updateClockBuffer1(int num)
{
	led_buffer1[0] = num / 10;
	led_buffer1[1] = num % 10;
}

void updateClockBuffer2(int num)
{
	led_buffer2[0] = num / 10;
	led_buffer2[1] = num % 10;
}

void checktimer()
{
	if (flag_red == 0) t_red = timer_red;
	if (flag_yellow == 0) t_yellow = timer_yellow;
	if (flag_green == 0) t_green = timer_green;
	if (flag_red == 1 || flag_yellow == 1 || flag_green == 1)
	{
		if (t_red == (t_yellow + t_green))
		{
			timer_red = t_red;
			timer_yellow = t_yellow;
			timer_green = t_green;
		}
		flag_red = 0;
		flag_yellow = 0;
		flag_green = 0;
	}
}
void set_timer_default(int mode)
{
	switch (mode)
	{
		case NORMAL:
			checktimer();
			t_red = timer_red;
			t_yellow = timer_yellow;
			t_green = timer_green;
			break;
		case MODIFY_RED:
			t_red = timer_red;
			break;
		case MODIFY_YELLOW:
			t_yellow = timer_yellow;
			break;
		case MODIFY_GREEN:
			t_green = timer_green;
			break;
		default:
			break;
	}
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

void set_led(int mode)// nhap nhay led
{
	if (timer2_flag == 1)
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
		setTimer2(250);
	}
}
void light_traffic_run()
{
	if (timer1_flag == 1)
	{
		if (isCross == 1)
			  {
				  if (t_red > 0)
				  {
					  updateClockBuffer2(t_red);
					  if (t_red > timer_yellow)
					  {
						  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);

						  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
						  updateClockBuffer1(t_green);
						  t_green -= 1;
					  }
					  else if (t_red <= timer_yellow && t_red >= 1)
					  {
						  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);

						  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
						  updateClockBuffer1(t_yellow);
						  t_yellow -= 1;
					  }
					  t_red -= 1;
				  }
				  if (t_yellow == 0) t_yellow = timer_yellow;
				  if (t_green == 0) t_green = timer_green;
				  if (t_red == 0)
				  {
					  t_red = timer_red;
					  isCross = 2;
				  }
			  }
			  else
			  {
				  if (t_red > 0)
				  {
					  updateClockBuffer1(t_red);
					  if (t_red > timer_yellow)
					  {
						  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
				  		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);

						  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
						  updateClockBuffer2(t_green);
						  t_green -= 1;
					  }
					  else if (t_red <= timer_yellow && t_red >= 1)
					  {
						  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
				  		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);

						  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
				  		  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
						  updateClockBuffer2(t_yellow);
						  t_yellow -= 1;
					  }
					  t_red -= 1;
				  }
				  if (t_yellow == 0) t_yellow = timer_yellow;
				  if (t_green == 0) t_green = timer_green;
				  if (t_red == 0)
				  {
					  t_red = timer_red;
				  	  isCross = 1;
				  }
			  }
			  setTimer1(400);
	}
	if (timer5_flag == 1)
	{
		update7SEG(index_led1);
		index_led1 = (index_led1 + 1) % 2;

		update7SEG(index_led2);
		index_led2++;
		if (index_led2 > 3) index_led2 = 2;
		setTimer5(50);
	}
}

void Confirm_action(int mode)
{
	switch (mode)
	{
		case MODIFY_RED:
			flag_red = 1;
			break;
		case MODIFY_YELLOW:
			flag_yellow = 1;
			break;
		case MODIFY_GREEN:
			flag_green = 1;
			break;
		default:
			break;
	}
	//timer_red = t_red;
	//timer_yellow = t_yellow;
	//timer_green = t_green;
}

void update7SEG(int index)
{
	switch (index)
	{
		case 0:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer1[0], GPIO_PIN_0);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer1[1], GPIO_PIN_0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer2[0], GPIO_PIN_7);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer2[1], GPIO_PIN_7);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void display7SEG(int num, uint32_t GPIO_Pin)
{
	if(num < 0 || num > 9) return;
	char segNumber[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	for (int i = 0; i < 7; i++)
	HAL_GPIO_WritePin(GPIOB, GPIO_Pin << i, (segNumber[num] >> i) & 1);
}
