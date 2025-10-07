# usart_atmega
usart library for the atmega328p for embedded systems programming using embedded C and avr-gcc
# makefile Suggestions
A possible way of including this library to projects are to git clone the repository to a libs directory in the project directory. Then you can either generate a shell script to iterate through all project folders to call make or make a explicit rule in your project makefile.
`make -C other_makefile_dir`
the command above will rule make in the provided directory.
# Disclaimer
Currently the library requires the manual definition of F_CPU macro in usart.h. This macro is also used by the avr-libc for functions like _delay_ms()
# Macro definitions
## usart modes
The following are the available modes to set baudRate data member in usart_config_t
`USART_MODE_ASYNC`
Asynchronous communication (UART)
`USART_MODE_SYNC`
Asynchronous communication (USRT)
## stop bit options
`USART_STOP_BIT_1`
Sets the frame to use 1 stop bit
`USART_STOP_BIT_2`
Sets the frame to use 2 stop bits
## parity modes
`USART_PARITY_OFF`
Disables parity checking on frame transmission
`USART_PARITY_EVEN`
Sets parity on and enables even parity
`USART_PARITY_ODD`
Sets parity on and enables odd parity
# Data types
`usart_config_t`
Struct that hold the desired usart configuration data.
|data member name|description|
|------------------|-------------|
|baudRate| the desired baudrate of the usart communication|
|usartMode|the desired mode of communication async or sync (refer to [usart modes](#usart-modes) for macro options)|
|frameSize|the number of bits per frame transmission (accepts values where 5 <= frameSize <= 9 as uint8_t)|
|stopBits|the number of stopBits per frame transmission (refer to [stop bit options](#stop-bit-options) for macro options)|
|parityMode|enable/disable parity for usart transmission (refer to [parity modes](#parity-modes) for macro options)|
`usart_config_ptr`
pointer to usart_config_t
# Functions
`uint8_t usart_calc_baud(uint16_t baudrate)`
Function that calculates the UDDRn value required to achieve desired baudrate. (**Disclaimer currently requires manual setting of U2Xn**)
`void usart_init(usart_config_ptr)`
function that initialises the usart using the usart_config_t data passed
`usart_sendChar(char c)`
Function to send a single character of the usart bus
`usart_sentString(char* string)`
Function to send a string over the usart bus
