CC         = gcc 
XFLAGS     = -W -Wall -Werror -pedantic
INC1       = ./Firmware/HAL
INCDIRS    = -I ${INC1} 
CFLAGS     = ${INCDIRS} ${XFLAGS} 

DecimalToBinary: DecimalToBinary.o Main.o Conversion.o CheckValues.o Memory.o
	gcc -o DecimalToBinary DecimalToBinary.o Main.o Conversion.o CheckValues.o Memory.o


DecimalToBinary.o: ./Firmware/HAL/DecimalToBinary.c ./Firmware/HAL/DecimalToBinary.h ./Firmware/HAL/Conversion.h ./Firmware/HAL/Memory.h ./Firmware/HAL/CheckValues.h
	gcc -o DecimalToBinary.o -c ./Firmware/HAL/DecimalToBinary.c ${CFLAGS}

Main.o: ./Firmware/APP/Main.c ./Firmware/HAL/DecimalToBinary.h
	gcc -o Main.o -c ./Firmware/APP/Main.c ${CFLAGS}

Conversion.o: ./Firmware/HAL/Conversion.c ./Firmware/HAL/DecimalToBinary.h ./Firmware/HAL/Conversion.h ./Firmware/HAL/Memory.h ./Firmware/HAL/CheckValues.h
	gcc -o Conversion.o -c ./Firmware/HAL/Conversion.c ${CFLAGS}

CheckValues.o: ./Firmware/HAL/CheckValues.c ./Firmware/HAL/DecimalToBinary.h ./Firmware/HAL/Conversion.h ./Firmware/HAL/Memory.h ./Firmware/HAL/CheckValues.h
	gcc -o CheckValues.o -c ./Firmware/HAL/CheckValues.c ${CFLAGS}

Memory.o: ./Firmware/HAL/Memory.c ./Firmware/HAL/DecimalToBinary.h ./Firmware/HAL/Conversion.h ./Firmware/HAL/Memory.h ./Firmware/HAL/CheckValues.h
	gcc -o Memory.o -c ./Firmware/HAL/Memory.c ${CFLAGS}
	

				