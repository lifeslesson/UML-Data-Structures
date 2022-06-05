/* Nathan Dynice
   UML summer 2022
   Dr. M Geiger*/
   /* Program to obtain a users input of price, quantity, name of two seperate items and utilize class' to
      determing the output of totals*/

#include "ShoppingCart.h"
#include <string>
using namespace std;

void PrintMenu(ShoppingCart& ShopCart);

int main() {
    string nameOfCustomer, customerDate;

    // get user name and date
    cout << "Enter customer's name: " << endl;
    getline(cin, nameOfCustomer);
    cout << "Enter today's Date: " << endl;
    getline(cin, customerDate);

    //Output name and date
    cout << "\nCustomer name:" << nameOfCustomer << endl;
    cout << "Today's date:" << customerDate << endl;

    ShoppingCart  shopCart(nameOfCustomer, customerDate);
    PrintMenu(shopCart);
    cin.ignore();
    return 0;
}

void PrintMenu(ShoppingCart& cartItems) {
    string newItem, itemDescription;
    char userInput;
    double newItemPrice;
    int itemQuantity, i = 0, j = 0;

    while (i == 0) {
        cout << "\nMenu" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << "\n" << endl;
        j = 0;

        while (j == 0) {
            cout << "Choose an option:" << endl;
            cin >> userInput;
            cin.ignore();

            if (userInput == 'a' || userInput == 'A') {
                cout << "ADD ITEM TO CART" << endl;
                cout << "Enter the item name:" << endl;
                getline(cin, newItem);

                cout << "Enter the item description:" << endl;
                getline(cin, itemDescription);

                cout << "Enter the item price:" << endl;
                cin >> newItemPrice;
                cin.ignore();

                cout << "Enter the item quantity:" << endl;
                cin >> itemQuantity;

                ItemToPurchase shopCart(newItem, itemDescription, newItemPrice, itemQuantity);
                cartItems.AddItem(shopCart);
                ++j;
                cin.ignore();
            }

            else if (userInput == 'd' || userInput == 'D') {
                cout << "REMOVE ITEM FROM CART" << endl;
                cout << "Enter name of item to remove :" << endl;
                getline(cin, newItem);

                ItemToPurchase shopCart;
                shopCart.SetName(newItem);
                cartItems.RemoveItem(shopCart);
                ++j;
            }

            else if (userInput == 'c' || userInput == 'C') {
                cout << "CHANGE ITEM QUANTITY" << endl;
                cout << "Enter the item name:" << endl;
                getline(cin, newItem);

                cout << "Enter the new quantity:" << endl;
                cin >> itemQuantity;

                ItemToPurchase shopCart(newItem, itemDescription, newItemPrice, itemQuantity);
                cartItems.ModifyItem(shopCart);
                ++j;
            }

            else if (userInput == 'i' || userInput == 'I') {
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cout << cartItems.GetCustomerName() << "'s Shopping Cart - " << cartItems.GetDate() << endl;
                cout << "\nItem Descriptions" << endl;
                cartItems.PrintDescription();
                ++j;
            }

            else if (userInput == 'o' || userInput == 'O') {
                cout << "OUTPUT SHOPPING CART" << endl;
                cartItems.PrintTotal();
                ++j;
            }
            else if (userInput == 'q' || userInput == 'Q') {
                ++i;
                ++j;
            }
            else {
                j = 0;
            }
        }
    }
}