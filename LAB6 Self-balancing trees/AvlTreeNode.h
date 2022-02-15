#pragma once
#include <string>
using namespace std;

/// <summary>
/// Node for AVL-tree data structure
/// </summary>
struct AvlTreeNode
{
	/// <summary>
	/// Key of node
	/// </summary>
	int _key = 0;

	/// <summary>
	/// Value of node
	/// </summary>
	string _value = "";

	/// <summary>
	/// Pointer to parent node
	/// </summary>
	AvlTreeNode* _parent = nullptr;

	/// <summary>
	/// Pointer to left node
	/// </summary>
	AvlTreeNode* _leftSubtree = nullptr;

	/// <summary>
	/// Pointer to right node
	/// </summary>
	AvlTreeNode* _rightSubtree = nullptr;

	/// <summary>
	/// Height difference between left and right subtrees
	/// </summary>
	unsigned char _height = '1';

	/// <summary>
	/// Create node with inserted key and value
	/// </summary>
	/// <param name="key">Key of new node</param>
	/// <param name="value">Value of new Node</param>
	AvlTreeNode(int key, string value);
};