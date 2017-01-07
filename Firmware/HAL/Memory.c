/* 
 * File:   Conversion.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DecimalToBinary.h"
#include "Memory.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/
/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

void MemoryCheck(int *buffer) // AL GOOD mais le programme s'arette pas en cas d'erreur car tu test bien l'echec mais quand tu apelle cette fonction tu lis pas la valeur de retour de cette fonction donc ca sert a rien 
{
   if(buffer == NULL)
   {
      fprintf(stdout,"Error 03 : Allocation memory fail\n");
      exit(0);
   }
}

int* MemoryAdd(int value, int *memory)                     // Add some memory space if the number is bigger
{
   int *moreMemory;

   moreMemory = memory;

   if(value % ALLOCATION_STEP == 0)
   {
      moreMemory = (int*)realloc(memory,(value + ALLOCATION_STEP) * sizeof(int));
      MemoryCheck(moreMemory);
   }
   return (moreMemory);
}
