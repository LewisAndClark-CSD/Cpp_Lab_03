// ArrayAndFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Function Prototypes
int initialize(char theArray[80][20]);
void print_it(char theArray[80][20]);

int main(){
	char firstName[80][20];
	string lastName[80];

	//Function Call
	initialize(firstName);
	
	//print the initialized array
	print_it(firstName);

	//input from user
	cout << "Please enter 3 first names : ";
	for (int i = 0; i < 3; i++){
		cin >> firstName[i];
		firstName[i][19] = '\0';
	}

	//print the names
	print_it(firstName);

	return 0;
}

//Function Definitions
int initialize(char theArray[80][20]){
	/*Initializes all characters to NULL*/
	for (int i = 0; i < 80; i++){
		for (int j = 0; j < 20; j++){
			theArray[i][j] = NULL;
		}
	}
	return 0;
}

void print_it(char theArray[80][20]){
	/*Prints the array in a grid format*/
	for (int i = 0; i < 80; i++){
		for (int j = 0; j < 20; j++){
			if (theArray[i][0] != NULL){
				cout << theArray[i][j];
			}
		}
		if (theArray[i][0] != NULL){
			cout << endl;
		}
	}
}