#include "party.h"


Party::Party(void)
{

}

bool Party::save()
{
	return true;
};

bool Party::load()
{
	ifstream partyIn;
	string junk;
	int temp;
	int i = 0;

	partyIn.open("savedata.txt");
	if(partyIn.fail())
	{
		return false;
	}
	
	getline(partyIn, junk);
	
	do
	{
		partyIn>>hex>>temp;
		if(temp)
		{
			team[i].id = temp;
			partyIn >> team[i].name;
			partyIn >> team[i].level;
			partyIn >> team[i].armor;
			partyIn >> team[i].weapon;
			partyIn >> team[i].physique;
			partyIn >> team[i].fortitude;
			partyIn >> team[i].agility;
			partyIn >> team[i].knowledge;
			partyIn >> team[i].acuity;
			partyIn >> team[i].currhp;
			partyIn >> team[i].maxhp;
		}
		i++;
	} while(temp);

	getline(partyIn,junk);
	
	do
	{
		partyIn>>hex>>temp;
		if(temp)
		{
			
			
		}
		i++;
	} while(temp);

	cout<<temp;
	

	partyIn.close();
	return true;
}

void Party::newTeam()
{
	srand(int(time(NULL)));
	int i = 0;

	for(i; i<TEAMSIZE; i++)
	{
		cout << "Enter character "<<i+1<<"'s name: ";
		cin>>team[i].name;
		while(team[i].name.length() > 15)
		{
			cout<<"That's too long, please use less than 12 characters.\n";
			cout << "Enter character "<<i+1<<"'s name: ";
			cin>>team[i].name;
		}
	
		team[i].id = i+1;
		team[i].weapon = 0;
		team[i].armor = 0;

		team[i].acuity = rand() % 10 + 8;
		team[i].agility = rand() % 10 + 8;
		team[i].fortitude = rand() % 10 + 8;
		team[i].physique = rand() % 10 + 8;
		team[i].knowledge = rand() % 10 + 8;

		team[i].level = 1;	
		team[i].maxhp = rand() % 50 + 100;
		team[i].currhp = team[i].maxhp;
	}
}

Party::~Party(void)
{
}
