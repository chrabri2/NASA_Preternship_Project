#ifndef DLLIST_H
#define DLLIST_H


#include "Node.h"

#include <cstdlib>
#include <iostream>


template<class T>

class DLList{
	private:

		node<T>* head;
		node<T>* tail;

	public: 
		//default const
		DLList() : head(NULL), tail(NULL) {}
		
		//destructor
		~DLList(){
			delete head;
		}
	
		//constructor
		DLList(const DLList<T>& copy): head(NULL), tail(NULL){	
			node<T>* curr = copy.head;
			
			while(curr != NULL){	
				Insert(curr->data);
				curr = curr->next;
			}

		}




	// Assignment operator for SLL
	DLList<T>& operator=(DLList<T>&assign){
		if(this != &assign){
			node<T>* curr = assign.head;

			while(curr != NULL){
				this->Insert(curr->data);
				curr = curr->next;
			}

		}

	return *this;
		

	}

	//Insert func that creates a node witha value and inserts it at the end of the SLList
	void Insert(const T& value){
		
		node<T>* temp = new node<T>(value);
	

		if( IsEmpty()){
			head = temp; 
			tail = temp;
		}
		else
		{
			node<T>* prev = NULL;
			node<T>* curr = head;
			
			//traverse list until end
			while(curr != NULL){
				prev = curr; 
				curr = curr->next;
			}
				

			//insert node temp at the end, allocate the prev node and allocate the tail
			prev -> next = temp;
			prev -> next -> prev = prev;
			tail = prev -> next; 

		}

	}

	void SortInsert(const T& value){
		node<T>* temp = new node<T>(value);

		if( IsEmpty()){
			head = temp;
			tail = temp;
		}
		else if(value >= head->data){
			push_front(value);

		}
		else if(value <= tail->data){
			push_back(value);
		}
		else{
			node<T>* prev = NULL;
			node<T>* curr = head;
				
			while(curr != NULL && curr->data > value)
			{
				prev = curr;
				curr = curr->next;
			}
				prev->next = temp;
				curr->prev = temp;
				temp->prev = prev;
				temp->next = curr;
			
		}


	}


	//push to the front of the list /back (puts element at front // at back) 
	void push_front(const T& value){

		if(IsEmpty()){
			Insert(value);
		}
		else{

			//create new node
			node<T>* temp = new node<T>(value);
			
			temp->next = head;
			head->prev = temp;
			head = temp;


		}
	}

	void push_back(const T& value){

		if(IsEmpty()){
			Insert(value);
		}
		else{
			//create new node
			node<T>* temp = new node<T>(value);
			
			temp->next = tail;
			tail->prev = temp;
			tail = temp;

		}


	}

	// delete first instance of data 
	bool Delete(const T& target){
		node<T>* temp = new node<T>(); node<T>* prev = new node<T>(); node<T>* curr = new node<T>();

		if( IsEmpty()){
			std::cout << "Can't delete from an empty list"<< std::endl;
			return (-1); // returns -1 if not found
		}

		else if(target == head->data){
			if(head == tail){
				temp = head; 
				head = NULL;
				tail = NULL;
				free(temp);
				return true;
			}
			else{
				temp = head;
				head = head ->next;
				free(temp);
				return true;
			}
		}

		else{
			prev = head;
			curr = curr -> next;
			
			while(curr != NULL && curr -> data != target){
				prev = curr;
				curr = curr -> next;
			}

			if(curr !=NULL){
				//deletes the node with the target val
				temp = curr;
				
				if(curr = tail){
					tail = prev;
				}
				
				prev->next = curr->next;
				free(temp);

				if(prev->next != NULL){
					prev->next->prev = prev;
				}
				
				return true;

			}

			else{
				std::cout << target << "was not in the list" <<std::endl;
				return false;
			}
		}		

	}
	

	//is empty to check if list cont values
	bool IsEmpty() const{
		return head == NULL && tail == NULL;
	}

	//Function that searches list to see if it contains element
	bool contains(const T& searchVal) const{
		if(IsEmpty()){
				return false;
		}
		else{
			node<T>* curr = head;

			while(curr != NULL && curr->data != searchVal){
				curr = curr -> next;
			}
				
			return curr != NULL;

		}

	}
	
	//pop_front (used to remove values off front)
	bool pop_front(){
		if(IsEmpty()){
			std::cout << "Can't delete from empty list" << std::endl;
			return (-1);
		}
		
		//target is head (front of list)
		node<T>* temp = new node<T>();
		
		if(head == tail){
			temp = head;
			head = NULL;
			tail = NULL;
			free(temp);
			return true;
		}
		else{
			temp = head;
			head = head->next;
			head->prev = NULL;
			free(temp);
			return true;
		}

	}

	T front() const{
		return head->data;

	}


	T back(){
		return tail->data;
	}
	
	//friend operator to print out values **Go back and modify this accordinly**
	
	friend std::ostream& operator<<(std::ostream& output, const DLList<T>& theList){

		node<T>* curr;

		if(theList.IsEmpty()){
			output << "List is empty" << std::endl;

		}
		else{
			// set ptr to first node of list 
			curr = theList.head;
	
			while(curr != NULL){
				// print out current data item
				output << curr->data << " ";

				//move to next element
				curr = curr -> next; 

			}
		}
		
		return output;

	}

};
#endif
