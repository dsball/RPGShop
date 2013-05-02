/*------------------------------------Assets.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
LIMIT           INT	           size of arrays
consumList[]    Consumable     Array of Consumables, holds data from consumables file
weapList[]      Weapon         Array of Weapons, holds data from weapons file
armList[]       Armor          Array of Armors, holds data from armors file
inventory       Inventory      struct of arrays

--- Functions ---
Name                    Return            Description; Parameter description
--------------------------------------------------------------------------------------------
Assets                  none              initializes arrays
fill                    bool              fills arrays with data from files
getInventoryPtr         const Inventory*  returns pointer to aggregate inventory struct
~Assets                 none              default destructor
*/


#ifndef ASSETS_INTERFACE
#define ASSETS_INTERFACE

#include "utility.h"

struct Consumable
{
	int id;
	string name;
	int hpfix;
	int cost;
};

struct Weapon
{
	int id;
	string name;
	int shotPer;
	int dmgPerShot;
	int acc;
	int cost;
};

struct Armor
{
	int id;
	string name;
	int armor;
	int cost;
};

struct Inventory
{
	Consumable * consum;
	Weapon * weap;
	Armor * arm;
	int numc;
	int numw;
	int numa;
};

class Assets
{
private:
	const static int LIMIT = 10;
	Consumable consumList[LIMIT];
	Weapon weapList[LIMIT];
	Armor armList[LIMIT];
	Inventory inventory;

public:
	Assets();
	bool fill();
	const Inventory* getInventoryPtr() const;
	~Assets();
};


#endif