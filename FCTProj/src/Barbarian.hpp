#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

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

#include "Character.hpp"

#define MAX_STRENGTH			12
#define OVER_STRENGTH_FACTOR	3

class Barbarian : public Character {

private:



public:

	Barbarian(std::string namne = "");

	int attack() override;

	void defend(int) override;

	void getClass() const override;

	void recover() override;

	~Barbarian();
};



#endif