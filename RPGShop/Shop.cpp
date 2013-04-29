#include "Shop.h"


Shop::Shop(const Inventory * inputList/*, Party * inputParty*/)
{
	funds = 50000;
	itemList = inputList;
}

void Shop::buy(int id)
{
	;
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
	case 1: 
		cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(5)<<"HP"<<setw(6)<<"Cost"<<endl;
		for(i ; i<itemList->numc ; i++)
		{
			cout<<left<<setw(4)<<hex<<itemList->consum[i].id<<setw(15)<<itemList->consum[i].name<<setw(5)<<itemList->consum[i].hpfix<<setw(6)<<itemList->consum[i].cost<<endl;
		}
		break;
	case 2:
		cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(7)<<"Armor"<<setw(6)<<"Cost"<<endl;
		for(i ; i<itemList->numa ; i++)
		{
			cout<<left<<setw(4)<<itemList->arm[i].id<<setw(15)<<itemList->arm[i].name<<setw(7)<<itemList->arm[i].armor<<setw(6)<<itemList->arm[i].cost<<endl;
		}
		break;
	case 3:
		cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(9)<<"shot/rnd"<<setw(9)<<"dmg/shot"<<setw(4)<<"Acc"<<setw(4)<<"Cost"<<endl;
		for(i ; i<itemList->numw ; i++)
		{
			cout<<left<<setw(4)<<itemList->weap[i].id<<setw(15)<<itemList->weap[i].name<<setw(9)<<itemList->weap[i].shotPer<<setw(9)<<itemList->weap[i].dmgPerShot<<setw(4)<<itemList->weap[i].acc<<setw(4)<<itemList->weap[i].cost<<endl;
		}
		break;
	default:
		cout<<"Invalid Shop Type\n";
		break;
	}
}

void Shop::consum()
{	
	int i = 0;
	int purchase = 0;
	cout<<"Welcome to Stims 'n Stuff!";

	cout<<"1: Buy or 2: Sell?";

	cout<<"Cell Level Emergency Repair Injecion Kits (CLERICs):\n";
	cout<<string(50,'-');
	listStock(1);
	cout<<"Enter an item ID to make a purchase or 0 to exit the store.";
	if(purchase == 1)
	{
		while(cin>>hex>>purchase)
		{
			if(purchase)
			{
				buy(purchase);
				cout<<"Enter an item ID to make a purchase or 0 to exit the store.";
			}
			else
			{
				cout<<"Thank you for your custom\n";
				return;
			}
		}
	}
	else
	{
		cout<<"In your bags:\n";
		while(cin>>hex>>purchase)
		{
			if(purchase)
			{
				buy(purchase);
				cout<<"Enter an item ID to sell or 0 to exit the store.";
			}
			else
			{
				cout<<"Thank you for your custom!\n";
				return;
			}
		}
	}

	pause();
}

void Shop::weap()
{
	listStock(2);
	pause();
}

void Shop::arm()
{
	listStock(3);
	pause();
}

Shop::~Shop()
{
	;
}
