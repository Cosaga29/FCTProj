#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iostream>

#include "Character.hpp"
#include "Queue.hpp"
#include "Medusa.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "NumGenerator.hpp"


class Tournament {


private:

	int team1Size;
	int team2Size;

	Queue* team1List;
	Queue* team2List;


public:
	
	bool fasterCharacter(Character* first, Character* second);

	void stepAttack(Character* attacker, Character* defender);

	Character* selectChar(character_type charCode);

	void addCharacterToTeam(Queue*);

	void checkForDeath();

	void deathEvent(QueueNode* winner, QueueNode* loser);		


};





#endif