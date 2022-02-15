#include "AvlTreeNode.h"
#include <string>
using namespace std;

AvlTreeNode::AvlTreeNode(int key, string value)
{
	_key = key;
	_value = value;
}

unsigned char AvlTreeNode::GetHeight(AvlTreeNode* node)
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

unsigned char AvlTreeNode::BalanceFactor(AvlTreeNode* node)
{
	return node->_rightSubtree->_height-node->_leftSubtree->_height;
}
