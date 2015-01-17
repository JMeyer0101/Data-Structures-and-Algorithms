


// =======================================================

// HW1P2
// Your name: Jason Meyer
// Compiler:  g++ 
// File type: header file stack.h (vector stack)

//=======================================================

#include<vector>


typedef char el_t;      // the el_t type is int for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        std::vector<el_t>  el;       // el is  a vector of type el_t
       // int      top;           // top is index to the top of stack

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: provide an array to see the top element
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        


		// PURPOSE: check to see if stack has zero elements
      	bool isEmpty();

		//PURPOSE: checks to see if the stack has no more room for additional elements, always returns false
      	bool isFull();  

		//PURPOSE: display all elements of the stack
        void displayAll();

		//PURPOSE:  Pop all elements out of the stack.  Empties the stack.
        void clearIt();
        
  };  

// Note: semicolon is needed at the end of the header file

