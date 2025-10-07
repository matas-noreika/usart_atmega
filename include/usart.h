/*
 * Programmer: Matas Noreika 2025-10-05 16:14
 * Purpose: usart library for simplifying development on atmega328p and similar microcontrollers 
*/

//Header guard
#ifndef __USART_H__
#define __USART_H__

#include <avr/io.h> //avr library for register macros
#include <math.h>//libc math header -> round()
#define F_CPU 1000000UL //change to your cpu frequency

//Macro definitions for usart modes
#define USART_MODE_ASYNC 0x00 // -> 0000 0000 (UCSRnC)
#define USART_MODE_SYNC 0x40 // ->  0100 0000 (UCSRnC)

//Macro definitions for stop bit configurations
#define USART_STOP_BIT_1 0x00 // -> 0000 0000 (UCSRnC)
#define USART_STOP_BIT_2 0x08 // -> 0000 1000 (UCSRnC)

//Macros definitions for parity configurations
#define USART_PARITY_OFF 0x00 // -> 0000 0000 (UCSRnC)
#define USART_PARITY_EVEN 0x20 // -> 0010 0000 (UCSRnC)
#define USART_PARITY_ODD 0x30 // -> 0010 0000 (UCSRnC)

//definition of usart_config_t
typedef struct usart_config_t {
  uint16_t baudRate; //baud rate variable
  uint8_t usartMode; //switches between async and sync mode for transmission optional for spi master
  uint8_t frameSize; //frame size definition
  uint8_t stopBits; //the number of stop bits
  uint8_t parityMode; //sets odd, even or disabled parity
}usart_config_t;

//definition of usart_config_ptr
typedef usart_config_t *usart_config_ptr;

//function to calculate target baudrate from cpu clock speed and target baudrate
uint8_t usart_calc_baud(uint16_t);

//init function for usart
void usart_init(usart_config_ptr);

//function to send a single character using the usart
void usart_sendChar(char);

//function to send a string using the usart
void usart_sendString(char*);

#endif
