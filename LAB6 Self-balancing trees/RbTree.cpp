﻿#include "RbTree.h"

RbTree::RbTree()
{
	_nil = new RbTreeNode(0, "nil", nullptr);
	_nil->SetBlack();
}

RbTreeNode* RbTree::Insert(RbTreeNode* currentNode,
						   int keyToInsert,
						   string valueToInsert)
{
	RbTreeNode* newNode = new RbTreeNode(keyToInsert,
										 valueToInsert, _nil);
	if (!_root)
	{
		_root = newNode;
		_root->Parent = _nil;
	}
	else
	{
		RbTreeNode* tmpNodeForSearch = _root;
		RbTreeNode* parentNode = nullptr;
		while (tmpNodeForSearch != _nil)
		{
			parentNode = tmpNodeForSearch;
			if (tmpNodeForSearch->Key < keyToInsert)
			{
				tmpNodeForSearch = tmpNodeForSearch->LeftSubtree;
			}
			else
			{
				tmpNodeForSearch = tmpNodeForSearch->RightSubtree;
			}
		}
		if (parentNode->Key < keyToInsert)
		{
			parentNode->LeftSubtree = newNode;
		}
		else
		{
			parentNode->RightSubtree = newNode;
		}
		newNode->Parent = parentNode;
		GoBalanceAfterInsertion(newNode);
	}
	return currentNode;
}

void RbTree::DeleteByKey(int keyToDelete)
{
	if (GetRoot())
	{
		throw exception("Error: root node is empty");
	}
	RbTreeNode* currentNode = _root;
	while (currentNode != GetNil()
		   && keyToDelete != currentNode->Key)
	{
		if (keyToDelete < currentNode->Key)
		{
			currentNode = currentNode->LeftSubtree;
		}
		else
		{
			currentNode = currentNode->RightSubtree;
		}
	}
	if (currentNode->LeftSubtree == GetNil()
		&&
		currentNode->RightSubtree == GetNil())
	{
		if (currentNode == GetRoot())
		{
			_root = GetNil();
		}
		else
		{
			RbTreeNode* parent = currentNode->Parent;
			if (currentNode == parent->LeftSubtree)
			{
				parent->LeftSubtree = GetNil();
				delete currentNode;
			}
			else
			{
				parent->RightSubtree = GetNil();
				delete currentNode;
			}
			return;
		}
	}
	RbTreeNode* nodeWithNextKey = currentNode->RightSubtree;
	if (currentNode->LeftSubtree != GetNil()
		&&
		currentNode->RightSubtree == GetNil())
	{
		RbTreeNode* parent = currentNode->Parent;
		if (currentNode == parent->LeftSubtree)
		{
			parent->LeftSubtree = currentNode->LeftSubtree;
			delete currentNode->LeftSubtree;
		}
		else
		{
			parent->RightSubtree = currentNode->LeftSubtree;
			delete currentNode->LeftSubtree;
		}
	}
	else if (currentNode->RightSubtree != GetNil()
			 &&
			 currentNode->LeftSubtree == GetNil())
	{
		RbTreeNode* parent = currentNode->Parent;
		if (currentNode == parent->LeftSubtree)
		{
			parent->LeftSubtree = currentNode->RightSubtree;
			delete currentNode->RightSubtree;
		}
		else
		{
			parent->RightSubtree = currentNode->RightSubtree;
			delete currentNode->RightSubtree;
		}
	}
	else
	{
		while (nodeWithNextKey->LeftSubtree != GetNil())
		{
			nodeWithNextKey = nodeWithNextKey->LeftSubtree;
		}
		if (nodeWithNextKey->RightSubtree != GetNil())
		{
			nodeWithNextKey->RightSubtree->Parent =
				nodeWithNextKey->Parent;
		}
		if (nodeWithNextKey == GetRoot())
		{
			GetRoot() = nodeWithNextKey->RightSubtree;
		}
		else
		{
			RbTreeNode* parent = currentNode->Parent;
			if (currentNode == parent->LeftSubtree)
			{
				parent->LeftSubtree = nodeWithNextKey;
			}
			else
			{
				parent->RightSubtree = nodeWithNextKey;
			}
		}
	}
	if (nodeWithNextKey != currentNode)
	{
		if (nodeWithNextKey->IsRed())
		{
			currentNode->SetRed();
		}
		else
		{
			currentNode->SetBlack();
		}
	}
	if (!nodeWithNextKey->IsRed())
	{
		GoBalanceAfterDeletion(currentNode);
	}
}

string RbTree::SearchByKey(int keyToSearch)
{
	RbTreeNode* currentNode = GetRoot();
	while (currentNode != GetNil())
	{
		if (keyToSearch < currentNode->Key)
		{
			currentNode = currentNode->LeftSubtree;
		}
		else if (keyToSearch > currentNode->Key)
		{
			currentNode = currentNode->RightSubtree;
		}
		else
		{
			return currentNode->Value;
		}
	}
	throw exception("Error: there is no node with such key");
}

