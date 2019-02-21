#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

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

#include "Character.hpp"

class Vampire : public Character {


private:


public:

	Vampire();

	int attack() override;

	void getClass() const override;

	void defend(int) override;

	~Vampire();
};




#endif