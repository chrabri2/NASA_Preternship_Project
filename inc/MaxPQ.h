#ifndef MAXPQ_H
#define MAXPQ_H

#include "DLList.h"

template<class T>
class PriorityQueue {

	private:
		DLList<T> PQList;
	public:
		//Default Constructor
		PriorityQueue(): PQList(){}

		//methods
		void push(const T& value){	
			PQList.SortInsert(value);
		}
			
		void pop(){
			if(!PQList.IsEmpty()){
				PQList.pop_front();
			}
		}


		T top()
		{
      T valueT;
      valueT = PQList.front();
      return valueT;
		}
		
		bool empty(){

			return PQList.IsEmpty();

		}

};
#endif
