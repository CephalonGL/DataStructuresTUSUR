#include "AvlTree.h"
using namespace std;

void AvlTree::Insert(AvlTreeNode* currentNode,
	int keyToInsert,
	string valueToInsert,
	AvlTreeNode* parentNode)
{
	if (!currentNode)
	{
		currentNode = new AvlTreeNode(keyToInsert, valueToInsert);
		if (!GetRoot())
		{
			SetRoot(currentNode);
		}
		else if (currentNode->Key < parentNode->Key)
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
	GoBalance(currentNode);
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

void AvlTree::SetRoot(AvlTreeNode* newRoot)
{
	_root = newRoot;
	_root->Parent = nullptr;
}

AvlTreeNode* AvlTree::InsertWithRoot(int keyToInsert,
	string valueToInsert)
{
	return nullptr;
}

void AvlTree::GoBalance(AvlTreeNode* nodeToBalance)
{
	//BUG: balancing do not work. Pointers are not switching as they
	//should do.
	nodeToBalance->FixHeight();
	if (nodeToBalance->BalanceFactor() == 2)
	{
		if (nodeToBalance->LeftSubtree
			&& nodeToBalance->LeftSubtree->BalanceFactor() < 0)
		{
			RotateRight(nodeToBalance);
		}
		RotateLeft(nodeToBalance);
	}
	if (nodeToBalance->BalanceFactor() == -2)
	{
		if (nodeToBalance->LeftSubtree
			&& nodeToBalance->LeftSubtree->BalanceFactor() > 0)
		{
			RotateLeft(nodeToBalance);
		}
		RotateRight(nodeToBalance);
	}
}

void AvlTree::RotateLeft(AvlTreeNode* rotateNode)
{
	//Fix root
	if (rotateNode == GetRoot())
	{
		SetRoot(rotateNode->RightSubtree);
	}
	//Fix parents
	else
	{
		if (rotateNode->Parent->LeftSubtree
			&& rotateNode == rotateNode->Parent->LeftSubtree)
		{
			rotateNode->Parent->LeftSubtree = rotateNode->RightSubtree;
		}
		else
		{
			rotateNode->Parent->RightSubtree = rotateNode->RightSubtree;
		}
		if (rotateNode->RightSubtree->LeftSubtree)
		{
			rotateNode->RightSubtree->LeftSubtree->Parent =
				rotateNode->Parent;
		}
	}

	//Do rotation
	AvlTreeNode* tmp = rotateNode->RightSubtree->LeftSubtree;
	rotateNode->RightSubtree->LeftSubtree = rotateNode;
	rotateNode->RightSubtree->Parent = rotateNode->Parent;
	rotateNode->Parent = rotateNode->RightSubtree;
	rotateNode->RightSubtree = tmp;
	if (tmp)
	{
		tmp->Parent = rotateNode;
	}

	//Fix heights after rotation
	rotateNode->FixHeight();
	rotateNode->Parent->FixHeight();
}

void AvlTree::RotateRight(AvlTreeNode* rotateNode)
{
	//Fix root
	if (rotateNode == GetRoot())
	{
		SetRoot(rotateNode->LeftSubtree);
	}
	//Fix parents
	else
	{
		if (rotateNode->Parent->LeftSubtree
			&& rotateNode == rotateNode->Parent->LeftSubtree)
		{
			rotateNode->Parent->LeftSubtree = rotateNode->LeftSubtree;
		}
		else
		{
			rotateNode->Parent->RightSubtree = rotateNode->LeftSubtree;
		}
		rotateNode->LeftSubtree->RightSubtree->Parent =
			rotateNode->Parent;
	}

	//Do rotation
	AvlTreeNode* tmp = rotateNode->LeftSubtree->RightSubtree;
	rotateNode->LeftSubtree->RightSubtree = rotateNode;
	rotateNode->LeftSubtree->Parent = rotateNode->Parent;
	rotateNode->Parent = rotateNode->LeftSubtree;
	rotateNode->LeftSubtree = tmp;
	if (tmp)
	{
		tmp->Parent = rotateNode;
	}

	//Fix heights after rotation
	rotateNode->FixHeight();
	rotateNode->Parent->FixHeight();
}

AvlTree::AvlTree()
{
}

AvlTreeNode* AvlTree::GetRoot()
{
	return _root;
}
