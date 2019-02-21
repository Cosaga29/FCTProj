/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 01/28/19
* Project: Lab 4
* Description: Free functions designed to generate random numbers
* for use in other programs
******************************************/

#include "NumGenerator.hpp"


/*
Generates a random number between min and max and returns the value

Param:
	min - min number to roll
	max - max number to roll

Return - random int between min/max
*/
int generateRandomInt(const int& min, const int& max)
{

	int toReturn = rand();
	//old:(toReturn % (min + max)) - min;
	toReturn = (toReturn % (max - min + 1)) + min;

	return toReturn;

}


/*
Generates a random double between min and max and returns the value

Param:
	min - min number to roll
	max - max number to roll

Return - random int between min/max
*/
double generateRandomDouble(const double &min, const double &max)
{
	double toReturn = (double)rand() / RAND_MAX;
	return min + (toReturn * (max - min));
}


/*
Simulates a roll of one or multiple dies

Param - 
	die_num - number of die to roll
	max_roll - max possible die value

Example:
	roll 2d10
	Rolls 2 die of side 10 and returns the value
*/
int roll(const int& die_num, const int& max_roll)
{
	int total = 0;
	for (int i = 0; i < die_num; i++) {
		total += generateRandomInt(1, max_roll);
	}

	return total;
}
