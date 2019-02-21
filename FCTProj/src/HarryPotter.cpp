/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Harry Potter class
*
* Implements virtual attack and defend methods for the Harry Potter class.
* Harry has special ability 'hogwarts' which can heal him to 20 strength once per fight
*
*
******************************************/

#include "HarryPotter.hpp"

/*
Displays a message saying that Harry's strength was set to 20 and
sets Harry's strength to 20
*/
void HarryPotter::hogwarts()
{
	std::cout << "Harry Potter's health reaches 0, he uses \"Dumbledore's Favorite\" and heals back to 20 HP!" << std::endl;
	strength = 20;
}

/*
Harry Potter constructor, defines a short description and attributes for the Harry Potter class.

Param: (to base class constructor)
	int attack_power
	int armor
	int strength
	int speed

	sets death count to 0 - death count is used to track if harry potter has died once already
*/
HarryPotter::HarryPotter() :
	Character(6, 0, 10, 3)
{
	characteristic = "Yer a wizard Harry.";
	m_deathCount = 0;
}


/*
Overrides attack() from character class.

Attack power is defined as the maximum roll that the class can roll.
Attack_power of 6 = max roll of 6
*/
int HarryPotter::attack()
{
	return roll(2, attack_power);
}


/*
Overrides defend() from character class.

Rolls a defense roll defined by the class attributes (max 6 roll, 2 dice)

Defense calculaion is

Damage to strength = damage - (defense_roll + armor)

Defense calculation also checks to see if harry has died, if he has a check is made
to see if he has died once. If he hasnt, hogwarts is invoked.
*/
void HarryPotter::defend(int damage)
{

	int defense_roll = roll(2, 6);
	std::cout << "Defense Roll: " << defense_roll << std::endl;

 	int damage_taken = damage - (defense_roll + armor);
	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

	if (damage_taken > 0) {

		strength -= damage_taken;

	}

	//if harry dies, check if its his first death
	if (strength <= 0) {
		if (m_deathCount == 0) {	//if its his first death, use hogwarts ability
			hogwarts();				
			m_deathCount++;		
		}
	}

	std::cout << "Defenders strength: " << strength << std::endl;
}



/*
Returns short descriptor for a character pointer to access
*/
void HarryPotter::getClass() const
{
	std::cout << "Harry Potter " << std::endl;
}

HarryPotter::~HarryPotter()
{
}
