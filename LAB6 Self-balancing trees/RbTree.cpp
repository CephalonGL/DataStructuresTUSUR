#include "RbTree.h"

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
		_root->ParentNode = _nil;
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
		newNode->ParentNode = parentNode;
		GoBalanceAfterInsertion(newNode);
	}
	return currentNode;
}

void RbTree::DeleteByKey(int keyToDelete)
{
	if (_root)
	{
		throw exception("Error: root node is empty");
	}
	RbTreeNode* currentNode = _root;
	while (currentNode != _nil 
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
	if (currentNode->LeftSubtree == _nil
		&&
		currentNode->RightSubtree == _nil)
	{
		if (currentNode == _root)
		{
			_root = _nil;
		}
		else
		{
			RbTreeNode* parent = currentNode->ParentNode;
			if (currentNode == parent->LeftSubtree)
			{
				parent->LeftSubtree = _nil;
				delete currentNode;
			}
			else
			{
				parent->RightSubtree = _nil;
				delete currentNode;
			}
			return;
		}
	}
	RbTreeNode* nodeWithNextKey = currentNode->RightSubtree;
	if (currentNode->LeftSubtree != _nil
		&&
		currentNode->RightSubtree == _nil)
	{
		RbTreeNode* parent = currentNode->ParentNode;
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
	else if (currentNode->RightSubtree != _nil
		&&
		currentNode->LeftSubtree == _nil)
	{
		RbTreeNode* parent = currentNode->ParentNode;
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
		while (nodeWithNextKey->LeftSubtree != _nil)
		{
			nodeWithNextKey = nodeWithNextKey->LeftSubtree;
		}
		if (nodeWithNextKey->RightSubtree != _nil)
		{
			nodeWithNextKey->RightSubtree->ParentNode =
				nodeWithNextKey->ParentNode;
		}
		if (nodeWithNextKey == _root)
		{
			_root = nodeWithNextKey->RightSubtree;
		}
		else
		{
			RbTreeNode* parent = currentNode->ParentNode;
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
	RbTreeNode* currentNode = _root;
	while (currentNode != _nil)
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
	if (nodeToBalance == _root)
	{
		nodeToBalance->SetBlack();
		return;
	}
	RbTreeNode* parent = nodeToBalance->ParentNode;
	while (parent->IsRed())
	{
		RbTreeNode* grandfather = parent->ParentNode;
		if (grandfather && parent == grandfather->LeftSubtree)
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (uncle != _nil 
				&& uncle->IsRed())
			{
				parent->SetBlack();
				uncle->SetBlack();
				grandfather->SetRed();
				nodeToBalance = grandfather;
				//TODO: to method
				parent = nodeToBalance->ParentNode;
				grandfather = parent->ParentNode;
			}
			else
			{
				if (parent->RightSubtree == nodeToBalance)
				{
					nodeToBalance = parent;
					nodeToBalance = _SmallLeftRotation(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->ParentNode;
				}
				parent->SetBlack();
				grandfather->SetRed();
				nodeToBalance->ParentNode->ParentNode =
					_SmallRightRotation(grandfather);
			}
		}
		else
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (uncle != _nil 
				&& uncle->IsRed())
			{
				parent->SetBlack();
				uncle->SetBlack();
				grandfather->SetRed();
				nodeToBalance = grandfather;
				//TODO: to method
				parent = nodeToBalance->ParentNode;
				grandfather = parent->ParentNode;
			}
			else
			{
				if (nodeToBalance == parent->LeftSubtree)
				{
					nodeToBalance = parent;
					nodeToBalance = _SmallRightRotation(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->ParentNode;
					grandfather = parent->ParentNode;
				}
				parent->SetBlack();
				grandfather->SetRed();
				nodeToBalance->ParentNode->ParentNode =
					_SmallLeftRotation(grandfather);
			}
		}
	}
	_root->SetBlack();
}

void RbTree::GoBalanceAfterDeletion(RbTreeNode* nodeToBalance)
{
	RbTreeNode* currentNode = nodeToBalance;
	while (currentNode != _root
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
				currentNode->ParentNode =
					_SmallLeftRotation(parent);
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
					currentNode->ParentNode->RightSubtree =
						_SmallRightRotation(brother);
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
				currentNode->ParentNode =
					_SmallLeftRotation(parent);
				currentNode = _root;
			}
		}
	}
	currentNode->SetBlack();
	_root->SetBlack();
}

RbTreeNode* RbTree::_SmallLeftRotation(RbTreeNode* sourceRoot)
{
	RbTreeNode* newRoot = sourceRoot->RightSubtree;
	sourceRoot->RightSubtree = newRoot->LeftSubtree;
	newRoot->LeftSubtree = sourceRoot;
	if (sourceRoot->IsRed())
	{
		newRoot->SetRed();
	}
	else
	{
		newRoot->SetBlack();
	}
	return newRoot;
}

RbTreeNode* RbTree::_SmallRightRotation(RbTreeNode* sourceRoot)
{
	RbTreeNode* newRoot = sourceRoot->LeftSubtree;
	sourceRoot->LeftSubtree = newRoot->RightSubtree;
	newRoot->RightSubtree = sourceRoot;
	if (sourceRoot->IsRed())
	{
		newRoot->SetRed();
	}
	else
	{
		newRoot->SetBlack();
	}
	return newRoot;
}

RbTreeNode* RbTree::GetRoot()
{
	return _root;
}

RbTreeNode* RbTree::GetNil()
{
	return _nil;
}
