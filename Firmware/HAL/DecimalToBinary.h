/* 
 * File:   DecimalToBinary.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef DECIMALTOBINARY_H
#define	DECIMALTOBINARY_H

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define MAX_LENGHT_NUMBER 16
#define NB_ARGUMENTS_WANTED 2
#define CHARACTER_IGNORED '\n'
#define LIMIT_OF_CONVERSION_UP 9
#define LIMIT_OF_CONVERSION_DOWN 0
#define ALLOCATION_STEP 4

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/
void Reset(void);
int* MemoryCheck(int value,int* memory);
int* BinaryConv(void);
void PrintBinary(int* memory);
bool CheckSpace(char characterRead);
bool CheckNumber(char characterRead);
void DecToBin(FILE *fp);
/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/


#endif	/* DECIMALTOBINARY */
