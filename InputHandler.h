//Input handler is used for input validation ensuring that input is the correct type to be used for menu logic

#pragma once

#include <iostream>
#include <cstring>

using namespace std;


class InputHandler{
	public:
		string getStringInput();
		int getIntInput();
		bool getBool();
	private:
};

