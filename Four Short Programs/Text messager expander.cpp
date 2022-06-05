/* Nathan Dynice
   Data Structures
   Summer 2022
   Dr. M Geiger */

   /* This program converts text short hand from them dang kids into normal human speak. XD */

#include <iostream>
#include <string>
using namespace std;


/* this function checks for and switches the shorthand to normal */
string AbreviationToNormal(string userInput) {
    int BFF, IDK, JK, TMI, TTYL;

    if ((userInput.find("BFF")) != string::npos) {
        BFF = (userInput.find("BFF"));
        userInput.replace(BFF, 3, "Best friend forever");

    }
    if ((userInput.find("IDK")) != string::npos) {
        IDK = (userInput.find("IDK"));
        userInput.replace(IDK, 3, "I don't know");

    }
    if ((userInput.find("JK")) != string::npos) {
        JK = (userInput.find("JK"));
        userInput.replace(JK, 2, "just kidding");
    }

    if ((userInput.find("TMI")) != string::npos) {
        TMI = (userInput.find("TMI"));
        userInput.replace(TMI, 3, "Too much information");
    }

    if ((userInput.find("TTYL")) != string::npos) {
        TTYL = (userInput.find("TTYL"));
        userInput.replace(TTYL, 4, "Talk to you later");
    }

    return userInput;

}

int main() {
    string userInput;
    string fixedText;

    cout << "Enter text:" << endl;
    getline(cin, userInput);

    cout << "You entered: " << userInput << endl;;

    fixedText = AbreviationToNormal(userInput);

    cout << "Expanded: " << fixedText << endl;


    return 0;
}