
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


		infixToPostfixCalc(userInput);

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



	//tempPost.push('(');
	//userInput += ')';

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
	string tempPostFix = postFix;
	int tempNum, solution = 0, num1, num2;;
	for (unsigned int i = 0; i < tempPostFix.size(); ++i) {
		if (ispunct(tempPostFix[i])) {
			num1 = tempPostFix[i - 2];
			num2 = tempPostFix[i - 1];

			if (tempPostFix[i] == '+') {
				tempNum = num1 + num2;
			}
			else if (tempPostFix[i] == '-') {
				tempNum = num1 - num2;
			}
			else if (tempPostFix[i] == '*') {
				tempNum = num1 * num2;
			}
			else if (tempPostFix[i] == '/') {
				tempNum = num1 / num2;
			}
		}
		//tempPostFix.erase(tempPostFix[i-2], tempPostFix[i]);
		solution = solution + tempNum;
	}

	cout << "infix: " << userInput << endl;
	cout << "Postfix: " << postFix << endl;
	cout << "solution: " << solution << endl;
}



















/*
#include "Stack.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string infixToPostfixCalc(string userInput);
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

		cout << "infix: " << userInput << endl;
		cout << "Postfix: " << infixToPostfixCalc(userInput) << endl;
		//	cout << "Solution: " << solution << endl;

	} while (userInput != "exit");



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
	return 0;
}


string infixToPostfixCalc(string userInput) {
	Stack<char> tempPost;
	string postFix = "";
	char tempChar;

	//tempPost.push('(');
	//userInput += ')';

	for (unsigned int i = 0; i < userInput.length(); ++i) {
		tempChar = userInput[i];

		if (tempChar == ' ') {
			tempPost.push(tempChar);
		}
		else if (tempChar == '(') {
			tempPost.push(tempChar);
		}
		else if (isalnum(tempChar)) {
			postFix += tempChar;
			postFix += ' ';
		}
		else if (ispunct(tempChar)) {
			if (tempChar == '+' || tempChar == '-' || tempChar == '*' || tempChar == '/') {
				while (!tempPost.empty() && (PEMDAS(tempChar) >= PEMDAS(tempPost.getTop()))) {
					postFix += tempPost.getTop();
					tempPost.pop();
				}
				tempPost.push(tempChar);
			}
		}
		else if (tempChar == ')') {
			while (!tempPost.empty() && tempPost.getTop() != '(') {
				postFix += tempPost.getTop();
				tempPost.pop();
			}
			tempPost.pop();
		}
	}
	return postFix;
}


int Calculate(string infixToPostfixCalc(string userInput)) {
	string tempNum;
	int num;

	tempNum = infixToPostfixCalc(string userInput);

		while (1) {
			for (int i = 0; i < tempNum.size(); i++) {
				if (isdigit(tempNum)) {

				}

			}
		}


	for (int i = 0; i < postfixNotation; ++i) {

	}
}





vector<char> userInputConstructor;
vector<int> userInputNum;
vector<string> postFix;
vector<string> inFix;
int i;

do {
	cout << "Enter expression (or exit to end): ";
	getline(cin, userInput);

	while (1) {
		userInput.pop(i);
	}








	if (isdigit(userInput[0]) || userInput[0] == '(' || userInput[0] != 'e') {
		if (userInput[i] == 'exit') {
			cout << "Exiting program ..." << endl;
			break;
		}
	}


	for (i = 0; i < userInput.size(); ++i) {
		if (userInput[i] == '(' || userInput[i] == ')') {
		}
		if (isdigit(userInput[i])) {
			userInputNum.push([i]);
		}
		else {
			userInputConstructor.push(userInput[i]);
		}
	}

	postFix = userInputNum + userInputConstructor;

} while (userInput[i] != 'exit');

			else if (isspace(userInput[i])) {
			prefix.push(' ');
			++spaceCount;
			}


			if (isdigit(userInput[i])) {
					postfix.push(userInput[i]);
				}

				if (ispunct(userInput[i])) {
					if (ispunct(userInput[i]) == '(') {
						operators.push(userInput[i]);
					}
				}





string convert(string infix) {
	stack stk;
	string postfix = "";

	stk.push('(');

	int count = 0;
	for(int i=0; i<infix.size(); i++) {
		if(isalpha(infix[i]))
		count++;
	}

	infix = infix + ")";

	for(int i=0; i<infix.size(); i++; {
		char ch = infix[i];

		if(ch==' ') continue;

		if(isalpha(ch)){
			postfix = postfix + " " + ch;
		}
		else if(ch=='(') {
			stk.push('(');
		}
		else if(ch==')') {
			while(stk.peek()!='('){
				postfix = postfix + " " + stk.pop();
			}
			stk.pop();
		}
		else {
			int p1 = precedence(ch);
			int p2 = precedence(stk.peek());
		}
	}

	while(p1<=p2) {
		postfix = postfix + " " + stk.pop();
		p2=precedence(stk.peek());
	}
	stk.push(ch);

	return postfix;




















	if (isalnum(userInput[i])) {
			infPostFix += userInput[i];
		}
		if (userInput[i] == '(') {
			temp.push('(');
		}
		else if (userInput[i] == ')') {
			do {
				tempString = temp.getTop();
				temp.pop();
			} while (temp.getTop() != '(');
		}
		else {
			do {
				tempString = temp.getTop();
				infPostFix += tempString;
				temp.pop();
			} while (!temp.empty() && PEMDAS(userInput[i] <= PEMDAS(temp.getTop())));
			temp.push(userInput[i]);
		}
	}
	while (!temp.empty()) {
		tempString = temp.getTop();
		infPostFix += tempString;
		temp.pop();
	}
	return infPostFix;










	cout << "Expression:" << userInput << endl;
		cout << "Postfix form :" << infixToPostfix(userInput) << endl;


	} while (userInput != "exit");
	return 0;











	if (isalnum(userInput[0])) {
		for (int i = 0; i < userInput.size(); ++i) {
			if (isalnum(userInput[i])) {
				postFix += userInput[i];
			}
			else if (userInput[i] == '(') {
				tempPost.push('(');
			}
			else if (userInput[i] == ')') {
				while (tempPost.getTop() != '(') {
					a = tempPost.getTop();
					postFix += a;
					tempPost.pop();
				}
				if (tempPost.getTop() == '(') {
					a = tempPost.getTop();
					tempPost.pop();
				}
			}
			else {
				while (!tempPost.empty() && PEMDAS(userInput[i] <= PEMDAS(tempPost.getTop()))) {
					a = tempPost.getTop();
					postFix += a;
					tempPost.push(userInput[i]);
				}
				tempPost.push(userInput[i]);
			}
			while (!tempPost.empty()) {
				a = tempPost.getTop();
				postFix += a;
				tempPost.pop();
			}
			cout << "PostFix:" << postFix << endl;
		}
	}

}



*/









