/* 
 * File:   CheckValues.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef CHECKVALUES_H
#define	CHECKVALUES_H

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define CHARACTER_IGNORED '\n'
#define LIMIT_OF_CONVERSION_UP 9
#define LIMIT_OF_CONVERSION_DOWN 0

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

bool CheckSpace(char characterRead);
bool CheckNumber(char characterRead);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* CHECKVALUES */
