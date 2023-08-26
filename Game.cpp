#include"Game.h"
Game::Game()
{

	int PlayerPerTeam=4;
	int Maxball=6;
	int TotalPlayers=11;
	

	Players[0] = "Atiq khan";
	Players[1] = "Bahadur khan";
	Players[2] = "Ishaq khan";
	Players[3] = "salman khan"; 
	Players[4] = "Arshad khan";
	Players[5] = "Ashab khan";
	Players[6] = "arish khan";
	Players[7] = "sib khan"; 
	Players[8] = "Shadab khan";
	Players[9] = "zohan khan";
	Players[10]= "maruf  khan";


	IsFirstinnings = false;
	TeamA.TeamName = "Team-A";
	TeamB.TeamName = "Team-B";

}
void Game :: Welcome()

{
	cout << "|----------------------------------------- |" << endl;
	cout << "| ===============CRIC-IN===================|" << endl;
	cout << "|                                          |" << endl;
	cout << "|     WELLCOME TO VIRTUAL CRICKET GAME     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|==========================================|" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << endl; cout << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "|              INSTRUCTIONS                |" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << endl;
	cout << "|-------------------------------------------------------|" << endl;
	cout << "|2.Creat two teams (TeamA and TeamB with 4 player each )|" << endl;
	cout << "| from the given pool of 11 players                     |" << endl;
	cout << "|Lead the toss and decide the choice of the play        |" << endl;
	cout << "|  Each innings of 6 balls                              |" << endl;
	cout << "|-------------------------------------------------------|" << endl;

	
	


}
void Game::showAllplayers()
{
	int TotalPlayers = 11;
	
	cout << "|------------------------------|" << endl;
	cout << "|    Pool of 11 players        |" << endl;
	cout << "|------------------------------|" << endl;
	cout << TotalPlayers << endl;

	for (int i = 0; i < TotalPlayers; i++)
    cout << " [" << i << "] " << Players[i] << endl;;
	
}

int Game::TakeIntegerValue()
{
	int n;
	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "invalid input please enter the valid input " << endl;
	}
	return n;
}
bool Game::ValidatePlayers(int index)
{
	int n;
	vector<Player>playername;
	playername = TeamA.playername;
	n = playername.size();
	for (int i = 0; i < n; i++)
	{
		if (playername[i].ID == index)
		{
			return false;
		}
	}
	
	playername = TeamB.playername;
	n = playername.size();
	for (int i = 0; i < n; i++)
	{
		if (playername[i].ID == index)
		{
			return false;
		}
	}
	return true;

}
void Game::SelectPLayer()
{
	int PlayerPerTeam=4;
	cout << endl;
	cout << "|-----------------------------------|" << endl;
	cout << "|       CREAT TEAM-A & TEAM-B       |" << endl;
	cout << "|-----------------------------------|" << endl;

	for (int i = 0; i < PlayerPerTeam; i++)
	{
		// add player to team A
		TeamAselection:
		cout << "Select Player " << i + 1 << " Of team A -";

		int PlayerIndexTeamA = TakeIntegerValue();
		if (PlayerIndexTeamA < 0 || PlayerIndexTeamA >10)
		{
			cout << "Please chose the player from given pool " << endl;
			goto TeamAselection;
		}
		else if (!ValidatePlayers(PlayerIndexTeamA ))
		{
			cout << "this player is already selected " << endl;
			goto TeamAselection;
		}
		else
		{
			
			Player TeamAplayer;
			TeamAplayer.ID = PlayerIndexTeamA;
			TeamAplayer.name = Players[PlayerIndexTeamA];
			TeamA.playername.push_back(TeamAplayer);
		}

		
		//Team TeamA;
		// add player to team B
		TeamBselection:
		cout << "Select Player " << i + 1 << " Of team B - ";
		int PlayerIndexTeamB = TakeIntegerValue();
		if (PlayerIndexTeamB < 0 || PlayerIndexTeamB>10)
		{
			cout << "Please Enter the correct choice " << endl;
			goto TeamBselection;
		}
		else if (!ValidatePlayers(PlayerIndexTeamB))
		{
			cout << "This player already selected " << endl;
			goto TeamBselection;
		}
		else
		{
			Player TeamBplayer;
			TeamBplayer.ID = PlayerIndexTeamB;
			TeamBplayer.name = Players[PlayerIndexTeamB];
		     TeamB.playername.push_back(TeamBplayer);
		}
		
	}
}

void Game::showSelectedPlayers()

