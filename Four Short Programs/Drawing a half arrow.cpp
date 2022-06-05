/*Nathan Dynice
  Data Structures
  summer 2022
  Dr. M Geiger */

  /* Utilize a user input of integer value and export a vertical half of an arrow */
#include <iostream>
using namespace std;

int main() {
    int arrowBaseHeight;
    int arrowBaseWidth;
    int arrowHeadWidth;
    int i, j;

    cout << "Enter arrow base height:" << endl;
    cin >> arrowBaseHeight;

    cout << "Enter arrow base width:" << endl;
    cin >> arrowBaseWidth;

    cout << "Enter arrow head width:" << endl;
    cin >> arrowHeadWidth;

    while (arrowHeadWidth <= arrowBaseWidth) {
        cout << "Enter arrow head width:" << endl;
        cin >> arrowHeadWidth;
    }
    cout << endl;
    // Draw arrow base 
    for (i = 0; i < arrowBaseHeight; ++i) {
        for (j = 0; j < arrowBaseWidth; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Draw arrow head 
    for (i = arrowHeadWidth; i > 0; --i) {
        for (j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
