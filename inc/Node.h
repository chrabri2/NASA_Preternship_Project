#ifndef NODE_H
#define NODE_H

#include <cstdlib>	/* For NULL */

/* NODE contains the data and a pointer to the next node */
template< class T >
struct node
{
	/* Public struct members */
	T     data;
	node<T>* next;
	node<T>* prev;
	
	/* Default constructor */
	node() : data(), next(NULL), prev(NULL) { }
	
	/* Overloaded constructor */
	node(const T& dataIn) : data(dataIn), next(NULL), prev(NULL) { }
	
	/* Destructor */
	~node(){
		
		delete next;
		
	}
	

	/* Copy constructor (*/
	node(const node<T>& copy) : data( copy.data ), next( NULL ), prev( NULL ) { }
	
	
	/* Assignment Operator */
	node<T>& operator=(const node<T>& assign){
		
		if(this != &assign){
			this->data = assign.data;
			this->next = NULL;
			this->prev = NULL;
		}
		return *this;
	}
	
	
	/* Node pointer assignment operator */
	node<T>* operator=(const node<T>* assign){
		
		if(this != (void *)&assign){
			this->data = assign->data;
			this->next = NULL;
			this->prev = NULL;
		}
		return *this;
	}
	
	/* Node != operator */
	bool operator!=(const node<T>* rhs){
		
		return this != (void *)&rhs;
		
	}
	
};



#endif
