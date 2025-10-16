/*
 * global.h
 *
 *  Created on: Oct 16, 2025
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define NORMAL			1
#define MODIFY_RED		2
#define MODIFY_YELLOW 	3
#define MODIFY_GREEN	4

extern int timer_red;
extern int timer_yellow;
extern int timer_green;

int t_red;
int t_yellow;
int t_green;

void Confirm_action();
void set_timer_led(int mode);
void set_timer_default();
void light_traffic_run();
void set_led(int mode);
void set_timer_led();
void display7SEG(int num, uint32_t GPIO_Pin);

#endif /* INC_GLOBAL_H_ */
