#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 02/07/19
* Project: Project 3
* Description: BlueMen class
*
* Implements virtual attack and defend methods for the BlueMen class.
* BlueMen has special ability, called Mob which is calculated directly in the
* defense method.
*
* The BlueMens defense scales with how many "bluemen" are in a group.
******************************************/

#include "Character.hpp"
#include <cmath>


class BlueMen : public Character {

private:


public:

	BlueMen(std::string name = "");

	int attack() override;

	void defend(int) override;

	void getClass() const override;

	int calcMobDefenseRolls() const;

	~BlueMen();
};



#endif