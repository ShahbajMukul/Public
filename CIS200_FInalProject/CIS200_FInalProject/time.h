#pragma once

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
using namespace std;

struct timeNode {
	string time;
	timeNode* next = nullptr;
	timeNode* prev = nullptr;
};

class storeTime {
public:
	storeTime();
	~storeTime();

	bool isItemAvailable(const string& searchItem);
	timeNode* findItem(const string& searchItem);

	void insertItemEnd(const string& listItem);
	void insertItemStart(const string& listItem);
	void insertItemAfter(timeNode* prevItem, const string& listItem);

	void moveItemEnd(const string& listItem);
	void moveItemStart(const string& listItem);
	void moveItemAfter(timeNode* prevItem, const string& listItem);
	void removeItem(const string& itemToRemove);

	void print();
	void printItem(const string& listItem);

	void sort();

private:
	int count;
	timeNode* first;
	timeNode* last;
	timeNode* current;
};

#endif
