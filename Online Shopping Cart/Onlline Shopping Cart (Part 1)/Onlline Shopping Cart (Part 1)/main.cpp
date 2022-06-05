/* Nathan Dynice
   UML summer 2022
   Dr. M Geiger*/
   /* Program to obtain a users input of price, quantity, name of two seperate items and utilize class' to
      determing the output of totals*/

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
    ItemToPurchase firstItem, secondItem;
    string itemName;
    int totalPrice, item1Price, item2Price, itemQuantity;
    double itemPrice;


    // obtain input from user on the first item, price, and quantity of item
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, itemName);
    cout << "Enter the item price:" << endl;
    cin >> itemPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity;

    firstItem.SetName(itemName);
    firstItem.SetPrice(itemPrice);
    firstItem.SetQuantity(itemQuantity);
    cin.ignore();

    // optain the users input on the second item name, price, quantity
    cout << "\nItem 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, itemName);
    cout << "Enter the item price:" << endl;
    cin >> itemPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity;

    secondItem.SetName(itemName);
    secondItem.SetPrice(itemPrice);
    secondItem.SetQuantity(itemQuantity);
    cin.ignore();

    // optain the total prices for the items
    item1Price = firstItem.GetPrice() * firstItem.GetQuantity();
    item2Price = secondItem.GetPrice() * secondItem.GetQuantity();

    totalPrice = item1Price + item2Price;

    // output for the total cost
    cout << "\nTOTAL COST" << endl;
    // first items price and info output
    cout << firstItem.GetName() << " " << firstItem.GetQuantity() << " @ $" << firstItem.GetPrice() << " = $"
        << item1Price << endl;

    // second items price and info output
    cout << secondItem.GetName() << " " << secondItem.GetQuantity() << " @ $" << secondItem.GetPrice() << " = $"
        << item2Price << endl;

    // total cost of both items 
    cout << "\nTotal: $" << totalPrice << endl;

    return 0;
}