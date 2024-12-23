#include "InputHandler.h"
string InputHandler::getStringInput() {
	string tempInput;

	cin >> tempInput;
	while (cin.fail()) {
		cout << "Invalid input was received, please Enter string Value" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempInput;
	}
	return tempInput;

}
int InputHandler::getIntInput() {
	int tempInput;

	cin >> tempInput;
	while (cin.fail()) {
		cout << "Invalid input was received, please Enter Integer Value" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempInput;
	}
	return tempInput;
}

bool InputHandler::getBool() {
	 char tempInput;

	cin >> tempInput;
	while (cin.fail() || tempInput!= 'y' && tempInput!= 'n') {
		cout << "Invalid input was received, please enter y/n" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempInput;
	}

	tempInput = tolower(tempInput);

	if (tempInput == 'y') {
		return true;
	}
	else {
		return false;
	}
	
}