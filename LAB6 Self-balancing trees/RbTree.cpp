#include "RbTree.h"

RbTree::RbTree()
{
	SetNil(new RbTreeNode(0, "nil", nullptr));
	SetRoot(GetNil());
	GetRoot()->SetParent(GetNil());
	GetRoot()->SetLeft(GetNil());
	GetRoot()->SetRight(GetNil());
	GetRoot()->SetBlack();
}


void RbTree::Insert(int keyToInsert,
					string valueToInsert)
{
	if (IsNil(GetRoot()))
	{
		SetRoot(Insert(GetRoot(), keyToInsert, valueToInsert));
	}
	else
	{
		Insert(GetRoot(), keyToInsert, valueToInsert);
	}
	GetRoot()->SetParent(GetNil());
	GetRoot()->SetBlack();
}


RbTreeNode* RbTree::Insert(RbTreeNode* currentNode,
						   int keyToInsert,
						   string valueToInsert)
{
	RbTreeNode* newNode = new RbTreeNode(keyToInsert, valueToInsert,
										 GetNil());
	if (IsNil(GetRoot()))
	{
		return newNode;
	}
	else
	{
		RbTreeNode* currentNode = GetRoot();
		RbTreeNode* parentOfNewNode = GetRoot();
		while (!IsNil(currentNode))
		{
			parentOfNewNode = currentNode;
			if (currentNode->GetKey() < keyToInsert)
			{
				currentNode = GetRight(currentNode);
			}
			else
			{
				currentNode = GetLeft(currentNode);
			}
		}
		newNode->SetParent(parentOfNewNode);
		if (keyToInsert > parentOfNewNode->GetKey())
		{
			parentOfNewNode->SetRight(newNode);
		}
		else
		{
			parentOfNewNode->SetLeft(newNode);
		}
		GoBalanceAfterInsertion(newNode);
	}
	return currentNode;
}

