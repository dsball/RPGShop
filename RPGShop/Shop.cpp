#include "Shop.h"


Shop::Shop(const Inventory * inputList, Party * inputParty)
{
	funds = 50000;
	itemList = inputList;
	activeParty = inputParty;
}

bool Shop::buy(int id)
{
	int qty;
	int type = id/16;
	bool valid = false;

	//validate item
	switch(type)
	{
	case 1:
		for(int i=0; i<itemList->numa; i++)
		{
			if(itemList->arm[i].id == id)
			{
				valid = true;
			}
		}
		break;
	case 2:
		for(int i=0; i<itemList->numw; i++)
		{
			if(itemList->weap[i].id == id)
			{
				valid = true;
			}
		}
		break;
	case 3:
		for(int i=0; i<itemList->numc; i++)
		{
			if(itemList->consum[i].id == id)
			{
				valid = true;
			}
		}
		break;
	default:
		return false;
	}
	
	if(valid)
	{
		cout<<"How many: ";
		while(!(cin>>dec>>qty))
		{
			cin.clear();
			cin.sync();
			cout<<"Could you repeat that: ";
		}
		activeParty->addToInventory(id, qty);
	}

	
}

void Shop::sell(int id)
{
	;
}

void Shop::listStock(int shopType)
{
	int i = 0;

	switch(shopType)
	{
	case 3: 
		cout<<left<<dec<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(5)<<dec<<"HP"<<setw(6)<<"Cost"<<endl;
		for(i ; i<itemList->numc ; i++)
		{
			cout<<left<<setw(4)<<itemList->consum[i].id<<setw(15)<<itemList->consum[i].name<<setw(5)<<itemList->consum[i].hpfix<<setw(6)<<itemList->consum[i].cost<<endl;
		}
		break;
	case 2:
		cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(9)<<dec<<"shot/rnd"<<setw(9)<<"dmg/shot"<<setw(4)<<"Acc"<<setw(4)<<"Cost"<<endl;
		for(i ; i<itemList->numw ; i++)
		{
			cout<<left<<setw(4)<<itemList->weap[i].id<<setw(15)<<itemList->weap[i].name<<setw(9)<<itemList->weap[i].shotPer<<setw(9)<<itemList->weap[i].dmgPerShot<<setw(4)<<itemList->weap[i].acc<<setw(4)<<itemList->weap[i].cost<<endl;
		}
		break;
	case 1:
		cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(7)<<"Armor"<<setw(6)<<"Cost"<<endl;
		for(i ; i<itemList->numa ; i++)
		{
			cout<<left<<setw(4)<<itemList->arm[i].id<<setw(15)<<itemList->arm[i].name<<setw(7)<<itemList->arm[i].armor<<setw(6)<<itemList->arm[i].cost<<endl;
		}
		break;
	
	default:
		cout<<"Invalid Shop Type\n";
		break;
	}
}

void Shop::storefront(int shopType)
{	
	int i = 0;
	int purchase = 0;

	clearScreen();
	switch(shopType)
	{
	case 3:
		cout<<"Welcome to Stims 'n Stuff!\n";
		break;
	case 2:
		cout<<"Welcome to the Armory!\n";
		break;
	case 1:
		cout<<"Welcome to Guardian Armor and Apparel!\n";
		break;
	default:
		exit(0);
	}
	cout<<string(50,'-')<<endl;
	listStock(shopType);
		
	cout<<"Enter an item ID to make a purchase or 0 to exit the store: ";
	while(cin>>purchase)
	{
		if(purchase)
		{
			if(purchase/16 != shopType || !buy(purchase))
			{
				cout<<"I'm sorry, I was unable to complete your order.\n";
			}
			cout<<"Enter an item ID to make a purchase or 0 to exit the store: ";
		}
		else
		{
			cout<<"Thank you for your custom\n";
			return;
		}
	}
}



Shop::~Shop()
{
	;
}
