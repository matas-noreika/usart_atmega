/*
 * Programmer: Matas Noreika 2025-10-06 17:44 
 * Purpose: Hello world example to show how to send a hello world string over the usart
*/

#include "usart.h"
#include <util/delay.h>

void main(void){
  
  usart_config_t configData;
  configData.frameSize = 8;
  configData.usartMode = USART_MODE_ASYNC;
  configData.baudRate = 9600;
  configData.stopBits = USART_STOP_BIT_1;
  configData.parityMode = USART_PARITY_OFF;
  
  //manually set the transmit speed to double
  UCSR0A |= (1<<U2X0);

  usart_init(&configData);

  while (1){
    usart_sendString("Hello world\n");
    _delay_ms(250);
  }
}
