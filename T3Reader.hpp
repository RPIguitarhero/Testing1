#pragma once

/***********************************
**Author:Kai Kang
**Date:2018/3/08
**Description:Project10.a: a class that decides which player excutes the 1st turn
and reads the players' move oreders, eventually display them using the Board class.
************************************/
#include <string>
#include"Board.hpp"

#ifndef T3READER_HPP
#define T3READER_HPP
using namespace std;
class T3Reader {

private:
	//the member variables are a Board, and an int to record the turn for each player
	Board bo;
	int player;
public:
	//default constructor
	T3Reader() { player = ' '; }
	/*function prototypes */
	T3Reader(char);
	bool readGameFile(string);

	//a friend function for debuggin in Main
	friend Board getBoard(T3Reader);
};
#endif