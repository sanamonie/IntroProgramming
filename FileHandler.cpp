#include "FileHandler.h"


void FileHandler::setupRecord(string fileName, RecordObject& recordObject) {
	inStream.open(fileName);
	string tempItem;


	if (!inStream.is_open()) 
	{
		throw runtime_error("Unable to open record file");
	}

	while (!inStream.eof()) {

		inStream >> tempItem;
		if (inStream.fail()) {
			inStream.clear();
			inStream.ignore(100, '\n');
			continue;
		}


		recordObject.AddRecord(tempItem);
		
		

		
	}
	inStream.close();
}

void FileHandler::createBackup(RecordObject& recordObject) {
	outStream.open("frequency.dat");

	if (!outStream.is_open())
	{
		throw runtime_error("Unable to record backup data file");
	}

	for (auto val : recordObject.getRecordMap()) 
	{
		outStream << val.first << " " << val.second << endl;
	}
	outStream.close();
	

}
