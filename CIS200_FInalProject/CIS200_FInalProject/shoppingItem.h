#pragma once

#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <iostream>
#include <string>
using namespace std;

struct itemNode {
	string shoppingItem;
	itemNode* next = nullptr;
	itemNode* prev = nullptr;
};

class shoppingItem {
public:
	shoppingItem();
	~shoppingItem();

	bool isItemAvailable(const string& searchItem); //Returns true if item is in the list
	itemNode* findItem(const string& searchItem); //Returns node that you're trying to find

	void insertItemEnd(const string& listItem); //Inserts new node at end of list; increment count
	void insertItemStart(const string& listItem); //Inserts new node at start of list; increment count
	void insertItemAfter(itemNode* prevItem, const string& listItem); //Inserts new node after a given node; increment count

	void moveItemEnd(const string& listItem); //Moves node to end of list; no increment
	void moveItemStart(const string& listItem); //Moves node to start; no increment
	void moveItemAfter(itemNode* prevItem, const string& listItem); //Moves node after given node; no increment

	void removeItem(const string& itemToRemove); //Removes node from list; decrements count

	void print(); //Prints item names with amount in list
	void printItem(const string& listItem); //Prints item you wish to print

	void sort(); //Sorts list in alphabetical order; uses insertion sorting algorithm

private:
	int count;
	itemNode* first;
	itemNode* last;
	itemNode* current;
};

#endif
