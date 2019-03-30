#include<iostream>
#include"tabtenn0.h"

int main()
{
	using std::cout;
	//tabletennisplayer player1("Chuck", "Blizzard", true);
	tabletennisplayer player1;
	tabletennisplayer player2("Tara", "Booomdea", false);
	player1.Name();
	player1.setName("LL");
	/*if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": has not a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": has not a table.\n";*/
	return 0;
}