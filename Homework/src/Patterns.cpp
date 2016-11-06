/*
 * Patterns.c
 *
 *  Created on: Nov 4, 2016
 *      Author: Designing Future
 */
#include <iostream>
#include <map>
#include "Patterns.h"

using namespace std;
static long iteration=0;	// variable to iterate for array

typedef void (*function) (void);
std::map<std::string, function> func_map;		//map to store pattern name with pattern function

// array to hold all pattern function
void (* patFunction_Array [])() = {myPattern10, myPattern11, myPattern12, myPattern13, myPattern14, myPattern15, myPattern16, myPattern17,
					 myPattern18, myPattern19, myPattern20, myPattern21, myPattern22, myPattern23, myPattern24};
//----------------------------------------------------------------------------------------------

// create map based on string as key assigning to predefine functions
void linkPatternToFunction(string patName){

	func_map.insert(std::pair<std::string, function>(patName, patFunction_Array[iteration++]));
}
//----------------------------------------------------------------------------------------------

// call pattern function based on string
void show_pattern(string patName){

	func_map[patName]();
}
//----------------------------------------------------------------------------------------------

void myPattern10(){
	cout<<"myPattern10 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern11(){
	cout<<"myPattern11 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern12(){
	cout<<"myPattern12 called"<<endl;
}
//----------------------------------------------------------------------------------------------
void myPattern13(){
	cout<<"myPattern13 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern14(){
	cout<<"myPattern14 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern15(){
	cout<<"myPattern15 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern16(){
	cout<<"myPattern16 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern17(){
	cout<<"myPattern17 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern18(){
	cout<<"myPattern18 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern19(){
	cout<<"myPattern19 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern20(){
	cout<<"myPattern20 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern21(){
	cout<<"myPattern21 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern22(){
	cout<<"myPattern22 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern23(){
	cout<<"myPattern23 called"<<endl;
}
//----------------------------------------------------------------------------------------------

void myPattern24(){
	cout<<"myPattern24 called"<<endl;
}
//----------------------------------------------------------------------------------------------
