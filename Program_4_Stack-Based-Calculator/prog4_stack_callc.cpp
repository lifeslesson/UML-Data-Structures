#include "Stack.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void infixToPostfixCalc(string userInput);
int PEMDAS(char val);

int main() {
	string userInput;


	do {
		cout << "Enter expression (or exit to end): " << endl;
		getline(cin, userInput);

		if (userInput == "exit") {
			cout << "Exiting program ..." << endl;
			break;
		}
		else if (userInput[0] == '(') {
			infixToPostfixCalc(userInput);
		}
		else if (isdigit(userInput[0])) {
			infixToPostfixCalc(userInput);
		}
		else {
			cout << "Invalid expression" << endl;
		}
	} while (1);
}

int PEMDAS(char val) {
	if (val == '*' || val == '/') {
		return 1;
	}
	else if (val == '+' || val == '-') {
		return 2;
	}
	else {
		return 3;
	}
}

bool checkOP(char opReq) {
	switch (opReq) {
	case '*':
	case '+':
	case '/':
	case '-':
		return true;
	}
	return false;
}

bool OrderOpCheck(char firstVal, char secondVal) {
	int v1, v2;

	v1 = PEMDAS(firstVal);
	v2 = PEMDAS(secondVal);

	if (v1 == v2) {
		return true;
	}
	if (v1 > v2) {
		return true;
	}
	return false;
}

void infixToPostfixCalc(string userInput) {
	Stack<char> tempPost;
	string postFix = "";
	char tempChar;

	for (unsigned int i = 0; i < userInput.length(); ++i) {
		tempChar = userInput[i];

		if (tempChar == '(') {
			tempPost.push(tempChar);
		}
		if (isalnum(tempChar)) {
			postFix += tempChar;
			postFix += ' ';
		}
		if (checkOP(tempChar)) {
			while (!tempPost.empty() && OrderOpCheck(tempChar, tempPost.getTop())) {
				postFix += tempPost.getTop();
				tempPost.pop();
			}
			tempPost.push(tempChar);
		}
		else if (tempChar == ')') {
			while (!tempPost.empty() && tempPost.getTop() != '(') {
				postFix += tempPost.getTop();
				tempPost.pop();
				postFix += ' ';
			}
			tempPost.pop();
		}
	}
	while (!tempPost.empty()) {
		postFix += tempPost.getTop();
		tempPost.pop();
		postFix += ' ';
	}
	cout << "Expression: " << userInput << endl;
	cout << "Postfix form: " << postFix << endl;


	Stack<int> numToCalc;
	int x, y, solution, tempSolution, stringToInt;

	for (unsigned int i = 0; i < postFix.size(); ++i) {
		if (isdigit(postFix[i])) {
			stringToInt = postFix[i];
			stringToInt = stringToInt - 48;
			numToCalc.push(stringToInt);
		}
		if (checkOP(postFix[i])) {
			y = numToCalc.getTop();
			numToCalc.pop();
			x = numToCalc.getTop();
			numToCalc.pop();

			if (postFix[i] == '+') {
				tempSolution = x + y;
				numToCalc.push(tempSolution);
			}
			if (postFix[i] == '-') {
				tempSolution = x - y;
				numToCalc.push(tempSolution);
			}
			if (postFix[i] == '*') {
				tempSolution = x * y;
				numToCalc.push(tempSolution);
			}
			if (postFix[i] == '/') {
				tempSolution = x / y;
				numToCalc.push(tempSolution);
			}
		}
	}
	solution = numToCalc.getTop();
	cout << "Result: " << solution << endl;
}