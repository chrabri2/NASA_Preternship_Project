// CoECI Simulator 
// NASA Preternship Team
// Rebecca Hunt, Ana Sofia Gonzalez, Maria Markert, Carter Hrabrick
// Final simulator that 
//  - takes in CSV data
//  - compares the different data entries using min & max PQs
//  - calculates the top 3 winning designs
//  - displays graphical information
//  - produces the final outputs

#include "../inc/CSVReader.h"
#include "../inc/Node.h"
#include "../inc/DLList.h"
#include "../inc/MaxPriorityQueue.h"
#include "../inc/MinPriorityQueue.h"
#include "../inc/Player.h"
#include "../inc/Member.h"
#include "../inc/Owner.h"
#include "../inc/graphics.h"

#define COUT std::cout
#define ENDL std::endl

int main() {
  // initialize variables
  int nSolns = 7;
  Member solutions[7]; //= malloc(7*sizeof(Member));
  Owner *challengeOwner = new Owner;
  int scores[7] = {0, 0, 0, 0, 0, 0, 0};

  // READ IN CSV DATA
	//Solutions
  // filenames (hard coded in [at the moment])
	const char* filein_s = "solutions.csv";
	const char* fileout_s = "solutionsout.csv";	
	//csv reader for solutions files
	CSVReader read_solutions(filein_s, fileout_s);
	//checks if read in solutions class line by line
		//read_solutions.readline(solutions);
	//close reader
	read_solutions.close();

  //Owner
	//filenames (hard coded in [at the moment])
	const char* fileout_v = "vendorout.csv";
	const char* filein_v = "vendor.csv";
	//read in owner csv
	CSVReader read_owner(filein_v, fileout_v); 
	//checks if line read in for Owner class
		//	read_owner.readline(challengeOwner);	



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
    surfaceTempPQ.push(solutions[i].get_SurfaceTemp());
  }
  
  // CALCULATE SCORES
  // priority queues
  for(int k = 0; k < 3; k++) { // 1st, 2nd, 3rd  index
    for(int j = 0; j < nSolns; j++) { // solution index
      if(weightAcceptedPQ.top() == solutions[j].get_WeightAccepted()) {
        scores[j] += (3 - k);
      }
      if(volumePQ.top() == solutions[j].get_Volume()) {
        scores[j] += (3 - k);
      }
      if(energyPQ.top() == solutions[j].get_Energy()) {
        scores[j] += (3 - k);
      }
      if(soundsVolumePQ.top() == solutions[j].get_SoundsVolume()) {
        scores[j] += (3 - k);
      }
      if(yearsPQ.top() == solutions[j].get_Years()) {
        scores[j] += (3 - k);
      }
      if(surfaceTempPQ.top() == solutions[j].get_SurfaceTemp()) {
        scores[j] += (3 - k);
      }
    }
    weightAcceptedPQ.pop();
    volumePQ.pop();
    energyPQ.pop();
    soundsVolumePQ.pop();
    yearsPQ.pop();
    surfaceTempPQ.pop();
  }

  for(int l = 0; l < nSolns; l++) {
    if(solutions[l].get_Preprocesses()) {
      scores[l]++;
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

	// set winner attributes	
  solutions[winnerIndicies[0]].set_winner(true);
  solutions[winnerIndicies[0]].set_PrizeMoney(challengeOwner->get_AwardAmount());
  
  // Graphics output
  
  
  
  // FINAL OUTPUT
  COUT << "First Place Solution" << ENDL;
  COUT << solutions[winnerIndicies[0]] << ENDL << ENDL;
  COUT << "Second Place Solution" << ENDL;
  COUT << solutions[winnerIndicies[1]] << ENDL << ENDL;
  COUT << "Third Place Solution" << ENDL;
  COUT << solutions[winnerIndicies[2]] << ENDL << ENDL;

  //free(solutions);
  free(challengeOwner);
  return 0;
}
