/* 
 * File:   Main.c
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

int main(int argc, char* argv [])
{
	FILE *fp;
	
	if(argc == NB_ARGUMENTS_WANTED)
	{
		if((fp = fopen(argv[1],"r")) == NULL)
		{
			fprintf(stdout,"Error 00 : This file doesn't exist"); 
		}
		else
		{
			DecToBin(fp);
			fclose(fp);        
		}		                      
	}
	if(argc > NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout,"Error 01 : Too many arguments"); 
	}
	if(argc < NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout,"Error 02 : Not enough arguments"); 
	}                                              
	return(0);
}
