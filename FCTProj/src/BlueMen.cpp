/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3/4
* Description: BlueMen class
*
* Implements virtual attack and defend methods for the BlueMen class.
* BlueMen has special ability, called Mob which is calculated directly in the 
* defense method. 
*
* The BlueMens defense scales with how many "bluemen" are in a group.
******************************************/

#include "BlueMen.hpp"


/*
BlueMen constructor, defines a short description and attributes for the barbarian class.

Param: (to base class constructor)
	int attack_power
	int armor
	int strength
	int speed

*/
BlueMen::BlueMen(std::string name) :
	Character(10, 3, MAX_STRENGTH_BLUE, 2, name)
{
	characteristic =  "They are small, 6 inch tall, but fast and tough.\n";
	characteristic += "They are hard to hit so they can take some damage. \n";
	characteristic += "They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.\n";
}


/*
Overrides attack() from character class.

Attack power is defined as the maximum roll that the class can roll.
Attack_power of 6 = max roll of 6
*/
int BlueMen::attack()
{
	return roll(2, attack_power);
}


/*
Overrides defend() from character class.

Rolls a defense roll defined by the class attributes (max 6 roll, 2 dice)

BlueMen mob avility is handled via calcMobDefenseRoll()
	this function returns the correct defense roll depending on the strength of the blue man


Defense calculaion is

Damage to strength = damage - (defense_roll + armor)
*/
void BlueMen::defend(int damage)
{
	int defense_roll = roll(calcMobDefenseRolls(), 6);
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
void BlueMen::getClass() const
{
	std::cout << "BlueMen " << std::endl;
}

/*
Blue men special ability 

Defensive rolls for strength 12 starts at 3d6
Every 4 points of health lost they lose a die roll

Example:
strength 11 / 4.0 = 3.66 = 4 defense roll max

strength 7 / 4.0 = 2 defense roll max
*/
int BlueMen::calcMobDefenseRolls() const
{
	int defense_rolls = std::ceil((double)strength / 4.0);

	return defense_rolls;
}

/*
Recovery function for blue men, since they have a decent amount of armor,
the recovery function simply heals between 15-35% of max health. Caps at max strength.
*/
void BlueMen::recover()
{
	double percentRecovery = roll(1, 20) + 15; //(roll 15-35)
	percentRecovery /= 100; //roll - 0.15-0.35


	strength += (percentRecovery * static_cast<double>(MAX_STRENGTH_BLUE)); //heal for 15-35% of max health
	if (strength >= MAX_STRENGTH_BLUE) {	//prevent overhealing
		strength = MAX_STRENGTH_BLUE;
	}

}

BlueMen::~BlueMen()
{
}
