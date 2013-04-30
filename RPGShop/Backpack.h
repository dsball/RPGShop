#ifndef Backpack_INTERFACE
#define Backpack_INTERFACE

#include "Utility.h"
#include "Assets.h"

struct Item
{
	int id;
	int qty;
	Item* prev;
	Item* next;
};

class Backpack
{
private:
	Item * head;
	Item * current;
	Item * tempNode;

public:
	Backpack();
	Item * makeNode(int id, int qty);
	Item * findNode(int id);
	bool modify(Item * inputNode);
	void remove(Item * inputNode);
	const string Backpack::outputForSave();
	const void printList(const Inventory * itemList);
	~Backpack(void);
};

#endif