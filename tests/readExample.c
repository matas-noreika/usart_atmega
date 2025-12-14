/*
 * Programmer: Matas Noreika 2025-12-14 16:38
 * Purpose: Read example using the usart library
*/

#include <avr/io.h>
#include "usart_atmega.h"

void main(void){

  usart_config_t usart_config = {
    .usart_num = 0,
    .baudrate = 9600,
    .usart_mode = USART_MODE_ASYNC,
    .frame_size = 8,
    .stop_bits = USART_STOP_BIT_1,
    .parity_mode = USART_PARITY_OFF
  };

  //manually set the transmit speed to double
  UCSR0A |= (1<<U2X0);

  usart_init(&usart_config);

  while(1){//start of program loop

    if(usart_available(0)){
      char c = usart_readChar(0);
      usart_sendChar(0,c);
    }

  }//end of program loop

}
