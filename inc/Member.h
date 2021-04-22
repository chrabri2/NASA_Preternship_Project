#ifndef MEMBER_H
#define MEMBER_H

#include "Player.h"

class Member : public  Player{

  protected:
       
  public:
    // constructor
    Member() : Player( const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn) {}

    
	~Member() {}	

};

#endif
