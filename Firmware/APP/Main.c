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

static void Checkfopen(FILE *fp, char* argv [])
{
	if((fp = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stdout,"Error 00 : This file doesn't exist");
		exit(0); 
	}
}

static void Checkfclose(FILE *fp)
{
	if(fclose(fp) == EOF)
	{
		fprintf(stdout,"Error 01 : This file did not closed properly");
		exit(0);
	}
}

/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

int main(int argc, char* argv [])
{
	FILE *fp;
	
	if(argc == NB_ARGUMENTS_WANTED)
	{
		fp = fopen(argv[1],"r")
		Checkfopen(FILE *fp,argv[1]);
		DecToBin(fp);
		fclose(fp);
		Checkfclose(fp);        		                      
	}
	if(argc > NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout,"Error 02 : Too many arguments");
		exit(0); 
	}
	if(argc < NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout,"Error 03 : Not enough arguments");
		exit(0); 
	}                                              
	return(0);
}
