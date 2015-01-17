// ====================================================

//HW6 dgraph
//Your name: Jason Meyer
//Compiler:  g++
//File type: Implementation file - dgraph.cpp

//=====================================================

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"dgraph.h"
#include<cctype>
using namespace std;

dgraph::dgraph()  //initial constructor
{
	for (int i = 0; i < MAX; i++)
	{
		Gtable[i].Name = ' ';		//initialize vertex name to be blank char
		Gtable[i].VisitNum = 0;
		Gtable[i].Out = 0;
	}
}

dgraph::~dgraph()		//deconstructor (may need modification later)
{
}

void dgraph::displayGraph()  //displays the table content in readable format
{
	for (int i = 0; i < MAX; i++)
	{
		if (Gtable[i].Name != ' ')
		{
			cout << Gtable[i].Name << endl;
			cout << "Out Deg: " << Gtable[i].Out << endl;

			cout << "Visit Num: " << Gtable[i].VisitNum << endl; //new for hw7p2
			cout << "Adjacency list: ";
			Gtable[i].AdjacentOnes.displayAll();  //calls the displayall function from slist/llist to display adjacent nodes
		}
		cout << " " << endl;
	}
}


void dgraph::fillTable() //fills the Gtable list with vertices after defining the instance variables for each vertex from text file data.
{
	ifstream myfile("table.txt");  //first get data from text file and assign the data to appropriate variables.
	string x;

	int i = 0;   //int used to iterate through gtable

	

	while (getline(myfile, x))   //while text file has data..
	{
		//the following variables will be used to set the instance variables for each Gvertex in the Gtable

		char newName;   //Gvertex name
		int  newOut;	//Gvertex out degree
		char newAdjacent;  //order number in which the Gvertex was visited
		slist newAdjacentOnes = slist(); //slist of nodes adjacent to the current Gvertex

		stringstream SS(x);  //we use stringstream to help in setting the appropriate text data to variables.

		SS >> newName;
		SS >> newOut;
		//SS >> newAdjacent;
		//cout << newAdjacent << endl;

		//cout << newOut << endl;

		while (SS >> newAdjacent)
		{
			newAdjacentOnes.addRear((char)newAdjacent);
		}

		Gvertex gvertex;			//set the gvertex instance variables to the newly defined variables taken from table.txt
		gvertex.Name = newName;
		gvertex.Out = newOut;
		gvertex.VisitNum = 0;
		gvertex.AdjacentOnes = newAdjacentOnes;

		Gtable[i] = gvertex; //set the list head in gtable for each vertex.
		i++; //increment iterator variable to move to the next vertext element space in Gtable
		count++;
	}
		myfile.close();
	
}

int dgraph::findOutDegree(char c)		// – returns the out degree of the vertex whose name is given as an argument
{

	
			for (int i = 0; i < MAX; i++)
			{
				if (Gtable[i].Name == c)
				{
					return Gtable[i].Out;
				}
			}
	
}			

slist dgraph::findAdjacency(char c)  //returns the slist of adjacent nodes to the vertex whose name is given as an argument
{
	
		for (int i = 0; i < MAX; i++)
		{
			if (Gtable[i].Name == c)
			{
			return Gtable[i].AdjacentOnes;
			}
		}
		
	
}

//hw7p2 functions

void dgraph::visit(int num, char c)
{
	for (int i = 0; i < MAX; i++)
	{
		if (Gtable[i].Name == c)
		{
			Gtable[i].VisitNum = num;
		}
	}
}

bool dgraph::isMarked(char c)
{
	for (int i = 0; i < MAX; i++)
	{
		if (Gtable[i].Name == c)
		{
			if (Gtable[i].VisitNum > 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
