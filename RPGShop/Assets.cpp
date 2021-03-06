#include "Assets.h"

//initializes arrays
Assets::Assets()
{
	inventory.numc = 0;
	inventory.numw = 0;
	inventory.numa = 0;
	inventory.arm = armList;
	inventory.consum = consumList;
	inventory.weap = weapList;
}
//fill arrays from files
bool Assets::fill()
{
	string junk;
	ifstream itemIn;
	int id = -1;

	itemIn.open("consumlist.txt");
	if(itemIn.fail())
	{
		return false;
	}

	getline(itemIn, junk);
	while(inventory.numc<LIMIT && id)
	{
		itemIn>>hex>>id;
		if(id)
		{
			consumList[inventory.numc].id = id;
			itemIn>>dec>>consumList[inventory.numc].name; 
			itemIn>>consumList[inventory.numc].hpfix;
			itemIn>>consumList[inventory.numc].cost;
			inventory.numc++;
		}
		
	}
	itemIn.close();
	
	id = -1;
	itemIn.open("armorlist.txt");
	if(itemIn.fail())
	{
		return false;
	}
	getline(itemIn, junk);
	while(inventory.numa<LIMIT && id)
	{
		itemIn>>hex>>id;
		if(id)
		{
			armList[inventory.numa].id = id;
			itemIn>>armList[inventory.numa].name;
			itemIn>>dec>>armList[inventory.numa].armor;
			itemIn>>armList[inventory.numa].cost;
			inventory.numa++;
		}
		
	}
	itemIn.close();
	
	id = -1;
	itemIn.open("weaponlist.txt");
	if(itemIn.fail())
	{
		return false;
	}
	getline(itemIn, junk);
	while(inventory.numw<LIMIT && id)
	{
		itemIn>>hex>>id;
		if(id)
		{
			weapList[inventory.numw].id = id;
			itemIn>>weapList[inventory.numw].name;
			itemIn>>dec>>weapList[inventory.numw].shotPer;
			itemIn>>weapList[inventory.numw].dmgPerShot;
			itemIn>>weapList[inventory.numw].acc;
			itemIn>>weapList[inventory.numw].cost;
			inventory.numw++;
		}
		
	}
	itemIn.close();
	return true;
}
//return pointer to inventory aggregate struct
const Inventory* Assets::getInventoryPtr() const
{
	return &inventory;
}
//default destructor
Assets::~Assets()
{
	;
}