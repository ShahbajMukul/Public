#include "shoppingItem.h"
#include "itemPrice.h"
#include "itemAmount.h"
#include "date.h"
#include "time.h"
#include "customerInfo.h"

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	shoppingItem groceryItems;
	itemPrice prices;
	itemAmount amtInStock;
	date storeDates;
	storeTime storeTimes;
	char changeKey;
	int menuSelection1;
	int menuSelection2;

	map<string, float> itemAndPrice;
	itemAndPrice.emplace("Milk", 5.40);
	cout << itemAndPrice.at("Milk") << endl;




	do {
		cout << "Welcome! Press \"a\" to take action or \"q\" to quit: " << endl;
		cin >> changeKey;

		if (changeKey == 'a') {
			cout << "Please select the number of what you would like to access: " << endl;
			cout << " 1. Inventory items by name" << endl;
			cout << " 2. Prices" << endl;
			cout << " 3. Amount in stock" << endl;
			cout << " 4. Dates" << endl;
			cout << " 5. Times" << endl;
			cout << " 6. Customer information" << endl;
			cin >> menuSelection1;

			cout << "Please select the number of what action you would like to take: " << endl;
			cout << " 1. Check to see if an item is in the list (does not work for empty lists)" << endl;
			cout << " 2. Return item(s)" << endl;
			cout << " 3. Checkout item(s)" << endl;
			cout << " 4. Display items/information" << endl;
			cin >> menuSelection2;

			if (menuSelection1 == 1) {
				if (menuSelection2 == 1) {
					cout << "Is item in list?" << endl;
					bool doesItemExist = groceryItems.isItemAvailable("Milk");

					if (doesItemExist) {
						cout << "Yes, the item does exist." << endl;
					}
					else {
						cout << "No, the item does NOT exist." << endl;
					}
				}
				else if (menuSelection2 == 2) {

				}
			}
		}
	} while (changeKey != 'q');

	amtInStock.insertItemStart(4);
	amtInStock.insertItemEnd(3);
	amtInStock.insertItemEnd(3);
	amtInStock.insertItemEnd(5);
	amtInStock.checkoutItem(5, 4);

	amtInStock.sort();
	amtInStock.print();


	customerInfo<string> customerNames;
	customerNames.insertItemStart("Rhea");
	customerNames.insertItemEnd("Rhonda");
	customerNames.insertItemEnd("Byan");
	customerNames.insertItemEnd("Amal");

	customerNames.sort();
	customerNames.print();



	groceryItems.insertItemStart("Milk");
	groceryItems.insertItemEnd("Eggs");
	groceryItems.insertItemEnd("Apples");
	groceryItems.insertItemEnd("Frozen Vegetables");
	groceryItems.insertItemAfter(groceryItems.findItem("Eggs"), "Frozen Beef");
	groceryItems.removeItem("Eggs");

	groceryItems.sort();
	groceryItems.print();
	cout << "***************************************************" << endl;



	prices.insertItemStart(5.40);
	prices.insertItemEnd(3.14);
	prices.insertItemEnd(6.30);
	prices.insertItemEnd(11.06);
	
	prices.insertItemAfter(prices.findItem(6.30), 4.50);
	prices.removeItem(3.14);

	prices.sort();
	prices.print();

	return 0;
}