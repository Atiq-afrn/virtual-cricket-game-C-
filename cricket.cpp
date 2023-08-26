#include"Game.h"  // #include<iostream> we allready added the iostream header file in the Game.h file 

using namespace std;
int main()
{
	Game khan;
    khan.Welcome();
	cout << "| Press enter to contonue|" << endl;
	getchar();
	khan.showAllplayers();
	cout << "Press enter to continue" << endl;
	getchar();
	khan.SelectPLayer();
	khan.TakeIntegerValue();
	khan.showSelectedPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	khan.Toss();
	khan.startFirstInning();
	khan.StartSecondInning();
	khan.ShowMatchSummry();

	
}