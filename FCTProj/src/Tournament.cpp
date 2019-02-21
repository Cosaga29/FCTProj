#include "Tournament.hpp"


//comparison for character speed
bool Tournament::fasterCharacter(Character* first, Character* second) {

	return first->getSpeed() > second->getSpeed();	//if first > second, return true 

}





/*
Function that handles a single attack made in the game.

Param-
	attacker- attacking character
	defender- defending character


*/
void Tournament::stepAttack(Character * attacker, Character * defender) 
{
	//display attacker
	std::cout << "Attacker: ";
	attacker->getClass();

	//display defender
	std::cout << "Defender: ";
	defender->getClass();

	//display defender stats
	std::cout << "\tArmor:   " << defender->getArmor()
		<< "\tStrength:" << defender->getStrength() << std::endl;


	//Start combat
	std::cout << "\n\nCombat:\n" << std::endl;

	//first character attakcs
	int attack_roll = attacker->attack();
	std::cout << "Attack roll: " << attack_roll << std::endl;


	//second character defends against attack
	defender->defend(attack_roll);
	std::cout << "\n\n" << std::endl;
}


/*
Function that allows for a user to select a character to add given a certain character code
Character_type is defined in Character class.


*/
Character* Tournament::selectChar(character_type charCode) {

	Character* toReturn = 0;

	switch (charCode) {
	case BARB:		//create a barbarian
		toReturn = new Barbarian();
		break;

	case BLUE:		//create a bluemen
		toReturn = new BlueMen();
		break;

	case HARRY:		//create harry potter
		toReturn = new HarryPotter();
		break;

	case MEDUSA:	//create medusa
		toReturn = new Medusa();
		break;

	case VAMPIRE:	//create vampire
		toReturn = new Vampire();
		break;

	}

	//return selected character
	return toReturn;
}
