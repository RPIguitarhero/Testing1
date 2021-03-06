// 10a.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include "T3Reader.hpp"
#include"Board.hpp"
using namespace std;

void checkCondition(Results);
Board getBoard(T3Reader a) { return a.bo; };
int main()
{/* Example format of text file :
 0 1
 2 1
 2 0
 1 2
 Which coordinate is the row and which is the column doesn't matter as long as you're consistent.
 */
	//testing basic Board functions, first int parameter as row, 2nd as column
	cout << "now testing Board" << endl;
	Board b1;
	b1.makeMove(1, 1, 'o');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(0, 0, 'x');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(2, 2, 'o');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(0, 1, 'x');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(0, 2, 'o');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(1, 0, 'x');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(1, 2, 'o');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(2, 0, 'x');
	b1.print();
	checkCondition(b1.gameState());
	b1.makeMove(2, 1, 'o');
	b1.print();
	//checkCondition is to dispay the content of enumerated Result
	checkCondition(b1.gameState());
	cout << "now testing T3Reader " << endl;
	//checker.txt has the exact format as above,9 movements F
	T3Reader t1('o');
	cout<<t1.readGameFile("c:\\checker.txt")<<endl;
	Board b = getBoard(t1);
	b.print();
	//checker2.txt has 1 more movement line so it should return false; 10 movements F
	T3Reader t2('o');
	cout << t2.readGameFile("c:\\checker2.txt")<<endl;
	Board b2 = getBoard(t2);
	b2.print();
	//checker3.txt has fewer lines so should return true 4 movements T
	T3Reader t3('o');
	cout << t3.readGameFile("c:\\checker3.txt")<<endl;
	Board b3 = getBoard(t3);
	b3.print();
	//checker4.txt has one line repeated, should return false; 4 movements F
	T3Reader t4('o');
	cout << t4.readGameFile("c:\\checker4.txt") << endl;
	Board b4 = getBoard(t4);
	b4.print();
	//checker5.txt has x move first, should return true; 5 movements x won T
	T3Reader t5('x');
	cout << t5.readGameFile("c:\\checker5.txt") << endl;
	Board b5 = getBoard(t5);
	b5.print();
	//checker6.txt has x move first, should return true; 9 movements draw T
	T3Reader t6('x');
	cout << t6.readGameFile("c:\\checker6.txt") << endl;
	Board b6 = getBoard(t6);
	b6.print();

	//T should return True
	T3Reader t7('x');
	cout << t7.readGameFile("c:\\gameFile.txt") << endl;
	Board b7 = getBoard(t7);
	b7.print();
    return 0;
}

//a function to display results for debuging
void checkCondition(Results a) 
{
	switch (a)
	{
	case X_WON: cout << "X won" << endl;break;
	case O_WON: cout << "O won" << endl;break;
	case UNFINISHED: cout << "NOT FINISHED" << endl;break;
	case DRAW: cout << "DRAW" << endl;break;
	default:cout << "invalid" << endl;
	}
};

