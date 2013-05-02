#include "Shop.h"


//Initializes shop funds, stock, and party being served
Shop::Shop(const Inventory * inputList, Party * inputParty)
{
	funds = 50000;
	itemList = inputList;
	activeParty = inputParty;
}
//Purchase an item and add it to the party inventory
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
		if(qty > 0)
		{
			return activeParty->addToInventory(id, qty);
		}
	}

	return false;
}
//Sell item from party inventory
bool Shop::sell(int id)
{
	int qty;

	if(activeParty->findItem(id)->id != id)
	{
		return false;
	}
	else
	{
		cout<<"How many would you like to sell: ";
		while(!(cin>>qty))
		{
			cin.clear();
			cin.sync();
			cout<<"I'm sorry, could you repeat that: ";
		}
		return activeParty->addToInventory(id, -qty);
	}
}
//lists stock available at a store
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
//buy/sell/exit interface for stores
void Shop::storefront(int shopType)
{	
	int i = 0;
	int itemID;
	string title = "junk";
	int choice = 0;

	switch(shopType)
	{
	case 3:
		title = "Welcome to Stims 'n Stuff!";
		break;
	case 2:
		title = "Welcome to the Armory!";
		break;
	case 1:
		title = "Welcome to Guardian Armor and Apparel!";
		break;
	}

	Menu shopMenu(title);
	shopMenu.addItem("Buy");
	shopMenu.addItem("Sell");
	shopMenu.addItem("exit");

	while(choice != 3)
	{
		choice = shopMenu.getChoice();
		switch(choice)
		{
		case 1:
			do
			{
				clearScreen();
				cout<<"Available Items\n";
				cout<<string(50,'-')<<endl;	
				listStock(shopType);
				cout<<string(50,'-')<<endl;	
				cout<<"Enter an item ID to make a purchase or 0 to return to the store menu: ";
				if(cin>>itemID)
				{
					if(itemID && (itemID/16 != shopType || !buy(itemID)))
					{
						cout<<"I'm sorry, there was a problem with your order.\n";
						Sleep(1000);
					}
				}
			}while(itemID);
			break;
		case 2:
			do
			{
				clearScreen();
				cout<<"Your Items\n";
				cout<<string(50,'-')<<endl;	
				activeParty->showInventory();
				cout<<string(50,'-')<<endl;	
				cout<<"Enter the ID of the item to sell or 0 to return to the store menu: ";
				if(cin>>itemID)
				{
					if(itemID)
					{
						if(!sell(itemID))
						{
							cout<<"I'm sorry, I was unable to complete your order.\n";
							Sleep(500);
						}
					}
				}
			}while(itemID);
			break;
		case 3:
			cout<<"Thank you for your custom";
			Sleep(1000);
			break;
		}
	}
}
//default destructor
Shop::~Shop()
{
	;
}
