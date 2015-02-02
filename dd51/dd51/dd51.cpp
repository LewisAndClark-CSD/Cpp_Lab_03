 
	 /*

	 Jacob steiner and Nate Rowe
	 2/2/15
	 dd51
	 
	 6 question Trivia game */

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
void player2(char play2[6]);
void player1(char play1[6]);
void display_board(char play1[6], char play2[6]);
void ask();
void ask2();
int number1;
int number2;
int main()
{
	
	cout << "Welcome to trivia, enter the answer accordingly\n\n";
	while (number1 || number2 < 6){
		char playing1[7];
		char playing2[7];
		player1(playing1);
		player2(playing2);
		display_board(playing1, playing2);
		ask();
		ask2();

	}
	cout << "Congrats winner";
	getchar();
	getchar();
}

void player1(char play1[7]){
	for (int i = 0; i < 7; i++){
		play1[i] = ' ';
		play1[number1] = '1';

	}
}
void player2(char play2[7]){
	for (int i = 0; i < 7; i++){
		play2[i] = ' ';
		play2[number2] = '2';

	}
}

void display_board(char play1[7], char play2[7]){
	cout << play1[0] << play1[1] << play1[2] << play1[3] << play1[4] << play1[5] << play1[6] <<endl;
	cout << "______\n";
	cout << "______\n";
	cout << play2[0] << play2[1] << play2[2] << play2[3] << play2[4] << play2[5] << play2[6] << endl;
}

void ask()
{
	string questions[6] = { "what country is samsung from\n", "who is the 1st president\n", "what is Nate's last name\n", "what company owns dr.pepper\n", "what makes kowalas sleepy\n", "who inveted the light bulb\n" };
	string answers[6] = { "Japan", "Washington", "Rowe", "Coke", "Leaves", "Thomas" };
	cout << questions[number1];
	string guess;
	cout << "\n\n\What is the answer?\n\n ";
	cin >> guess;
	if (guess == answers[number1]){
		number1++;
	}
}

void ask2()
{
	string questions[6] = { "what country is samsung from\n", "who is the 1st president\n", "what is Nate's last name\n", "what company owns dr.pepper\n", "what makes kowalas sleepy\n", "who inveted the light bulb\n" };
	string answers[6] = { "Japan", "Washington", "Rowe", "Coke", "Leaves", "Thomas" };
	cout << questions[number2];
	string guess;
	cout << "\n\n\n\n\n\nWhat is the answer?\n\n ";
	cin >> guess;
	if (guess == answers[number2]){
		number2++;
	}
}