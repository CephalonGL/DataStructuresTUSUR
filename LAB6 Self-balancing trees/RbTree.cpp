#include "RbTree.h"

RbTree::RbTree()
{
	SetNil(new RbTreeNode(0, "nil", nullptr));
}

void RbTree::Insert(int keyToInsert,
					string valueToInsert)
{
	SetRoot(Insert(GetRoot(), keyToInsert, valueToInsert));
	GetRoot()->SetBlack();
}


RbTreeNode* RbTree::Insert(RbTreeNode* currentNode,
						   int keyToInsert,
						   string valueToInsert)
{
	RbTreeNode* newNode = new RbTreeNode(keyToInsert, valueToInsert,
										 GetNil());
	if (!GetRoot())
	{
		SetRoot(newNode);
		GetRoot()->SetParent(GetNil());
	}
	else
	{
		RbTreeNode* currentNode = GetRoot();
		while (!IsNil(currentNode))
		{
			if (currentNode->GetKey() < keyToInsert)
			{
				currentNode->SetParent(currentNode);
				currentNode = GetLeft(currentNode);
			}
			else
			{
				currentNode->SetParent(currentNode);
				currentNode = GetRight(currentNode);
			}
		}
		newNode->SetParent(currentNode);
		if (GetParent(currentNode)->GetKey() < keyToInsert)
		{
			GetParent(currentNode)->SetLeft(newNode);
		}
		else
		{
			GetParent(currentNode)->SetRight(newNode);
		}
		GoBalanceAfterInsertion(newNode);
	}
	return currentNode;
}

