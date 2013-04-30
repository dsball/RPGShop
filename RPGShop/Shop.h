#ifndef SHOP_INTERFACE
#define SHOP_INTERFACE

#include "Utility.h"
#include "Assets.h"
#include "Party.h"

class Shop
{	
private:
	int funds;
	const Inventory * itemList;
	Party * activeParty;
public:
	Shop(const Inventory* , Party * inputParty);
	bool buy(int id);
	void sell(int id);
	void storefront(int shopType);
	void listStock(int shopType);
	~Shop(void);
};

#endif
