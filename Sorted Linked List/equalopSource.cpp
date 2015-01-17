// ====================================================

//HW3P3  extra credit
//Your name: Jason Meyer
//Compiler:  g++
//File type: Client file - Source.cpp

//=====================================================
//This program will demonstrate the overloaded equals operator
//using test cases described in hw3p3.
#include"slist.h"
#include <stddef.h>
#include<iostream>
using namespace std;

int main()
{
	int oldnum;		//oldnum is used to store deleted elements as they are removed
	slist L1 = slist();
	slist L2 = slist();
	cout << "Output diplays 1 when lists are equal and 0 when lists are not equal" << endl;
	cout << "L1 is empty and L2 is empty : " << (L1 == L2) << endl;

	L2.addRear(1);
	L2.addRear(2);
	cout << "L1 is empty and L2 has 2 elements : " << (L1 == L2) << endl;
	
	L2.deleteRear(oldnum);
	L2.deleteRear(oldnum);
	L1.addRear(1);
	L1.addRear(2);
	cout << "L1 has 2 elements and L2 is empty : " << (L1 == L2) << endl;

	L1.addRear(3);
	L2 = L1;
	cout << "L1 has 1, 2, 3 and L2 has 1, 2, 3 : " << (L1 == L2) << endl;

	L2.deleteRear(oldnum);
	cout << "L1 has 1, 2, 3 and L2 has 1, 2 : " << (L1 == L2) << endl;

	L2.addRear(3);
	L2.addRear(4);
	cout << "L1 has 1, 2, 3 and L2 has 1, 2, 3, 4 : " << (L1 == L2) << endl;

	L2.deleteIth(3, oldnum);
	
	cout << "L1 has 1, 2, 3 and L2 has 1, 2, 4 : " << (L1 == L2) << endl;
	cin.get();
}