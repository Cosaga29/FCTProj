#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iostream>
#include "Menu.hpp"
#include "InputValidationFunctions.hpp"

#include "Character.hpp"
#include "Queue.hpp"
#include "Medusa.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "NumGenerator.hpp"

#define WIN_VALUE	2
#define LOSE_VALUE -1


class Tournament {


public://testing change to private

	int team1Size;
	int team2Size;

	Queue* team1List;
	Queue* team2List;
	Queue* loserList;

	void buildTeams();

	bool stepAttack(QueueNode* attacker, QueueNode* defender);

	Character* selectChar(character_type charCode, std::string name);

	bool transferCharacter(Queue*, Queue*);

	void resetResources();

public:

	Tournament();

	~Tournament();

	void printTeam();

	bool start();

};





#endif