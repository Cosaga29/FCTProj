#ifndef MEDUSA_HPP
#define MEDUSA_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3/4
* Description: Medusa class
*
* Implements virtual attack and defend methods for the Medusa class.
* Special ability is stone glare, which is handled in the attack method override.
*
*
******************************************/

#include "Character.hpp"

#define MAX_STRENGTH_MEDUSA	 8
#define OVER_STRENGTH_FACTOR 2

class Medusa : public Character {

private:


public:

	Medusa(std::string name = "");

	int attack() override;

	void getClass() const override;

	void defend(int) override;

	void recover() override;

	~Medusa();
};


#endif