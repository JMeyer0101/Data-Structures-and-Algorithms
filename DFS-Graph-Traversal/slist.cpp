// ====================================================

//HW3P2 slist
//Your name: Jason Meyer
//Compiler:  g++
//File type: Implementation file - slist.cpp

//=====================================================
#include"slist.h"
#include <stddef.h>
using namespace std;

//Constructor
slist::slist(){
	Front = NULL;
	Rear = NULL;
	Count = 0;
}//-initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.

slist::~slist()
{
	while (!isEmpty())
	{
		el_t node;
		deleteFront(node);
	}
}

int slist::search(el_t Key)                 //search through the list to see if any node contains Key.
{									//If so, return its position(>= 1).Otherwise, return 0.
	Node *p = new Node;
	p = Front;
	int counter = 1;
	while (p != NULL)
	{
		if (p->Elem == Key)
		{
			return counter;
		}

		p = p->Next;
		counter++;
	}
	
	return 0;

}

void slist::replace(el_t Elem, int I)     //go to the Ith node (I is between 1 and Count) and replace the element there with Elem. 
{										//If I was an illegal value, throw an exception.

	Node *p = new Node;
	p = Front;
	

	if (I > Count + 1 || I < 1)
	{
		throw OutOfRange();
	}
	else if (isEmpty())
	{
		throw Underflow();
	}
	else
	{
		for (int j = 1; j < I; j++)
		{
			p = p->Next;
		}
		p->Elem = Elem;
	}
		


	
}

slist& slist::operator=(const slist& OtherOne)
{
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .
	if (&OtherOne != this)  // if not the same
	{
		// this-> object has to be emptied first.
		el_t oldnum;
		while (!this->isEmpty())
		{
		
		this->deleteRear(oldnum);
	    }
		// this-> object has to be built up by allocating new cells (**)
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;               // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;    // return the result unconditionally.
}


bool slist::operator==(const slist& OtherOne)
{
	if (this->isEmpty() && OtherOne.isEmpty())  //if both are empty return true
	{
		return true;
	}
	else if (this->Count != OtherOne.Count)		//lists cannot be equal if their sizes are different
	{
		return false;
	}
	else
	// if the lists are the same size, we check to see if each element of both lists have the same value
	{
		
		
		Node *p, *p2;		//user two node pointers to run through each list
		p = this->Front;
		p2 = OtherOne.Front;
		while (p != NULL)
		{
			if (p->Elem != p2->Elem)		//if the elements differ at all, the lists are not equal
			{
				return false;
			}
			p = p->Next;
			p2 = p2->Next;

		}
		return true;				//if the loop reaches this far, all elements are equal, so the lists are equal
	}
}

//copy constructor:
slist::slist(const slist& Original)
{
	//  this->'s data members need to be initialized first
	Front = NULL;
	Rear = NULL;
	Count = 0;
	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this, see the (**) lines in Operator Overloading of =.
	Node* p;  // local pointer for OtherOne
	p = Original.Front;
	while (p != NULL)  // This uses a loop which repeats until you reach the end of OtherOne. 
	{
		this->addRear(p->Elem);    //P’s element is added to this->
		p = p->Next;               // Go to the next node in OtherOne   
	}
	//  Nothing to return.
}


