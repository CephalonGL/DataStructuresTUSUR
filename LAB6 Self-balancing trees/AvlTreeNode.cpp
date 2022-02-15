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

void AvlTreeNode::FixHeight(AvlTreeNode* node)
{
	short int leftSubtreeHeight = GetHeight(node->_leftSubtree);
	short int rightSubtreeHeight = GetHeight(node->_rightSubtree);
	if (leftSubtreeHeight > rightSubtreeHeight)
	{
		node->_height = leftSubtreeHeight + 1;
	}
	else
	{
		node->_height = rightSubtreeHeight + 1;
	}
}
