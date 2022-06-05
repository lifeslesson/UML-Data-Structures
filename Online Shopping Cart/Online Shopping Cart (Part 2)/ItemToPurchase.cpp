#include "ItemToPurchase.h"

#include <string>
using namespace std;



ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string newItemName, string NewItemDescription, double newItemPrice, int newItemQuantity) {
    itemName = newItemName;
    itemDescription = NewItemDescription;
    itemPrice = newItemPrice;
    itemQuantity = newItemQuantity;
}


void ItemToPurchase::SetName(string newItemName) {
    itemName = newItemName;
}

void ItemToPurchase::SetDescription(string newItemDescription) {
    itemDescription = newItemDescription;
}

void ItemToPurchase::SetPrice(double newItemPrice) {
    itemPrice = newItemPrice;
}

void ItemToPurchase::SetQuantity(int newItemQuantity) {
    itemQuantity = newItemQuantity;
}




void ItemToPurchase::PrintItemCost() {
    double itemTotalCost;

    itemTotalCost = itemQuantity * itemPrice;
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemTotalCost << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ":" << itemDescription << endl;
}

string ItemToPurchase::GetName() {
    return itemName;
}
string ItemToPurchase::GetDescription() {
    return itemDescription;
}

double ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}
