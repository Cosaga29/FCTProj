#ifndef INTGENERATOR_HPP
#define INTGENERATOR_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 01/28/19
* Project: Lab 4
* Description: Free functions designed to generate random numbers
* for use in other programs
******************************************/


#include <stdlib.h>
#include <time.h>


int generateRandomInt(const int&, const int&);

double generateRandomDouble(const double&, const double&);

int roll(const int&, const int&);


#endif