#pragma once
#include <string>

using namespace std;

struct AvlTreeNode
{
	int _key = 0;
	string _value = "";
	AvlTreeNode* _parent = nullptr;
	AvlTreeNode* _leftSubtree = nullptr;
	AvlTreeNode* _rightSubtree = nullptr;
	short int _height = 0;
};