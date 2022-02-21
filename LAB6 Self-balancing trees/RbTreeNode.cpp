#include "RbTreeNode.h"

RbTreeNode::RbTreeNode(int key, string value, RbTreeNode* nil)
{
	Key = key;
	Value = value;
	LeftSubtree = nil;
	RightSubtree = nil;
	ParentNode = nullptr;
	HeightBlack = 0;
	SetRed();
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
