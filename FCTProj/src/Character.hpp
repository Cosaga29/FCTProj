#ifndef CHARACTER_HPP
#define CHARACTER_HPP

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

#include <string>
#include "NumGenerator.hpp"
#include <iostream>


//type codes used for printing round information only
enum character_type {BARB, BLUE, HARRY, MEDUSA, VAMPIRE };

static const std::string charactrer_names[5] = { "Barbarian ", "BlueMen ", "Harry Potter ", "Medusa ", "Vampire " };

/*
Abstract class for character
*/


class Character {

protected:

	int attack_power;
	int armor;
	int strength;
	int speed;

	std::string characteristic;
	std::string name;


public:

	Character(int, int, int, int, std::string);

	virtual int attack() = 0; //return damage from attack

	virtual void defend(int) = 0; //accept an attack, calculate damage infliced

	virtual void getClass() const = 0;

	virtual ~Character();

	int getStrength() const; //return strength

	int getArmor() const; //return armor

	std::string getCharacteristic() const;

	int getSpeed() const; //return speed

	const std::string& getName() const;


	//TODO:: ADD RECOVERY SCHEME FOR CHARACTERS
	//virtual void recover() = 0;

};


#endif