void RbTree::DeleteByKey(int keyToDelete)
{
	if (GetRoot()
		|| IsNil(GetRoot()))
	{
		throw exception("Error: root node is empty");
	}
	RbTreeNode* currentNode = GetRoot();
	while (!IsNil(currentNode)
		   && keyToDelete != currentNode->GetKey())
	{
		if (keyToDelete < currentNode->GetKey())
		{
			currentNode = GetLeft(currentNode);
		}
		else
		{
			currentNode = GetRight(currentNode);
		}
	}
	if (IsNil(GetLeft(currentNode))
		&& IsNil(GetRight(currentNode)))
	{
		if (currentNode == GetRoot())
		{
			SetRoot(GetNil());
		}
		else
		{
			if (currentNode == GetLeft(GetParent(currentNode)))
			{
				GetParent(currentNode)->SetLeft(GetNil());
				delete currentNode;
			}
			else
			{
				GetParent(currentNode)->SetLeft(GetNil());
				delete currentNode;
			}
			return;
		}
	}
	RbTreeNode* nodeWithNextKey = GetRight(currentNode);
	if (!IsNil(GetLeft(currentNode))
		&& IsNil(GetRight(currentNode)))
	{
		RbTreeNode* parent = currentNode->Parent;
		if (IsLeftChild(currentNode))
		{
			//TODO: Something is wrong
			GetParent(currentNode)->SetLeft(GetLeft(currentNode));
			//parent->LeftSubtree = currentNode->LeftSubtree;
			delete GetLeft(currentNode);
		}
		else
		{
			GetParent(currentNode)->SetRight(GetLeft(currentNode));
			//parent->RightSubtree = currentNode->LeftSubtree;
			delete GetLeft(currentNode);
		}
	}
	else if (!IsNil(GetRight(currentNode))
			 && IsNil(GetLeft(currentNode)))
	{
		if (currentNode == GetLeft(GetParent(currentNode)))
		{
			//TODO: something is wrong
			GetParent(currentNode)->SetLeft(GetRight(currentNode));
			delete GetRight(currentNode);
		}
		else
		{
			GetParent(currentNode)->SetRight(GetRight(currentNode));
			delete GetRight(currentNode);
		}
	}
	else
	{
		while (!IsNil(GetLeft(nodeWithNextKey)))
		{
			nodeWithNextKey = GetLeft(nodeWithNextKey);
		}
		if (!IsNil(GetRight(nodeWithNextKey)))
		{
			GetRight(nodeWithNextKey)->
				SetParent(GetParent(nodeWithNextKey));
		}
		if (IsRoot(nodeWithNextKey))
		{
			SetRoot(GetRight(nodeWithNextKey));
		}
		else
		{
			if (currentNode == GetLeft(GetParent(currentNode)))
			{
				GetParent(currentNode)->SetLeft(nodeWithNextKey);
			}
			else
			{
				GetParent(currentNode)->SetRight(nodeWithNextKey);
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
	if (nodeWithNextKey->IsBlack())
	{
		GoBalanceAfterDeletion(currentNode);
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
	RbTreeNode* parent = nodeToBalance->Parent;
	while (GetParent(nodeToBalance)->IsRed())
	{
		RbTreeNode* grandfather = parent->Parent;
		if (GetGrandparent(nodeToBalance)
			&& IsLeftChild(GetParent(nodeToBalance)))
		{
			RbTreeNode* uncle = grandfather->RightSubtree;
			if (!IsNil(GetUncle(nodeToBalance))
				&& GetUncle(nodeToBalance)->IsRed())
			{
				GetParent(nodeToBalance)->SetBlack();
				GetUncle(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				nodeToBalance = GetGrandparent(nodeToBalance);

				//TODO: to method +
				//parent->SetBlack();
				//uncle->SetBlack();
				//grandfather->SetRed();
				//nodeToBalance = grandfather;
				//parent = nodeToBalance->Parent;
				//grandfather = parent->Parent;
			}
			else
			{
				if (parent->RightSubtree == nodeToBalance)
				{
					nodeToBalance = RotateLeft(GetParent(nodeToBalance));
					//TODO: to method +
					//parent = nodeToBalance->Parent;
				}
				GetParent(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				RotateRight(GetGrandparent(nodeToBalance));

				//Source
				//parent->SetBlack();
				//grandfather->SetRed();
				//nodeToBalance->Parent->Parent =
				//	RotateRight(grandfather);
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

				//parent->SetBlack();
				//uncle->SetBlack();
				//grandfather->SetRed();
				//nodeToBalance = grandfather;
				//TODO: to method +
				//parent = nodeToBalance->Parent;
				//grandfather = parent->Parent;
			}
			else
			{
				if (IsLeftChild(nodeToBalance))
				{
					nodeToBalance = RotateRight(GetParent(nodeToBalance));


					//TODO: to method +
					//nodeToBalance = parent;
					//nodeToBalance = RotateRight(nodeToBalance);
					//parent = nodeToBalance->Parent;
					//grandfather = parent->Parent;
				}
				GetParent(nodeToBalance)->SetBlack();
				GetGrandparent(nodeToBalance)->SetRed();
				RotateLeft(GetGrandparent(nodeToBalance));

				//parent->SetBlack();
				//grandfather->SetRed();
				//nodeToBalance->Parent->Parent =
				//	RotateLeft(grandfather);
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
		RbTreeNode* parent = currentNode;
		if (IsLeftChild(currentNode))
		{
			RbTreeNode* brother = parent->RightSubtree;
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

					//brother->LeftSubtree->SetBlack();
					//brother->SetRed();
					//currentNode->Parent->RightSubtree =
					//	RotateRight(brother);
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
				//currentNode->Parent =
				//	RotateLeft(parent);
				currentNode = GetRoot();
			}
		}
	}
	currentNode->SetBlack();
	GetRoot()->SetBlack();
}

RbTreeNode* RbTree::RotateLeft(RbTreeNode* rotateNode)
{
	//TODO: Fix reassignmensts of pointers for parents as it is in AVL 
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
	RbTreeNode* tmp = GetRight(GetLeft(rotateNode));
	GetLeft(rotateNode)->SetRight(rotateNode);
	GetLeft(rotateNode)->SetParent(GetParent(rotateNode));
	rotateNode->SetParent(GetLeft(rotateNode));
	rotateNode->SetLeft(tmp);
	if (!IsNil(tmp))
	{
		tmp->SetParent(rotateNode);
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
	_root->Parent = GetNil();
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
	if (!IsNil(sourceNode)
		&& !IsNil(GetParent(sourceNode))
		&& GetLeft(GetParent(sourceNode)) == sourceNode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RbTree::IsRightChild(RbTreeNode* sourceNode)
{
	if (!IsNil(sourceNode)
		&& !IsNil(GetParent(sourceNode))
		&& GetRight(GetParent(sourceNode)) == sourceNode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RbTree::IsRoot(RbTreeNode* sourceNode)
{
	return sourceNode == GetRoot();
}
