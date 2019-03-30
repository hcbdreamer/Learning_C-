#ifndef TABTENN0_H_
#define TABTENN0_H_
#include<string>

using std::string;

class tabletennisplayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	tabletennisplayer(const string & fn="none" ,const string & ln="none" ,bool hT=true );
	void Name() const;
	bool HasTable() const
	{
		return hasTable;
	}
	void ResetTable(bool v)
	{
		hasTable = v;
	}
	void setName(string name){
		firstname = name;
		std::cout << firstname;
	}
	
};
#endif;