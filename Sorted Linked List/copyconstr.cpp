// ====================================================

//HW3P3 
//Your name: Jason Meyer
//Compiler:  g++
//File type: Client file - copyconstr.cpp

//=====================================================
//This program will demonstrate the copy constructor functionality using
//client functions and test cases described in hw3p3.
#include"slist.h"
#include <stddef.h>
#include<iostream>
using namespace std;

void Copytest(slist L);
int main()
{
	int oldnum;
	slist L1 = slist();
	for (int i = 1; i < 6; i++)
	{
		L1.addRear(i);
	}
	Copytest(L1);
	L1.displayAll();
	L1 = L1;
	L1.displayAll();
	slist L2 = slist();
	for (int i = 7; i < 11; i++)
	{
		L2.addRear(i);
	}
	L2.displayAll();
	L2 = L1;
	L2.displayAll();
	L1.deleteRear(oldnum);
	L1.displayAll();
	L1.displayAll();
	L2.displayAll();
	cin.get();
}


//Copytest will receive the list passed by value from main() and Simply 
//1) add a node to its rear with 6 in it(should not affect the original)
//2) display it(6 elements 1, 2, 3, 4, 5, 6)

void Copytest(slist L)
{
	slist LNum = slist(L);
	LNum.addRear(6);
	LNum.displayAll();
}
