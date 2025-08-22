/************************************
* Ken Smith
* CS210 Project3
* ItemNode class method definitons
************************************/
#include "ItemNode.h"
#include <iostream>
#include <iomanip>

//Constructors:
//default
ItemNode::ItemNode()
{
	name = "";
	count = -1;
	nextNode = nullptr;
}

//with new item name
ItemNode::ItemNode(string item)
{
	name = item;
	count = 1;
	nextNode = nullptr;
}

//Destuctor to deallocate entire list.
ItemNode::~ItemNode() {
	//cout << "deleting node for: " << this->GetName() << endl;
	delete nextNode;
}

//method to add to the existing count, default +1
void ItemNode::AddToCount(int add)
{
	count += add;
}

//Recursivly traverse the list with an item name.
//if it matches add one.
//if not, and there are no more nodes, create a new node.
//otherwise pass it to the next node.
void ItemNode::CountItem(string name) {
	if (name == this->GetName()) {
		this->AddToCount();
	}
	else if (this->GetNextNode() == nullptr) {
		ItemNode* newNode = new ItemNode(name);
		this->SetNextNode(newNode);
	}
	else {
		this->GetNextNode()->CountItem(name);
	}
}

//output the item name and its count
void ItemNode::PrintItemCount()
{
	cout << setfill(' ') << setw(12) << name << " " << count << endl;
}

//output the item name and '*' equal to the number of hits.
void ItemNode::PrintItemHistogram()
{
	cout << setfill(' ') << setw(12) << name << setw(count) << setfill('*') << "" << endl;
}

//Recursivly traverse the list printing the count of each item.
void ItemNode::PrintListCount() 
{
	if (this->count > 0) {
		this->PrintItemCount();
	}
	if (this->GetNextNode() != nullptr) {
		this->GetNextNode()->PrintListCount();
	}
}

//Recursively traverse the list printing each items bar chart.
void ItemNode::PrintListHistogram()
{
	if (this->count > 0) {
		this->PrintItemHistogram();
	}
	if (this->GetNextNode() != nullptr) {
		this->GetNextNode()->PrintListHistogram();
	}
}

//Recursively traverse the list to find a specific item
//then output just that items count.
void ItemNode::CountForItem(string item) 
{
	if (this->GetName() == item) {
		this->PrintItemCount();
		return;
	}
	else if (this->GetNextNode() == nullptr) {
		cout << "Item not found" << endl;
		return;
	}
	else {
		this->GetNextNode()->CountForItem(item);
	}
}

//MUTATORS AND ACCESSORS
string ItemNode::GetName()
{
	return name;
}

void ItemNode::SetName(string name)
{
	this->name = name;
}

int ItemNode::GetCount()
{
	return count;
}

void ItemNode::SetCount(int count)
{
	this->count = count;
}

ItemNode* ItemNode::GetNextNode()
{
	return nextNode;
}

void ItemNode::SetNextNode(ItemNode* nextNode)
{
	this->nextNode = nextNode;
}
