// Max and Min Priority Queue Test Script
// NASA Preternship Group

#include "../inc/MaxPQ.h"
#include "../inc/MinPQ.h"

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main() {
  // Declare arrays of float and char test values
  float fArray[5] = {2.56, 17.94, 8.45, 1, 150.68};
  char cArray[] = "PreTERnsHIp";

  // Float Max and Min PQ Test
  COUT << "Max & Min Float Priority Queue Test" << ENDL;
  COUT << "Pre-Sort Floats" << ENDL;
  
  // Declare Float Max & Min PQ
  PriorityQueue<float> fMaxPQ;
  MinPriorityQueue<float> fMinPQ;

  // Print Pre-sort Values & Push Them to PQ
  for(int i = 0; i < 5; i++) {
    COUT << fArray[i] << " ";
    fMaxPQ.push(fArray[i]);
    fMinPQ.push(fArray[i]);
  }
  COUT << ENDL;
  
  // Print Max Sorted Values
  COUT << "Max PQ Sorted Floats" << ENDL;
  while(!fMaxPQ.empty()){
    COUT << fMaxPQ.top() << " ";
    fMaxPQ.pop();
  }
  COUT << ENDL;

  // Print Min Sorted Values
  COUT << "Min PQ Sorted Floats" << ENDL;
  while(!fMinPQ.empty()){
    COUT << fMinPQ.top() << " ";
    fMinPQ.pop();
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
