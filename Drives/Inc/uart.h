/*
 * uart.h
 *
 *  Created on: Feb 16, 2022
 *      Author: abdelazim
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f10x.h"
//#include "timer.h"
#include "delay.h"

/* UART2 */
void Uart_Init(USART_TypeDef* uart, uint32_t baudrate);
void Uart_SendByte(USART_TypeDef* uart, uint8_t data);
void Uart_SendString(USART_TypeDef* uart, uint8_t* str);
void Uart_ReceiveByte(USART_TypeDef* uart, uint8_t* pData);





#endif /* INC_UART_H_ */
