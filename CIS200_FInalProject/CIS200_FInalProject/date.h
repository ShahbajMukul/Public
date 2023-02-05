#pragma once

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

struct dateNode {
	string date;
	dateNode* next = nullptr;
	dateNode* prev = nullptr;
};

class date {
public:
	date();
	~date();

	bool isItemAvailable(const string& searchItem);
	dateNode* findItem(const string& searchItem);

	void insertItemEnd(const string& listItem);
	void insertItemStart(const string& listItem);
	void insertItemAfter(dateNode* prevItem, const string& listItem);

	void moveItemEnd(const string& listItem);
	void moveItemStart(const string& listItem);
	void moveItemAfter(dateNode* prevItem, const string& listItem);
	void removeItem(const string& itemToRemove);

	void print();
	void printItem(const string& listItem);

	void sort();

private:
	int count;
	dateNode* first;
	dateNode* last;
	dateNode* current;
};

#endif