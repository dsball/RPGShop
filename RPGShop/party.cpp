#include "Party.h"
#include "Assets.h"
#include "Utility.h"

Party::Party(const Inventory* inputList)
{
	itemList = inputList;
}

bool Party::save()
{
	
	ofstream partyOut;

	string memberCaptions = "ID	name		     lvl Arm Wep Str Sta Agi Kno Wit chp mhp";
	string itemCaptions = "ID  QTY";
	int i = 0;

	partyOut.open("savedata.txt");
	if(partyOut.fail())
	{
		return false;
	}

	partyOut<<memberCaptions<<endl;

	for(i = 0; i<TEAMSIZE; i++)
	{
		partyOut <<left<< hex << setw(3) << team[i].id<<" "
		<<  setw(19) <<team[i].name<<" "
		<< dec << setw(3) << team[i].level<<" "
		<< hex << setw(5) << team[i].armor<<" "
		<<  setw(5) << team[i].weapon<<" "
		<< dec <<  setw(5) <<  team[i].str<<" "
		<<  setw(5) <<  team[i].sta<<" "
		<<  setw(5) <<  team[i].agi<<" "
		<<  setw(5) <<  team[i].kno<<" "
		<<  setw(5) <<  team[i].wit<<" "
		<<  setw(5) <<  team[i].currhp<<" "
		<<  setw(5) <<  team[i].maxhp<<endl;
	}
	partyOut<<"00\n";
	partyOut<<itemCaptions<<endl;
	partyOut << partyBackpack.outputForSave();
	partyOut<<"\n00";


	partyOut.close();

	return true;
};

bool Party::load()
{
	ifstream partyIn;
	string junk;
	int id;
	int qty;
	int i = 0;

	partyIn.open("savedata.txt");
	if(partyIn.fail())
	{
		return false;
	}
	
	getline(partyIn, junk);
	do
	{
		partyIn>>hex>>id;
		if(id)
		{
			team[i].id = id;
			partyIn >> team[i].name;
			partyIn >>dec>> team[i].level;
			partyIn >>hex>> team[i].armor;
			partyIn >> team[i].weapon;
			partyIn >>dec>> team[i].str;
			partyIn >> team[i].sta;
			partyIn >> team[i].agi;
			partyIn >> team[i].kno;
			partyIn >> team[i].wit;
			partyIn >> team[i].currhp;
			partyIn >> team[i].maxhp;
		}
		i++;
	} while(id);

	getline(partyIn,junk);
	getline(partyIn,junk);

	do
	{
		partyIn>>hex>>id;
		if(id)
		{
			partyIn>>dec>>qty;
			partyBackpack.modify(partyBackpack.makeNode(id, qty));
		}
		i++;
	} while(id);
	
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

		team[i].wit = rand() % 10 + 8;
		team[i].agi = rand() % 10 + 8;
		team[i].sta = rand() % 10 + 8;
		team[i].str = rand() % 10 + 8;
		team[i].kno = rand() % 10 + 8;

		team[i].level = 1;	
		team[i].maxhp = rand() % 50 + 100 + team[i].sta;
		team[i].currhp = team[i].maxhp;
	}
}

const void Party::showInventory()
{
	partyBackpack.printList(itemList);
}

const void Party::showParty()
{
	int i;
	//clearScreen();

	cout<<"|";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<string(25,'-')+"|";
	}
	
	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE ; i++)
	{
		cout<<left<<setw(5)<<intToStr(team[i].id)+": "<<setw(19)<<team[i].name<<"| ";
	}

	cout<<"\n|";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<string(25,'-')+"|";
	}

	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE ; i++)
	{
		cout<<left<<setw(5)<<"lv: "<<setw(19)<<team[i].level<<"| ";
	}

	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<left<<setw(5)<<"HP:"<<setw(19)<<intToStr(team[i].currhp) + "/" + intToStr(team[i].maxhp)<<"| ";
	}
	
	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<left<<setw(5)<<"Arm:"<<setw(19)<<itemList->arm[team[i].armor%16].name<<"| ";
	}
	
	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<left<<setw(5)<<"Wep:"<<setw(19)<<itemList->weap[team[i].weapon%16].name<<"| ";
	}

	cout<<"\n|";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<string(25,'-')+"|";
	}
	
	

	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<"Str |Sta |Agi |Kno |Wit | ";
	}

	cout<<"\n|";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<string(25,'-')+"|";
	}

	cout<<"\n| ";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<setw(4)<<" " + intToStr(team[i].sta)<<"|"<<setw(4)<<" " + intToStr(team[i].str)<<"|"<<setw(4)<<" " + intToStr(team[i].agi)<<"|"<<setw(4)<<" " + intToStr(team[i].kno)<<"|"<<setw(4)<<" " + intToStr(team[i].wit)<<"| ";
	}

	cout<<"\n|";
	for(i = 0 ; i<TEAMSIZE;i++)
	{
		cout<<string(25,'-')+"|";
	}
	cout<<endl;
}

Party::~Party(void)
{
	;
}
