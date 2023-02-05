#include "date.h"
#include <iostream>
#include <string>
using namespace std;

date::date() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

date::~date() {
	while (first) {
		dateNode* next = first->next;
		delete first;
		first = next;
	}
}

bool date::isItemAvailable(const string& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->date == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->date == searchItem);
	}

	return found;
}

dateNode* date::findItem(const string& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->date == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

void date::insertItemEnd(const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

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

void date::insertItemStart(const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

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

void date::insertItemAfter(dateNode* prevItem, const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

void date::moveItemEnd(const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

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

void date::moveItemStart(const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

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

void date::moveItemAfter(dateNode* prevItem, const string& listItem) {
	dateNode* newItem;

	newItem = new dateNode;
	newItem->date = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

void date::removeItem(const string& itemToRemove) {
	dateNode* nextItem;
	dateNode* prevItem;

	nextItem = new dateNode;
	nextItem = current->next;

	prevItem = new dateNode;
	prevItem = current->prev;

	current = new dateNode;
	current->date = itemToRemove;

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

void date::print() {
	string todaysDate;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;

	while (current != nullptr) {
		cout << "Item: " << current->date << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
}

void date::printItem(const string& listItem) {
	current = findItem(listItem);
	cout << current->date << endl;
}

void date::sort() {
	current = first->next;
	dateNode* prevItem;
	dateNode* nextItem;

	prevItem = new dateNode;
	nextItem = new dateNode;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->date > current->date) {
			prevItem = prevItem->prev;
		}

		removeItem(current->date);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->date);
		}
		else {
			moveItemAfter(prevItem, current->date);
		}

		current = nextItem;
	}
}