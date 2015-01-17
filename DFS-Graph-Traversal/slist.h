// ====================================================

//HW3P2 slist
//Your name: Jason Meyer
//Compiler:  g++
//File type: header file - slist.h

//=====================================================
#include"llist.h"

typedef char el_t;
using namespace std;



class slist: public llist			//define slist class to inherit from llist
{
	public:
	
		slist();					//functions
		~slist();

		int search(el_t Key);
		void replace(el_t Elem, int I);
		bool operator==(const slist& OtherOne);		//overloaded equals operator
		slist& operator=(const slist& OtherOne);	//overloaded assignment operator
		slist(const slist& Original);
		

};
