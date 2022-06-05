#include "ShoppingCart.h"
#include <string>
using namespace std;

ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string nameOfCustomer, string customerDate) {
	this->customerName = nameOfCustomer;
	this->currentDate = customerDate;
}

string ShoppingCart::GetCustomerName() {
	return customerName;
}
string ShoppingCart::GetDate() {
	return currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase& item) {
	cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(ItemToPurchase& item) {
	unsigned int i;

	for (i = 0; i < cartItems.size(); ++i) {
		if (cartItems.at(i).GetName() == item.GetName()) {
			cartItems.erase(cartItems.begin() + 1);
			return;
		}
	}
	cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::ModifyItem(ItemToPurchase& item) {
	unsigned int i;

	for (i = 0; i < cartItems.size(); ++i) {
		if (cartItems.at(i).GetName() == item.GetName()) {
			//cartItems.at(i).SetDescription(item.GetDescription());
			cartItems.at(i).SetQuantity(item.GetQuantity());
			return;
		}
		else {
			cout << "Item not found in cart. Nothing modified." << endl;
			return;
		}
	}
}

void ShoppingCart::PrintTotal() {
	unsigned int i, itemTotal = 0;

	cout << customerName << "'s Shopping Cart - " << currentDate << endl;
	for (i = 0; i < cartItems.size(); ++i) {
		itemTotal = itemTotal + cartItems.at(i).GetQuantity();
	}
	cout << "Number of Items: " << itemTotal << endl;
	cout << "\n";
	for (i = 0; i < cartItems.size(); ++i) {
		cartItems.at(i).PrintItemCost();
	}
	//itemTotal = itemTotal + cartItems.size();
	if (cartItems.size() == 0) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}

	cout << "\nTotal: $" << GetCostOfCart() << endl;
	return;
}

void ShoppingCart::PrintDescription() {
	unsigned int i;

	if (cartItems.size() == 0) {
		cout << "Shopping Cart is empty.";
	}
	else {
		for (i = 0; i < cartItems.size(); ++i) {
			cartItems.at(i).PrintItemDescription();
		}
	}
}
int ShoppingCart::GetNumItemsInCart() {
	unsigned int quantity = 0, i;

	for (i = 0; i < cartItems.size(); ++i) {
		quantity += cartItems.at(i).GetQuantity();
	}
	return quantity;
}
int ShoppingCart::GetCostOfCart() {
	unsigned int cartPrice = 0, i;

	for (i = 0; i < cartItems.size(); ++i) {

		cartPrice += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
	}
	return cartPrice;
}
