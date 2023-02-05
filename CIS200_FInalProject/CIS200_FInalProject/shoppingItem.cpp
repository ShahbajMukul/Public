#include "shoppingItem.h"
#include <iostream>
#include <string>
using namespace std;

shoppingItem::shoppingItem() {
	first = nullptr;
	last = nullptr;
	count = 0;
}

shoppingItem::~shoppingItem() {
	while (first) {
		itemNode* next = first->next;
		delete first;
		first = next;
	}
}

bool shoppingItem::isItemAvailable(const string& searchItem) {
	bool found = false; //Current points to first node in list and iterates through each list until
						//item is found (or not, thats fine too)

	current = first;
	while (current != nullptr && !found) {
		if (current->shoppingItem == searchItem) {
			found = true;
		}
		else {
			current = current->next;
		}
	}

	if (found) {
		found = (current->shoppingItem == searchItem);
	}

	return found;
}

itemNode* shoppingItem::findItem(const string& searchItem) {
	current = first; //Returns the node that was found that you were looking for
	while (current != nullptr) {
		if (current->shoppingItem == searchItem) {
			return current;
		}
		else {
			current = current->next;
		}
	}
	return nullptr;
}

void shoppingItem::insertItemEnd(const string& listItem) {
	itemNode* newItem; //Inserts item at end of list and increments count

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

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

void shoppingItem::insertItemStart(const string& listItem) {
	itemNode* newItem; //Inserts item at beginning of list; increments count

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

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

void shoppingItem::insertItemAfter(itemNode* prevItem, const string& listItem) {
	itemNode* newItem;

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}

	count++;
}

void shoppingItem::moveItemEnd(const string& listItem) {
	itemNode* newItem;

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

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

void shoppingItem::moveItemStart(const string& listItem) {
	itemNode* newItem;

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

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

void shoppingItem::moveItemAfter(itemNode* prevItem, const string& listItem) {
	itemNode* newItem;

	newItem = new itemNode;
	newItem->shoppingItem = listItem;

	newItem->next = prevItem->next;
	prevItem->next = newItem;
	newItem->prev = prevItem;

	if (newItem->next != nullptr) {
		newItem->next->prev = newItem;
	}
}

void shoppingItem::removeItem(const string& itemToRemove) {
	itemNode* nextItem;
	itemNode* prevItem;

	nextItem = new itemNode;
	nextItem = current->next;

	prevItem = new itemNode;
	prevItem = current->prev;

	current = new itemNode;
	current->shoppingItem = itemToRemove;

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

void shoppingItem::print() {
	string todaysDate;

	current = first;
	cout << "Enter today's date: ";
	cin >> todaysDate;

	while (current != nullptr) {
		cout << "Item: " << current->shoppingItem << endl;
		cout << "-------------------------------------------" << endl;
		current = current->next;
	}

	cout << "Amount total: " << count << endl;
	cout << "Today's date: " << todaysDate << endl;
}

void shoppingItem::printItem(const string& listItem) {
	current = findItem(listItem);
	cout << current->shoppingItem << endl;
}

void shoppingItem::sort() {
	current = first->next;
	itemNode* prevItem;
	itemNode* nextItem;

	prevItem = new itemNode;
	nextItem = new itemNode;

	while (current != nullptr) {
		nextItem = current->next;
		prevItem = current->prev;

		while (prevItem != nullptr && prevItem->shoppingItem > current->shoppingItem) {
			prevItem = prevItem->prev;
		}

		removeItem(current->shoppingItem);
		count++;

		if (prevItem == nullptr) {
			current->prev = nullptr;
			moveItemStart(current->shoppingItem);
		}
		else {
			moveItemAfter(prevItem, current->shoppingItem);
		}

		current = nextItem;
	}
}