// ====================================================

//HW7p2 graph DFS
//Your name: Jason Meyer
//Compiler:  g++
//File type: Implementation file - DFSgraphCLIENT.cpp

//=====================================================
#include<iostream>
#include<string>
#include"dgraph.h"
#include"stack.h"
using namespace std;

int main()
{
	cout << "Initializing.." << endl;
	
	dgraph graph = dgraph();		//initialize our graph
	stack stack0 = stack();			//initialize our stack
	slist slist0 = slist();			//initialize our slist
	
	cout << "Filling graph table.." << endl;
	cout << "Displaying Graph: \n" << endl;
	graph.fillTable();				//fill the graph with data from the text file
	graph.displayGraph();			//display our graph using the displaygraph function

	
		

	cout << "Initializing DFS.." << endl;
	char vertexname = 'A';  //start by marking vertex a with 1
	cout << vertexname << " has not been visited. Marking " << vertexname << " and pushing adjacent vertices" << endl;
	int visitAssign = 1;    //	Mark / visit A(**), the start vertex visit number as 1.
	graph.visit(visitAssign, vertexname);

	slist0 = graph.findAdjacency(vertexname);		//Get the adjacency list of A and push adjacent vertices onto the stack.
	
	while (!slist0.isEmpty())			
		
	{
		slist0.deleteRear(vertexname);			
		stack0.push(vertexname);
	}
	cout << "Displaying stack: \n" << endl;

	stack0.displayAll();  //display the stack

	

	
	while (!stack0.isEmpty())		//		While the stack is not empty do
	{
		stack0.pop(vertexname);							//		Remove a vertex v from the stack.	
		cout << "Visiting " << vertexname << endl;	//			Display the vertex name.
		if (!graph.isMarked(vertexname))			//			If v is not marked yet(visit number is 0) then
		{
			cout << vertexname << " has not been visited. Marking "<< vertexname <<" and pushing adjacent vertices" << endl;
			visitAssign++;
			graph.visit(visitAssign, vertexname);							//			•	mark it(visit it **) and inform the user E.G.“visited B”
			slist0 = graph.findAdjacency(vertexname);	//	•	get its adjacency list and put adjacent ones on the stack.
			while (!slist0.isEmpty())
			{
				slist0.deleteRear(vertexname);
				stack0.push(vertexname);
			}
			cout << "::::New stack with adjacencies::::  "<< endl;
			stack0.displayAll();//	•	display the stack clearly labeling it as the stack

		}
		else
		{
			cout << "Vertex " << vertexname << " has been marked" << endl;
		}
	}
	cout << " :::::Graph Result::::  " << endl;  //	Display the Graph with visit numbers for all vertices.

	graph.displayGraph();
	system("pause");
}



