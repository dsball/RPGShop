#ifndef PARTY_INTERFACE
#define PARTY_INTERFACE

#include "utility.h"
#include "pack.h"

struct member
{
	int id;
	string name;
	int level;
	int armor;
	int weapon;
	int physique;
	int fortitude;
	int agility;
	int knowledge;
	int acuity;
	int currhp;
	int maxhp;
};

class Party
{
private:
	const static int TEAMSIZE = 4;
	member team[TEAMSIZE];
public:
	Party(void);
	void newTeam();
	bool load();
	bool save();
	const void display();
	void fillInventory();
	void addToInventory();

	~Party(void);
};

#endif
