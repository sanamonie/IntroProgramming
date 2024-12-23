//Responsible for handling all file interactions 
//reading text file and writing dat file

#pragma once
#include "RecordObject.h"
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;


class FileHandler
{
	public:
		void setupRecord( string fileName, RecordObject& recordObject);
		void createBackup(RecordObject& recordObject);

	private:
		ifstream inStream;
		ofstream outStream;

};

