/***********************************
**Author:Kai Kang
**Date:2018/3/08
**Description:Project10.a:implementation for the T3reader class.
************************************/
#include<fstream>
#include<iostream>
#include<string>
#include "T3Reader.hpp"
using namespace std;
/* a constructor that takes a char parameter that specifies whether 'x' or 'o' should have the first move. */
T3Reader::T3Reader(char ch)
{
	//set the first char in makeMove() as int
	if (ch =='x')
	{
		player = 2;
	}
	if (ch =='o')
	{
		player = 1;
	}
};

bool T3Reader::readGameFile(string fileName)
{
	//ifstream data to read
	ifstream inputFile;

	//declare str as a line, 
	string str;

	//open the file
	inputFile.open(fileName);

	//check if the file is successfully opened
	if (!inputFile) { cout << "file open failed" << endl; }

	while (getline(inputFile, str))
	{
		//return false when there's still line but game is over
		if (bo.gameState() != UNFINISHED && str != " ") { return false; }

		/*read a line, assume there are only two integers seperated by a single space per line, convert the content to 2 int
		based on printable ASCI characters */
		int a = static_cast<int>(str[0]) - 48, b = static_cast<int>(str[2]) - 48;

		
		//movement for each player
		if (player == 2)
		{
			//check if the slot is empty
			if (bo.makeMove(a, b, 'x') == true)
			{
				bo.makeMove(a, b, 'x');
			}
			//return false when the slot is already occupied
			else  return false;
			//"flip" to the other side, continue to next iteration to reset a,b
			player = 1;
			
		}
		else if (player == 1)
		{
			if (bo.makeMove(a, b, 'o') == true)
			{
				bo.makeMove(a, b, 'o');
			}
		
			else return false;
			//"flip" to the other side
			player = 2;
		}

	}

	inputFile.close();

	return true;
}


