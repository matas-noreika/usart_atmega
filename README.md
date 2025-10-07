# usart_atmega
usart library for the atmega328p for embedded systems programming using C and avr-gcc

## usart_config_t
Struct that hold the desired usart configuration data.
| data member name | description |
|------------------|-------------|
|baudRate| the desired baudrate of the usart communication|
|usartMode|the desired mode of communication async or sync|
## usart_init()
