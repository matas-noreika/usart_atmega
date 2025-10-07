/*
 * Programmer: Matas Noreika 2025-10-05 16:34 
 * Purpose: implementation of usart library
*/

#include "usart.h"

//function to calculate target baudrate from cpu clock speed and target baudrate
uint8_t usart_calc_baud(uint16_t baudrate){
  double baudValue;
  //check if the double transmission speed flag is set
  if (UCSR0A & (1<<U2X0)){
    baudValue = (F_CPU/(8.00*baudrate)) - 1;
  }else{
    baudValue = (F_CPU/(16.00*baudrate)) - 1;
  }
  
  //return the rounded value
  return round(baudValue);
}

//init function for usart
void usart_init(usart_config_ptr configData){
  //set the correct baudrate
  UBRR0 = usart_calc_baud(configData->baudRate);
  //set the usart transmission mode
  UCSR0C |= configData->usartMode;
  //set the parity mode
  UCSR0C |= configData->parityMode;
  //set number of stop bits
  UCSR0C |= configData->stopBits;
  //usart frame size switch case 
  switch (configData->frameSize){
    case 6:
      UCSR0C |= (1<<UCSZ00);
      break;
    case 7:
      UCSR0C |= (1<<UCSZ01);
      break;
    case 8:
      UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
      break;
    case 9:
      UCSR0B |= (1<<UCSZ02); 
      UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
      break;
    default:
      break;
  }
  //enable reciever & tramsmitter
  UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
}

//function to send a single character using the usart
void usart_sendChar(char c){
  while ((UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
	UDR0 = c;
}

//function to send a string using the usart
void usart_sendString(char* string){
  uint8_t i = 0;
  
  while(string[i] != '\0'){
    usart_sendChar(string[i++]);
  }
}

