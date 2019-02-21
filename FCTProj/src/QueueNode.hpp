#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Project: Lab 7
* Date: 02/20/19
* Description: Definitions for QueueNode struct
* QueueNode holds
	reference to next node
	reference to prev node
	value
*
******************************************/

#include "Character.hpp"
#include <memory>

struct QueueNode {

	QueueNode* next;

	QueueNode* prev;

	std::unique_ptr<Character> data;

	QueueNode(Character*);

	QueueNode(Character*, QueueNode*);

	QueueNode(Character*, QueueNode*, QueueNode*);

};


#endif