#include "RbTree.h"

RbTree::RbTree(int rootKey, string rootValue)
{
	_nil = new RbTreeNode(0, "nil", nullptr);
	_nil->Set;
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
}

void RbTree::DeleteByKey(int keyToDelete)
{

}

string RbTree::SearchByKey(int keyToSearch)
{
	RbTreeNode* currentNode = _root;
	while (currentNode!=_nil)
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
			if (uncle != _nil && uncle->IsRed())
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
					_SmallLeftRotation(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->ParentNode;
				}
				parent->SetBlack();
				grandfather->SetRed();
				_SmallRightRotation(grandfather);
			}
		}
		else
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (uncle!= _nil && uncle->IsRed())
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
					_SmallRightRotation(nodeToBalance);
					//TODO: to method
					parent = nodeToBalance->ParentNode;
					grandfather = parent->ParentNode;
				}
				parent->SetBlack();
				grandfather->SetRed();
				_SmallLeftRotation(grandfather);
			}
		}
	}
	_root->SetBlack();
}

void RbTree::GoBalanceAfterDeletion(RbTreeNode* nodeToBalance)
{
}

RbTreeNode* RbTree::_SmallLeftRotation(RbTreeNode* sourceRoot)
{
	RbTreeNode* newRoot = sourceRoot->RightSubtree;
	sourceRoot->RightSubtree = newRoot->LeftSubtree;
	newRoot->LeftSubtree = sourceRoot;
	sourceRoot->FixHeightBlack();
	newRoot->FixHeightBlack();
	return newRoot;
}

RbTreeNode* RbTree::_SmallRightRotation(RbTreeNode* sourceRoot)
{
	RbTreeNode* newRoot = sourceRoot->LeftSubtree;
	sourceRoot->LeftSubtree = newRoot->RightSubtree;
	newRoot->RightSubtree = sourceRoot;
	sourceRoot->FixHeightBlack();
	newRoot->FixHeightBlack();
	return newRoot;
}

RbTreeNode* RbTree::GetRoot()
{
	return _root;
}
