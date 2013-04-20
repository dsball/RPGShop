#ifndef PACK_INTERFACE
#define PACK_INTERFACE

#include "utility.h"

struct Item
{
	int ID;
	int qty;
	item* link;
};

class Pack
{
private:
	Item bag;
public:
	Pack(void);
	Item * makeNode();
	Item * findPrev();
	void add();
	void remove();
	~Pack(void);
};

#endif