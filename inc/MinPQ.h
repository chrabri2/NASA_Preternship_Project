#ifndef MINPQ_H
#define MINPQ_H

#include "DLList.h"

template<class T>
class MinPriorityQueue {

	private:
		DLList<T> PQList;
	public:
		//Default Constructor
		MinPriorityQueue(): PQList(){}

		//methods
		void push(const T& value){	
			PQList.SortInsert(value);
		}
			
		void pop(){
			if(!PQList.IsEmpty()){
				PQList.pop_back();
			}
		}


		T top(){
			return PQList.back();

		}
		
		bool empty(){

			return PQList.IsEmpty();

		}

};
#endif
