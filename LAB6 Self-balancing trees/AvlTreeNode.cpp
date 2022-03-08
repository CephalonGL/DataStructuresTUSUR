#include "AvlTreeNode.h"
#include <string>
using namespace std;

AvlTreeNode::AvlTreeNode(int key, string value)
{
	Key = key;
	Value = value;
}

short int AvlTreeNode::GetHeight()
{
	if (this)
	{
		return Height;
	}
	else
	{
		return 0;
	}
}

short int AvlTreeNode::BalanceFactor()
{
	return RightSubtree->GetHeight() - LeftSubtree->GetHeight();
}

void AvlTreeNode::FixHeight()
{
	if (this)
	{
		short int leftSubtreeHeight = LeftSubtree->GetHeight();
		short int rightSubtreeHeight = RightSubtree->GetHeight();
		if (leftSubtreeHeight > rightSubtreeHeight)
		{
			this->Height = leftSubtreeHeight + 1;
		}
		else
		{
			this->Height = rightSubtreeHeight + 1;
		}
	}
}
