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
	void printAll();
	const Inventory* getInventoryPtr() const;
	~Assets();
};


#endif