#include "output_display.h"
// buffer to display 7 seg, can be count by time of traffic light
int buffer_7SEG[4] = {1,3,1,0};
//id to scan 7 seg led
int id = 0;
int flag_to_off = 0;
// function to turn off and on 7 segments
void off7SEG(void){
	flag_to_off = 1;
	HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, SET);
}
void on7SEG(void){
	flag_to_off = 0;
}
//function to display 7 segment
void display7SEG(int num){
	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG7_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG7_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG7_G_Pin, RESET);
		break;
	}
}
// update buffer to display after countdown
void update7SegBuffer(int time1, int time2){
	buffer_7SEG[0] = time1/10;
	buffer_7SEG[1] = time1%10;
	buffer_7SEG[2] = time2/10;
	buffer_7SEG[3] = time2%10;
}
// function to display traffic light with id of each traffic ways
void displayTrafficLight (int id, int red, int green, int yellow){
	if(id == 0){
		HAL_GPIO_WritePin(GPIOA, RED1_Pin, (1-red));
		HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, (1-green));
		HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, (1-yellow));
	}else if(id == 1){
		HAL_GPIO_WritePin(GPIOA, RED2_Pin, (1-red));
		HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, (1-green));
		HAL_GPIO_WritePin(GPIOA, YELLOW2_Pin, (1-yellow));
	}
}
// funtion to scan 4 7 segments leds
void scan7Seg(void){
	if(flag_to_off) return;
	if(id == 0){
	  HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, 0);
	  HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, 1);
  }else if(id == 1){
	  HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, 0);
	  HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, 1);
  }else if(id == 2){
	  HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, 0);
	  HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, 1);
  }else if(id == 3){
	  HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, 1);
	  HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, 0);
  }
  display7SEG(buffer_7SEG[id]);
  id++;
  id = id % 4;
}
