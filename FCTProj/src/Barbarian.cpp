/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Barbarian class
*
* Implements virtual attack and defend methods for the barbarian class.
* No special abilities. To be used with other Character derived classes and the
* fantasy project
*
*
******************************************/

#include "Barbarian.hpp"

/*
Barbarian constructor, defines a short description and attributes for the barbarian class.

Param: (to base class constructor)
	int attack_power 
	int armor 
	int strength 
	int speed

*/
Barbarian::Barbarian() :
	Character(6, 0, 12, 3) 
{
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
}


/*
Overrides attack() from character class.

Attack power is defined as the maximum roll that the class can roll.
Attack_power of 6 = max roll of 6
*/
int Barbarian::attack()
{
	return roll(2, attack_power);
}


/*
Overrides defend() from character class.

Rolls a defense roll defined by the class attributes (max 6 roll, 2 dice)

Defense calculaion is

Damage to strength = damage - (defense_roll + armor)
*/
void Barbarian::defend(int damage)
{
	int defense_roll = roll(2, 6);
	std::cout << "Defense roll: " << defense_roll << std::endl;

	int damage_taken = damage - (defense_roll + armor);

	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;


	if (damage_taken > 0) {

		strength -= damage_taken;
	
	}
	std::cout << "Defenders strength: " << strength << std::endl;
}


/*
Returns short descriptor for a character pointer to access
*/
void Barbarian::getClass() const
{
	std::cout << "Barbarian " << std::endl;
}

Barbarian::~Barbarian()
{
}
