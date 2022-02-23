/*
 * sim800l.h
 *
 *  Created on: Feb 16, 2022
 *      Author: abdelazim
 */

#ifndef INC_SIM800L_H_
#define INC_SIM800L_H_

#include "stm32f10x.h"
#include "uart.h"

//the GSM module Response macros
#define SIM900_OK 1
#define SIM900_READY 2
#define SIM900_FAIL 3
#define SIM900_RING 4
#define SIM900_NC 5
#define SIM900_UNLINK 6

//read and write information from/to our GSM module
void Initialize_SIM900(void);
void SIM900_putch(char data);			//USART1 for now: must be updated
char SIM900_getch();
void SIM900_send_string(char *str);
void SIM900_print(unsigned const char *ptr);
uint8_t SIM900_isStarted(void);
uint8_t SIM900_isReady(void);
unsigned char SIM900_waitResponse(void);


#endif /* INC_SIM800L_H_ */
