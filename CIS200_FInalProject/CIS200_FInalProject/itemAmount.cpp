#include "itemAmount.h"
#include <iostream>
#include <string>
using namespace std;

itemAmount::itemAmount() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

itemAmount::~itemAmount() {
	while (first) {
		amtNode* next = first->next;
		delete first;
		first = next;
	}
}

bool itemAmount::isItemAvailable(const int& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->itemAmount == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->itemAmount == searchItem);
	}

	return found;
}

amtNode* itemAmount::findItem(const int& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->itemAmount == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

void itemAmount::insertItemEnd(const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

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

void itemAmount::insertItemStart(const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

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

void itemAmount::insertItemAfter(amtNode* prevItem, const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

void itemAmount::returnItems(const int& listItem, const int& amountToReturn) {
	current = findItem(listItem);
	current->itemAmount += amountToReturn;
}

void itemAmount::moveItemEnd(const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

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

void itemAmount::moveItemStart(const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

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

void itemAmount::moveItemAfter(amtNode* prevItem, const int& listItem) {
	amtNode* newItem;

	newItem = new amtNode;
	newItem->itemAmount = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

void itemAmount::removeItem(const int& itemToRemove) {
	amtNode* nextItem;
	amtNode* prevItem;

	nextItem = new amtNode;
	nextItem = current->next;

	prevItem = new amtNode;
	prevItem = current->prev;

	current = new amtNode;
	current->itemAmount = itemToRemove;

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

void itemAmount::checkoutItem(const int& listItem, const int& amountBought) {
	current = findItem(listItem);

	if (amountBought < current->itemAmount) {
		current->itemAmount -= amountBought;
	}
}

void itemAmount::print() {
	string todaysDate;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;

	while (current != nullptr) {
		cout << "Item: " << current->itemAmount << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
}

void itemAmount::printItem(const int& listItem) {
	current = findItem(listItem);
	cout << current->itemAmount << endl;
}

void itemAmount::sort() {
	current = first->next;
	amtNode* prevItem;
	amtNode* nextItem;

	prevItem = new amtNode;
	nextItem = new amtNode;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->itemAmount > current->itemAmount) {
			prevItem = prevItem->prev;
		}

		removeItem(current->itemAmount);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->itemAmount);
		}
		else {
			moveItemAfter(prevItem, current->itemAmount);
		}

		current = nextItem;
	}
}