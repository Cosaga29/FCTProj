#include "Tournament.hpp"

void Tournament::healWinner(QueueNode *)
{


}

Tournament::Tournament()
{
	team1Size = 0;
	team2Size = 0;

	team1List = new Queue();
	team2List = new Queue();
	loserList = new Queue();

	buildTeams();
}

Tournament::~Tournament()
{
	delete team1List;
	delete team2List;
}

/*
Function dedicated to getting input from user and adding characters to respective teams
*/
void Tournament::buildTeams()
{
	Menu characterSelection;
	characterSelection.addPrompt("Barbarian");
	characterSelection.addPrompt("BlueMen");
	characterSelection.addPrompt("Harry Potter");
	characterSelection.addPrompt("Medusa");
	characterSelection.addPrompt("Vampire");
	
	
	team1Size = validateInputGreaterThan(0, "Enter number of fighters for team 1.");

	team2Size = validateInputGreaterThan(0, "Enter number of fighters for team 2 ");

	std::string nameBuffer; //used to store name of character being created

	//build team 1 character list
	for (int i = 0; i < team1Size; i++) {	//for up to team size, prompt for characters for team 1


		//get character classes from user
		characterSelection.displayMessage("Pick a character for team 1 ");
		int firstChar = characterSelection.getUserChoice();

		characterSelection.displayMessage("Enter a name for the character: ");

		clearInputStream();	//clear '\n' chars
		std::getline(std::cin, nameBuffer);		//get name for ccharacter

		//add character to queue
		std::cout << "Adding character.. " << std::endl;
		team1List->addBack(selectChar(static_cast<character_type>(firstChar-1), nameBuffer));

	}

	for (int i = 0; i < team2Size; i++) {	//for up to team size, prompt for characters for team 2

		//get character classes from user
		characterSelection.displayMessage("Pick a character for team 2 ");
		int firstChar = characterSelection.getUserChoice();

		characterSelection.displayMessage("Enter a name for the character: ");

		clearInputStream();	//clear '\n' chars
		std::getline(std::cin, nameBuffer);		//get name for ccharacter

		//add character to queue
		std::cout << "Adding character.. " << std::endl;
		team2List->addBack(selectChar(static_cast<character_type>(firstChar - 1), nameBuffer));

	}




}

//comparison for character speed
bool Tournament::fasterCharacter(Character* first, Character* second) {

	return first->getSpeed() > second->getSpeed();	//if first > second, return true 

}



/*
Function that handles a single attack made in the game.

Param-
	attacker- attacking character
	defender- defending character

Return-
	true - the defender has died
	false - other

*/
bool Tournament::stepAttack(QueueNode * attacker, QueueNode * defender) 
{
	//display attacker
	std::cout << "Attacker: " << attacker->data.get()->getName() << std::endl;
	attacker->data.get()->getClass();

	//display defender
	std::cout << "Defender: " << defender->data.get()->getName() << std::endl;
	defender->data.get()->getClass();

	//display defender stats
	std::cout << "\tArmor:   " << defender->data.get()->getArmor()
		<< "\tStrength:" << defender->data.get()->getStrength() << std::endl;


	//Start combat
	std::cout << "\n\nCombat:\n" << std::endl;

	//first character attakcs
	int attack_roll = attacker->data.get()->attack();
	std::cout << "Attack roll: " << attack_roll << std::endl;


	//second character defends against attack
	defender->data.get()->defend(attack_roll);
	std::cout << "\n\n" << std::endl;


	//check for death
	if (defender->data.get()->getStrength() <= 0) { //character has died
		return true;
	}
	else {
		return false;
	}
}


/*
Function that allows for a user to select a character to add given a certain character code
Character_type is defined in Character class.


*/
Character* Tournament::selectChar(character_type charCode, std::string name) {

	Character* toReturn = 0;

	switch (charCode) {
	case BARB:		//create a barbarian
		toReturn = new Barbarian(name);
		break;

	case BLUE:		//create a bluemen
		toReturn = new BlueMen(name);
		break;

	case HARRY:		//create harry potter
		toReturn = new HarryPotter(name);
		break;

	case MEDUSA:	//create medusa
		toReturn = new Medusa(name);
		break;

	case VAMPIRE:	//create vampire
		toReturn = new Vampire(name);
		break;

	}

	//return selected character
	return toReturn;
}

/*
Function to transfer the queueNode head from a source to a destination without losing the reference
*/
bool Tournament::transferCharacter(Queue* source, Queue* destination, QueueNode* nodeToTransfer)
{
	QueueNode* temp = source->getFront();	//store temp reference from source list

	if (temp != nullptr) {
		source->removeNoDelete();	//remove the reference from the source list, without deleting the node

		destination->addBack(temp);	//add the reference to the destination list: destination now manages the queueNode
		return true; //transferred
	}
	else {
		return false; //could not transfer 
	}
	
}



void Tournament::printTeam()
{
	std::cout << "Team 1 list Contents: " << std::endl;
	team1List->printQueue();	//print t1 contents
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Team 2 list Contents: " << std::endl;
	team2List->printQueue();	//print t2 contents
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Loser list Contents: " << std::endl;
	loserList->printQueue();	//print loser container contents
}



void Tournament::start()
{
	//teams should be well formed with at least 1 character in a list
	QueueNode* team1Fighter;
	QueueNode* team2Fighter;





	while (!team1List->isEmpty() && team2List->isEmpty()) {	//continue until a team is exhausted

		//get two fighters from list (head of each team)
		team1Fighter = team1List->getFront();
		team2Fighter = team2List->getFront();


		//flag to pick new characters when a death occurs
		bool death_event = false;
		while (!death_event) {									//while a fighter pair hasnt died:
			


			//faster fighter attacks first
			if (team1Fighter->data.get()->getSpeed() > team2Fighter->data.get()->getSpeed()) {


				//team 1 fighter attacks first:
				if (stepAttack(team1Fighter, team2Fighter)) {	//team 1 fighter attacks team 2 fighter

					//team2Fighter defeated
					transferCharacter(team2List, loserList, team2Fighter); //transfer loser to list, heal winner by some amount
					//team1Fighter->data.get()->recover();
					team1List->moveFrontToBack();
					death_event = true;

				}

				//team 2 fighter attacks second
				if (!death_event) {
					if (stepAttack(team2Fighter, team1Fighter)) {

						//team1Fighter defeated
						transferCharacter(team1List, loserList, team1Fighter);
						//team2Fighter->data.get()->recover();
						team2List->moveFrontToBack();
						death_event = true;
					}
				}

			

			}
			else {
				//team 2 fighter attacks first
				if (stepAttack(team2Fighter, team1Fighter)) {

					//team1Fighter defeated
					transferCharacter(team1List, loserList, team1Fighter);
					//team2Fighter->data.get()->recover();
					team2List->moveFrontToBack();
					death_event = true;
				}

				//team 1 fighter attacks second
				if (!death_event) {
					if (stepAttack(team1Fighter, team2Fighter)) {	

						transferCharacter(team2List, loserList, team2Fighter);
						//team1Fighter->data.get()->recover();
						team1List->moveFrontToBack();
						death_event = true;
					}
				}

			}

		}

	}


}
