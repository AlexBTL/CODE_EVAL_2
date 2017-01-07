/* 
 * File:   DecimalToBinary.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DecimalToBinary.h"
#include "Conversion.h"
#include "Memory.h"
#include "CheckValues.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

static bufferInt_s GetValue(bufferInt_s buffStruct, FILE *fp)
{
   buffStruct.pRead[1] = buffStruct.pRead[0];
   buffStruct.pRead[0] = fgetc(fp);
   return (buffStruct); 
}

static bufferInt_s MakeConversion(bufferInt_s buffStruct)
{
   buffStruct.pInt = BinaryConv(buffStruct.pInt,buffStruct.indice);
   buffStruct.indice = 0;
   buffStruct.notOnlyLetter = false;
   return (buffStruct);
}

static bufferInt_s CopyNumberIntoBuffer(bufferInt_s buffStruct)
{
   buffStruct.indice++;
   buffStruct.pInt = MemoryAdd(buffStruct.indice,buffStruct.pInt);
   buffStruct.pInt[buffStruct.indice] = (buffStruct.pRead[0] - '0');  // Convert the char to an int and add it in the buffer
   buffStruct.notOnlyLetter = true;
   return (buffStruct);
}

/**************************************************************/
/*                        PUBLIC FUNCTIONS                   */
/**************************************************************/

void DecToBin(FILE *fp)                         
{                  
   bufferInt_s bufferInt;
    
   bufferInt.indice = 0;
   bufferInt.notOnlyLetter = false;
   bufferInt.pInt = (int*)calloc(ALLOCATION_STEP, sizeof(int));
   MemoryCheck(bufferInt.pInt);  
   bufferInt.pRead = (int*)calloc(SIZE_BUFF_READ, sizeof(int));
   MemoryCheck(bufferInt.pRead);   

   while(!feof(fp))
   {  
      bufferInt = GetValue(bufferInt,fp);                                                                                                                // Get the char
      if(((CheckSpace(bufferInt.pRead[0]) == true) || (bufferInt.pRead[0] == EOF)) && (CheckSpace(bufferInt.pRead[1]) == false) && (bufferInt.notOnlyLetter == true))        // If we are at the end of the line or if we are at the end of the file
      {                     
         bufferInt = MakeConversion(bufferInt);
      }
      else if(CheckNumber(bufferInt.pRead[0]) == true)    // Check if its a number between 0 and 9     
      { 
         bufferInt = CopyNumberIntoBuffer(bufferInt);
      }
   }                                                           
}
