/* 
 * File:   DecimalToBinary.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DecimalToBinary.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/


/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

static int OldNumberRead;                           // Hold the number of each line
static char OldCharacterRead;                       // Hold the previous char red
static char NewCharacterRead;                       // Hold the char read each time
static bool NotOnlyLetter;                          //Bolean to know if there at least one number on a line
static int CountNumberDisplay;
    

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/
/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/


void Reset(void)
{
	OldNumberRead = 0;
	NewCharacterRead = '0';

}


int* MemoryCheck(int value,int* memory)   // Add some memory space if the number is bigger
{
   int* moreMemory;
   moreMemory = memory;
   if(value % ALLOCATION_STEP == 0)
   {
      moreMemory = (int*)realloc(memory,(value + ALLOCATION_STEP) * sizeof(int));
   }
   return(moreMemory);
}



int* BinaryConv(void)               
{
   int* memory;
   memory = (int*)calloc(ALLOCATION_STEP,sizeof(int));
   CountNumberDisplay = 0;   
   while(OldNumberRead != 0)      // Ignore the empty line 
   {
      CountNumberDisplay++;
      memory = MemoryCheck(CountNumberDisplay,memory);
      if(OldNumberRead % 2 == 1)   // Easy way to know how many one there is on the binary number => mod2 = 1 => There is a 1 / mod2 = 0 => There is a 0
      {
         memory[CountNumberDisplay] = 1;
      }
      else
      {
         memory[CountNumberDisplay] = 0;
      }
      OldNumberRead = OldNumberRead / 2;       
   }
   return (memory);                                  // Retrun the lenght of the binary conversion
}



void PrintBinary(int* memory)                   // Print the table holding the binary conversion of the integer
{
   int numberOfPrint;
   numberOfPrint = CountNumberDisplay;
   while( numberOfPrint != 0)
   {
      printf("%d", memory[numberOfPrint]);
      numberOfPrint--;
   }
   free(memory);
   NotOnlyLetter = false;         // end of line we reset the bolean
   printf("\n");     
}
 
   


bool CheckSpace(char characterRead)
{
   if(characterRead != CHARACTER_IGNORED)           // If its not an empty line
   {
      return (false);
   }
   else
   {
      return (true);
   }

}

bool CheckNumber(char characterRead)
{
   if( ((characterRead - '0') > LIMIT_OF_CONVERSION_UP) || ((characterRead - '0') < LIMIT_OF_CONVERSION_DOWN) )   // Check if its a number between 0 and 9     
   { 
      return (false);
   }
   else
   {
      NotOnlyLetter = true;
      return (true);
   }
}



void DecToBin(FILE *fp)
{               
   Reset();                                                         
   while(!feof(fp))
   {
   	OldCharacterRead = NewCharacterRead;
      NewCharacterRead= fgetc(fp);                    // Get the char
      if(CheckSpace(NewCharacterRead) == true)          // If we are at the end of the line
      {   
         if((CheckSpace(OldCharacterRead) == false) && (NotOnlyLetter == true))      // If its not an empty line
         {                    
               PrintBinary(BinaryConv());
         }
      }
      else
      {
         if(CheckNumber(NewCharacterRead) == true)    // Check if its a number between 0 and 9     
         { 
      	  OldNumberRead = OldNumberRead * 10 + (NewCharacterRead - '0');  // Convert the char to an int and add it
         }
      }
   }
   fclose(fp);
}







