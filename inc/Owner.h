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
		Owner() : Player(), AwardAmount(), ActualCost(), BudgetCost(), EstDollars() {}

		Owner(const float& AwardAmountIn, const float& ActualCostIn, const float& BudgetCostIn, const float& EstDollarsIn, const STRING& TypeIn, const STRING& MembersIn, const STRING& CampIDIn, const STRING& CampNameIn, const STRING& ChallIDIn, const STRING& ChallTypeIn, const STRING& CoordinatorIn, const float& WeightAcceptedIn, const float& VolumeIn, const double& EnergyIn, const float& SoundsVolumeIn, const float& YearsIn, const float& SurfaceTempIn, const bool& PreprocessesIn): Player(TypeIn, MembersIn, CampIDIn, CampNameIn, ChallIDIn, ChallTypeIn, CoordinatorIn, WeightAcceptedIn, VolumeIn, EnergyIn, SoundsVolumeIn, YearsIn, SurfaceTempIn, PreprocessesIn), AwardAmount(AwardAmountIn), ActualCost(ActualCostIn), BudgetCost(BudgetCostIn), EstDollars(EstDollarsIn) {}

		//Destructor
		~Owner(){}

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


