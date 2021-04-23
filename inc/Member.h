#ifndef MEMBER_H
#define MEMBER_H

#include "Player.h"
#define ENDL std::endl

class Member : public  Player{

  protected:
	
	float PrizeMoney;
	
	int rank;

	bool winner;
       
  public:
    // constructor
    Member() : Player(), PrizeMoney(0), rank(0), winner( false ) {}

	Member(const float& prizeMoneyIn, const int& rankIn, const bool& winnerIn, const STRING& TypeIn, const STRING& MembersIn, const STRING& campIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn) : Player(TypeIn, MembersIn, CampIDIn, CampNameIn, ChallIDIn, ChallTypeIn, CoordinatorIn, WeightAcceptedIn, VolumeIn, EnergyIn, SoundsVolumeIn, YearsIn, SurfaceTempIn, PreprocessesIn), PrizeMoney(prizeMoneyIn), rank(rankIn), winner( winnerIn ) {}

	// destructor
    ~Member() {}

	float get_PrizeMoney () const{
		return PrizeMoney;
	}

	float set_PrizeMoney ( const float& amount ) {
		PrizeMoney = amount;
	}

	int get_rank () const {
		return rank;
	}

	int set_rank ( const int& ranking ) {
		rank = ranking;
	}

	bool get_winner_status () const {
		return winner;
	}

	int set_winner ( const bool& status ) {
		winner = status;
	}

	friend std::ostream& operator<<( std::ostream& output, const Member& memberIn){
		
		output<<ENDL<<ENDL<<"Type: " << memberIn.Type<<ENDL;
		output<<"Members: " << memberIn.Members<<ENDL;
		output<<"Camp ID: " << memberIn.CampID<<ENDL;
		output<<"Camp Name: " << memberIn.CampName<<ENDL;
		output<<"Challenge ID: " << memberIn.ChallID<<ENDL;
		output<<"Challenge Type: " << memberIn.ChallType<<ENDL;
		output<<"Coordinator: " << memberIn.Coordinator<<ENDL;
		output<<"Weight Accepted: " << memberIn.WeightAccepted<<ENDL;
		output<<"Volume: " << memberIn.Volume<<ENDL;
		output<<"Energy: " << memberIn.Energy<<ENDL;
		output<<"Sounds Volume: " << memberIn.CoundsVolume<<ENDL;
		output<<"Years: " << memberIn.Years<<ENDL;
		output<<"Surface Temp: " << memberIn.SurfaceTemp<<ENDL;
		output<<"Preprocesses: " << memberIn.Preprocesses<<ENDL;
		output<<"PrizeMoney: " << memberIn.PrizeMoney<<ENDL;
		output<<"Rank: " << memberIn.rank<<ENDL;
		if( winner ) output<<"Winner!"<<ENDL<<ENDL;
		
		return output;
};

#endif
