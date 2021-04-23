#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <cstdbool>
#include <cstdlib>

#define STRING std::string

class Player{

  protected:
    // Challenge Player Identifiers
    STRING Type;
    STRING Members;
    STRING CampID;
    STRING CampName;
    STRING ChallID;
    STRING ChallType;
    STRING Coordinator;
    // Challenge Design Considerations
    float WeightAccepted;
    float Volume;
    double Energy;
    float SoundsVolume;
    float Years;
    float SurfaceTemp;
    bool Preprocesses;
    
  public:
    // constructors
	Player() : Type(), Members(), CampID(), CampName(), ChallID(), ChallType(), Coordinator(), WeightAccepted(), Volume(), Energy(), SoundsVolume(), Years(), SurfaceTemp(), Preprocesses() {}

    Player( const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn) : Type(TypeIn), Members(MembersIn), CampID(CampIDIn), CampName(CampNameIn), ChallID(ChallIDIn), ChallType(ChallTypeIn), Coordinator(CoordinatorIn), WeightAccepted(WeightAcceptedIn), Volume(VolumeIn), Energy(EnergyIn), SoundsVolume(SoundsVolumeIn), Years(YearsIn), SurfaceTemp(SurfaceTempIn), Preprocesses(PreprocessesIn) {}
	
	virtual ~Player() {}
	
    // get methods
    float get_WeightAccepted() const {
      return WeightAccepted;
    }

    float get_Volume() const{
      return Volume;
    }

    double get_Energy() const{
      return Energy;
    }

    float get_SoundsVolume() const{
      return SoundsVolume;
    }

    float get_Years() const{
      return Years;
    }

    float get_SurfaceTemp() const{
      return SurfaceTemp;
    }
  
    bool get_Preprocess() const{
      return Preprocesses;
    }

};

#endif
