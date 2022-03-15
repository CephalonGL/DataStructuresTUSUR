#include "AvlTree.h"
using namespace std;

void AvlTree::Insert(AvlTreeNode* currentNode,
					 int keyToInsert,
					 string valueToInsert,
					 AvlTreeNode* parentNode)
{

	try
	{
		FindNodeByKey(keyToInsert);
		throw exception("Error: there is already"
						" a node with such key.");
	}
	catch (const exception&)
	{
	}
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

string AvlTree::GetValueByKey(int keyToSearch)
{
	return FindNodeByKey(keyToSearch)->Value;
}

void AvlTree::DeleteByKey(int keyToDelete)
{
	if (!GetRoot())
	{
		throw exception("Error: root is empty.");
	}
	AvlTreeNode* nodeToDelete = FindNodeByKey(keyToDelete);
	if (!nodeToDelete->RightSubtree)
	{
		if (nodeToDelete == GetRoot())
		{
			if (!nodeToDelete->LeftSubtree)
			{
				delete nodeToDelete;
				SetRoot(nullptr);
			}
			else
			{
				nodeToDelete->LeftSubtree->Parent = nullptr;
				SetRoot(nodeToDelete->LeftSubtree);
				delete nodeToDelete;
				nodeToDelete = nullptr;
			}
		}
		else if (!nodeToDelete->LeftSubtree
				 && !nodeToDelete->RightSubtree)
		{
			if (nodeToDelete == nodeToDelete->Parent->LeftSubtree)
			{
				nodeToDelete->Parent->LeftSubtree = nullptr;
			}
			else
			{
				nodeToDelete->Parent->RightSubtree = nullptr;
			}
			delete nodeToDelete;
		}
		else
		{
			nodeToDelete->LeftSubtree->Parent = nodeToDelete->Parent;
			if (nodeToDelete == nodeToDelete->Parent->LeftSubtree)
			{
				nodeToDelete->Parent->LeftSubtree =
					nodeToDelete->LeftSubtree;
			}
			else
			{
				nodeToDelete->Parent->RightSubtree =
					nodeToDelete->LeftSubtree;
			}
			GoBalanceUpToRoot(nodeToDelete->Parent);
			delete nodeToDelete;
			nodeToDelete = nullptr;
		}
		return;
	}
	AvlTreeNode* nodeWithMinKey =
		FindNodeWithMinKey(nodeToDelete->RightSubtree);

	if (nodeToDelete == GetRoot())
	{
		SetRoot(nodeWithMinKey);
	}
	if (nodeWithMinKey->RightSubtree)
	{
		nodeWithMinKey->Parent->LeftSubtree =
			nodeWithMinKey->RightSubtree;
		nodeWithMinKey->RightSubtree->Parent =
			nodeWithMinKey->Parent->LeftSubtree;
		GoBalanceUpToRoot(nodeWithMinKey->RightSubtree);
	}
	if (nodeToDelete->LeftSubtree
		&& nodeWithMinKey != nodeToDelete->RightSubtree)
	{
		nodeWithMinKey->LeftSubtree = nodeToDelete->LeftSubtree;
		nodeWithMinKey->LeftSubtree->Parent = nodeWithMinKey;
	}
	if (nodeToDelete->RightSubtree
		&& nodeToDelete->RightSubtree != nodeWithMinKey)
	{
		nodeWithMinKey->RightSubtree = nodeToDelete->RightSubtree;
		nodeWithMinKey->RightSubtree->Parent = nodeWithMinKey;
	}
	if (nodeToDelete->Parent
		&& nodeWithMinKey != nodeToDelete->RightSubtree)
	{
		nodeWithMinKey->Parent = nodeToDelete->Parent;
		if (nodeToDelete == nodeToDelete->Parent->LeftSubtree)
		{
			nodeToDelete->Parent->LeftSubtree = nodeWithMinKey;
		}
		else
		{
			nodeToDelete->Parent->RightSubtree = nodeWithMinKey;
		}
	}
	GoBalance(nodeWithMinKey);
	delete nodeToDelete;
	nodeToDelete = nullptr;
}

AvlTreeNode* AvlTree::FindNodeByKey(int keyToFind)
{
	AvlTreeNode* currentNode = GetRoot();
	while (currentNode)
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
	if (newRoot)
	{
		_root->Parent = nullptr;
	}
}

void AvlTree::GoBalance(AvlTreeNode* nodeToBalance)
{
	if (!nodeToBalance)
	{
		return;
	}
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
		if (rotateNode->LeftSubtree->RightSubtree)
		{
			rotateNode->LeftSubtree->RightSubtree->Parent =
				rotateNode->Parent;
		}
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

AvlTreeNode* AvlTree::FindNodeWithMinKey(AvlTreeNode* sourceNode)
{
	return sourceNode->LeftSubtree ?
		FindNodeWithMinKey(sourceNode->LeftSubtree)
		: sourceNode;
}

void AvlTree::GoBalanceUpToRoot(AvlTreeNode* sourceNode)
{
	while (sourceNode)
	{
		GoBalance(sourceNode);
		sourceNode = sourceNode->Parent;
	}
}


AvlTreeNode* AvlTree::GetRoot()
{
	return _root;
}
