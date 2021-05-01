// Max and Min Priority Queue Test Script
// NASA Preternship Group

#include "../inc/MaxPriorityQueue.h"
#include "../inc/MinPriorityQueue.h"

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main() {
  // Declare array of double test values
  double  dArray[5] = {2.45, 17.94, 8.45, 1, 150.68};

  // Double Max and Min PQ Test
  COUT << "**Max & Min Double Priority Queue Test**" << ENDL;
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
  COUT << ENDL;

  // Declare array of char test values
  char cArray[12] = "PreTERnsHIp";

  // Double Max and Min PQ Test
  COUT << "**Max & Min Char Priority Queue Test**" << ENDL;
  COUT << "Pre-Sort Chars" << ENDL;
  
  // Declare Double Max & Min PQ
  MaxPriorityQueue<char> cMaxPQ;
  MinPriorityQueue<char> cMinPQ;
  char letter;

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
    letter = cMaxPQ.top();
    COUT << letter << " ";
    cMaxPQ.pop();
  }
  COUT << ENDL;

  // Print Min Sorted Values
  COUT << "Min PQ Sorted Chars" << ENDL;
  while(!cMinPQ.empty()){
    letter = cMinPQ.top();
    COUT << letter << " ";
    cMinPQ.pop();
  }
  COUT << ENDL;
  
  return 0;
}
