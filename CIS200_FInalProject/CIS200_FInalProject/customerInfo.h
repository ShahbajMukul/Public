#pragma once

#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H

#include <iostream>
#include <string>
using namespace std;

template<typename Type>
struct customerNode {
	Type customerInfo;
	customerNode<Type>* next = nullptr;
	customerNode<Type>* prev = nullptr;
};

template<typename Type>
class customerInfo {
public:
	customerInfo();
	~customerInfo();

	bool isItemAvailable(const Type& searchItem);
	customerNode<Type>* findItem(const Type& searchItem);

	void insertItemEnd(const Type& listItem);
	void insertItemStart(const Type& listItem);
	void insertItemAfter(customerNode<Type>* prevItem, const Type& listItem);

	void moveItemEnd(const Type& listItem);
	void moveItemStart(const Type& listItem);
	void moveItemAfter(customerNode<Type>* prevItem, const Type& listItem);
	void removeItem(const Type& itemToRemove);

	void print();
	void printItem(const Type& listItem);

	void sort();

private:
	int count;
	customerNode<Type>* first;
	customerNode<Type>* last;
	customerNode<Type>* current;
};

#endif
