#C compiler
CC= avr-gcc
#Target microcontroller
MMCU= atmega328p
#C compiler flags
CCFLAGS= -O2 -mmcu=$(MMCU) -I../include

#local directories
LOCALBIN=../bin
LOCALOBJ=../obj
LOCALDEP=../dep

#retrieve all source files
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=$(LOCALOBJ)/%.o)
DEPS=$(SRCS:%.c=%.d)

#declare all and clean
.PHONY: all clean

#retain all object files generated
.PRECIOUS: $(LOCALOBJ)/%.o

all: $(OBJS)

clean:
	@echo "Running clean"
	-@rm -f $(LOCALBIN)/*.exe 2> /dev/null
	-@rm -f $(LOCALOBJ)/*.o 2> /dev/null
	-@rm -f $(LOCALDEP)/*.d 2> /dev/null

#include .d file rules
-include $(DEPS)

#static pattern rule to generate object files
$(LOCALOBJ)/%.o: %.c
	$(CC) $(CCFLAGS) -c -MMD $< -o $@
	mv $(LOCALOBJ)/$(*F).d $(LOCALDEP)/$(*F).d