void RbTree::DeleteByKey(int keyToDelete)
{
	if (IsNil(GetRoot()))
	{
		throw exception("Error: root node is empty.");
	}
	RbTreeNode* nodeToDelete = AssertFindNodeByKey(keyToDelete);
	if (IsNil(GetLeft(nodeToDelete))
		&& IsNil(GetRight(nodeToDelete)))
	{
		if (IsRoot(nodeToDelete))
		{
			SetRoot(GetNil());
		}
		else
		{
			if (IsLeftChild(nodeToDelete))
			{
				GetParent(nodeToDelete)->SetLeft(GetNil());
			}
			else
			{
				GetParent(nodeToDelete)->SetLeft(GetNil());
			}
		}
		delete nodeToDelete;
		return;
	}
	RbTreeNode* nodeWithNextMinKey =
		FindNodeWithNextMinKey(nodeToDelete);
	if (!IsNil(GetLeft(nodeToDelete))
		&& IsNil(GetRight(nodeToDelete)))
	{
		if (IsRoot(nodeToDelete))
		{
			SetRoot(GetLeft(nodeToDelete));
			GetLeft(nodeToDelete)->SetParent(GetNil());
		}
		else
		{
			if (IsLeftChild(nodeToDelete))
			{
				GetParent(nodeToDelete)->SetLeft(GetLeft(nodeToDelete));
			}
			else
			{
				GetParent(nodeToDelete)->SetRight(GetLeft(nodeToDelete));
			}
			GetLeft(nodeToDelete)->SetParent(GetParent(nodeToDelete));
		}
		delete nodeToDelete;
		return;
	}
	else if (IsNil(GetLeft(nodeToDelete))
			 && !IsNil(GetRight(nodeToDelete)))
	{
		if (IsRoot(nodeToDelete))
		{
			SetRoot(GetRight(nodeToDelete));
			GetRight(nodeToDelete)->SetParent(GetNil());
		}
		else
		{
			if (IsLeftChild(nodeToDelete))
			{
				GetParent(nodeToDelete)->SetLeft(GetRight(nodeToDelete));
			}
			else
			{
				GetParent(nodeToDelete)->SetRight(GetRight(nodeToDelete));
			}
			GetRight(nodeToDelete)->SetParent(GetParent(nodeToDelete));
		}
		delete nodeToDelete;
		return;
	}
	else
	{
		if (!IsNil(GetRight(nodeWithNextMinKey)))
		{
			GetRight(nodeWithNextMinKey)->
				SetParent(GetParent(nodeWithNextMinKey));
			GetParent(nodeWithNextMinKey)->
				SetLeft(GetRight(nodeWithNextMinKey));
		}
		if (IsRoot(nodeToDelete))
		{
			SetRoot(nodeWithNextMinKey);
			nodeWithNextMinKey->SetParent(GetNil());
			nodeWithNextMinKey->SetLeft(GetLeft(nodeToDelete));
			GetLeft(nodeWithNextMinKey)->SetParent(nodeWithNextMinKey);
			if (nodeWithNextMinKey != GetRight(nodeToDelete))
			{
				nodeWithNextMinKey->SetRight(GetRight(nodeToDelete));
				GetRight(nodeWithNextMinKey)->
					SetParent(nodeWithNextMinKey);
			}
			else
			{
				nodeWithNextMinKey->SetRight(GetNil());
			}
		}
		else
		{
			if (!IsNil(GetRight(nodeWithNextMinKey)))
			{
				GetRight(nodeWithNextMinKey)->
					SetParent(GetParent(nodeWithNextMinKey));
				GetParent(nodeWithNextMinKey)->
					SetLeft(GetRight(nodeWithNextMinKey));
			}
			if (IsLeftChild(nodeToDelete))
			{
				GetParent(nodeToDelete)->SetLeft(nodeWithNextMinKey);
			}
			else
			{
				GetParent(nodeToDelete)->SetRight(nodeWithNextMinKey);
			}
			nodeWithNextMinKey->SetParent(GetParent(nodeToDelete));
			if (nodeWithNextMinKey != GetRight(nodeToDelete))
			{
				nodeWithNextMinKey->SetRight(GetRight(nodeToDelete));
			}
			nodeWithNextMinKey->SetLeft(GetLeft(nodeToDelete));
			GetLeft(nodeToDelete)->SetParent(nodeWithNextMinKey);
		}
		delete nodeToDelete;
	}
	if (nodeWithNextMinKey->IsBlack())
	{
		GoBalanceAfterDeletion(nodeWithNextMinKey);
	}
}

string RbTree::GetValueByKey(int keyToSearch)
{
	RbTreeNode* currentNode = GetRoot();
	while (!IsNil(currentNode))
	{
		if (keyToSearch < currentNode->GetKey())
		{
			currentNode = GetLeft(currentNode);
		}
		else if (keyToSearch > currentNode->GetKey())
		{
			currentNode = GetRight(currentNode);
		}
		else
		{
			return currentNode->GetValue();
		}
	}
	throw exception("Error: there is no node with such key");
}

