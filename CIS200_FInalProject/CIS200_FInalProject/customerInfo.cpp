#include "customerInfo.h"
#include <iostream>
#include <string>
using namespace std;

template<typename Type>
customerInfo<Type>::customerInfo() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<typename Type>
customerInfo<Type>::~customerInfo() {
	while (first) {
		customerNode<Type>* next = first->next;
		delete first;
		first = next;
	}
}

template<typename Type>
bool customerInfo<Type>::isItemAvailable(const Type& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->customerInfo == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->customerInfo == searchItem);
	}

	return found;
}

template<typename Type>
customerNode<Type>* customerInfo<Type>::findItem(const Type& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->customerInfo == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

template<typename Type>
void customerInfo<Type>::insertItemEnd(const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
		count++;
	}
	else {
		last->next = newItem;
		newItem->prev = last;
		last = newItem;
		count++;
	}
}

template<typename Type>
void customerInfo<Type>::insertItemStart(const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
		count++;
	}
	else {
		newItem->next = first;
		first->prev = newItem;
		first = newItem;
		count++;
	}
}

template<typename Type>
void customerInfo<Type>::insertItemAfter(customerNode<Type>* prevItem, const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

template<typename Type>
void customerInfo<Type>::moveItemEnd(const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
	}
	else {
		last->next = newItem;
		newItem->prev = last;
		last = newItem;
	}
}

template<typename Type>
void customerInfo<Type>::moveItemStart(const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	if (first == nullptr) {
		first = newItem;
		last = newItem;
	}
	else {
		newItem->next = first;
		first->prev = newItem;
		first = newItem;
	}
}

template<typename Type>
void customerInfo<Type>::moveItemAfter(customerNode<Type>* prevItem, const Type& listItem) {
	customerNode<Type>* newItem;

	newItem = new customerNode<Type>;
	newItem->customerInfo = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

template<typename Type>
void customerInfo<Type>::removeItem(const Type& itemToRemove) {
	customerNode<Type>* nextItem;
	customerNode<Type>* prevItem;

	nextItem = new customerNode<Type>;
	nextItem = current->next;

	prevItem = new customerNode<Type>;
	prevItem = current->prev;

	current = new customerNode<Type>;
	current->customerInfo = itemToRemove;

	if (nextItem != nullptr) {
		nextItem->prev = prevItem;
	}

	if (prevItem != nullptr) {
		prevItem->next = nextItem;
	}

	if (current == first) {
		first = nextItem;
	}

	if (current == last) {
		last = prevItem;
	}

	count--;
}

template<typename Type>
void customerInfo<Type>::print() {
	string todayscustomerInfo;

	current = first;
	cout << "Enter today's customerInfo: ";
	cin >> todayscustomerInfo;

	while (current != nullptr) {
		cout << "Item: " << current->customerInfo << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's customerInfo: " << todayscustomerInfo << endl;
}

template<typename Type>
void customerInfo<Type>::printItem(const Type& listItem) {
	current = findItem(listItem);
	cout << current->customerInfo << endl;
}

template<typename Type>
void customerInfo<Type>::sort() {
	current = first->next;
	customerNode<Type>* prevItem;
	customerNode<Type>* nextItem;

	prevItem = new customerNode<Type>;
	nextItem = new customerNode<Type>;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->customerInfo > current->customerInfo) {
			prevItem = prevItem->prev;
		}

		removeItem(current->customerInfo);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->customerInfo);
		}
		else {
			moveItemAfter(prevItem, current->customerInfo);
		}

		current = nextItem;
	}
}