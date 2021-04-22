#ifndef MEMBER_H
#define MEMBER_H

#include "Player.h"

class Member : public  Player{

  protected:
	
	float PrizeMoney;
	
	int rank;

	bool winner;
       
  public:
    // constructor
    Member() : Player( const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn), PrizeMoney(0), rank(0), winner( false ) {}

	Member(const float prizeMoneyIn, const int rankIn, const bool winnerIn) : Player( const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn), PrizeMoney(prizeMoneyIn), rank(rankIn), winner( winnerIn ) {}


    
	const float get_PrizeMoney () {
		return PrizeMoney;
	}

	float set_PrizeMoney ( float amount ) {
		PrizeMoney = amount;
	}

	const int get_rank () {
		return rank;
	}

	int set_rank ( int rank ) {
		rank = ranking;
	}
	const bool get_winner_status () {
		return winner;
	}

	int set_winner ( bool status ) {
		winner = status;
	}

	friend std::ostream& operator<<( std::ostream& output ){
		
		output<<ENDL<<ENDL<<"Type: " << this->Type<<ENDL;
		output<<"Members: " << this->Members<<ENDL;
		output<<"Camp ID: " << this->CampID<<ENDL;
		output<<"Camp Name: " << this->CampName<<ENDL;
		output<<"Challenge ID: " << this->ChallID<<ENDL;
		output<<"Challenge Type: " << this->ChallType<<ENDL;
		output<<"Coordinator: " << this->Coordinator<<ENDL;
		output<<"Weight Accepted: " << this->WeightAccepted<<ENDL;
		output<<"Volume: " << this->Volume<<ENDL;
		output<<"Energy: " << this->Energy<<ENDL;
		output<<"Sounds Volume: " << this->CoundsVolume<<ENDL;
		output<<"Years: " << this->Years<<ENDL;
		output<<"Surface Temp: " << this->SurfaceTemp<<ENDL;
		output<<"Preprocesses: " << this->Preprocesses<<ENDL;
		output<<"PrizeMoney: " << PrizeMoney<<ENDL;
		output<<"Rank: " << rank<<ENDL;
		if( winner ) output<<"Winner!"<<ENDL<<ENDL;

};

#endif
