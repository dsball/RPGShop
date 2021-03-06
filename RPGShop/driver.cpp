#include "Utility.h"
#include "Menu.h"
#include "Party.h"
#include "Shop.h"
#include "Assets.h"
#include "Backpack.h"

int main()
{
	int choice = 0;
	
	Assets assets;
	assets.fill();
	
	Party party(assets.getInventoryPtr());

	Shop shop(assets.getInventoryPtr(), &party);

	if(!SetWindow(107,25))
    { 
		cout<<"Failed to resize console."; 
    } 
	
	Menu mainMenu("Choose An Option:");
	Menu primeMenu("What would you like to do?");
	Menu shopMenu("Where would you like to shop?");

	mainMenu.addItem("New Game");
	mainMenu.addItem("Load Game");
	mainMenu.addItem("Exit Game");

	primeMenu.addItem("Shopping");
	primeMenu.addItem("View Inventory");
	primeMenu.addItem("View Party");
	primeMenu.addItem("Rest");
	primeMenu.addItem("Explore the Arc");
	primeMenu.addItem("Save and Quit");
	
	shopMenu.addItem("Stims 'n Stuff");
	shopMenu.addItem("The Arsenal");
	shopMenu.addItem("Guardian Armor and Apparel");
	shopMenu.addItem("Return to Base");

	printFile("splash.txt");
	Sleep(2000);
	printFile("plotsummary.txt");
	pause();
	
	choice = mainMenu.getChoice();
	switch(choice)
	{
	case 1:
		cout<<"New game\n";
		party.newTeam();
		break;
	case 2:
		cout<<"Load game\n";
		party.load();
		break;
	case 3:
		return 0;
	}

	while(choice != 6)
	{
		choice = primeMenu.getChoice();

		switch(choice)
		{
		case 1:
			cout<<"Going Shopping\n";

			while(choice!=4)
			{
			choice = shopMenu.getChoice();
				switch(choice)
				{
				case 1:
					shop.storefront(3);
					break;
				case 2:
					shop.storefront(2);
					break;
				case 3:
					shop.storefront(1);
					break;
				case 4:
					break;
				}
			}
			break;
		case 2:
			cout<<"Viewing Inventory\n";
			clearScreen();
			party.showInventory();
			pause();
			break;
		case 3:
			cout<<"Viewing Party\n";
			party.showParty();
			pause();
			break;
		case 4:
			cout<<"Rest (Not Yet Implemented)\n";
			pause();
			break;
		case 5:
			cout<<"Exploring the Arc (Not Yet Implemented)\n";
			pause();
			break;
		case 6:
			party.save();
			cout<<"You'll be back. They always come back.\n";
			pause();
			break;
		}
	}
	return 0;
}