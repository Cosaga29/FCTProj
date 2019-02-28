/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/27/19
* Project: Project 4
* Description: Main function
*
* Main function that creates a tournament object, seeds RNG and checks
* for user exit input
*
*
******************************************/

#include <iostream>
#include "Queue.hpp"
#include "NumGenerator.hpp" 
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Menu.hpp"
#include "Vampire.hpp"
#include "Tournament.hpp"



int main() {

	
	srand(time(NULL));			//seed random number generator

	Tournament tourney;
	while (tourney.start());	//start returns true/false value depending if user wishes to exit or not

	std::cin.ignore(24474, '\n');
	std::cin.get();

	return 0;
}

