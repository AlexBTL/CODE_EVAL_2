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
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/
/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/


bool MemoryCheck(int *buffer)
{
   if(buffer != NULL)
   {
      return (true);
   }
   else
   {
      fprintf(stdout,"Error 03 : Allocation memory fail\n");
      return (false);
   }
}





int* MemoryAdd(int value,int *memory)                     // Add some memory space if the number is bigger
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





int FunctionDivByTwo(int indice, int size, int* buffer)
{
   int temp;                                                  // Hold the temporary value allowing to use the conversion method
   int carry;
   
   temp = 0;
   carry = 0;

   while(indice <= size)                                        // indice        = 1  / 2  / 3               2  / 3         2  / 3        2  / 3            3       3      3        3                  
   { 
      temp = (10 * carry + buffer[indice]);                     // temp         <= 1  / 13 / 14              6  / 7         3 / 13        1  / 16           8       4      2        1
      buffer[indice] = temp / 2;                                // bufferInt[]  <= 0  / 6  / 7               3  / 3         1  / 6        0  / 8            4       2      1        0
      carry = temp % 2;                                         // carry        <= 1  / 1  / (0)             0  / (1)       1  / (1)      1  / (0)         (0)     (0)    (0)      (1)
      indice++;                                                 // indice       <= 2  / 3  / 4               3  / 4         3  / 4        3  / 4            4       4      4        4
   }
   return (carry);   
}





int* BinaryConv(int *buffer,int size)               
{   
   int firstIndice;                                               // Put an offset if we loose un digit between the number and the result of his division by two
   int countNumberDisplay;                                        // Count how many bit we will have to display
   int *bufferBinary;
   
   firstIndice = 1;                                               // Use when you loose a digit during the division to read next time one indice after the begining
   countNumberDisplay = 0;
   bufferBinary = (int*)calloc(ALLOCATION_STEP,sizeof(int));
   MemoryCheck(bufferBinary);
   
   while(firstIndice <= size)                                                            // Exemple : number 134 (1000 0110)=> size 3  bufferInt = [1,3,4]                            
   {  
      bufferBinary[countNumberDisplay] = FunctionDivByTwo(firstIndice,size,buffer);
      countNumberDisplay++;
      bufferBinary = MemoryAdd(countNumberDisplay,bufferBinary);
      firstIndice = TestEqualZero(buffer, firstIndice);                                                                                     
   }
   PrintBinary((countNumberDisplay-1),bufferBinary);                                          // Retrun the lenght of the binary conversion
   return (RenewBuffer(buffer));
}





int* RenewBuffer(int *buffer)
{
   free(buffer);
   buffer = (int*)calloc(ALLOCATION_STEP,sizeof(int));
   MemoryCheck(buffer);
   return (buffer);
}





int TestEqualZero(int *buffer, int indice)
{
   if(buffer[indice] == 0)
   {                                                                     
      indice++;
   }
   return (indice); 
}





void PrintBinary(int count, int *buffer)                   // Print in reverse the table holding the binary conversion of the integers
{
   int numberOfPrint;
   numberOfPrint = count;

   while( numberOfPrint >= 0)
   {
      printf("%d", buffer[numberOfPrint]);
      numberOfPrint--;
   }
   free(buffer);                                     // end of line we reset the bolean
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





bool CheckNumber(char characterRead)       // Check if the number in on the range       
{
   if( ((characterRead - '0') > LIMIT_OF_CONVERSION_UP) || ((characterRead - '0') < LIMIT_OF_CONVERSION_DOWN) )   // Check if its a number between 0 and 9     
   { 
      return (false);
   }
   else
   {
      return (true);
   }
}




void DecToBin(FILE *fp)                              
{                  
   int indice;                          
   int *bufferInt;
   bool notOnlyLetter;
   char buffRead[SIZE_BUFF_READ]; 

   indice = 0;
   bufferInt = (int*)calloc(ALLOCATION_STEP,sizeof(int));
   MemoryCheck(bufferInt);  
   notOnlyLetter = false; 

   while(!feof(fp))
   {  
      buffRead[1] = buffRead[0];
      buffRead[0] = fgetc(fp);                                                                                                                // Get the char
      if(((CheckSpace(buffRead[0]) == true) || (buffRead[0] == EOF)) && (CheckSpace(buffRead[1]) == false) && (notOnlyLetter == true))        // If we are at the end of the line or if we are at the end of the file
      {                     
         bufferInt = BinaryConv(bufferInt,indice);
         indice = 0;
         notOnlyLetter = false;
      }
      else if(CheckNumber(buffRead[0]) == true)    // Check if its a number between 0 and 9     
      { 
            indice++;
            bufferInt = MemoryAdd(indice,bufferInt);
            bufferInt[indice] = (buffRead[0] - '0');  // Convert the char to an int and add it in the buffer
            notOnlyLetter = true;
      }
   }                                                           
}









