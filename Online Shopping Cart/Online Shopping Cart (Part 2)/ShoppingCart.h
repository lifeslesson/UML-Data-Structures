#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart
{
public:
	ShoppingCart();
	ShoppingCart(string nameOfCustomer, string customerDate);

	string GetCustomerName();
	string GetDate();
	void AddItem(ItemToPurchase& item);
	void RemoveItem(ItemToPurchase& item);
	void ModifyItem(ItemToPurchase& item);
	void PrintTotal();
	void PrintDescription();
	int GetNumItemsInCart();
	int GetCostOfCart();

private:
	string customerName;
	string currentDate;
	vector <ItemToPurchase> cartItems;
};
#endif // !SHOPPING_CART_H
