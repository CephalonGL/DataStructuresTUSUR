#pragma once
#include <string>
#include "AvlTreeNode.h"
using namespace std;

class AvlTree
{
public:
	void Insert(int keyToInsert, string valueToInsert);
	string GetValueByKey(int keyToSearch);
	void DeleteByKey(int keyToDelete);
	AvlTree(int rootKey, string rootValue);
private:
	AvlTreeNode _root;
	AvlTreeNode* _FindNodeByKey(int keyToFind);
	void _GoBalance(AvlTreeNode* node);
	void _SmallLeftRotation();
	void _SmallRightRotation();
	void _BigLeftRotation();
	void _BigRightRotation();
};
