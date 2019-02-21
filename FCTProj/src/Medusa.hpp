#ifndef MEDUSA_HPP
#define MEDUSA_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: Medusa class
*
* Implements virtual attack and defend methods for the Medusa class.
* Special ability is stone glare, which is handled in the attack method override.
*
*
******************************************/

#include "Character.hpp"



class Medusa : public Character {

private:


public:

	Medusa();

	int attack() override;

	void getClass() const override;

	void defend(int) override;

	~Medusa();
};


#endif