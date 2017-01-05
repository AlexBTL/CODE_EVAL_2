CC         = gcc 
XFLAGS     = -W -Wall -Werror -pedantic
INC1       = ./Firmware/HAL
INCDIRS    = -I ${INC1} 
CFLAGS     = ${INCDIRS} ${XFLAGS} 

DecimalToBinary: DecimalToBinary.o Main.o
	gcc -o DecimalToBinary DecimalToBinary.o Main.o


DecimalToBinary.o: ./Firmware/HAL/DecimalToBinary.c ./Firmware/HAL/DecimalToBinary.h
	gcc -o DecimalToBinary.o -c ./Firmware/HAL/DecimalToBinary.c ${CFLAGS}

Main.o: ./Firmware/APP/Main.c ./Firmware/HAL/DecimalToBinary.h
	gcc -o Main.o -c ./Firmware/APP/Main.c ${CFLAGS}



	

				