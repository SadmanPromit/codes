#ifndef STACKTYPELL_H
#define STACKTYPELL_H

#include<iostream>
#include<new>
using namespace std;

template<class ItemType>
class NodeType
{
public:
    int data;
    NodeType *next;
};

template<class ItemType>
class StackTypeLL
{
private:
    NodeType<ItemType> *tos;
public:
    StackTypeLL();
    ~StackTypeLL();
    void Push(ItemType);
    void pop(ItemType &);
    bool isFull () const;
	bool isEmpty() const;
	void makeEmpty();
	void printStack() const;


};


#endif // STACKTYPELL_H
#include "StackTypeLL.cpp"
