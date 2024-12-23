#include "RecordObject.h"

RecordObject::RecordObject(){
	
}
//prints repeating char strings
string RecordObject::nCharString(size_t n, char c) {

	string a(n, c);
	return a;
}

// uses an iterator wth a enhanced for loop to iterate through all values of the map object
void RecordObject::printRecords() {
	for (const auto& val : recordMap) {
		cout << setw(13) << val.first << ":  " << val.second << endl;
	}
}
// uses an iterator wth a enhanced for loop to iterate through all values of the map object, prints * instead

void RecordObject::printHistogram() {
	for (const auto& val : recordMap) {
		
		cout << setw(13) << val.first << ": " << nCharString(val.second,'*') << endl;
	}
}
// prints a list of options to be used for specific requests
void RecordObject::printOptions() {

	for (const auto& val : recordMap) {
		cout << val.first << ", ";
	}
	cout << endl;
}
//checks if the requaested item is in inventory (map) if so prints the item and amount
void RecordObject::printRecord(string itemName) {
	if (recordMap.count(itemName)) {
		cout << itemName << ": " << recordMap.at(itemName) << endl << endl;

	}
	else {
		cout << "item not found, Remember to use proper capitilization" << endl;
	}
	
}

//checks if the item is in the map, if it is increment the amount, if not create a new map value and asign its qunatity to one
void RecordObject::AddRecord(string itemName) {
	if (recordMap.count(itemName)) {

		recordMap.at(itemName)++;
	}
	else {
		recordMap.emplace(itemName, 1);
	}
	

}

//this returns the map object so that the file handler can convert it to an iterator
map<string,int> RecordObject::getRecordMap() {
	return recordMap;
}