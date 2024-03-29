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

#include "Medusa.hpp"


/*
Medusa constructor, defines a short description and attributes for the Medusa class.

Param: (to base class constructor)
	int attack_power
	int armor
	int strength
	int speed

*/
Medusa::Medusa(std::string name) :
	Character(6, 3, MAX_STRENGTH_MEDUSA , 4, name)
{
	characteristic = "Scrawny lady with snakes for hair which helps her during combat. Just don�t look at her!";
}



/*
Overrides attack() from character class.

Checks to see if medusa rolled a 12, if she did then a message displaying that medusa used the ability
is displayed.

For simplicity, medusa is declared the winner via returning a rediculous amount of damage, instantly killing the opponenet


Attack power is defined as the maximum roll that the class can roll.
Attack_power of 6 = max roll of 6
*/
int Medusa::attack()
{
	int attack_damage = roll(2, attack_power);

	if (attack_damage == 12) {	//check for stone glare ability

		std::cout << "Medusa rolled \"Snake Eyes\" (two 6's), its super effective and turned her opponent to stone!" << std::endl;

		return 5000;			//one shot the opponent
	}

	return roll(2, attack_power);
}



/*
Returns short descriptor for a character pointer to access
*/
void Medusa::getClass() const
{
	std::cout << "Medusa " << std::endl;
}


/*
Overrides defend() from character class.

Rolls a defense roll defined by the class attributes (max 6 roll, 2 dice)

Defense calculaion is

Damage to strength = damage - (defense_roll + armor)
*/
void Medusa::defend(int damage)
{

	int defense_roll = roll(1, 6);		//roll 1D-6
	std::cout << "Defense roll: " << defense_roll << std::endl;

	int damage_taken = damage - (defense_roll + armor);		//calculate damage taken
	std::cout << "Damage taken: " << damage << " - " << "(" << defense_roll << " + " << armor << ") = " << damage_taken << std::endl;

	if (damage_taken > 0) {			//if damage is not negative or 0, apply damage

		strength -= damage_taken;
	}
	std::cout << "Defenders strength: " << strength << std::endl;
}

/*
Medusa heals for a decent amount 30-50% of max health, but has a similar overhealing
ability to the barbarian class. Her strength from recovery is capped at 2x base (16)
*/
void Medusa::recover()
{
	double percentRecovery = roll(1, 20) + 30; //(roll 30-50)
	percentRecovery /= 100; //roll - 0.3-0.5


	strength += (percentRecovery * static_cast<double>(MAX_STRENGTH_MEDUSA )); //heal for 20-50% of max health

	//MEDUSA IS ALLOWED TO OVERHEAL
	//Able to overheal to a limit of 2x her base strength (max 16 strength)
	if (strength >= MAX_STRENGTH_MEDUSA  * OVER_STRENGTH_FACTOR) {	
		strength = MAX_STRENGTH_MEDUSA  * OVER_STRENGTH_FACTOR;
	}
}

Medusa::~Medusa()
{
}
