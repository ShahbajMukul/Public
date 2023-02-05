#include "time.h"
#include <iostream>
#include <string>
using namespace std;

storeTime::storeTime() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

storeTime::~storeTime() {
	while (first) {
		timeNode* next = first->next;
		delete first;
		first = next;
	}
}

bool storeTime::isItemAvailable(const string& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->time == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->time == searchItem);
	}

	return found;
}

timeNode* storeTime::findItem(const string& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->time == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

void storeTime::insertItemEnd(const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

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

void storeTime::insertItemStart(const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

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

void storeTime::insertItemAfter(timeNode* prevItem, const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

void storeTime::moveItemEnd(const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

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

void storeTime::moveItemStart(const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

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

void storeTime::moveItemAfter(timeNode* prevItem, const string& listItem) {
	timeNode* newItem;

	newItem = new timeNode;
	newItem->time = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

void storeTime::removeItem(const string& itemToRemove) {
	timeNode* nextItem;
	timeNode* prevItem;

	nextItem = new timeNode;
	nextItem = current->next;

	prevItem = new timeNode;
	prevItem = current->prev;

	current = new timeNode;
	current->time = itemToRemove;

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

void storeTime::print() {
	string todaysDate;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;

	while (current != nullptr) {
		cout << "Item: " << current->time << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
}

void storeTime::printItem(const string& listItem) {
	current = findItem(listItem);
	cout << current->time << endl;
}

void storeTime::sort() {
	current = first->next;
	timeNode* prevItem;
	timeNode* nextItem;

	prevItem = new timeNode;
	nextItem = new timeNode;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->time > current->time) {
			prevItem = prevItem->prev;
		}

		removeItem(current->time);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->time);
		}
		else {
			moveItemAfter(prevItem, current->time);
		}

		current = nextItem;
	}
}