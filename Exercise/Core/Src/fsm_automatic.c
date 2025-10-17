/*
 * fsm_automatic.c
 *
 *  Created on: Oct 16, 2025
 *      Author: Admin
 */
#include "fsm_automatic.h"

int mode = 1;

void fsm_automatic_mode()
{
	switch (mode)
	{
		case NORMAL:
			light_traffic_run();
			break;
		case MODIFY_RED:
			set_led(mode); // cho led nhap nhay 2hz
			display1(mode); // hien thi che do
			display2(t_red); // hien thi thoi gian dang dieu chinh
			break;
		case MODIFY_YELLOW:
			set_led(mode);
			display1(mode);
			display2(t_yellow);
			break;
		case MODIFY_GREEN:
			set_led(mode);
			display1(mode);
			display2(t_green);
			break;
		default:
			break;
	}
}

void fsm_automatic_run()
{
	fsm_automatic_mode();
	if (isButton1Pressed())
	{
		mode = (mode % 4) + 1;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|
				GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, SET);
		set_timer_default();
		clear_buttonPressed();
	}
	if (mode != 1)
	{
		if (isButton2Pressed()) set_timer_led(mode);
	}
	if (isButton3Pressed())
	{
		Confirm_action();
	}
}

