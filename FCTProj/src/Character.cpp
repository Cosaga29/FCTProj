/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Character class
*
* Defines simple get methods to return data from the character class
*
*
******************************************/

#include "Character.hpp"


/*
Character constructor, sets
attack_Power
armor
strength
speed

Speed is added to be used to determine who attacks first in a fight
*/
Character::Character(int attack_power, int armor, int strength, int speed) :
	attack_power(attack_power), armor(armor), strength(strength), speed(speed)
{
}

Character::~Character()
{
}

int Character::getStrength() const
{
	return strength;
}

int Character::getArmor() const
{
	return armor;
}

std::string Character::getCharacteristic() const
{
	return characteristic;
}

int Character::getSpeed() const
{
	return speed;
}
