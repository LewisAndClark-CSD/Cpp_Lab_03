// Lab3_1.cpp : tic tack toe game.
// Matt Gilmore & Michael Coyne

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
char x = 'X';
char o = 'O';
char EMPTY = ' ';
string TIE = "TIE";
int NUM_SQUARES = 9;

void new_board(char[]);
void display_board(char[]);
int human_move(char[], char);
void display_instruct();
char ask_yes_no(string);
int ask_number(string, int, int);
char pieces();
char next_turn(char);
string winner(char[]);
int computer_move(char[], char, char);


int _tmain(int argc, _TCHAR* argv[])
{
	char human = NULL;
	char computer = NULL;
	char turn = X;
	char board[9];
	int move = NULL;


	display_instruct();
	computer, human = pieces();
	new_board();
	display_board();

	while (!winner())
	{
		if (turn == human)
		{
			move = human_move(human);
			board[move] = human;
		}
		else
		{
			move = computer_move(board, computer, human);
			board[move] = computer;
		}
		display_board(board);
		turn = next_turn(turn);
		the_winner = winner(board);
		congrat_winner(the_winner, computer, human);
	}
	return 0;
}

void new_board(char board[])
{
	for (int i = 0; i < NUM_SQUARES; i++)
	{
		board[i] = ' ';

	}
}

void display_board(char board[])
{
	cout << board[0] << "|" << board[1] << '|' << board[2] << endl;
	cout << "-----";
	cout << board[3] << "|" << board[4] << '|' << board[5] << endl;
	cout << "-----";
	cout << board[6] << "|" << board[7] << '|' << board[8] << endl;
}


int human_move(char board[], char human)
{
	//Get human move.
	int move = NULL;
	while (board[move] != ' ');
	{
		move = ask_number("Where will you move? (0 - 8):", 0, NUM_SQUARES);
		if (move != ' ')
		{
			cout << "\nThat square is already occupied, foolish human.  Choose another.\n";
		}
	}
	cout << "Fine...";
	return move;
}

void display_instruct()
{
	cout << "Welcome to the greatest intellectual challenge of all time : Tic - Tac - Toe." << endl;
	cout << "This will be a showdown between your human brain and my silicon processor." << endl;
	cout << "You will make your move known by entering a number, 0 - 8.  The number " << endl;
	cout << "will correspond to the board position as illustrated: " << endl << endl;

	cout << "7 | 8 | 9" << endl;
	cout << "---------" << endl;
	cout << "4 | 5 | 6" << endl;
	cout << "---------" << endl;
	cout << "1 | 2 | 3" << endl << endl;
	cout << "Prepare yourself, human. The ultimate battle is about to begin." << endl << endl;

	cout << "<Press Enter to Begin>";
	cin.ignore();

}

char ask_yes_no(string question)
{ //Ask a yes or no question and return respones
	char response = NULL;

	cout << question << endl;
	cin >> response;

	while (response == !'y' || response == !'n')
	{//Ask question again
		cout << question << endl;
		cin >> response;
	}
	return response;
}

int ask_number(string question, int low, int high)
{//Check if user choice is on board
	int response = 0;

	cout << question << endl;
	cin >> response;

	if (response < 1 || response > 9)
	{
		cout << question << endl;
		cin >> response;
	}
	return response;
}

char pieces()
{//Determine who goes first

	char human = NULL;
	char computer = NULL;

	char go_first = ask_yes_no("Do you want to go first? (y/n): ");
	if (go_first == 'y')
	{
		cout << "Then take the first move. You will need it.";

		human = x;
		computer = o;
	}
	else
	{
		cout << "Your bravery will be your undoing... I will go first.";

		human = o;
		computer = x;
	}
	return human, computer;
}

char next_turn(char turn)
{//Switch Turns
	if (turn == x)
	{
		return o;
	}
	else
	{
		return x;
	}
}

string winner(char board[])
{
	int WAYS_TO_WIN[8][3] =
	{ { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 }
	};

	for (int i = 0; i < 8; i++)
	{
		if (board[WAYS_TO_WIN[i][0]] == board[WAYS_TO_WIN[i][1]] == board[WAYS_TO_WIN[i][2]] != NULL)
		{
			char winner = board[i[0]];
			return winner;
		}
	}

}


int computer_move(char board[], char computer, char humnan)
{
	int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			board[i] = computer;
		}
	}



}