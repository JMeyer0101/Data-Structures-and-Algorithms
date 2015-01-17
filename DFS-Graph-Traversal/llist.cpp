
//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

// ====================================================

//HW3P1 llist
//Your name: Jason Meyer
//Complier:  g++
//File type: Implementation file - llist.cpp

//=====================================================

#include"llist.h" 
#include <stddef.h>
#include <iostream>

using namespace std;

//Constructor
llist::llist(){
	Front = NULL;
	Rear = NULL;
	Count = 0;
}//-initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.  The new list is empty.

llist::~llist()
{
	while (!isEmpty())
	{
		el_t node;
		deleteFront(node);
	}
}

//Destructor  
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
bool llist::isEmpty() const{
	if (Front == NULL && Rear == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//- return true if Front and Rear are both pointing to NULL.
//- (note: do not use Count for this!!!)

void llist::displayAll()
{
	if (isEmpty())
	{
		cout << " [ empty ] " << endl;
	}
	else{
		int i = 0;
		Node *j = Front;


		while (i != Count)
		{
			
			cout << j->Elem;
			j = j->Next;
			i++;
		}
		cout << endl;
	}

}
//- displays each element of the list starting from Front in [ ].
//- (special case: if the list is empty, display [ empty ] ).

void llist::addRear(el_t NewNum)  //- adds a new node at the rear and puts NewNum in the Elem field
{									//  of this new node. Count is updated.
	if (isEmpty())
	{
		Node *tail = new Node;
		tail->Next = NULL;
		tail->Elem = NewNum;
		Front = tail;
		Rear = tail;
		
	}
	else
	{
	//Regular case:
	Rear->Next = new Node;
	Rear = Rear->Next;
	Rear->Elem = NewNum;
	Rear->Next = NULL;
	}
	Count++;
}

void llist::deleteFront(el_t& OldNum)
{
	//3 cases
	//error case: if the List is empty, throw an exception.
	if (isEmpty()){
		throw Underflow();
	}
	else{
		//else give back the front node element through OldNum (pass by reference)
		//and also remove the front node. Count is updated.
		//(special case: if this is going to make the list empty,
		//make sure both Front and Rear become NULL).
		//Regular case:
		OldNum = Front->Elem;

		if (Front->Next == NULL) // case where count == 1
		{
			Front = NULL;
			Rear = NULL;
		}
		else // The regular case 
		{
			Node *p = Front->Next; // p points to the second node in the list
			delete Front;
			Front = p;	// second node is set as new front
		}

		Count--;
	}

}

void llist::addFront(el_t NewNum)
{
	//-2 cases
	//	- will add a new node to the front of the list.Count is updated.
	if (isEmpty())
	{
		Node *head = new Node();			

		head->Elem = NewNum;			//- (special case: this is going to be the very first node, 
		head->Next = NULL;				//   creates a new node and makes Front and Rear point to it.)
		
		Front = head;				
		Rear = head;
	}
	else{
		//	Regular case:  list has at least one node.  Creates a new node and sets it to front, sets front->next equal to previous node
		Node *x;		
		x = new Node;
		x->Next = Front;
		Front = x;
		Front->Elem = NewNum;
	}
	Count++;
}
void llist::deleteRear(el_t& OldNum)
{
	//- 3 cases
	//- error case: if empty, throw an exception.
	if (isEmpty())
	{
		throw Underflow();
	}
	else //give back the rear node element through OldNum(pass by reference)
	{
		//and also remove the rear node.Count is updated.
		OldNum = Rear->Elem;

		if (Front->Next == NULL)
		{
			Front = NULL;
			Rear = NULL;
		}//- (special case: if this is going to make the list empty,
		//   make sure both Front and Rear become NULL).
		else{
			//Regular case:
			
			Node *p = Front;
			while (p->Next != Rear)			//Make p go to the one right before rear(using while)
			{
				p = p->Next;
			}
			delete Rear;
			Rear = p;
			Rear->Next = NULL;
			
		}
		Count--;
	}
}
void llist::deleteIth(int I, el_t& OldNum){
	
	if (I > Count || I < 1)
	{
		throw OutOfRange();
	}
	else if (I == 1)
	{
		deleteFront(OldNum);
	}
	else if (isEmpty())					//- 4 cases
	{									//- will delete the Ith node (I starts out at 1).  Count is updated.
		throw Underflow();				//- Error cases: 
	}									//  If I is an illegal value (i.e. > Count or < 1) throw an exception.
										//- (note: this may simply call deleteFront or deleteRear for some cases)
	
	else if (I == Count)
	{
		deleteRear(OldNum);
	}
	else{
		Node *p = new Node();
		Node *q = new Node();

		p = Front;
		for (int i = 1; i < I - 1; i++)
		{
			p = p->Next;
		}
		q = p->Next;
		OldNum = q->Elem;
		p->Next = q->Next;
		delete q;
		Count--;
	}
	
	
}




void llist::addbeforeIth(int I, el_t newNum)
{

	if (I > Count +1|| I < 1)
	{
		throw OutOfRange();
	}
	else if (I == 1)
	{
		addFront(newNum);			
	}
	else if (isEmpty())					//- 4 cases
	{									//- will add right before the Ith node (I starts out at 1).  Count is updated.
		throw Underflow();				//- Error cases: 
	}									//  If I is an illegal value (i.e. > Count or < 1) throw an exception.
										//- (note: this may simply call deleteFront or deleteRear for some cases)

	else if (I == Count+1)
	{
		addRear(newNum);			//if I is the last, add to rear.
	}
	else{
		Node *p = new Node;
		Node *q = new Node;

		p = Front;
		for (int i = 1; i < I - 1; i++)
		{
			p = p->Next;
		}
		q->Next = p->Next;
		q->Elem = newNum;
		p->Next = q;
		Count++;
	}
}



