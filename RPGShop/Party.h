/*------------------------------------Assets.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
TEAMSIZE        int            size of team array
team[]          member         array of team members
itemList        Inventory*     pointer to an Inventory struct for list of available items
partyBackpack   Backpack       doubly linked list holds list of items party owns

--- Functions ---
Name                    Return            Description; Parameter description
--------------------------------------------------------------------------------------------
Party();				none       initializes item list
	inputList        list of all items loaded into game     
newTeam                 void       creates a new team and randomizes initial stats              
load                    bool       loads a team and inventory from memory              
save                    bool       saves a team and inventory to file       
showParty               void       shows party stats and equipped items
showInventory           void       shows all items in party inventory
findItem                Item *     finds an item or the address of the nearest match with a lower id value or null if the inventory is empty
    id      int      id of item to find
addToInventory          bool       adds a node to the inventory or modifies an existing node
	id      int      id of item to add
	qty     int      number of items to add (may be negative)
~Party(void);
*/

#ifndef PARTY_INTERFACE
#define PARTY_INTERFACE

#include "Utility.h"
#include "Backpack.h"
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
	const Inventory* itemList;
	Backpack partyBackpack;
public:
	Party(const Inventory* inputList);
	void newTeam();
	bool load();
	bool save();
	const void showParty();
	const void showInventory();
	Item * findItem(int id);
	bool addToInventory(int id, int qty);
	~Party();
};

#endif
