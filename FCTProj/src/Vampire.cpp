/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Vampire class
*
* Implements virtual attack and defend methods for the Vampire class.
* Special ability is Charm - gives a 50% chance to not take damage
*
*
******************************************/

#include "Vampire.hpp"

/*
Vampire constructor, defines a short description and attributes for the Vampire class.

Param: (to base class constructor)
	int attack_power
	int armor
	int strength
	int speed

*/
Vampire::Vampire() :
	Character(12, 1, 18, 1)
{
	characteristic = "Suave, debonair, but vicious and surprisingly resilient.";
}




/*
Overrides attack() from character class.

Attack power is defined as the maximum roll that the class can roll.
Attack_power of 6 = max roll of 6
*/
int Vampire::attack()
{
	return roll(1, attack_power);
}



/*
Returns short descriptor for a character pointer to access
*/
void Vampire::getClass() const
{
	std::cout << "Vampire " << std::endl;
}




/*
Overrides defend() from character class.

Rolls a defense roll defined by the class attributes (max 6 roll, 2 dice)

First a check is determined (50% chance) if the vampire takes any damage at all
If the ability activates a message is displayed and no damage is applied.

If the roll for charm isnt successful, normal damage is calculated

Defense calculaion is

Damage to strength = damage - (defense_roll + armor)
*/
void Vampire::defend(int damage)
{
	int damage_taken = 0;
	int defense_roll = roll(2, 6);

	//roll for charm special ability
	if (roll(1, 2) == 2) {
		std::cout << "The vampire charmed their opponent into not attacking! " << std::endl;
		std::cout << "Vampire took 0 damage. " << std::endl;
		return;
	}
	else {	//calculate damage normally
		std::cout << "Vampire defense roll: " << defense_roll << std::endl;

		damage_taken = damage - (defense_roll + armor);
		std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl; //display damage calc

		if (damage_taken > 0) {

			strength -= damage_taken;

		}

	}
	std::cout << "Defenders strength: " << strength << std::endl;
	
}

Vampire::~Vampire()
{
}
