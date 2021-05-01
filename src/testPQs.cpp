// Max and Min Priority Queue Test Script
// NASA Preternship Group

#include "../inc/MaxPriorityQueue.h"
#include "../inc/MinPriorityQueue.h"

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main() {
  // Declare arrays of double and char test values
  double  dArray[5] = {2.45, 17.94, 8.45, 1, 150.68};

  // Double Max and Min PQ Test
  COUT << "Max & Min Double Priority Queue Test" << ENDL;
  COUT << "Pre-Sort Doubles" << ENDL;
  
  // Declare Double Max & Min PQ
  MaxPriorityQueue<double> dMaxPQ;
  MinPriorityQueue<double> dMinPQ;
  double val;

  // Print Pre-sort Values & Push Them to PQ
  for(int i = 0; i < 5; i++) {
    COUT << dArray[i] << " ";
    dMaxPQ.push(dArray[i]);
    dMinPQ.push(dArray[i]);
  }
  COUT << ENDL;
   
  // Print Max Sorted Values
  COUT << "Max PQ Sorted Doubles" << ENDL;
  while(!dMaxPQ.empty()){
    val = dMaxPQ.top();
    COUT << val << " ";
    dMaxPQ.pop();
  }
  COUT << ENDL;

  // Print Min Sorted Values
  COUT << "Min PQ Sorted Doubles" << ENDL;
  while(!dMinPQ.empty()){
    val = dMinPQ.top();
    COUT << val  << " ";
    dMinPQ.pop();
  }
  COUT << ENDL;

  return 0;
}
