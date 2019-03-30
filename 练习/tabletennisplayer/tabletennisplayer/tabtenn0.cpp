#include<iostream>
#include"tabtenn0.h"

tabletennisplayer::tabletennisplayer(const string & fn,  const string & ln, bool hT)
{
	firstname = fn;
	lastname = ln;
	hasTable = hT;
}
void tabletennisplayer::Name() const
{
	std::cout << lastname << " , " << firstname;
}