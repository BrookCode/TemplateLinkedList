#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList();
	~LinkedList();

	void printList() const;
	void append(const T data);
	void prepend(const T data);
	bool removeFront();
	void insert(const T data);
	bool remove(const T data);
	bool find(const T data);
	bool isEmpty() const;

	T getFirst() const;
	T getLast() const;
};

//Constructor. Sets head to null, tail to null.
//Takes nothing, returns nothing
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

//Destructor. Iterates through list and deletes nodes.
//Takes nothing, returns nothing
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = head;

	while (head != nullptr)
	{
		head = head->next;
		delete temp;
		temp = head;
	}

	head = nullptr;
	tail = nullptr;
}

//Print method. Takes nothing, returns nothing. Displays list.
template <class T>
void LinkedList<T>::printList() const
{
	Node<T>* iter = head;

	while (iter)
	{
		cout << iter->data;
		iter = iter->next;
	}
}

//Append method. Takes constant T data, returns nothing. Appends
//node with that data to the end of the list.
template <class T>
void LinkedList<T>::append(const T data)
{
	Node<T>* newNode;  // To point to a new node
	newNode = new Node<T>(data);

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		tail->next = newNode;
		tail = newNode;
		
	}
}

//Prepend method. Takes constant T data, returns nothing. Prepends
//node with that data to the front of the list.
template <class T>
void LinkedList<T>::prepend(const T data)
{
	Node<T>* newNode;  // To point to a new node
	newNode = new Node<T>(data);
	Node<T>* temp;

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		temp = head;
		head = newNode;
		newNode->next = temp;

	}
}

//Takes nothing. Returns boolean. Removes the front node and adjusts head.
template <class T>
bool LinkedList<T>::removeFront()
{
	if (head == nullptr)
		return false;
	else
	{
		Node<T>* temp = head;

		head = head->next;
		delete temp;
	}
	return true;
}

//Insert method. Returns nothing. Takes in constant T data.
//Places node in order.
template <class T>
void LinkedList<T>::insert(const T data)
{
	Node<T>* newNode;  // To point to a new node
	Node<T>* temp;

	Node<T>* iter = head;
	Node<T>* prevPtr = nullptr;

	newNode = new Node<T>(data);

	if (head == nullptr) //list empty
		head = newNode;
	else //list not empty
	{
		
		if (head->data > newNode->data)
		{
			temp = head;
			head = newNode;
			newNode->next = temp;
			//newnode comes before head
		}
		else
		{
			
			while (iter != nullptr && iter->data < data)
			{
				prevPtr = iter;
				iter = iter->next;
			}

			//Updates tail accordingly
			
			if (iter == nullptr)
			{
				prevPtr->next = newNode;
				tail = newNode;
				tail->next = nullptr;
								
			}
			
			//Places node in between elements accordingly
			else
			{
				prevPtr->next = newNode;
				newNode->next = iter;
			}
			
			//Case 1: It is the greatest value
			//Case 2: it is in the middle
		}
	}
}

//Remove method. Takes in constant T data. Returns boolean.
//Removes a node if it matches data.
template <class T>
bool LinkedList<T>::remove(const T data)
{
	Node<T>* iter = head;
	Node<T>* prevPtr = nullptr;
	
	//If list is empty
	if (!head)
		return false;
	
	if (head->data == data)
	{
		head = head->next;
		delete iter;
		return true;
	}

	else
	{
		while (iter != nullptr && iter->data != data)
		{
			prevPtr = iter;
			iter = iter->next;
		}

		if (iter == nullptr)
			return false;

		else
		{
			//Adjusts tail accordingly
			if (iter->next == nullptr)
			{
				tail = prevPtr;
				tail->next = nullptr;
				delete iter;
				return true;
			}
			
			prevPtr->next = iter->next;
			delete iter;
			return true;
		}
	}
}

//Find method. Takes in constant T data. Returns boolean.
//Searches for a node that matches data. If found, returns true.
template <class T>
bool LinkedList<T>::find(const T data)
{
	Node<T>* iter = head;

	while (iter != nullptr)
	{
		if (iter->data == data)
			return true;

		iter = iter->next;
	}
	return false;
}

//Takes nothing, returns boolean. Checks to see if the list is empty or not.
template <class T>
bool LinkedList<T>::isEmpty() const
{
	if (head == nullptr)
		return true;
	else
		return false;
}

//Returns type T (varies depending on data type cause of template)
//Takes nothing, returns first node's data.
template <class T>
T LinkedList<T>::getFirst() const
{
	if (head != nullptr)
		return head->data;
}

//Returns type T (varies depending on data type cause of template)
//Takes nothing, returns last node's data.
template <class T>
T LinkedList<T>::getLast() const
{
	return tail->data;
}
