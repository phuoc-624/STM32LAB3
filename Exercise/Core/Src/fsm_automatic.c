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

