/* 
 * File:   CheckValues.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
/**************************************************************/
/*                        PUBLIC FUNCTIONS                   */
/**************************************************************/

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
