


// =========================================================

//HW1P2 
//Your name: Jason Meyer
//Complier:  g++
//File type: implementation file stack.cpp (vector stack)

//================================================================

#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

//constructor needs nothing since we are using a vector
stack::stack()
{ 
	
}

// ** Destructor removes all elements from vector
stack::~stack()
  { 
	
	
	
	}
  
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{

	
	if (this->el.empty())  //checks if vector is empty
	{
		return true;
	}
	else
	{
		return false;

	}
};
    
// ** isFull checks top and returns true if full, false otherwise. 
//For this excersize with vectors, always returns false
bool stack::isFull()
  { return false; }
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
	if (isFull())
	{
		throw Overflow();
	}
    else 
	{ 
		this->el.push_back(elem);
	}
}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
  { 
	if (isEmpty())
	{
		throw Underflow();
	}
    else 
	{ 
		elem = el.back();
		this->el.pop_back();
	}
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
  { 
	if (isEmpty())
	{
		throw Underflow();
	}
    else 
	{ 
		elem = this->el.back(); 
	} 
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
	if (isEmpty()) { cout << "[empty]" << endl; }
	else {
		for (std::vector<el_t>::const_iterator i = el.begin(); i != el.end(); ++i)
		{
			cout << *i << endl;
		}
	}
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt(){

	el_t j;				//since this is a vector we will have to pop everything into a variable until empty  //changed to el-t for hw7p2
	while (!isEmpty())
	{
		
		
		pop(j);

	}

}
