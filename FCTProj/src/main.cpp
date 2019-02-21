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

#include "NumGenerator.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Menu.hpp"
#include "Vampire.hpp"
#include "Tournament.hpp"





/*
Function that allows for a user to select a character to add given a certain character code
Character_type is defined in Character class.


*/
Character* selectChar(character_type charCode) {
	
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



int main() {

	srand(time(NULL));	//seed random number generator

	//Build play again menu
	Menu playAgain;
	playAgain.addPrompt("Play again");
	playAgain.addPrompt("Exit");


	//Build character selection menu
	Menu characterSelection;
	characterSelection.addPrompt("Barbarian");
	characterSelection.addPrompt("BlueMen");
	characterSelection.addPrompt("Harry Potter");
	characterSelection.addPrompt("Medusa");
	characterSelection.addPrompt("Vampire");

	//declar vector to store pointers to characters
	std::vector<Character*> characters;


	//exit flag
	bool playerExit = false;
	int combat_round = 1;


	
	while (!playerExit) {	//while the user hasn't elected to exit


		//get character classes from user
		characterSelection.displayMessage("Pick first character: ");
		int firstChar = characterSelection.getUserChoice();

		characterSelection.displayMessage("Pick second character: ");
		int secondChar = characterSelection.getUserChoice();


		//pick two characters to fight via select char method and the input given by the user
		characters.push_back(selectChar(static_cast<character_type>(firstChar - 1)));	//example: user enters 1 = character_type = 0 (Barbarian)
		characters.push_back(selectChar(static_cast<character_type>(secondChar - 1)));


		//sort pointers to characters based on speed. The character at characters[0] is the fastest.
		std::sort(characters.begin(), characters.end(), &fasterCharacter);
		//In the case of a speed tie, the character that was added first goes first in combat.


		//combat loop
		bool character_died = false;

		//while a character hasnt died
		while (!character_died) {

			std::cout << "\n\n\n\n\nRound: " << combat_round << std::endl;
			printAttack(characters[0], characters[1]);

			if (characters[1]->getStrength() > 0) {
				printAttack(characters[1], characters[0]);
			}
			else {
				character_died = true;
			}

			if (characters[0]->getStrength() <= 0) {
				character_died = true;
			}

			combat_round++;
		}


		//clean resources for next play if desired
		for (int i = 0; i < characters.size(); i++) {
			delete characters[i];
		}
		characters.clear();	//clear vector of pointer data



		//check if player would like to exit
		if (playAgain.getUserChoice() == playAgain.getExitCode()) {
			playerExit = true;
		}
	}



	return 0;
}

