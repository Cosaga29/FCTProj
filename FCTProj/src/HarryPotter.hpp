#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP	

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3/4
* Description: Harry Potter class
*
* Implements virtual attack and defend methods for the Harry Potter class.
* Harry has special ability 'hogwarts' which can heal him to 20 strength once per fight
*
*
******************************************/

#include "Character.hpp"

#define LIVES 1;

#define MAX_STRENGTH_HARRY 10


class HarryPotter : public Character {


private:

	int m_deathCount;	//keeps track of how many times Harry has died.

	void hogwarts();

public:

	HarryPotter(std::string name = "");

	int attack() override;

	void defend(int) override;

	void getClass() const override;

	void recover() override;

	~HarryPotter();
};




#endif