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
	short int _height = 1;

	/// <summary>
	/// Create node with inserted key and value
	/// </summary>
	/// <param name="key">Key of new node</param>
	/// <param name="value">Value of new Node</param>
	AvlTreeNode(int key = 0, string value = "empty");

	/// <summary>
	/// Getter function for _height
	/// </summary>
	/// <returns>
	/// Height of node. If node don't exist, return 0
	/// </returns>
	short int GetHeight();

	/// <summary>
	/// Calculate difference of heights between subtrees
	/// </summary>
	/// <returns>Difference of heights 
	/// between right and left subtrees</returns>
	short int BalanceFactor();

	/// <summary>
	/// Fix height of node
	/// </summary>
	void FixHeight();
};