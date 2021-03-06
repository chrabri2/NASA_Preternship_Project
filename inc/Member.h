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
    // constructors
	// Empty
    Member() : Player(), PrizeMoney(0), rank(0), winner( false ) {}
	
	// Standard
	Member(const float& prizeMoneyIn, const int& rankIn, const bool& winnerIn, const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn) : Player(TypeIn, MembersIn, CampIDIn, CampNameIn, ChallIDIn, ChallTypeIn, CoordinatorIn, WeightAcceptedIn, VolumeIn, EnergyIn, SoundsVolumeIn, YearsIn, SurfaceTempIn, PreprocessesIn), PrizeMoney(prizeMoneyIn), rank(rankIn), winner( winnerIn ) {}
	
	// Copy
	Member(const Member& member_in) : Player(member_in.Type, member_in.Members, member_in.CampID, member_in.CampName, member_in.ChallID, member_in.ChallType, member_in.Coordinator, member_in.WeightAccepted, member_in.Volume, member_in.Energy, member_in.SoundsVolume, member_in.Years, member_in.SurfaceTemp, member_in.Preprocesses), PrizeMoney(member_in.PrizeMoney), rank(member_in.rank), winner(member_in.winner) {};
	
	// Assignment Operator
	Member& operator=(const Member& rhs) {
		if (this == &rhs)
			return *this;
		
		this->Type = rhs.Type;
		this->Members = rhs.Members;
		this->CampID = rhs.CampID;
		this->CampName = rhs.CampName;
		this->ChallID = rhs.ChallID;
		this->ChallType = rhs.ChallType;
		this->Coordinator = rhs.Coordinator;
		this->WeightAccepted = rhs.WeightAccepted;
		this->Volume = rhs.Volume;
		this->Energy = rhs.Energy;
		this->SoundsVolume = rhs.SoundsVolume;
		this->Years = rhs.Years;
		this->SurfaceTemp = rhs.SurfaceTemp;
		this->Preprocesses = rhs.Preprocesses;
		this->PrizeMoney = rhs.PrizeMoney;
		this->rank = rhs.rank;
		this->winner = rhs.winner;
		
		return *this;
	}
	
	// destructor
    ~Member() {}; 
    
	float get_PrizeMoney () const{
		return PrizeMoney;
	}

	void set_PrizeMoney ( const float& amount ) {
		PrizeMoney = amount;
	}

	int get_rank () const {
		return rank;
	}

	void set_rank ( const int& ranking ) {
		rank = ranking;
	}

	bool get_winner_status () const {
		return winner;
	}

	void set_winner ( const bool& status ) {
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
		output<<"Sounds Volume: " << memberIn.SoundsVolume<<ENDL;
		output<<"Years: " << memberIn.Years<<ENDL;
		output<<"Surface Temp: " << memberIn.SurfaceTemp<<ENDL;
		output<<"Preprocesses: " << memberIn.Preprocesses<<ENDL;
		output<<"PrizeMoney: " << memberIn.PrizeMoney<<ENDL;
//		output<<"Rank: " << memberIn.rank<<ENDL;
		if( memberIn.winner ) output<<"Winner!"<<ENDL<<ENDL;
		
		return output;
	}
};

#endif
