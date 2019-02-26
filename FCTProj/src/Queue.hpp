#ifndef QUEUE_HPP
#define QUEUE_HPP

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Project: Lab 7
* Date: 02/20/19
* Description: Function definitions for the queue
* class. The class models a queue data type structure
* that allows elements of type int to be pushed onto the queue,
* lets elements be de-queued, and the queue to be printed.
******************************************/


#include <iostream>
#include "QueueNode.hpp"


class Queue {

private:

	QueueNode *head;


public:

	Queue();

	~Queue();

	bool isEmpty();

	void addBack(Character*);

	void addBack(QueueNode*);

	QueueNode* getFront();

	void removeFront();

	QueueNode* removeNoDelete();

	void printQueue();

	void printQueueR();

	void moveFrontToBack();

	void clearQueue();


};




#endif