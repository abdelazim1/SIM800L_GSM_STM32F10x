/*
 * uart.c
 *
 *  Created on: Feb 16, 2022
 *      Author: abdelazim
 */

#include "uart.h"

/* UART2 */
void Uart_Init(USART_TypeDef* uart, uint32_t baudrate)
{
	uint8_t frac;
	uint16_t integ;
	float UARTDIV;

	if(uart == USART1){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

		// PA 9,10
		GPIOA->CRH	&= ~(3<<(2*2)); ///////////must be updated, MODE9
		GPIOA->CRH	&= ~(3<<(3*2));		//CNF9
		GPIOA->CRH  &=~(3<<(4*2));		//MODE10
		GPIOA->CRH  &= ~(3<<(5*2));		//CNF10


		GPIOA->CRH	|= (2<<(2*2));
		GPIOA->CRH	|= (3<<(3*2));
		GPIOA->CRH  |=(2<<(4*2));
		GPIOA->CRH  |=(3<<(5*2));

		AFIO->MAPR	&= ~AFIO_MAPR_USART1_REMAP;
		RCC->APB2ENR	|= RCC_APB2ENR_USART1EN;

	}


	UARTDIV			= (SystemCoreClock/(16.0*baudrate));
	integ			= (uint16_t)UARTDIV;
	frac			= (UARTDIV-integ)*16;
	uart->BRR		=(integ<<4)+frac;

	uart->CR1		|=((USART_CR1_TE)|(USART_CR1_RE)|(USART_CR1_UE));

}
void Uart_SendByte(USART_TypeDef* uart, uint8_t data

	while(!(uart->SR &USART_SR_TXE));
	uart->DR 		= data;
}
void Uart_SendString(USART_TypeDef* uart, uint8_t* str)
{
	uint32_t i = 0;
	while(str[i])
	{
		Uart_SendByte(uart,str[i]);
		i++;
	}
}


void Uart_ReceiveByte(USART_TypeDef* uart, uint8_t* pData)
{
	while(!(uart->SR &USART_SR_RXNE));
	(*pData)	=	uart->DR;
}