void RbTree::GoBalanceAfterInsertion(RbTreeNode* insertedNode)
{
	RbTreeNode* nodeToBalance = insertedNode;
	if (IsRoot(nodeToBalance))
	{
		nodeToBalance->SetBlack();
		return;
	}
	while (GetParent(nodeToBalance)->IsRed())
	{
		if (GetGrandparent(nodeToBalance)
			&& IsLeftChild(GetParent(nodeToBalance)))
		{
			if (!IsNil(GetUncle(nodeToBalance))
				&& GetUncle(nodeToBalance)->IsRed())
			{
				GetParent(nodeToBalance)->SetBlack();
				GetUncle(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				nodeToBalance = GetGrandparent(nodeToBalance);
			}
			else
			{
				if (IsRightChild(nodeToBalance))
				{
					nodeToBalance = RotateLeft(GetParent(nodeToBalance));
				}
				GetParent(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				RotateRight(GetGrandparent(nodeToBalance));
			}
		}
		else if (GetGrandparent(nodeToBalance))
		{
			if (!IsNil(GetUncle(nodeToBalance))
				&& GetUncle(nodeToBalance)->IsRed())
			{
				GetParent(nodeToBalance)->SetBlack();
				GetUncle(nodeToBalance)->SetBlack();
				nodeToBalance = GetGrandparent(nodeToBalance);
			}
			else
			{
				if (IsLeftChild(nodeToBalance))
				{
					nodeToBalance = RotateRight(GetParent(nodeToBalance));
				}
				GetParent(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				RotateLeft(GetGrandparent(nodeToBalance));
			}
		}
	}
	GetRoot()->SetBlack();
}

void RbTree::GoBalanceAfterDeletion(RbTreeNode* nodeToBalance)
{
	RbTreeNode* currentNode = nodeToBalance;
	while (!IsRoot(currentNode)
		   && currentNode->IsBlack())
	{
		if (IsLeftChild(currentNode))
		{
			if (GetBrother(currentNode)->IsRed())
			{
				GetBrother(currentNode)->SetBlack();
				GetParent(currentNode)->SetRed();
				RotateLeft(GetParent(currentNode));
			}
			if (!IsNil(GetLeft(GetBrother(currentNode)))
				&& GetLeft(GetBrother(currentNode))->IsBlack()
				&& GetRight(GetBrother(currentNode))->IsBlack())
			{
				GetBrother(currentNode)->SetRed();
			}
			else
			{
				if (!IsNil(GetRight(GetBrother(currentNode)))
					&& GetRight(GetBrother(currentNode))->IsBlack())
				{
					GetLeft(GetBrother(currentNode))->SetBlack();
					GetBrother(currentNode)->SetRed();
					RotateRight(GetBrother(currentNode));
				}
				if (GetParent(currentNode)->IsRed())
				{
					GetBrother(currentNode)->SetRed();
				}
				else
				{
					GetBrother(currentNode)->SetBlack();
				}
				GetParent(currentNode)->SetBlack();
				GetRight(GetBrother(currentNode))->SetBlack();
				RotateLeft(GetParent(currentNode));
				currentNode = GetRoot();
			}
		}
	}
	currentNode->SetBlack();
	GetRoot()->SetBlack();
}

RbTreeNode* RbTree::FindNodeWithNextMinKey(RbTreeNode* sourceNode)
{
	RbTreeNode* currentNode = GetRight(sourceNode);
	while (!IsNil(GetLeft(currentNode)))
	{
		currentNode = GetLeft(currentNode);
	}
	return currentNode;
}

RbTreeNode* RbTree::AssertFindNodeByKey(int keyToFind)
{
	RbTreeNode* currentNode = GetRoot();
	while (!IsNil(currentNode))
	{
		if (keyToFind < currentNode->GetKey())
		{
			currentNode = GetLeft(currentNode);
		}
		else if (keyToFind > currentNode->GetKey())
		{
			currentNode = GetRight(currentNode);
		}
		else
		{
			return currentNode;
		}
	}
	throw exception("Error: there is no node with such key.");
}

RbTreeNode* RbTree::RotateLeft(RbTreeNode* rotateNode)
{
	//Fix root
	if (IsRoot(rotateNode))
	{
		SetRoot(GetRight(rotateNode));
	}
	//Fix parents
	else
	{
		if (IsLeftChild(rotateNode))
		{
			GetParent(rotateNode)->SetLeft(GetRight(rotateNode));
		}
		else
		{
			GetParent(rotateNode)->SetRight(GetRight(rotateNode));
		}
		if (!IsNil(GetLeft(GetRight(rotateNode))))
		{
			GetLeft(GetRight(rotateNode))->
				SetParent(GetParent(rotateNode));
		}
	}

	//Do rotation
	if (!IsNil(GetRight(rotateNode)))
	{
		RbTreeNode* tmp = GetLeft(GetRight(rotateNode));
		GetRight(rotateNode)->SetLeft(rotateNode);
		GetRight(rotateNode)->SetParent(GetParent(rotateNode));
		rotateNode->SetParent(GetRight(rotateNode));
		rotateNode->SetRight(tmp);
		if (!IsNil(tmp))
		{
			tmp->SetParent(rotateNode);
		}
	}
	return rotateNode;
}

RbTreeNode* RbTree::RotateRight(RbTreeNode* rotateNode)
{
	//Fix root
	if (IsRoot(rotateNode))
	{
		SetRoot(GetLeft(rotateNode));
	}
	//Fix parents
	else
	{
		if (IsLeftChild(rotateNode))
		{
			GetParent(rotateNode)->SetLeft(GetLeft(rotateNode));
		}
		else
		{
			GetParent(rotateNode)->SetRight(GetLeft(rotateNode));
		}
		GetRight(GetLeft(rotateNode))->SetParent(GetParent(rotateNode));
	}
	//Do rotation
	if (!IsNil(GetLeft(rotateNode)))
	{
		RbTreeNode* tmp = GetRight(GetLeft(rotateNode));
		GetLeft(rotateNode)->SetRight(rotateNode);
		GetLeft(rotateNode)->SetParent(GetParent(rotateNode));
		rotateNode->SetParent(GetLeft(rotateNode));
		rotateNode->SetLeft(tmp);
		if (!IsNil(tmp))
		{
			tmp->SetParent(rotateNode);
		}
	}
	return rotateNode;
}

RbTreeNode* RbTree::GetRoot()
{
	return _root;
}

void RbTree::SetRoot(RbTreeNode* newRoot)
{
	_root = newRoot;
	if (newRoot
		&& !IsNil(newRoot))
	{
		_root->SetBlack();
		_root->Parent = GetNil();
	}
}

RbTreeNode* RbTree::GetNil()
{
	return _nil;
}

void RbTree::SetNil(RbTreeNode* newNil)
{
	_nil = newNil;
	_nil->SetBlack();
}

RbTreeNode* RbTree::GetLeft(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(sourceNode->LeftSubtree))
	{
		return sourceNode->LeftSubtree;
	}
	else
	{
		return GetNil();
	}
}

RbTreeNode* RbTree::GetRight(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(sourceNode->RightSubtree))
	{
		return sourceNode->RightSubtree;
	}
	else
	{
		return GetNil();
	}
}

RbTreeNode* RbTree::GetBrother(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(GetParent(sourceNode)))
	{
		if (IsLeftChild(sourceNode))
		{
			return GetRight(GetParent(sourceNode));
		}
		else if (IsRightChild(sourceNode))
		{
			return GetLeft(GetParent(sourceNode));
		}
	}
	else
	{
		return GetNil();
	}
}