void RbTree::GoBalanceAfterInsertion(RbTreeNode* insertedNode)
{
	RbTreeNode* nodeToBalance = insertedNode;
	if (nodeToBalance == GetRoot())
	{
		nodeToBalance->SetBlack();
		return;
	}
	RbTreeNode* parent = nodeToBalance->Parent;
	while (parent->IsRed())
	{
		RbTreeNode* grandfather = parent->Parent;
		if (grandfather && parent == grandfather->LeftSubtree)
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (uncle != GetNil()
				&& uncle->IsRed())
			{
				parent->SetBlack();
				uncle->SetBlack();
				grandfather->SetRed();
				nodeToBalance = grandfather;
				//TODO: to method
				parent = nodeToBalance->Parent;
				grandfather = parent->Parent;
			}
			else
			{
				if (parent->RightSubtree == nodeToBalance)
				{
					nodeToBalance = parent;
					nodeToBalance = RotateLeft(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->Parent;
				}
				parent->SetBlack();
				grandfather->SetRed();
				nodeToBalance->Parent->Parent =
					RotateRight(grandfather);
			}
		}
		else
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (uncle
				&& uncle != GetNil()
				&& uncle->IsRed())
			{
				parent->SetBlack();
				uncle->SetBlack();
				grandfather->SetRed();
				nodeToBalance = grandfather;
				//TODO: to method
				parent = nodeToBalance->Parent;
				grandfather = parent->Parent;
			}
			else
			{
				if (nodeToBalance == parent->LeftSubtree)
				{
					nodeToBalance = parent;
					nodeToBalance = RotateRight(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->Parent;
					grandfather = parent->Parent;
				}
				parent->SetBlack();
				grandfather->SetRed();
				nodeToBalance->Parent->Parent =
					RotateLeft(grandfather);
			}
		}
	}
	GetRoot()->SetBlack();
}

void RbTree::GoBalanceAfterDeletion(RbTreeNode* nodeToBalance)
{
	RbTreeNode* currentNode = nodeToBalance;
	while (currentNode != GetRoot()
		   &&
		   !currentNode->IsRed())
	{
		RbTreeNode* parent = currentNode;
		if (currentNode == parent->LeftSubtree)
		{
			RbTreeNode* brother = parent->RightSubtree;
			if (brother->IsRed())
			{
				brother->SetBlack();
				parent->SetRed();
				currentNode->Parent =
					RotateLeft(parent);
			}
			if (brother->LeftSubtree
				&& brother->LeftSubtree
				&& !brother->LeftSubtree->IsRed()
				&& !brother->RightSubtree->IsRed())
			{
				brother->SetRed();
			}
			else
			{
				if (brother->RightSubtree
					&& !brother->RightSubtree->IsRed())
				{
					brother->LeftSubtree->SetBlack();
					brother->SetRed();
					currentNode->Parent->RightSubtree =
						RotateRight(brother);
				}
				if (parent->IsRed())
				{
					brother->SetRed();
				}
				else
				{
					brother->SetBlack();
				}
				parent->SetBlack();
				brother->RightSubtree->SetBlack();
				currentNode->Parent =
					RotateLeft(parent);
				currentNode = GetRoot();
			}
		}
	}
	currentNode->SetBlack();
	GetRoot()->SetBlack();
}

RbTreeNode* RbTree::RotateLeft(RbTreeNode* rotateNode)
{
	//TODO: Fix reassignmensts of pointers for parents as is in AVL 
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
		if (rotateNode->RightSubtree
			&& rotateNode->RightSubtree->LeftSubtree)
		{
			rotateNode->RightSubtree->LeftSubtree->Parent =
				rotateNode->Parent;
		}
	}

	//Do rotation
	if (rotateNode->RightSubtree)
	{
		RbTreeNode* tmp = rotateNode->RightSubtree->LeftSubtree;
		rotateNode->RightSubtree->LeftSubtree = rotateNode;
		rotateNode->RightSubtree->Parent = rotateNode->Parent;
		rotateNode->Parent = rotateNode->RightSubtree;
		rotateNode->RightSubtree = tmp;
		if (tmp)
		{
			tmp->Parent = rotateNode;
		}
	}
	//Fix color
	//if (rotateNode->IsRed())
	//{
	//	newRoot->SetRed();
	//}
	//else
	//{
	//	newRoot->SetBlack();
	//}
	return rotateNode;
}

RbTreeNode* RbTree::RotateRight(RbTreeNode* rotateNode)
{
	//TODO: Fix reassignmensts of pointers for parents as is in AVL 
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
	RbTreeNode* tmp = rotateNode->LeftSubtree->RightSubtree;
	rotateNode->LeftSubtree->RightSubtree = rotateNode;
	rotateNode->LeftSubtree->Parent = rotateNode->Parent;
	rotateNode->Parent = rotateNode->LeftSubtree;
	rotateNode->LeftSubtree = tmp;
	if (tmp)
	{
		tmp->Parent = rotateNode;
	}
	//Fix color
	//if (rotateNode->IsRed())
	//{
	//	newRoot->SetRed();
	//}
	//else
	//{
	//	newRoot->SetBlack();
	//}
	return rotateNode;
}

RbTreeNode* RbTree::GetRoot()
{
	return _root;
}

void RbTree::SetRoot(RbTreeNode* newRoot)
{
	_root = newRoot;
	_root->SetBlack();
	_root->Parent = nullptr;
}

RbTreeNode* RbTree::GetNil()
{
	return _nil;
}
