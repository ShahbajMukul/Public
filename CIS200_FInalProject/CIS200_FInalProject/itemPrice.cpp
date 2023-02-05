#include "itemPrice.h"
#include <iostream>
#include <string>
using namespace std;

itemPrice::itemPrice() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

itemPrice::~itemPrice() {
	while (first) {
		priceNode* next = first->next;
		delete first;
		first = next;
	}
}

bool itemPrice::isItemAvailable(const float& searchItem) {
	bool found = false;

	current = first;
	while (current != nullptr && !found) {
		if (current->itemPrice == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->itemPrice == searchItem);
	}

	return found;
}

priceNode* itemPrice::findItem(const float& searchItem) {
	current = first;
	while (current != nullptr) {
		if (current->itemPrice == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

void itemPrice::insertItemEnd(const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

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

void itemPrice::insertItemStart(const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

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

void itemPrice::insertItemAfter(priceNode* prevItem, const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

void itemPrice::moveItemEnd(const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

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

void itemPrice::moveItemStart(const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

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

void itemPrice::moveItemAfter(priceNode* prevItem, const float& listItem) {
	priceNode* newItem;

	newItem = new priceNode;
	newItem->itemPrice = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

void itemPrice::removeItem(const float& itemToRemove) {
	priceNode* nextItem;
	priceNode* prevItem;

	nextItem = new priceNode;
	nextItem = current->next;

	prevItem = new priceNode;
	prevItem = current->prev;

	current = new priceNode;
	current->itemPrice = itemToRemove;

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

void itemPrice::print() {
	string todaysDate;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;

	while (current != nullptr) {
		cout << "Item: " << current->itemPrice << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
}

void itemPrice::printItem(const float& listItem) {
	current = findItem(listItem);
	cout << current->itemPrice << endl;
}

void itemPrice::sort() {
	current = first->next;
	priceNode* prevItem;
	priceNode* nextItem;

	prevItem = new priceNode;
	nextItem = new priceNode;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->itemPrice > current->itemPrice) {
			prevItem = prevItem->prev;
		}

		removeItem(current->itemPrice);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->itemPrice);
		}
		else {
			moveItemAfter(prevItem, current->itemPrice);
		}

		current = nextItem;
	}
}