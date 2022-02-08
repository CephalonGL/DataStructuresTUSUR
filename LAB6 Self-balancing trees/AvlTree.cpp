#include "AvlTree.h"
using namespace std;

void AvlTree::Insert(int keyToInsert, string valueToInsert)
{
	AvlTreeNode* currentNode = &_root;
	while (currentNode != nullptr)
	{
		if (currentNode->_key == keyToInsert)
		{
			while (currentNode != &_root)
			{
				currentNode->_height--;
				currentNode = currentNode->_parent;
			}
			throw string("InsertError: there is already a node with such key.");
		}
		currentNode->_height++;
		if (currentNode->_key < keyToInsert)
		{
			currentNode = currentNode->_leftSubtree;
		}
		else
		{
			currentNode = currentNode->_rightSubtree;
		}
	}
	_GoBalance(currentNode);
}

string AvlTree::GetValueByKey(int keyToSearch)
{
	try
	{
		AvlTreeNode* currentNode = _FindNodeByKey(keyToSearch);
		return currentNode->_value;
	}
	catch (const string msg)
	{
		throw msg;
		return "";
	}
}

void AvlTree::DeleteByKey(int keyToDelete)
{
	try
	{
		AvlTreeNode* currentNode = _FindNodeByKey(keyToDelete);
		AvlTreeNode* parentNode = currentNode->_parent;
		delete currentNode;
		currentNode = nullptr;
		_GoBalance(parentNode);
	}
	catch (const string msg)
	{
		throw msg;
		return;
	}
}

AvlTreeNode* AvlTree::_FindNodeByKey(int keyToFind)
{
	AvlTreeNode* currentNode = &_root;
	while (currentNode != nullptr)
	{
		if (keyToFind < currentNode->_key)
		{
			currentNode = currentNode->_leftSubtree;
		}
		else if (keyToFind > currentNode->_key)
		{
			currentNode = currentNode->_rightSubtree;
		}
		else
		{
			return currentNode;
		}
	}
	throw string("Error: there is no node with such key.");
	return nullptr;
}

void AvlTree::_GoBalance(AvlTreeNode* node)
{

}

void AvlTree::_SmallLeftRotation()
{
}

void AvlTree::_SmallRightRotation()
{
}

void AvlTree::_BigLeftRotation()
{
}

void AvlTree::_BigRightRotation()
{
}

AvlTree::AvlTree(int rootKey, string rootValue)
{
	_root._key = rootKey;
	_root._value = rootValue;
}