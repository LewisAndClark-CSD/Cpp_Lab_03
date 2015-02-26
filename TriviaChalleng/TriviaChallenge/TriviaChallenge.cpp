// TriviaChallenge.cpp : A Trivia Challenge using arrays.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

const int rows = 14;
const int columns = 2;
int board[rows][columns] = { 0, 0 };

void displayBoard();


int main()
{
	displayBoard();

	/*The number for go first indicates the player that goes first.*/
	int goFirst = 0;
	/*Simulates a dice roll.*/
	int roll = rand() % 6 + 1;
	char player1 = '1';
	char player2 = '2';
	/*This is the gameboard.*/
	char gameboard[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	cout << endl << endl << "This is a trivia challenge for two people!" << endl;
	getchar();
	cin.ignore();
	cout << endl;

	return 0;
}

void Turn(int roll(), int player1Roll = rand() % 6 + 1, int player2Roll = rand() % 6 + 1, int goFirst = 0)
{
	cout << roll << endl;
	while (goFirst != 1 || 2){

		if (player1Roll > player2Roll)
		{
			int goFirst = 1;
		}
		else if (player1Roll < player2Roll)
		{
			int goFirst = 2;
		}
		else
		{
			int player1Roll = rand() % 6 + 1;
			int player2Roll = rand() % 6 + 1;
		}
		return;
	}
}
	void displayBoard()
	{

		cout << "  1 2" << endl;
		cout << " -----";

		for (int bRow = 0; bRow<14; bRow++)
		{
			cout << "\n ";
			for (int bCol = 0; bCol< 2; bCol++)

				if (board[bRow][bCol] == 0)
					cout << ".  ";
				else
					cout << ".  ";
		}
		cout << endl;

		return;
	}
	void Movement(int roll(), char bRow())
	{
		srand(time(NULL));
		int spot = 0;
		while (spot != 14)
		{
			int roll = rand() % 6 + 1;
			for (int bRow = 0; bRow<14; bRow++)
			{
				cout << "\n ";
				for (int bCol = 0; bCol< 2; bCol++)

					if (board[bRow][bCol] == 0)
						cout << ".  ";
					else
						cout << ".  ";
			}
			cout << endl;

			return;
		}
		}

		
	}