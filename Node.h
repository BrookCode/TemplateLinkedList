#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{

public:
	T data;
	Node<T>* next;
	
	Node(T value);

};

//Overloaded Constructor. Takes in T value, returns nothing
template <class T>
Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
}