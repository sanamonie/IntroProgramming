// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Main File
//The Project3.cpp files is responsible for holding references to the input handler, file handler and recordObject, as well as dispalying menu options and controlling menu logic

#include <iostream>
#include "RecordObject.h"
#include "FileHandler.h"
#include "InputHandler.h"

using namespace std;
using std::cout;

string nCharString(size_t n, char c) {
    size_t test = n;
    string a(n, c);
    return a;
}

int main()
{
    InputHandler iHandler;

    RecordObject* recordObject = new RecordObject();
    FileHandler fileHandler;

    try {
        fileHandler.setupRecord("CS210_Project_Three_Input_File.txt", *recordObject);
        fileHandler.createBackup(*recordObject);
    }
    catch (const exception& e) {

        cout << e.what() << endl;
    }
    
    
    cout << "File Uploaded" << endl;

    bool answer = true;
    int menuOption;
    string itemName;

    while (answer) {
        cout << nCharString(5, '*') << "Corner Grocer Record System" << nCharString(5, '*') << endl;
        cout << endl;
        cout << nCharString(40, '*') << endl;
        cout << "Menu Options" << endl;
        cout << nCharString(40, '*') << endl;
        cout << "1. Print specific item count" << endl;
        cout << "2. Print all item counts" << endl;
        cout << "3. print Histogram of items" << endl;
        cout << nCharString(40, '*') << endl;
        cout << endl;
        cout << "please enter index of chosen menu option" << endl;
        
        menuOption = iHandler.getIntInput();

        switch (menuOption) {
            case 1:
                while (answer) {
                    cout << "Enter Item Name" << endl;

                    cout << nCharString(30, '*') << endl;
                    recordObject->printOptions();
                    cout << nCharString(30, '*') << endl;

                    itemName = iHandler.getStringInput();
                    recordObject->printRecord(itemName);
                    cout << "would you like to print another item? " << endl;
                    answer = iHandler.getBool();
                }
                break;
            case 2 :
                recordObject->printRecords();
                break;
            case 3:
                recordObject->printHistogram();
                break;
            default:
                cout << "index was out of range" << endl;
        }
        cout << "would you like to perform another action? y/n" << endl;
        answer = iHandler.getBool();

        
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
