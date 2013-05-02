#include "Backpack.h"

//initializes linked list pointers
Backpack::Backpack()
{
	tempNode = nullptr;
	head = nullptr;
}
//prints a list of backpack contents
const void Backpack::printList(const Inventory * itemList)
{
	int choice;
	bool found = false;
	Item* current = head;

	cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(4)<<"QTY\n";
	cout<<string(50,'-')<<endl;
	while(current)
	{ 
		int category = current->id/16;

		switch(category)
		{
		case 1:
			cout<<left<<setw(4)<<current->id<<setw(15)<<itemList->arm[current->id%16].name<<dec<<setw(4)<<current->qty<<endl;
			break;
		case 2:
			cout<<left<<setw(4)<<current->id<<setw(15)<<itemList->weap[current->id%16].name<<dec<<setw(4)<<current->qty<<endl;
			break;
		case 3:
			cout<<left<<setw(4)<<current->id<<setw(15)<<itemList->consum[current->id%16].name<<dec<<setw(4)<<current->qty<<endl;
			break;
		default:
			cout<<left<<setw(4)<<current->id<<"ITEM ID ERROR, ID DOES NOT EXIST!\n";
		}
		current = current->next;
	}
}
//outputs a formatted string containing pack contents to be appended to party save data
const string Backpack::outputForSave()
{
	string saveString;
	stringstream saveStream;
	Item* current = head;

	while(current && current->next)
	{
		saveStream<<hex<<current->id<<" "<<dec<<current->qty<<endl;
		current = current->next;
	}
	if(current)
	{
		saveStream<<hex<<current->id<<" "<<dec<<current->qty<<"!";
	}
	getline(saveStream, saveString, '!');
	return saveString;
}
//creates a temporary node with item ID and quantity to be added/removed
Item* Backpack::makeNode(int id, int qty)
{
	tempNode = new Item;
	if(!tempNode)
	{
		cout<<"failure in allocating memory.";
		pause();
		exit(0);
	}
	tempNode->id = id;
	tempNode->qty = qty;
	tempNode->next = nullptr;
	tempNode->prev = nullptr;
	return tempNode;

}
//Returns the address of: the node with the ID, the closest node if not found, null if empty
Item* Backpack::findNode(int id)
{
	Item *tempNode = head;
	if(head)
	{
		while(tempNode->next != nullptr && tempNode->next->id <= id)
		{
			tempNode = tempNode->next;
		}
	}
	return tempNode;
}
//adds a new node or modifies/deletes an existing node depending on ID match and quantity
bool Backpack::modify(Item * inputNode)
{
	
	Item* tempNode = nullptr;
	int i = 0;

	if(!head)                                   //create new head if list is empty
	{
		head = inputNode;
	}

	else
	{
		tempNode = findNode(inputNode->id);
		if(tempNode->id == inputNode->id)		//if already in bag
		{
			if(inputNode->qty < 0)				//if qty being added is negative (removing items)
			{
				if(tempNode->qty + inputNode->qty < 0)
				{
					cout<<"You don't have enough items for that!";
					Sleep(500);
					delete inputNode;
					return false;
				}
				if(tempNode->qty + inputNode->qty == 0)
				{
					remove(tempNode);
					return true;
				}
			}
			tempNode->qty += inputNode->qty;	//update qty
		}
		else
		{
			if(inputNode->qty < 0)
			{
				return false;
			}
			if(tempNode->id > inputNode->id)
			{
				while(tempNode->prev && tempNode->prev->id > inputNode->id)
				{
					tempNode = tempNode->prev;
				}
			}
			else
			{
				while(tempNode->next && tempNode->next->id < inputNode->id)
				{
					tempNode = tempNode->next;
				}
			}
			
			if(tempNode->id > inputNode->id)
			{
				inputNode->prev = tempNode->prev;
				inputNode->next = tempNode;
				tempNode->prev = inputNode;
				head = inputNode;
			}
			else
			{
				inputNode->next = tempNode->next;
				inputNode->prev = tempNode;
				tempNode->next = inputNode;
			}
			
		}
	}
	return true;
}
// removes a node from the list
void Backpack::remove(Item * inputNode)
{
	Item * prev = inputNode->prev;
	Item * next = inputNode->next;
	if(!prev && !next)
	{
		head = nullptr;
	}
	else if(!prev)
	{
		head = head->next;
		head->prev = nullptr;
	}
	else if(!next)
	{
		prev->next = nullptr;
	}
	else
	{
		prev->next = inputNode->next;
		next->prev = inputNode->prev;
	}
	delete inputNode;
}
//de-allocates dynamically assigned variables
Backpack::~Backpack()
{
	Item * current = head;
	cout<<"Freeing Backpack Memory";
	while(head)
	{
		head = head->next;
		delete current;
		current = head;
	}
	cout<<head;
}