// CoECI Simulator 
// NASA Preternship Team
// Rebecca Hunt, Ana Sofia Gonzalez, Maria Markert, Carter Hrabrick
// Final simulator that 
//  - takes in CSV data
//  - compares the different data entries using min & max PQs
//  - calculates the top 3 winning designs
//  - produces the final outputs

#include "../inc/csvio.h"
#include "../inc/Node.h"
#include "../inc/DLList.h"
#include "../inc/MaxPriorityQueue.h"
#include "../inc/MinPriorityQueue.h"
#include "../inc/Player.h"
#include "../inc/Member.h"
#include "../inc/Owner.h"

#define COUT std::cout
#define ENDL std::endl

int main() {
  // initialize variables
  int nSolns = 7;
  Member solutions[nSolns] = malloc(7*sizeof(Member));
  Owner challengeOwner = malloc(sizeof(Owner));
  int scores[nSolns] = {0, 0, 0, 0, 0, 0, 0};
  int first = 3;
  int second = 2;
  int third = 1;

  // READ IN CSV DATA
  // read in solutions


  // read in owner

  // PRIORITY QUEUES
  MaxPriorityQueue<float> weightAcceptedPQ;
  MinPriorityQueue<float> volumePQ;
  MaxPriorityQueue<double> energyPQ;
  MinPriorityQueue<float> soundsVolumePQ;
  MinPriorityQueue<float> yearsPQ;
  MinPriorityQueue<float> surfaceTempPQ; 

  // push values for wach 
  for(int i = 0; i < nSolns; i++) {
    weightAcceptedPQ.push(solutions[i].get_WeightAccepted());
    volumePQ.push(solutions[i].get_Volume());
    energyPQ.push(solutions[i].get_Energy());
    soundsVolumePQ.push(solutions[i].get_SoundsVolume());
    yearsPQ.push(solutions[i].get_Years());
    surfaceTempPQ(solutions[i].get_SurfaceTemp());
  }
  
  // CALCULATE SCORES
  // priority queues
  for(int k = 0; k < 3; k++) { // 1st, 2nd, 3rd  index
    for(int j = 0; i < nSolns; j++) { // solution index
      if(weightAcceptedPQ.top() == solutions[i].get_WeightAccepted()) {
        scores[j] += (3 - k);
      }
      if(volumePQ.top() == solutions[i].get_Volume()) {
        scores[j] += (3 - k);
      }
      if(energyPQ.top() == solutions[i].get_Energy()) {
        scores[j] += (3 - k);
      }
      if(soundsVolumePQ.top() == solutions[i].get_SoundsVolume()) {
        scores[j] += (3 - k);
      }
      if(yearsPQ.top() == solutions[i].get_Years()) {
        scores[j] += (3 - k);
      }
      if(surfaceTempPQ.top() == solutions[i].get_SurfaceTemp()) {
        scores[j] += (3 - k);
      }
    }
    weightAcceptedPQ.pop();
    volumePQ.pop();
    energyPQ.pop();
    soundsVolumePQ.pop();
    yearsPQ.pop();
    surfactTempPQ.pop();
  }

  for(int l = 0; l < nSolns; l++) {
    if(solutions[i].get_Preprocess()) {
      scores[j]++;
    }
  }

  // insert scores into maxPQ
  MaxPriorityQueue<int> scoresPQ;
  for(int m = 0; m < nSolns; m++) {
     scoresPQ.push(scores[m]);
  }
  
  int winnerIndicies[3] = {0, 0, 0};  
  for (int o = 0; o < 3; o++) {
    for(int n = 0; n < nSolns; n++) {
      if(scoresPQ.top() == scores[n]) {
        winnerIndicies[o] = n;
      }
    }
    scoresPQ.pop();
  }

  // FINAL OUTPUT
  COUT << "First Place Solution" << ENDL;
  COUT << solution[winnerIndicies[0]] << ENDL << ENDL;
  COUT << "Second Place Solution" << ENDL;
  COUT << solution[winnerIndicies[1]] << ENDL << ENDL;
  COUT << "Third Place Solution" << ENDL;
  COUT << solution[winnerIndicies[2]] << ENDL << ENDL;

  free(solutions);
  free(challengeOwner);
  return 0;
}
