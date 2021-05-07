#ifndef OWNER_H
#define OWNER_H

#include "Player.h"


class Owner : public Player{

	private: 

	//Challange Owner information
	float AwardAmount;
	float ActualCost;
	float BudgetCost;
	float EstDollars;

	//Money Saved method
	float moneySaved() const {	
		return BudgetCost - ActualCost;
	}
	
	

	public:

		//Constructors
		// Null
		Owner() : Player(), AwardAmount(), ActualCost(), BudgetCost(), EstDollars() {}
		
		// Standard
		Owner(const float& AwardAmountIn, const float& ActualCostIn, const float& BudgetCostIn, const float& EstDollarsIn, const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn): Player(TypeIn, MembersIn, CampIDIn, CampNameIn, ChallIDIn, ChallTypeIn, CoordinatorIn, WeightAcceptedIn, VolumeIn, EnergyIn, SoundsVolumeIn, YearsIn, SurfaceTempIn, PreprocessesIn), AwardAmount(AwardAmountIn), ActualCost(ActualCostIn), BudgetCost(BudgetCostIn), EstDollars(EstDollarsIn) {}
		
		// Copy
		Owner(const Owner& owner_in) : Player(owner_in.Type, owner_in.Members, owner_in.CampID, owner_in.CampName, owner_in.ChallID, owner_in.ChallType, owner_in.Coordinator, owner_in.WeightAccepted, owner_in.Volume, owner_in.Energy, owner_in.SoundsVolume, owner_in.Years, owner_in.SurfaceTemp, owner_in.Preprocesses), AwardAmount(owner_in.AwardAmount), ActualCost(owner_in.ActualCost), BudgetCost(owner_in.BudgetCost), EstDollars(owner_in.EstDollars) {}
		
		// Assignment operator
		Owner& operator=(const Owner& rhs) {
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
			this->AwardAmount = rhs.AwardAmount;
			this->ActualCost = rhs.ActualCost;
			this->BudgetCost = rhs.BudgetCost;
			this->EstDollars = rhs.EstDollars;
			
			return *this;
		}
		
		//Destructor
		~Owner() {};

		// get methods
			float get_AwardAmount() const{
				return AwardAmount;
			}

			float get_ActualCost() const{
				return ActualCost;
			}

			float get_BudgetCost() const{
				return BudgetCost;
			}
		
			float get_EstDollars() const{
				return EstDollars;
			}

			float get_moneySaved() const{
				return moneySaved();
			}


		//Friend methods/operators for Owner Class methods/info
		friend std::ostream& operator<<( std::ostream& output, const Owner& c_owner){
			output << "Actual Award Amount/Prize Amount ($):  " << c_owner.AwardAmount << std::endl;
			output << "Actual Cost in Campaign ($): " << c_owner.ActualCost<< std::endl;
			output << "Budgeted Cost in Campaign ($): " << c_owner.BudgetCost << std::endl;
			output << "Estimated Dollars ($): " << c_owner.EstDollars << std::endl;

			output << "Money Saved ($): " << c_owner.moneySaved() << std::endl;
			
			return output;
		}


};

#endif


