#ifndef SHOP_INTERFACE
#define SHOP_INTERFACE

struct item
{

};

struct weapon
{

};

struct armor
{

};



class Shop
{
private:
	 int funds;

public:
	Shop(void);
	void fillInventory();
	void buy();
	void sell();
	void listStock();
	~Shop(void);
};

#endif
