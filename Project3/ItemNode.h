/********************************
* Ken Smith
*CS210 Project 3
*ItemNode class
* defines the ItemNode for a linked list
* includes recursive methods for specific output formats
******************************/
#pragma once
#include <string>
using namespace std;
class ItemNode
{
public:
	ItemNode();
	ItemNode(string item);
	~ItemNode();
	void AddToCount(int add = 1);
	void CountItem(string name);
	void PrintItemCount();
	void PrintItemHistogram();
	void PrintListCount();
	void PrintListHistogram();
	void CountForItem(string item);
	string GetName();
	void SetName(string name);
	int GetCount();
	void SetCount(int count);
	ItemNode* GetNextNode();
	void SetNextNode(ItemNode* nextNode);

private:
	string name;
	int count;
	ItemNode* nextNode;
};

