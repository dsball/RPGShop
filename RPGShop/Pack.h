#ifndef PACK_INTERFACE
#define PACK_INTERFACE

#include "utility.h"
#include "Shop.h"
#include "Assets.h"

struct Item
{
	int id;
	int qty;
	Item* prev;
	Item* next;
};

class Pack
{
private:
	Item * head;
	Item * current;
	Item * tempNode;

public:
	Pack();
	Item * makeNode(int id, int qty);
	Item * findNode(int id);
	bool modify(Item * inputNode);
	void remove(Item * inputNode);
	const string Pack::outputForSave();
	const void printList(const Inventory * itemList);
	~Pack(void);
};

#endif