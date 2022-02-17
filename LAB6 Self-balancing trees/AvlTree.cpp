﻿#include "AvlTree.h"
using namespace std;

AvlTreeNode* AvlTree::Insert(AvlTreeNode* currentNode,
							int keyToInsert,
							string valueToInsert)
{
	if (!currentNode)
	{
		currentNode = new AvlTreeNode(keyToInsert, valueToInsert);
	}
	if (keyToInsert > currentNode->_key)
	{
		Insert(currentNode->_rightSubtree, 
			keyToInsert, valueToInsert);
	}
	else
	{
		Insert(currentNode->_leftSubtree,
			keyToInsert, valueToInsert);
	}
	return _GoBalance(currentNode);
}

string AvlTree::keySearch(int keyToSearch)
{
	AvlTreeNode* currentNode = _FindNodeByKey(keyToSearch);
	return currentNode->_value;
}

void AvlTree::DeleteByKey(int keyToDelete)
{
	AvlTreeNode* currentNode = _FindNodeByKey(keyToDelete);
	AvlTreeNode* parentNode = currentNode->_parent;
	delete currentNode;
	_GoBalance(parentNode);
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
	throw exception("Error: there is no node with such key.");
}

AvlTreeNode* AvlTree::_GoBalance(AvlTreeNode* sourceRoot)
{
	sourceRoot->FixHeight();
	if (sourceRoot->BalanceFactor() == 2)
	{
		if (sourceRoot->_leftSubtree->BalanceFactor() < 0)
		{
			sourceRoot = _SmallRightRotation(sourceRoot);
		}
		sourceRoot = _SmallLeftRotation(sourceRoot);
	}
	if (sourceRoot->BalanceFactor() == -2)
	{
		if (sourceRoot->_leftSubtree->BalanceFactor() > 0)
		{
			sourceRoot = _SmallLeftRotation(sourceRoot);
		}
		sourceRoot = _SmallLeftRotation(sourceRoot);
	}
	return sourceRoot;
}

AvlTreeNode* AvlTree::_SmallLeftRotation(AvlTreeNode* sourceRoot)
{
	AvlTreeNode* newRoot = sourceRoot->_rightSubtree;
	sourceRoot->_rightSubtree = newRoot->_leftSubtree;
	newRoot->_leftSubtree = sourceRoot;
	sourceRoot->FixHeight();
	newRoot->FixHeight();
	return newRoot;
}

AvlTreeNode* AvlTree::_SmallRightRotation(AvlTreeNode* sourceRoot)
{
	AvlTreeNode* newRoot = sourceRoot->_leftSubtree;
	sourceRoot->_leftSubtree = newRoot->_rightSubtree;
	newRoot->_rightSubtree = sourceRoot;
	sourceRoot->FixHeight();
	newRoot->FixHeight();
	return newRoot;
}

AvlTreeNode* AvlTree::_BigLeftRotation(AvlTreeNode* node)
{

}

AvlTreeNode* AvlTree::_BigRightRotation(AvlTreeNode* node)
{
}

AvlTree::AvlTree(int rootKey, string rootValue)
{
	_root._key = rootKey;
	_root._value = rootValue;
}