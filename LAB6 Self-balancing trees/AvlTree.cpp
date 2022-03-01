#include "AvlTree.h"
using namespace std;

AvlTreeNode* AvlTree::Insert(AvlTreeNode* currentNode,
							int keyToInsert,
							string valueToInsert,
							AvlTreeNode* parentNode)
{
	if (!currentNode)
	{
		currentNode = new AvlTreeNode(keyToInsert, valueToInsert);
		if (!parentNode)
		{
			_root = currentNode;
			return nullptr;
		}
		if (currentNode->Key < parentNode->Key)
		{
			parentNode->LeftSubtree = currentNode;
			currentNode->Parent = parentNode;
		}
		else
		{
			parentNode->RightSubtree = currentNode;
			currentNode->Parent = parentNode;
		}
	}
	else if (keyToInsert < currentNode->Key)
	{
		Insert(currentNode->LeftSubtree,
			keyToInsert, valueToInsert, currentNode);
	}
	else
	{
		Insert(currentNode->RightSubtree,
			keyToInsert, valueToInsert, currentNode);
	}
	return GoBalance(currentNode);
}

string AvlTree::SearchByKey(int keyToSearch)
{
	return FindNodeByKey(keyToSearch)->Value;
}

void AvlTree::DeleteByKey(int keyToDelete)
{
	AvlTreeNode* nodeToDelete = FindNodeByKey(keyToDelete);
	AvlTreeNode* parentNode = nodeToDelete->Parent;
	delete nodeToDelete;
	while (!parentNode)
	{
		GoBalance(parentNode);
		parentNode = parentNode->Parent;
	}
}

AvlTreeNode* AvlTree::FindNodeByKey(int keyToFind)
{
	AvlTreeNode* currentNode = _root;
	while (currentNode != nullptr)
	{
		if (keyToFind < currentNode->Key)
		{
			currentNode = currentNode->LeftSubtree;
		}
		else if (keyToFind > currentNode->Key)
		{
			currentNode = currentNode->RightSubtree;
		}
		else
		{
			return currentNode;
		}
	}
	throw exception("Error: there is no node with such key.");
}

AvlTreeNode* AvlTree::InsertWithRoot(int keyToInsert, 
									string valueToInsert)
{
	return nullptr;
}

AvlTreeNode* AvlTree::GoBalance(AvlTreeNode* sourceRoot)
{
	sourceRoot->FixHeight();
	if (sourceRoot->BalanceFactor() == 2)
	{
		if (sourceRoot->LeftSubtree
			&& sourceRoot->LeftSubtree->BalanceFactor() < 0)
		{
			sourceRoot = RotateRight(sourceRoot);
		}
		sourceRoot = RotateLeft(sourceRoot);
	}
	if (sourceRoot->BalanceFactor() == -2)
	{
		if (sourceRoot->LeftSubtree
			&& sourceRoot->LeftSubtree->BalanceFactor() > 0)
		{
			sourceRoot = RotateLeft(sourceRoot);
		}
		sourceRoot = RotateLeft(sourceRoot);
	}
	return sourceRoot;
}

AvlTreeNode* AvlTree::RotateLeft(AvlTreeNode* sourceRoot)
{
	AvlTreeNode* newRoot = sourceRoot->RightSubtree;
	sourceRoot->RightSubtree = newRoot->LeftSubtree;
	newRoot->LeftSubtree = sourceRoot;
	sourceRoot->FixHeight();
	newRoot->FixHeight();
	return newRoot;
}

AvlTreeNode* AvlTree::RotateRight(AvlTreeNode* sourceRoot)
{
	AvlTreeNode* newRoot = sourceRoot->LeftSubtree;
	sourceRoot->LeftSubtree = newRoot->RightSubtree;
	newRoot->RightSubtree = sourceRoot;
	sourceRoot->FixHeight();
	newRoot->FixHeight();
	return newRoot;
}

AvlTree::AvlTree()
{
}

AvlTreeNode* AvlTree::GetRoot()
{
	return _root;
}
