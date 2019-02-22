/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Main function
*
* Creates a vector to manage the order of attacks in a given round.
* Position 0 is the character to attack first, 1 to attack second
*
* The vector consists of character pointers sorted via speed
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

	


	srand(time(NULL));	//seed random number generator


	Queue myQueue;
	Character* myChar = new Medusa("1");
	Character* myChar1 = new Medusa("2");


	myQueue.addBack(myChar);
	myQueue.addBack(myChar1);

	myQueue.printQueue();

	
	myQueue.moveFrontToBack();

	myQueue.printQueue();



	//myQueue.printQueue();

	
	//Tournament tourney;

	//tourney.printTeam();

	//tourney.transferCharacter(tourney.team1List, tourney.loserList, tourney.team1List->getFront());

	//tourney.printTeam();


	std::cin.ignore(24474, '\n');
	std::cin.get();



	return 0;
}

