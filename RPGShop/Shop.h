#ifndef SHOP_INTERFACE
#define SHOP_INTERFACE

#include "utility.h"
#include "Assets.h"
#include "Party.h"

class Shop
{	
private:
	int funds;
	const Inventory * itemList;
public:
	Shop(const Inventory * inputList);
	void buy(int id);
	void sell(int id);
	void consum();
	void weap();
	void arm();
	void listStock(int shopType);
	~Shop(void);
};

#endif
