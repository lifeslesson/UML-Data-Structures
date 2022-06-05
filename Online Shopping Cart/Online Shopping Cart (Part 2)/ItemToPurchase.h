#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <iostream>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string newItemName, string newItemDescription, double newItemPrice, int newItemQuantity = 0);

    void SetName(string itemName);
    void SetPrice(double itemPrice);
    void SetQuantity(int itemQuantity);
    void SetDescription(string itemDescription);
    void PrintItemCost();
    void PrintItemDescription();

    string GetName();
    string GetDescription();
    double GetPrice();
    int GetQuantity();

private:
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
};


#endif