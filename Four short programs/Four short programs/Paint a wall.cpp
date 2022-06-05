/* Nathan Dynice Data
   Data Structures
   Dr. M Geiger*/
   /* This program determins the area of a wall from user input Hight and Widths, determines the amount of paint
      needed to cover the wall, and the amount of cans required based on that paint usage*/

#include <iostream>
#include <cmath>                  // Note: Needed for math functions in part (3)
#include <iomanip>
using namespace std;

int main() {
    double wallHeight;
    double wallWidth;
    double wallArea;
    double paintArea;
    double paintCans;
    const double paintGallonSqFt = 350;


    cout << "Enter wall height (feet):" << endl;
    cin >> wallHeight;

    cout << "Enter wall width (feet):" << endl;
    cin >> wallWidth;

    // Calculate and output wall area
    wallArea = wallHeight * wallWidth;
    cout << fixed << setprecision(2) << "Wall area: " << wallArea << " square feet" << endl;

    //Calculate and output the amount of paint in gallons needed to paint the wall
    paintArea = wallArea / paintGallonSqFt;
    cout << fixed << setprecision(2) << "Paint needed: " << paintArea << " gallons" << endl;

    //Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
    paintCans = round(paintArea);
    cout << setprecision(0) << "Cans needed: " << paintCans << " can(s)" << endl;


    return 0;
}