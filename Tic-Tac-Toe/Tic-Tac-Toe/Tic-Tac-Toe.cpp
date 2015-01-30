// Tic-Tac-Toe.cpp : Defines the entry point for the console application.
//

// Tic-Tac-Toe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*******************
* Brandon McCurry
* play Tic-Tac-Toe
*******************/

void display_board(char[]);
char winner(char[]);
int human_move(char[]);
int computer_move(char[], char, char);

int main()
{
	//try strings if classes needed
	char turn = 'X';
	//display_instruct
	cout << "Welcome to the greatest intellectual challenge of all time: Tic-Tac-Toe.  \n"
		<< "This will be a showdown between your human brain and my silicon processor.\n"
		<< "You will make your move known by entering a number, 0 - 8.  The number \n"
		<< "will correspond to the board position as illustrated : \n"
		<< endl << endl
		<< "0 | 1 | 2\n"
		<< "-------- -\n"
		<< "3 | 4 | 5\n"
		<< "-------- -\n"
		<< "6 | 7 | 8\n"
		<< "Prepare yourself, human. The ultimate battle is about to begin. \n";
	//end of display_instruct
	//pieces
	char go_first = 'a';
	char human = 'X';
	char computer = 'O';
	//ask_yes_no
	cout << "Do you require the first move? (y/n): ";
	cin >> go_first;
	cin.sync();
	while (tolower(go_first) != 'y' && tolower(go_first) != 'n')
	{
		cout << "Do you require the first move? (y/n): ";
		cin >> go_first;
		cin.sync();
	}
	//end of ask_yes_no
	if (go_first == 'n')
	{
		cout << "\nYour bravery will be your undoing... I will go first." << endl;
		human = 'O';
		computer = 'X';
	}
	else
	{
		cout << "\nThen take the first move. You will need it." << endl;
	}
	//end of pieces
	//new_board
	char board[9];
	for (int i = 0; i < 9; i++)
	{
		board[i] = ' ';
	}
	//end of new board
	display_board(board);
	int move = 0;
	char result = winner(board);
	while (result != 'X' && result != 'O' && result != 'T')
	{
		if (turn == human)
		{
			move = human_move(board);
			board[move] = human;
		}
		else
		{
			move = computer_move(board, computer, human);
			board[move] = computer;
			cout << move;
		}
		display_board(board);
		if (turn == 'X')
		{
			turn = 'O';
		}
		else
		{
			turn = 'X';
		}
		result = winner(board);
	}
	if (result != 'T')
	{
		cout << result << " won!" << endl;
		if (result == computer)
		{
			cout << "As I predicted, human, I am triumphant once more.  \n"
				<< "Proof that computers are superior to humans in all regards." << endl;
		}
		else if (result == human)
		{
			cout << "No, no!  It cannot be!  Somehow you tricked me, human. \n"
				<< "But never again!  I, the computer, so swear it!" << endl;
		}
	}
	else
	{
		cout << "It's a tie!" << endl;
		cout << "You were most lucky, human, and somehow managed to tie me.  \n"
			<< "Celebrate today... for this is the best you will ever achieve.";
	}
}
int computer_move(char board[], char computer, char human)
{
	int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
	cout << "I shall take square number ";
	char result = 'a';
	int retVal = 8;
	int i = 0;
	//if cannot win or block, place at next best
	while (i < 9)
	{
		if (board[BEST_MOVES[i]] == ' ')
		{
			retVal = BEST_MOVES[i];
			i = 9;
		}
		i++;
	}
	//if human can win, block that move
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			board[i] = human;
			result = winner(board);
			if (result == human)
			{
				retVal = i;
			}
			board[i] = ' ';
		}
	}
	//if computer can win, take that move
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			board[i] = computer;
			result = winner(board);
			if (result == computer)
			{
				retVal = i;
			}
			board[i] = ' ';
		}
	}
	return retVal;
}

int human_move(char board[])
{
	int response = 0;
	cout << "Where will you move? (0 - 8): ";
	cin >> response;
	while (response < 0 || response > 8)
	{
		if (board[response] != ' ')
		{
			cout << "That square is already occupied, foolish human. "
				<< "Choose another. " << endl;
		}
		cout << "Where will you move? (0 - 8): ";
		cin >> response;
	}
	cout << "Fine..." << endl;
	return response;
}
char winner(char board[])
{
	char winner = 'a';
	int WAYS_TO_WIN[8][3] = { { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } };
	bool tie = true;
	for (int i = 0; i < 8; i++)
	{
		if (board[WAYS_TO_WIN[i][0]] == board[WAYS_TO_WIN[i][1]] &&
			board[WAYS_TO_WIN[i][1]] == board[WAYS_TO_WIN[i][2]])
		{
			if (board[WAYS_TO_WIN[i][1]] != ' ')
			{
				winner = board[WAYS_TO_WIN[i][0]];
				return winner;
			}
		}
		if (board[i] == ' ')
		{
			tie = false;
		}
	}
	if (tie == true)
	{
		return 'T';
	}
	else
	{
		return 'F';
	}
}

void display_board(char board[])
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2]
		<< "\n\t" << "---------" << "\n\t" << board[3] << " | " << board[4]
		<< " | " << board[5] << "\n\t" << "---------" << "\n\t" << board[6]
		<< " | " << board[7] << " | " << board[8] << endl;
}