RbTreeNode* RbTree::GetParent(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(sourceNode->Parent))
	{
		return sourceNode->Parent;
	}
	else
	{
		return GetNil();
	}
}

RbTreeNode* RbTree::GetGrandparent(RbTreeNode* sourceNode)
{
	return GetParent(GetParent(sourceNode));
}

RbTreeNode* RbTree::GetUncle(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(GetGrandparent(sourceNode)))
	{
		if (IsLeftChild(GetParent(sourceNode)))
		{
			return IsNil(GetRight(GetGrandparent(sourceNode))) ?
				GetNil()
				: GetRight(GetGrandparent(sourceNode));
		}
		else if (IsRightChild(GetParent(sourceNode)))
		{

			return IsNil(GetLeft(GetGrandparent(sourceNode))) ?
				GetNil()
				: GetLeft(GetGrandparent(sourceNode));
		}
	}
	else
	{
		return GetNil();
	}
}

bool RbTree::IsNil(RbTreeNode* sourceNode)
{
	return sourceNode == GetNil();
}

bool RbTree::IsLeftChild(RbTreeNode* sourceNode)
{
	return !IsNil(sourceNode)
		&& !IsNil(GetParent(sourceNode))
		&& GetLeft(GetParent(sourceNode)) == sourceNode;
}

bool RbTree::IsRightChild(RbTreeNode* sourceNode)
{
	return !IsNil(sourceNode)
		&& !IsNil(GetParent(sourceNode))
		&& GetRight(GetParent(sourceNode)) == sourceNode;
}

bool RbTree::IsRoot(RbTreeNode* sourceNode)
{
	return sourceNode == GetRoot();
}
