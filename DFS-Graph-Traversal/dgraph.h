// ====================================================

//HW6 dgraph
//Your name: Jason Meyer
//Compiler:  g++
//File type: Header file - dgraph.h

//=====================================================

#include<iostream>
#include"slist.h"
using namespace std;

const int MAX = 20;  //for the purposes of the client program our max size will be 20

class dgraph
{

private:

	struct Gvertex
	{
		char Name;   //Gvertex name
		int  Out;	//Gvertex out degree
		int VisitNum;  //order number in which the Gvertex was visited
		slist AdjacentOnes; //slist of nodes adjacent to the current Gvertext

		
	};


	Gvertex Gtable[MAX];
	int count; //not used for now, stores num of vertices

public:

	class unknownVertex{};  // used for input error handling

	dgraph();		//constructor
	~dgraph();		//destructor

	void displayGraph();  //displays the table content in a very readable format
					//But make sure you do not display unused slots

	void fillTable();		//- reads the input file table.txt to fill the table
					//Open and close the input file table.txt in here

	int findOutDegree(char c);		// – returns the out degree of the vertex
									//whose name is given as an argument

	slist findAdjacency(char c);		//– returns the linked list of
									//adjacent vertices of the vertex whose name is given as an argument



	///HW7p2 function
	void visit(int, char); // will enter the given visit number for a given vertex
		//	this is to indicate the order in which vertices were visited.


	bool isMarked(char); // returns true if a given vertex was already visited
						//(0 means not visited)


};

