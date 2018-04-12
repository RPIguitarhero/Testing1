/***********************************
**Author:Kai Kang
**Date:2018/3/08
**Description:Project10.a:implementation file for the Board Class
************************************/

#include<iostream>
#include"Board.hpp"
using namespace std;
/* makeMove that takes two ints and a char (either 'x' or 'o') as parameters, assume the input are always valid    */
bool Board::makeMove(int r, int c, char player)
{
	//check the slot, proceed if empty
	if (board[r][c] == ' ')
	{
		board[r][c] = player;
		return true;
	}
	else
	{
		return false;
	}

};

/*return the current outcome of the game */
Results Board::gameState()
{

	
	//check the win conditions-----by row
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		if (board[0][0] == 'x')
		{
			return X_WON;
		}
		else if (board[0][0] == 'o') { return O_WON; }
	}
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		if (board[1][0] == 'x')
		{
			return X_WON;
		}
		else if (board[1][0] == 'o') { return O_WON; }
	}	if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		if (board[2][0] == 'x')
		{
			return X_WON;
		}
		else if (board[2][0] == 'o') { return O_WON; }
	}
	//check the win conditions-----by column
		if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
		{
			if (board[0][0] == 'x')
			{
				return X_WON;
			}
			if (board[0][0] == 'o') { return O_WON; }
		}
		if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		if (board[0][1] == 'x')
		{
			return X_WON;
		}
		else if (board[0][1] == 'o') { return O_WON; }
	}	if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
	{
		if (board[0][2] == 'x')
		{
			return X_WON;
		}
		else if (board[0][2] == 'o') { return O_WON; }
	}
	//check the win conditions-----by slash
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'x')
		{
			return X_WON;
		}
		else if (board[0][0] == 'o') { return O_WON; }
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'x')
		{
			return X_WON;
		}
		else if (board[0][2] == 'o') { return O_WON; }
	}
	//when no one has won, check if every slot has been filled
	int row = 0, col = 0;
	for (int index = 0; index<3;index++)
	{
		col = 0;
		for (int index = 0;index<3;index++)
		{
			if (board[row][col] == ' ')
			{
				//return UNFINSHED when no one won and there is still empty slot
				return UNFINISHED;
			}
			col += 1;
		}
		row += 1;
	}
	//when no one has won and every slot is filled, return DRAW
	return DRAW;
};

/*Optional: write a method called print, which just prints out the current board to the screen
- this is not required, but will very likely be useful for debugging.*/

void Board::print()
{
	int row = 0, col = 0;
	//display every element in the array
	for (int index = 0; index<3;index++)
	{
		col = 0;
		for (int index = 0;index<3;index++)
		{
			cout << board[row][col] << " ";
			col += 1;
		}
		cout << endl;
		row += 1;
	}
	cout << endl;
};