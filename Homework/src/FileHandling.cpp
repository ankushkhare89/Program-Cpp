/*
 * FileHandling.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: Designing Future
 */

/*
 * File1.c
 *
 *  Created on: Oct 30, 2016
 *      Author: Designing Future
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "FileHandling.h"
#include "Patterns.h"
#include "LinkedList.h"
//----------------------------------------------------------------------------------------------
using namespace std;

//----------------------------------------------------------------------------------------------

void FileHandle::readFile() {

	fstream fileObject;
	char filename[50];
	int id;
	string Id, pat, addr, flag;
	string singleLine;				// store the string from line

	// Take file name from user
	cout<<" Enter file name"<<endl;
	cin>>filename;
	fileObject.open(filename);

	if(!fileObject){
		cout<<"error in opening file to read";			// unable to open the file
	}else{
		createLinklist();		// create linked list
		// this function will read the data in the file line by line
		while(getline(fileObject, Id, ',' )){
				// get id
				id = atoi(Id.c_str());
				//get pattern
				getline(fileObject, pat, ',' );
				pat = string( pat, 1, pat.length()-2);
				// get address
				getline(fileObject, addr, ',' );
				addr = string( addr, 0, addr.length());
				// get flag
				getline(fileObject, flag );
				flag = string( flag, 0, flag.length());
				// save the parameters
				addLinklist(id, pat, addr, flag);
		}
	}
	fileObject.close();		//close the file
	displayAll();	//Display data stored after reading from file
}
//----------------------------------------------------------------------------------------------

void FileHandle::writeFile(){

	int i;
	stringstream temp_Str;
	string flag[] = {"true", "false"};
	ofstream fileObject;
	ofstream fileObject2;
	const string pattern = "myPattern";

// Write the tuple once for reference in read.txt
	fileObject.open ("read.txt", ios::trunc);

	// Open the file
	if(!fileObject){
			cout<<"error in opening file to write";		//Unsuccessful
	}
	else{
		for(i=10;i<25;i++){		// create 15 dummy tuple
			temp_Str << pattern<<i;		// string myPattern10....myPattern24
			linkPatternToFunction(temp_Str.str());		// create a map for myPattern string as key and function to execute
			temp_Str.str("");
			temp_Str << i<<"," <<"\""<< pattern<<i<<"\""<<","<<"src/patterns/Functional"<<i<<".pat"<<","<<flag[i%2]<<"\n";
			fileObject<<temp_Str.str();		// writing tuple into file to read later
			temp_Str.str("");		//clear string
		}
		fileObject.close();		// close read.txt
	}

	// create 15 files in /src/patterns folder to read later
	for(i=10;i<25;i++){
		temp_Str <<"../Homework/src/patterns/"<<"Functional"<<i<<".pat";
		fileObject2.open(temp_Str.str().c_str(), ios::trunc );		//create and open the file in trunc mode
		temp_Str.str("");

		if(!fileObject2){
				cout<<"error ";				// unable to open file
		}
		else{
			const string pattern = "myPattern";
			temp_Str <<"src/patterns/Functional"<<i<<"\n";
			fileObject2<<temp_Str.str();		//write string in this file
			temp_Str.str("");
			fileObject2.close();		//close the file
		}
	}
	cout<<"writing process complete.."<<endl;
}
//----------------------------------------------------------------------------------------------

// Function to read from dummy.txt and
void FileHandle::readDummyFile(){

	int id;
	string Id, pat, addr, flag;
	fstream fileObject;
	fileObject.open ("dummy.txt");

		// Open the file
		if(!fileObject){
				cout<<"error in opening dummy file";		//Unsuccessful
		}
		else{
			while(getline(fileObject, Id, ',' )){
				// get id
				id = atoi(Id.c_str());
				//get pattern
				getline(fileObject, pat, ',' );
				pat = string( pat, 1, pat.length()-2);
				// get address
				getline(fileObject, addr, ',' );
				addr = string( addr, 0, addr.length());
				// get flag
				getline(fileObject, flag );
				flag = string( flag, 0, flag.length());
				// save the parameters
				if(searchNode(id, pat, addr, flag)){
					cout<<"Match found for tuple with id:" <<id<<endl;
				}else{
					cout<<"No match found for tuple with id:" <<id<<endl;
				}
			}
		}
}
