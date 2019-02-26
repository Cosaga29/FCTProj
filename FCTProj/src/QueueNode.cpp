/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Project: Project 4
* Date: 02/25/19
* Description: Definitions for QueueNode struct
* QueueNode holds
	reference to next node
	reference to prev node
	data - smart pointer to character object
*
******************************************/

#include "QueueNode.hpp"

/*
One arg constructor

Creates node with nullptrs and initializes value
*/
QueueNode::QueueNode(Character* cData) {
	next = nullptr;
	prev = nullptr;
	data.reset(cData);
}


/*
Two arg constructor

Creates a queueNode that has its next node set
*/
QueueNode::QueueNode(Character* cData, QueueNode* nextNode) {
	next = nextNode;
	prev = nullptr;
	data.reset(cData);
}

/*
Three arg constructor

Creates a queueNode that has its previous and next references set, good for mid list addition and circular addition

Example:

Node = new QueueNode(5, head, head) - Creates a node whos prev and next is the same node

Node = new QueueNode(5, prev, next) - Inserts the node between a previous node and next node
*/
QueueNode::QueueNode(Character* cData, QueueNode* nextNode, QueueNode* prevNode) {
	next = nextNode;
	prev = prevNode;
	data.reset(cData);
}
