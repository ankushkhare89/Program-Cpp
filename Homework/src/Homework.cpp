//============================================================================
// Name        : Homework.cpp
// Author      : Ankush Khare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "FileHandling.h"
#include "LInkedList.h"

using namespace std;

// Structure contains Id, Name



int main() {

		int displayFlagWise;
		FileHandle FileHandleObj;

		// creating data for reading
		FileHandleObj.writeFile();

		// reading data from read.txt
		FileHandleObj.readFile();

		// access data after reading
		cout<<"Press 1. to display Pattern with true flag"<<endl;
		cout<<"Press 2. to display Patter with false flag"<<endl;
		cin>>displayFlagWise;
		displayPatternWithFlags(displayFlagWise);

		// read dummy file and compare with list from read.txt
		FileHandleObj.readDummyFile();
		return 0;
}
