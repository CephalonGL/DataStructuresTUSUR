#include "RbTreeNode.h"

RbTreeNode::RbTreeNode(int key, string value, RbTreeNode* nil)
{
	Key = key;
	Value = value;
	LeftSubtree = nil;
	RightSubtree = nil;
	Parent = nil;
	HeightBlack = 0;
	SetRed();
}

void RbTreeNode::SetParent(RbTreeNode* newParent)
{
	Parent = newParent;
}

void RbTreeNode::SetLeft(RbTreeNode* newLeftChild)
{
	LeftSubtree = newLeftChild;
}

void RbTreeNode::SetRight(RbTreeNode* newRightChild)
{
	RightSubtree = newRightChild;
}

int RbTreeNode::GetKey()
{
	return Key;
}

void RbTreeNode::SetKey(int keyToSet)
{
	if (this)
	{
		Key = keyToSet;
	}
}

string RbTreeNode::GetValue()
{
	return Value;
}

void RbTreeNode::SetValue(string valueToSet)
{
	if (this)
	{
		Value = valueToSet;
	}
}

unsigned int RbTreeNode::GetHeightBlack()
{
	return HeightBlack;
}

int RbTreeNode::FixHeightBlack(RbTreeNode* nodeToFixHeight)
{
	return 0;
}

void RbTreeNode::SetRed()
{
	_isRed = true;
}

void RbTreeNode::SetBlack()
{
	_isRed = false;
}

bool RbTreeNode::IsRed()
{
	return _isRed;
}

bool RbTreeNode::IsBlack()
{
	return !IsRed();
}
