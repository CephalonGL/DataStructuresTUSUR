#include "AvlTreeNode.h"
#include <string>
using namespace std;

AvlTreeNode::AvlTreeNode(int key = 0, string value = "empty")
{
	_key = key;
	_value = value;
}

short int AvlTreeNode::GetHeight()
{
	if (this)
	{
		return _height;
	}
	else
	{
		return 0;
	}
}

short int AvlTreeNode::BalanceFactor()
{
	return _rightSubtree->GetHeight() - _leftSubtree->GetHeight();
}

void AvlTreeNode::FixHeight()
{
	short int leftSubtreeHeight = _leftSubtree->GetHeight();
	short int rightSubtreeHeight = _rightSubtree->GetHeight();
	if (leftSubtreeHeight > rightSubtreeHeight)
	{
		_height = leftSubtreeHeight + 1;
	}
	else
	{
		_height = rightSubtreeHeight + 1;
	}
}
