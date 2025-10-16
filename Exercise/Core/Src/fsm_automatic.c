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
			//todo
			// den giao thong chay binh thuong
			timer1_flag = 1;
			light_traffic_run();
			timer2_flag = 0;
			break;
		/*case MODIFY_RED:
			//todo
			// set co cho den do
			timer2_flag = 1;
			set_led(mode);
			break;
		case MODIFY_YELLOW:
			//todo
			// set co cho den vang
			timer2_flag = 1;
			set_led(mode);
			break;
		case MODIFY_GREEN:
			//todo
			// set co cho den xanh
			timer2_flag = 1;
			set_led(mode);
			break;*/
		default:
			timer2_flag = 1;
			set_led(mode);
			break;
	}
}

