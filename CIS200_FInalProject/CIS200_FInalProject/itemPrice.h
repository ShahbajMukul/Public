#pragma once

#ifndef ITEMPRICE_H
#define ITEMPRICE_H

#include <iostream>
#include <string>
using namespace std;

struct priceNode {
	float itemPrice;
	priceNode* next = nullptr;
	priceNode* prev = nullptr;
};

class itemPrice {
public:
	itemPrice();
	~itemPrice();

	bool isItemAvailable(const float& searchItem);
	priceNode* findItem(const float& searchItem);

	void insertItemEnd(const float& listItem);
	void insertItemStart(const float& listItem);
	void insertItemAfter(priceNode* prevItem, const float& listItem);

	void moveItemEnd(const float& listItem);
	void moveItemStart(const float& listItem);
	void moveItemAfter(priceNode* prevItem, const float& listItem);
	void removeItem(const float& itemToRemove);

	void print();
	void printItem(const float& listItem);

	void sort();

private:
	int count;
	priceNode* first;
	priceNode* last;
	priceNode* current;
};

#endif