{
	int PlayerPerTeam = 4;
	
	vector<Player>TeamAplayer = TeamA.playername;
	vector<Player>TeamBplayer = TeamB.playername;
	cout << "|=====================|"<<"\t\t"<<"|======================|" << endl;
	cout << "|    TEAM-A PLAYERS   |"<<"\t\t"<<"|    TEAM-B PLAYERS    |" << endl;
	cout << "|=====================|"<<"\t\t"<<"|======================|" << endl;
	
	for ( int i = 0; i < PlayerPerTeam; i++)
	{
		
		cout << "|" <<"[" << i << "]" << TeamAplayer[i].name <<"      |";
		cout << "\t\t";
		cout << "|" << "[" << i << "]" << TeamBplayer[i].name <<"         |" << endl;

	}
	cout << "|=====================|\t\t|======================|"<<endl<<endl;

}
void Game::Toss()
{
	cout << "|=========================|" << endl;
	cout << "|        Lets Toss        |" << endl;
	cout << "|=========================|" << endl;
	cout << "tossing the coin " << endl;
	srand(time(0));
	int generatedValue = rand() % 2; // this will generate the two nnumber 0,1
	switch (generatedValue)
	{
	case 0:
		cout << "Team A won the toss " << endl;
		Tosschoice(TeamA);
		break;
	case 1:
		cout << "Team B won the toss " << endl;
		Tosschoice(TeamB);
		break;
	}
	
}
void Game::Tosschoice(Team winner)
{
	cout << " Enter the 1 to batting  " << " 2 for bowling " << endl;
	cout << "1.bat" << endl;
	cout << "2.bowling" << endl;
	
	int choosetoss = TakeIntegerValue();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Choosing toss" << endl;

	switch (choosetoss)
	{
	case 1:
		cout << winner.TeamName << " won the toss and decided to bat first " << endl << endl;
		if (winner.TeamName.compare("Team-A") == 0) // if team-A is toss winner 
		{
			battingTeam = &TeamA;
			bowlingTeam = &TeamB;
		}
		else {   // else team-B toss winner  

			battingTeam = &TeamB;
			bowlingTeam = &TeamA;
		}

		break;
	case 2:
		cout << winner.TeamName << " won the toss and decided to ball first" << endl;
		if (winner.TeamName.compare("Team-A") == 0) // Team-A toss winner and choose to ball first
		{
			
			bowlingTeam = &TeamA;
			battingTeam = &TeamB;
			
		}
		else
		{
			
			bowlingTeam = &TeamB;
			battingTeam = &TeamA;
		}
		break;
	 default:
			cout << "Invalid Entery Please Enter the right choice " << endl;
			Tosschoice(winner); // we use recursion to call tosschoice function again in that invalid condition 
			break;
	}

	
}

