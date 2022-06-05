#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {

}

void ItemToPurchase::SetName(string itemName) {
    ItemToPurchase::itemName = itemName;
}

void ItemToPurchase::SetPrice(double itemPrice) {
    ItemToPurchase::itemPrice = itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
    ItemToPurchase::itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() {
    return itemName;
}

double ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}