/*Nathan dynice
  summer 2022
  Data structure
  Dr. M Geiger */

  /* Program that takes a string input from user and outputs a menu the user chooses and then outputs the chosen results */
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

char PrintMenu(string);
int GetNumOfNonWSCharacters(string);
int GetNumOfWords(string);
int FindText(string, string);
void ReplaceExclamation(string&);
void ShortenSpace(string&);

// Prints the menu options in loop form, plus desired outputs from functions
char PrintMenu(string userInput) {
    char letterInput;
    string stringSearch;

    //ShortenSpace(userOut);
    //ReplaceExclamation(userOut);

    while (true) {
        //int spaceCount = 0;

        cout << "\nMENU" << endl;
        cout << "c - Number of non-whitespace characters" << endl;
        cout << "w - Number of words" << endl;
        cout << "f - Find text" << endl;
        cout << "r - Replace all !'s" << endl;
        cout << "s - Shorten spaces" << endl;
        cout << "q - Quit" << endl;
        cout << "\n";
        cout << "Choose an option:" << endl;
        cin >> letterInput;

        if (letterInput == 'q' || letterInput == 'Q') {
            return 0;
        }

        else if (letterInput == 'c' || letterInput == 'C') {
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userInput) << endl;
        }
        else if (letterInput == 'w' || letterInput == 'W') {
            cout << "Number of words: " << GetNumOfWords(userInput) << endl;
        }
        else if (letterInput == 'f' || letterInput == 'F') {
            cin.ignore();
            cout << "Enter a word or phrase to be found:" << endl;
            getline(cin, stringSearch);
            cout << "\"" << stringSearch << "\"" << " instances: " << FindText(stringSearch, userInput) << endl;
        }
        else if (letterInput == 'r' || letterInput == 'R') {
            ReplaceExclamation(userInput);
            cout << "Edited text: " << userInput << endl;
        }
        else if (letterInput == 's' || letterInput == 'S') {
            ShortenSpace(userInput);
            cout << "Edited text: " << userInput << endl;
        }
        else {
            cout << "Invalid choice you idiot" << endl;
        }
    }
    return 0;
}

// retrieves the users data and counts the number of non white characters
int GetNumOfNonWSCharacters(const string userInput) {
    int nonWhiteNum = 0, i, strLen;

    strLen = userInput.length();

    for (i = 0; i < strLen; ++i) {
        if (!isspace(userInput[i])) {
            ++nonWhiteNum;
        }
    }
    return nonWhiteNum;
}

// gets user data and counts the number of words
int GetNumOfWords(const string userInput) {
    int i, numWord = 0, strLen;

    strLen = userInput.length();

    for (i = 0; i < strLen; ++i) {
        if (isspace(userInput[i])) {
            while (isspace(userInput[i])) {
                ++i;
            }
            ++numWord;
        }
    }
    return numWord + 1;
}

// finds input text from user from their origional data and counts the times its used
int FindText(const string stringSearch, const string userInput) {
    int i = 0;

    if (stringSearch.length() == 0) {
        return 0;
    }

    for (size_t offset = userInput.find(stringSearch); offset != string::npos;
        offset = userInput.find(stringSearch, offset + stringSearch.length())) {
        ++i;
    }
    return i;
}
// replaces ! with .
void ReplaceExclamation(string& replace) {
    int i, len = replace.length();
    string newOutPut = replace;


    for (i = 0; i < len; ++i) {
        if (replace.at(i) == '!') {
            newOutPut.at(i) = '.';
        }
    }
    replace = newOutPut;
}

//shortens the number of spaces if there are to many in a row to 1
void ShortenSpace(string& space) {
    char* newOutPut;
    int i, j = 0, len = space.length();
    newOutPut = new char[len + 1];

    for (i = 0; i < len; ++j) {
        newOutPut[j] = space[i];

        if (isspace(space[i])) {
            while (isspace(space[i])) {
                ++i;
            }
        }
        else {
            ++i;
        }
    }
    newOutPut[j] = '\0';
    space = newOutPut;
}


int main() {
    string userInput, stringSearch;

    cout << "Enter a sample text:\n" << endl;
    getline(cin, userInput);
    cout << "You entered: " << userInput << endl;

    //ReplaceExclamation(userInput);
    //ShortenSpace(userInput);
    PrintMenu(userInput);


    return 0;
}