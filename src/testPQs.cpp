// Max and Min Priority Queue Test Script
// NASA Preternship Group

#include "../inc/MaxPQ.h"
#include "../inc/MinPQ.h"

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main() {
  // Declare arrays of double and char test values
  double  dArray[5] = {2.45, 17.94, 8.45, 1, 150.68};
  char cArray[] = "PreTERnsHIp";

  // Double Max and Min PQ Test
  COUT << "Max & Min Double Priority Queue Test" << ENDL;
  COUT << "Pre-Sort Doubles" << ENDL;
  
  // Declare Double Max & Min PQ
  PriorityQueue<double> dMaxPQ;
  MinPriorityQueue<double> dMinPQ;

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
    COUT << dMaxPQ.top() << " ";
    dMaxPQ.pop();
  }
  COUT << ENDL;

  // Print Min Sorted Values
  COUT << "Min PQ Sorted Doubles" << ENDL;
  while(!dMinPQ.empty()){
    COUT << dMinPQ.top() << " ";
    dMinPQ.pop();
  }
  COUT << ENDL;

  // Char Max and Min PQ Test
  COUT << ENDL;
  COUT << "Max & Min Char Priority Queue Test" << ENDL;
  COUT << "Pre-Sort Chars" << ENDL;
  COUT << "PreTERnsHIp" << ENDL;

  // Declare Char Max and Min PQ
  PriorityQueue<char> cMaxPQ;
  MinPriorityQueue<char> cMinPQ;
  
  // Print Pre-sort Values & Push Them to PQ
  for(int i = 0; i < 11; i++) {
    COUT << cArray[i] << " ";
    cMaxPQ.push(cArray[i]);
    cMinPQ.push(cArray[i]);
  }
  COUT << ENDL;

  // Print Max Sorted Values
  COUT << "Max PQ Sorted Chars" << ENDL;
  while(!cMaxPQ.empty()){
    COUT << cMaxPQ.top() << " ";
    cMaxPQ.pop();
  }
  COUT << ENDL;

  // Print Min Sorted Values
  COUT << "Min PQ Sorted Chars" << ENDL;
  while(!cMinPQ.empty()){
    COUT << cMinPQ.top() << " ";
    cMinPQ.pop();
  }
  COUT << ENDL;

  return 0;
}
