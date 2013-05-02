/*------------------------------------Assets.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
int funds;
const Inventory * itemList;
Party * activeParty;

--- Functions ---
Name                    Return            Description; Parameter description
--------------------------------------------------------------------------------------------
Shop();                 none              Initializes shop funds, stock, and party being served
    Inventory*    stock list
    Party *       party being served
bool buy();             bool              Purchase an item and add it to the party inventory            
    int           id of item to be purchased
bool sell();                              Sell item from party inventory
    int           id of item to sell
void storefront();       void             buy/sell/exit interface for stores              
    int           shop type 3 = consum 2 = weapon 1 = armor
void listStock();        void             lists stock available at a store
    int           shop type 3 = consum 2 = weapon 1 = armor
~Shop()
*/

#ifndef SHOP_INTERFACE
#define SHOP_INTERFACE

#include "Utility.h"
#include "Assets.h"
#include "Party.h"
#include "Menu.h"

class Shop
{	
private:
	int funds;
	const Inventory * itemList;
	Party * activeParty;
public:
	Shop(const Inventory* inputList, Party * inputParty);
	bool buy(int id);
	bool sell(int id);
	void storefront(int shopType);
	void listStock(int shopType);
	~Shop(void);
};

#endif
