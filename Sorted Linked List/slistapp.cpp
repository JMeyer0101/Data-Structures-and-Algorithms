// ====================================================

//HW3P2 slist
//Your name: Jason Meyer
//Complier:  g++
//File type: Client File - slistapp.cpp

//=====================================================
//this program will demonstrate the slist class with various
//test cases described below
#include"slist.h"
#include<iostream>
using namespace std;

int main()
{
	slist S = slist();
	S.addFront(4);
	S.addRear(6);				//add to the front 4 times (elems 4,6,7,8)
	S.addRear(7);
	S.addRear(8);
	
	S.displayAll();
	cout << "position: " << S.search(6) << endl;	//display position of elem 6 using search
	
	S.replace(0, S.search(6));
	cout << "position: " << S.search(8) << endl;	//display position of elem 8 using search
	S.replace(2, S.search(8));
	S.displayAll();
	if (S.search(5) == 0)
	{
		cout << "not found" << endl;				//search for elem 5 which does not exist
	}												//demonstrates search function returns 0
													//when elem is not found
	
	//system("pause");
	

}
