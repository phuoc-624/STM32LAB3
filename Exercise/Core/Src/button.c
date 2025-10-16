#include "button.h"
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int button1 = NORMAL_STATE;
int button2 = NORMAL_STATE;
int button3 = NORMAL_STATE;

int TimeOutForKeyPress =  500;
int button1_pressed = 0;
int button1_long_pressed = 0;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button1_flag = 1;
}

void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  // Add your key
  button1 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  button2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
  button3 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
  KeyReg0 = button1 && button2 && button3;
  //KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        //subKeyProcess();
        if (button1 == PRESSED_STATE) button1_flag = 1;
        else if (button2 == PRESSED_STATE) button2_flag = 1;
        else if (button3 == PRESSED_STATE) button3_flag = 1;
      }

    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
        	if (KeyReg3 == PRESSED_STATE){
        		//subKeyProcess();
        		if (button1 == PRESSED_STATE) button1_flag = 1;
        		else if (button2 == PRESSED_STATE) button2_flag = 1;
                else if (button3 == PRESSED_STATE) button3_flag = 1;
        	}
        }
    }
  }
}

