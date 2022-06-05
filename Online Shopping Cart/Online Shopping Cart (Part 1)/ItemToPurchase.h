#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    void SetName(string itemName);
    void SetPrice(double itemPrice);
    void SetQuantity(int itemQuantity);

    string GetName();
    double GetPrice();
    int GetQuantity();

private:
    string itemName;
    double itemPrice;
    int itemQuantity;
};


#endif