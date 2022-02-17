#include "AvlTreeNode.h"
#include <string>
using namespace std;

AvlTreeNode::AvlTreeNode(int key = 0, string value = "empty")
{
	_key = key;
	_value = value;
}

short int AvlTreeNode::GetHeight(AvlTreeNode* node)
{
	if (node)
	{
		return node->_height;
	}
	else
	{
		return 0;
	}
}

short int AvlTreeNode::BalanceFactor(AvlTreeNode* node)
{
	return GetHeight(node->_rightSubtree) - GetHeight(node->_leftSubtree);
}

void AvlTreeNode::FixHeight()
{
	short int leftSubtreeHeight = GetHeight(_leftSubtree);
	short int rightSubtreeHeight = GetHeight(_rightSubtree);
	if (leftSubtreeHeight > rightSubtreeHeight)
	{
		_height = leftSubtreeHeight + 1;
	}
	else
	{
		_height = rightSubtreeHeight + 1;
	}
}
