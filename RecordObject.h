//RecordObject Is used to store the record Grocery Items within a map <itemName, quantity>
//RecorObject is reponsible for printint all item formats. 

#pragma once
#include<iostream>
#include<map>
#include <iomanip>
using namespace std;


class RecordObject {
public:
	RecordObject();
	void printRecords();
	void printRecord(string itemName);
	void printHistogram();
	void AddRecord(string itemName);
	void printOptions();
	map<string,int> getRecordMap();

	string nCharString(size_t n, char c);

private:
	map<string, int> recordMap;
};