void Game::startFirstInning()
{
	cout << "|=========================|" << endl;
	cout << "|   FIRST INNING START    |" << endl;
	cout << "|=========================|" << endl<<endl;
	IsFirstinnings = true;
	InitializePlayer();
	PlayInning();

}
void Game::InitializePlayer()
{
	batsman = &battingTeam->playername[0];
	bowler = &bowlingTeam->playername[0];

	cout << battingTeam->TeamName << "    " << batsman->name<<" Is batting " << endl;
	cout << bowlingTeam->TeamName << "    " << bowler->name <<" Is bowling" << endl<<endl;

}
void Game::PlayInning()
{
	int Maxball = 6;
	for (int i = 0; i < 6; i++)
	{
		cout << "Press enter to bowl" << endl;
		getchar();
		cout << "Bowling" << endl;
		bat();
		if (!ValidiatingInningScore())
		{
			break;
		}
}
}
void Game::bat()
{
	// update of batting team and run scored  by batsman 
	srand(time(0));
	int runScored = rand() % 7;
	batsman->RunScore = batsman->RunScore + runScored;
	battingTeam->TotalRuns = battingTeam->TotalRuns + runScored;
	batsman->ballPlayed = batsman->ballPlayed + 1;

	// update of bowling team and bowler score 
	bowler->ballBowled = bowler->ballBowled + 1;
	bowlingTeam->TotalballBowled = bowlingTeam->TotalballBowled + 1;
	bowler->RunsGiven = bowler->RunsGiven + runScored;

	if (runScored != 0) //1,2,3,4,5,6,
	{ 
		cout << endl << bowler->name << "  to " << batsman->name << "  " << runScored << " runs " << endl << endl;
		Showgamescorecard();
       
		
	}
	else
	{
		cout << endl << bowler->name << "  to " << batsman->name <<" " << runScored << " out  " << endl << endl;
		Showgamescorecard();

		battingTeam->WicketLost = battingTeam->WicketLost + 1;
		bowler->wicketTaken = bowler->wicketTaken + 1;
		
		

		int NextplayerIndex = battingTeam->WicketLost;
		batsman = &battingTeam->playername[NextplayerIndex];

	}
	

}
bool Game::ValidiatingInningScore()
{
	if (IsFirstinnings)
	{
		if (battingTeam->WicketLost == 11 || bowlingTeam->TotalballBowled == 6)
		{
			cout << "|------------------------|" << endl;
			cout << "|    FIRST INNING END    |" << endl;
			cout << "|------------------------|" << endl << endl;;

			cout << battingTeam->TeamName << "  " << battingTeam->TotalRuns << " - "
				<< battingTeam->WicketLost << " (" << bowlingTeam->TotalballBowled << " )" << endl << endl;
			cout << bowlingTeam->TeamName << "  needs " << battingTeam->TotalRuns + 1 << " to win the match " << endl << endl;
			return false;
		}

	}
	else {
		// second inning

		if (battingTeam->TotalRuns > bowlingTeam->TotalRuns)
		{
			cout << "|---------------------------|" << endl;
			cout << "|" << battingTeam->TeamName << "\t won the match |" << endl;
			cout << "|---------------------------|" << endl;
			return false;
		}
		else if (battingTeam->WicketLost == 11 || bowlingTeam->TotalballBowled == 6)
		{
			if (battingTeam->TotalRuns < bowlingTeam->TotalRuns)
			{
				cout << "|---------------------|" << endl;
				cout << bowlingTeam->TeamName << " " << "\t Won the match " << endl;
                cout << "|---------------------|" << endl;
			}
			else
			{

				cout << "|---------------------|" << endl;
				cout << "\tMatch Draw " << endl;
				cout << "|---------------------|" << endl;
			}
			return false;
		}
	}
	return true;
}
void Game::Showgamescorecard()
{
	cout << "|---------------------------------------------------------|" << endl << endl;
	cout <<" "<< battingTeam->TeamName << " " << battingTeam->TotalRuns << " - " << battingTeam->WicketLost << " ("
	<< batsman->ballPlayed << ")"<<" ";
	cout << batsman->name << " " << batsman->RunScore << " (" << batsman->ballPlayed << ") "
	<< bowler->name << "-" << bowler->RunsGiven << " - " << bowler->wicketTaken <<" - " << bowler->ballBowled <<endl;
	cout << "|---------------------------------------------------------|" << endl << endl;;

} 
void Game::StartSecondInning()

{
	cout << "|---------------------------|" << endl;
	cout << "|    SECOND INNING START    |" << endl;
	cout << "|---------------------------|" << endl << endl;

	IsFirstinnings = false;
	// swapping the pointers to eachother 
	Team tempTeam = *battingTeam;
	*battingTeam = *bowlingTeam;
	*bowlingTeam = tempTeam;
	InitializePlayer();
	PlayInning();
}
void Game::ShowMatchSummry()
{
	cout << "|=======================================|" << endl;
	cout << "|\t\t      MATCH END                    |" << endl;
	cout << "|=======================================|" << endl << endl;
    cout << battingTeam->TeamName << " " << battingTeam->TotalRuns << " (" << battingTeam->WicketLost << ")  -" << battingTeam->TotalballBowled << endl;

	cout << "|--------------------------------------------------------------|" << endl;
	cout << "  |PLAYER\t BATTING \t BOWLING|" << endl;
	for (int i = 0; i < 4; i++)

	{
		Player player = battingTeam->playername[i];
		cout << "|---------------------------------------------------|" << endl;
		cout << "[" << i << "] " << player.name << "\t" << player.RunScore << "(" << player.ballPlayed << ")" << "\t"
			<< player.ballBowled << "-" << player.wicketTaken << "-" << player.RunsGiven << "  |" << endl;
		cout << "|--------------------------------------------------------------|" << endl;

	}

	cout << "=====================================" << endl;
	cout << bowlingTeam->TeamName << " " << bowlingTeam->TotalRuns << " ( " 
		<< bowlingTeam->WicketLost << ") - " 
		<< bowlingTeam->TotalballBowled << endl;
	cout << " |PLAYER\t BATTING \T BOWLING|" << endl;
	for (int i = 0; i < 4; i++)
	{
		Player player = bowlingTeam->playername[i];
		cout << "-------------------------------------------------" << endl;
		cout << "[" << i << "]" << player.name << "\t" << player.RunScore << " ( " << player.ballPlayed << ")" << "\t"
			<< player.ballBowled << "-" << player.wicketTaken << "-" << player.RunsGiven << " |" << endl;
		cout << "---------------------------------------------------" << endl;
	}


}