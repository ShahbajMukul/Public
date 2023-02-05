#pragma once

#ifndef ITEMAMOUNT_H
#define ITEMAMOUNT_H

#include <iostream>
#include <string>
using namespace std;

struct amtNode {
	int itemAmount;
	amtNode* next = nullptr;
	amtNode* prev = nullptr;
};


class itemAmount {
public:
	itemAmount();
	~itemAmount();

	bool isItemAvailable(const int& searchItem);
	amtNode* findItem(const int& searchItem);

	void insertItemEnd(const int& listItem);
	void insertItemStart(const int& listItem);
	void insertItemAfter(amtNode* prevItem, const int& listItem);
	void returnItems(const int& listItem, const int& amountToReturn);

	void moveItemEnd(const int& listItem);
	void moveItemStart(const int& listItem);
	void moveItemAfter(amtNode* prevItem, const int& listItem);
	void removeItem(const int& itemToRemove);
	void checkoutItem(const int& listItem, const int& amountBought);

	void print();
	void printItem(const int& listItem);

	void sort();

private:
	int count;
	amtNode* first;
	amtNode* last;
	amtNode* current;
};

#endif
