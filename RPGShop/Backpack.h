/*------------------------------------Assets.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
Item * head;
Item * current;
Item * tempNode;

--- Functions ---
Name                    Return            Description; Parameter description
--------------------------------------------------------------------------------------------
Backpack();         none                  initializes linked list pointers
makeNode();         Item *                creates a temporary node with item ID and quantity to be added/removed
    int    item ID
    int    quantity
findNode();         Item *                Returns the address of: the node with the ID, the closest node if not found, null if empty
    int
modify();           bool                  adds a new node or modifies/deletes an existing node depending on ID match and quantity
    Item * 
remove();           void                  removes a node from the list
outputForSave();    string                outputs a formatted string containing pack contents to be appended to party save data
printList();        void                  prints a list of backpack contents
    const Inventory*                      item list (for printing additional info on items)
~Backpack();        none                  de-allocates dynamically assigned variables
*/

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