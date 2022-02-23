/*
 * sim800l.c
 *
 *  Created on: Feb 17, 2022
 *      Author: abdelazim
 */

#include "sim800l.h"

uint8_t recv;

void Initialize_SIM900(void)
{
		/*
        * Check if the SIM900 communication is successful
        *wait until the GSM send back "OK"
        */
		while (!SIM900_isStarted());

		/*
         *Check if the SIM card is detected
         *wait till the GSM to send back "+CPIN: READY"
         */
       while (!SIM900_isReady());
}


/*********************************************************************
 * @fn      		  - SIM900_putch
 *
 * @brief             - Function to send one byte of date to UART
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void SIM900_putch(char data)
{
	Uart_SendByte(USART1,(uint8_t)data);
}

/*********************************************************************
 * @fn      		  - SIM900_getch
 *
 * @brief             - Function to get one byte
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
char SIM900_getch()
{
	Uart_ReceiveByte(USART1,&recv);
	(char)recv;
	return recv;
}

/*********************************************************************
 * @fn      		  - SIM900_send_string
 *
 * @brief             -  to send string
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void SIM900_send_string(char *str)
	{
		Uart_SendString(USART1,(uint8_t *)str);
	}

/*********************************************************************
 * @fn      		  - SIM900_print
 *
 * @brief             -function to send any AT command
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  Here we are placing a call to number xxxxxxx,“ATDxxxxx\r\n",
 *                            your command should be followed with “\r\n”

 */

void SIM900_print(unsigned const char *ptr) {
    while (*ptr != 0) {
        SIM900_putch(*ptr++);
    }
}

/*********************************************************************
 * @fn      		  - SIM900_isStarted
 *
 * @brief             - will send “AT” to the GSM and waits for response “OK” from  it

 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  it will return 1 or 0;
 *
 * @Note              -  none

 */

uint8_t SIM900_isStarted(void) {
    SIM900_print("AT\r\n");
    return (SIM900_waitResponse() == SIM900_OK);
}


/*********************************************************************
 * @fn      		  - SIM900_isReady
 *
 * @brief             -will send “AT+CPIN?” to the GSM and waits for response “+CPIN: READY”
		from  i
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   it will return 1 or 0
 *
 * @Note              -  we check if the SIM card can be detected
 *

 */
uint8_t SIM900_isReady(void) {
    SIM900_print("AT+CPIN?\r\n");
    return (SIM900_waitResponse() == SIM900_READY);
}


/*********************************************************************
 * @fn      		  - SIM900_waitResponse
 *
 * @brief             - Check the GSM module Response
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   SIM900_OK,IM900_RIG
 *
 * @Note              -

 */
unsigned char SIM900_waitResponse(void) {
	unsigned char so_far[6] = {0,0,0,0,0,0};
	    unsigned const char lengths[6] = {2,12,5,4,6,6};
	    unsigned const char* strings[6] = {"OK", "+CPIN: READY", "ERROR", "RING", "NO CARRIER", "Unlink"};
	    unsigned const char responses[6] = {SIM900_OK, SIM900_READY, SIM900_FAIL, SIM900_RING, SIM900_NC, SIM900_UNLINK};
	    unsigned char received;
	    unsigned char response;
	    char continue_loop = 1;
	    while (continue_loop) {
	        received = SIM900_getch();
	        for (unsigned char i = 0; i < 6; i++) {
	            if (strings[i][so_far[i]] == received) {
	                so_far[i]++;
	                if (so_far[i] == lengths[i]) {
	                    response = responses[i];
	                    continue_loop = 0;
	                }
	            } else {
	                so_far[i] = 0;
	            }
	        }
	    }
	    return response;
}






























