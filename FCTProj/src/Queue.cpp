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


#include "Queue.hpp"

/*
Queue Construction, initializes head to default value


*/
Queue::Queue()
{
	head = nullptr;
}

/*
Queue destructor

Loops through the queue, removing the head if the queue is not empty

*/
Queue::~Queue()
{

	while (!isEmpty()) {	//check if queue is empty, if not, rmeove the front
		removeFront();
	}

}

/*
Check if the head value has been initialized to a QueueNode.

If QueueNode hasn't been added, head is null
*/
bool Queue::isEmpty()
{
	return head == nullptr;
}


/*
Add a queueNode element to the back of the queue.

Three cases:
	0 element case: 
	simply add new node and set head pointer


1 element case: 
	Node is added after head, update head next, prev pointers
	and update new node next and prev pointers to create a loop


2 element case:
	Find the last node in the queue, (the node that is not the head that points to the head)
	detach node from head and head from node
	insert node between last node and head
	reattach nodes to the node added


*/
void Queue::addBack(Character* data)
{
	if (head == nullptr) {			//0 elements
		head = new QueueNode(data);	//simply add head
		return;
	}

	if (head->next == nullptr) { //1 element case
		QueueNode* toAdd = new QueueNode(data, head, head);	//Add new node who's prev and next are the head

		head->next = toAdd;		//set head next to new node
		head->prev = toAdd;		//set head prev to new node
		return;
	}

	//2 or more element case:
	QueueNode *currentNode = head->next;

	while (currentNode->next != head) {	//search for last node in queue
		//find last node in queue
		currentNode = currentNode->next;
	}

	//current node is now pointer to last node in queue.
	QueueNode *toAdd = new QueueNode(data, head, currentNode); //create a new node whos next is head and prev was the last node in the list

	//modify old nodes to point to the new node added
	currentNode->next = toAdd;
	head->prev = toAdd;


}


/*
Add a queueNode element to the back of the queue.

Three cases:
	0 element case:
	simply add new node and set head pointer


1 element case:
	Node is added after head, update head next, prev pointers
	and update new node next and prev pointers to create a loop


2 element case:
	Find the last node in the queue, (the node that is not the head that points to the head)
	detach node from head and head from node
	insert node between last node and head
	reattach nodes to the node added


*/
void Queue::addBack(QueueNode* toAdd)
{
	if (head == nullptr) {			//0 elements
		head = toAdd;	//simply add head
		return;
	}

	if (head->next == nullptr) { //1 element case
		//Add new node who's prev and next are the head
		toAdd->next = head;
		toAdd->prev = head;

		head->next = toAdd;		//set head next to new node
		head->prev = toAdd;		//set head prev to new node
		return;
	}

	//2 or more element case:
	QueueNode *currentNode = head->next;

	while (currentNode->next != head) {	//search for last node in queue
		//find last node in queue
		currentNode = currentNode->next;
	}

	//current node is now pointer to last node in queue.

	//add new node whos next is head and prev was the last node in the list
	toAdd->next = head;
	toAdd->prev = currentNode;

	//modify old nodes to point to the new node added
	currentNode->next = toAdd;
	head->prev = toAdd;
}

/*
Function to return the front value of the list (head)
*/
QueueNode* Queue::getFront()
{
	return head;
}

/*
Function that removes the front node from the head

Checks to see if list is empty first

Two cases:

1 element removal:
	delete head
	set head to nullptr

2 element rmeoval:
	get heads next item
	get heads prev item

	create temp pointing to head
	set head to next head in queue
	delete temp

	check to see if deleting the head causes the list to go to 1 element
		if 1 element - set head prev/next to null
		if >1 element - set the new heads prev/next to the temp pointers created earlier
*/
void Queue::removeFront()
{
	if (isEmpty()) {		//double check that queue isn't emppty
		std::cout << "Queue is empty, cannot remove" << std::endl;
		return;
	}

	
	if (head->next == nullptr) {	//1 element removal
		delete head;
		head = nullptr;
		return;
	}


	//2 or more element front removal
	QueueNode* nextHead = head->next;	//store next head to be updated at the end
	QueueNode* prevHead = head->prev;

	QueueNode* temp = head;
	head = head->next;					//get next head

	delete temp;

	if (head->next != head->prev) {		//check that new head isn't pointing to itself for both prev/next (if it is, 1 element)
		nextHead->prev = prevHead;		//update links
		prevHead->next = nextHead;
	}
	else {
		head->next = nullptr;
		head->prev = nullptr;
	}

}

/*
Same logic as remove, but lacks delete functionality. Returns a pointer to the object removed from the list

This is reserved for when the resource will still be tracked by another list and managed by 
the tournament class.
*/
QueueNode* Queue::removeNoDelete()
{
	if (isEmpty()) {		//double check that queue isn't emppty
		std::cout << "Queue is empty, cannot remove" << std::endl;
		return nullptr;
	}


	if (head->next == nullptr) {	//1 element removal
		QueueNode* temp = head;
		head = nullptr;
		return temp;
	}


	//2 or more element front removal
	QueueNode* nextHead = head->next;	//store next head to be updated at the end
	QueueNode* prevHead = head->prev;

	QueueNode* temp = head;

	head = head->next;					//get next head

	if (head->next != head->prev) {		//check that new head isn't pointing to itself for both prev/next (if it is, 1 element)
		nextHead->prev = prevHead;		//update links
		prevHead->next = nextHead;
	}
	else {
		head->next = nullptr;
		head->prev = nullptr;
	}

	return temp;			//return pointer to character being removed from the list
}



/*
Function that loops through the queue printing the values of all nodes
*/
void Queue::printQueue()
{
	if (isEmpty()) {	
		std::cout << "Empty list" << std::endl;
		return;
	}


	QueueNode* currentNode = head;	//create pointer to move through queue
	do {
		std::cout << (currentNode->data.get())->getCharacteristic() << std::endl;
		std::cout << currentNode->data.get() << std::endl;

		currentNode = currentNode->next;
	} while (currentNode != head && currentNode != nullptr);	//while the currentNode is valid and hasn't reached the head again, print the value

	
	std::cout << std::endl;
}

/*
Function to move the front of the list to the back of the list

NON-DESTRUCTIVE
*/
void Queue::moveFrontToBack()
{
	QueueNode* toAdd = removeNoDelete();	//remove node from front of queue without deleting
	addBack(toAdd);							//add removed node to back of queue 
}
