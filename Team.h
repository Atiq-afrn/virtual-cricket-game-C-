#include<vector>
#include"player.h"

 class Team
{

public:
	Team();
	std:: string TeamName;
	 int WicketLost;
	 int TotalballBowled;
	 int TotalRuns;
	 std::vector<Player> playername;
};
