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

static void Checkfopen(FILE *fp)
{
	if(fp == NULL)
	{
		fprintf(stdout, "\nError 00 : This file doesn't exist\n");
		exit(0); 
	}
}

static void Checkfclose(int close)
{
	if(close == EOF)
	{
		fprintf(stdout, "\nError 01 : This file did not closed properly\n");
		exit(0);
	}
}

/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

int main(int argc, char *argv[])
{
	FILE *fp;
	int close;
	
	if(argc == NB_ARGUMENTS_WANTED)
	{
		fp = fopen(argv[1],"r");
		Checkfopen(fp);
		DecToBin(fp);
		close = fclose(fp);
		Checkfclose(close);        		                      
	}
	if(argc > NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout, "\nError 02 : Too many arguments\n");
		exit(0); 
	}
	if(argc < NB_ARGUMENTS_WANTED)
	{
		fprintf(stdout, "\nError 03 : Not enough arguments\n");
		exit(0); 
	}                                              
	return(0);
}
