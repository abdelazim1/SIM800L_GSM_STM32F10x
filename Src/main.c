/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "sim800l.h"

int main(void)
{
	Uart_Init(USART1, 9600);
    Initialize_SIM900();

     /*
      * Place a Phone Call
      * place a call to number 93643XXXXX
      */
     do
    {
    SIM900_print("ATD01112331539;\r\n");
    }while (SIM900_waitResponse() != SIM900_OK); //wait until ... "OK"

}
