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
#include <cstdio>
#include <unistd.h>

#define COUT std::cout
#define ENDL std::endl

int main() {
  // initialize variables
  int nSolns = 7;
  Member solutions[7]; //= malloc(7*sizeof(Member));
  Owner challengeOwner;
  int scores[7] = {0, 0, 0, 0, 0, 0, 0};

  // READ IN CSV DATA
	//Solutions
  // filenames (hard coded in [at the moment])
	const char* filein_s = "solutions.csv";
	const char* fileout_s = "solutionsout.csv";	
	//csv reader for solutions files
	CSVReader read_solutions(fileout_s, filein_s);
	//checks if read in solutions class line by line
	for (int i = 0; i < nSolns; i++) {
		read_solutions.readline(solutions[i]);
	}
	//close reader
	read_solutions.close();

  //Owner
	//filenames (hard coded in [at the moment])
	const char* fileout_v = "vendorout.csv";
	const char* filein_v = "vendor.csv";
	//read in owner csv
	CSVReader read_owner(fileout_v, filein_v); 
	//checks if line read in for Owner class
	read_owner.readline(challengeOwner);
  read_owner.close();


  // PRIORITY QUEUES
  MaxPriorityQueue<float> weightAcceptedPQ;
  MinPriorityQueue<float> volumePQ;
  MaxPriorityQueue<double> energyPQ;
  MinPriorityQueue<float> soundsVolumePQ;
  MinPriorityQueue<float> yearsPQ;
  MinPriorityQueue<float> surfaceTempPQ; 
  
  // RANKINGS with indices
  int weightAcceptedRank[3] = {0};
  int volumeRank[3] = {0};
  int energyRank[3] = {0};
  int soundsVolumeRank[3] = {0};
  int yearsRank[3] = {0};
  int surfaceTempRank[3] = {0};

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
		weightAcceptedRank[k] = j;
      }
      if(volumePQ.top() == solutions[j].get_Volume()) {
        scores[j] += (3 - k);
		volumeRank[k] = j;
      }
      if(energyPQ.top() == solutions[j].get_Energy()) {
        scores[j] += (3 - k);
		energyRank[k] = j;
      }
      if(soundsVolumePQ.top() == solutions[j].get_SoundsVolume()) {
        scores[j] += (3 - k);
		soundsVolumeRank[k] = j;
      }
      if(yearsPQ.top() == solutions[j].get_Years()) {
        scores[j] += (3 - k);
		yearsRank[k] = j;
      }
      if(surfaceTempPQ.top() == solutions[j].get_SurfaceTemp()) {
        scores[j] += (3 - k);
		surfaceTempRank[k] = j;
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
  
  

  int winnerIndices[3] = {0};  
  for (int o = 0; o < 7; o++) {
    for(int n = 0; n < nSolns; n++) {
      if(scoresPQ.top() == scores[n]) {
        winnerIndices[o] = n;
      }
    }
    scoresPQ.pop();
  }

	// set winner attributes	
  solutions[winnerIndices[0]].set_winner(true);
  solutions[winnerIndices[0]].set_PrizeMoney(challengeOwner.get_AwardAmount());
  
  // Graphics output
  // pixels
  int xlength = 1080;
  int ylength = 720;
  char *title = (char *)"CoECISimulator";
  
  gfx_open(xlength, ylength, title);
  bool graphics_run = 1;
  int key = 0;
  const char *first = (char *)"";
  const char *second = (char *)"";
  const char *third = (char *)"";
  float first_score = 0.0;
  float second_score = 0.0;
  float third_score = 0.0;
  int first_index = 0;
  int second_index = 0; 
  int third_index = 0;
  int status;
  draw_frame(key, xlength, ylength, first, (int)first_score, second, (int)second_score, third, (int)third_score);

  // Event loop
  while (graphics_run) {
    status = gfx_event_waiting();
	
	if (status) {
	key = gfx_wait();
	bool update = false;
	switch(key) {
	  case 'q': graphics_run = false; break;
	  case '1': 
	  	first_index = surfaceTempRank[0];
		second_index = surfaceTempRank[1];
		third_index = surfaceTempRank[2];
		first_score = solutions[first_index].get_SurfaceTemp();
		second_score = solutions[second_index].get_SurfaceTemp();
		third_score = solutions[third_index].get_SurfaceTemp();
		update = true;
	  break;
	  case '2': break;
	  	first_index = yearsRank[0];
		second_index = yearsRank[1];
		third_index = yearsRank[2];
		first_score = solutions[first_index].get_Years();
		second_score = solutions[second_index].get_Years();
		third_score = solutions[third_index].get_Years();
		update = true;
	  case '3': break;
	  	first_index = soundsVolumeRank[0];
		second_index = soundsVolumeRank[1];
		third_index = soundsVolumeRank[2];
		first_score = solutions[first_index].get_SoundsVolume();
		second_score = solutions[second_index].get_SoundsVolume();
		third_score = solutions[third_index].get_SoundsVolume();
		update = true;
	  case '4': break;
	  	first_index = energyRank[0];
		second_index = energyRank[1];
		third_index = energyRank[2];
		first_score = (float)(solutions[first_index].get_Energy());
		second_score = (float)(solutions[second_index].get_Energy());
		third_score = (float)(solutions[third_index].get_Energy());
		update = true;
	  case '5': break;
	  	first_index = volumeRank[0];
		second_index = volumeRank[1];
		third_index = volumeRank[2];
		first_score = solutions[first_index].get_Volume();
		second_score = solutions[second_index].get_Volume();
		third_score = solutions[third_index].get_Volume();
		update = true;
	  case '6': break;
	  	first_index = weightAcceptedRank[0];
		second_index = weightAcceptedRank[1];
		third_index = weightAcceptedRank[2];
		first_score = solutions[first_index].get_WeightAccepted();
		second_score = solutions[second_index].get_WeightAccepted();
		third_score = solutions[third_index].get_WeightAccepted();
		update = true;
	  case '7': break;
	  	first_index = winnerIndices[0];
		second_index = winnerIndices[1];
		third_index = winnerIndices[2];
		first_score = (float)scores[first_index];
		second_score = (float)scores[second_index];
		third_score = (float)scores[third_index];
		update = true;
	}
	first = solutions[first_index].get_Type().data();
	second = solutions[second_index].get_Type().data();
	third = solutions[third_index].get_Type().data();
	if (update) {
	  draw_frame(key, xlength, ylength, first, (int)first_score, second, (int)second_score, third, (int)third_score);
	}
	}

  }
  
  // FINAL OUTPUT
  COUT << "First Place Solution" << ENDL;
  COUT << solutions[winnerIndices[0]] << ENDL << ENDL;
  COUT << "Second Place Solution" << ENDL;
  COUT << solutions[winnerIndices[1]] << ENDL << ENDL;
  COUT << "Third Place Solution" << ENDL;
  COUT << solutions[winnerIndices[2]] << ENDL << ENDL;

  //free(solutions);
  //free(challengeOwner);
  return 0;
}
