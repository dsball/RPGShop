#include "Pack.h"


Pack::Pack()
{
	tempNode = nullptr;
	head = nullptr;
}


const void Pack::printList(const Inventory * itemList)
{
	int choice;
	bool found = false;
	Item* current = head;

	cout<<left<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(4)<<"QTY\n";
	cout<<string(50,'-')<<endl;
	while(current)
	{
		cout<<itemList->consum[current->id%16-1].name<<" "<<current->qty<<endl;
		current = current->next;
	}
	cout<<"Enter an item ID for more information: ";
	do
	{
		cin>>choice;
		;
	}while(!found);

}

const string Pack::outputForSave()
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

Item* Pack::makeNode(int id, int qty)
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

Item* Pack::findNode(int id)
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

bool Pack::modify(Item * inputNode)
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
					delete inputNode;
					return false;
				}
				if(tempNode->qty + inputNode->qty == 0)
				{
					remove(tempNode);
					delete inputNode;
					return false;
				}
			}
			tempNode->qty += inputNode->qty;	//update qty
		}
		else
		{
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

void Pack::remove(Item * inputNode)
{
	inputNode->prev->next = inputNode->next;
	delete inputNode;
}

Pack::~Pack()
{
	Item * current = head;
	cout<<"Freeing Pack Memory";
	while(head)
	{
		head = head->next;
		delete current;
		current = head;
	}
	cout<<head;

}