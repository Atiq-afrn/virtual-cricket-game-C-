
#include"Team.h" // #include<string> #include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;

class Game
{
    public:
	Game();
	int PlayerPerTeam;
	int Maxball=6;
	int TotalPlayers;
	std::string Players[11];

	bool IsFirstinnings;
	Team TeamA, TeamB;

	Team *battingTeam;
	Team *bowlingTeam;

	Player *batsman;
	Player *bowler;
	void Welcome();
	void showAllplayers();
	int TakeIntegerValue();
	void SelectPLayer();
	bool ValidatePlayers(int);
	void showSelectedPlayers();
	void Toss();
	void Tosschoice(Team);
	void startFirstInning();
	void InitializePlayer();
	void PlayInning();
	void bat();
	bool ValidiatingInningScore();
	void Showgamescorecard();
	void StartSecondInning();
	void ShowMatchSummry();


};
