#ifndef PARTY_INTERFACE
#define PARTY_INTERFACE

#include "utility.h"
#include "pack.h"
#include "Shop.h"
#include "Assets.h"

struct member
{
	int id;
	string name;
	int level;
	int armor;
	int weapon;
	int str;
	int sta;
	int agi;
	int kno;
	int wit;
	int currhp;
	int maxhp;
};

class Party
{
private:
	const static int TEAMSIZE = 4;
	member team[TEAMSIZE];
	Pack partyPack;
	const Inventory* itemList;
public:
	Party(const Inventory* inputList);
	void newTeam();
	bool load();
	bool save();
	void findItem();
	const void showParty();
	const void showInventory();
	void addToInventory();
	~Party(void);
};

#endif
