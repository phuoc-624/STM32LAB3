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

//int time_part1;
//int time_part2:
//int time_part3;

int t_red;
int t_yellow;
int t_green;

void Confirm_action(int mode);
void set_timer_led(int mode);
void set_timer_default(int mode);
void light_traffic_run();
void set_led(int mode);
void set_timer_led();
void display7SEG(int num, uint32_t GPIO_Pin);
void display1(int num);
void updateClockBuffer1(int num);
void updateClockBuffer2(int num);
void update7SEG(int index);
void display2(int num);
void checktimer();

#endif /* INC_GLOBAL_H_ */
