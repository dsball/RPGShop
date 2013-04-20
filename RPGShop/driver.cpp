#include "utility.h"
#include "menu.h"
#include "Party.h"

int main()
{
	int choice = 0;
	Party party;
	
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
	primeMenu.addItem("Save and Quit)");
	
	shopMenu.addItem("Stims 'n Stuff");
	shopMenu.addItem("The Arsenal");
	shopMenu.addItem("Return to Base");

	printFile("splash.txt");
	Sleep(3000);
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

	while(choice != 5)
	{
		choice = primeMenu.getChoice();

		switch(choice)
		{
		case 1:
			cout<<"Going Shopping\n";
			pause();
			break;
		case 2:
			cout<<"Viewing Inventory\n";
			pause();
			break;
		case 3:
			cout<<"Viewing Party\n";
			pause();
			break;
		case 4:
			cout<<"Exploring the Arc (Not Implemented)";
			pause();
			break;
		case 5:
			cout<<"Saving";
			Sleep(2000);
			cout<<"Thank you for playing.";
			pause();
			break;
		}
	}
	return 0;
}