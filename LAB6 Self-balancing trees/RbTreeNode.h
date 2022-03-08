#pragma once
#include <string>

using namespace std;

/// <summary>
/// Node for red black tree the data structure
/// </summary>
class RbTreeNode
{
public:
	/// <summary>
	/// Key of node
	/// </summary>
	int Key;

	/// <summary>
	/// Value of node
	/// </summary>
	string Value;

	/// <summary>
	/// Pointer to left subtree
	/// </summary>
	RbTreeNode* LeftSubtree = nullptr;

	/// <summary>
	/// Pointer to right subtree
	/// </summary>
	RbTreeNode* RightSubtree = nullptr;

	/// <summary>
	/// Pointer to parent node
	/// </summary>
	RbTreeNode* Parent = nullptr;
	
	/// <summary>
	/// Height of node. Counter of black nodes up to NIL
	/// </summary>
	unsigned int HeightBlack;

	/// <summary>
	/// Initialize key and value of node
	/// </summary>
	/// <param name="key">Key of node</param>
	/// <param name="value">Value of node</param>
	RbTreeNode(int key, string value, RbTreeNode* nil);

	void SetParent(RbTreeNode* newParent);

	void SetLeft(RbTreeNode* newLeftChild);

	void SetRight(RbTreeNode* newRightChild);

	/// <summary>
	/// Fix counter of black nodes up to nil
	/// </summary>
	/// <param name="nodeToFixHeight">Node to fix black height</param>
	/// <returns>correct count of black nodes up to nil</returns>
	int FixHeightBlack(RbTreeNode* nodeToFixHeight);

	/// <summary>
	/// Set color of node to red
	/// </summary>
	void SetRed();

	/// <summary>
	/// Set color of node to black
	/// </summary>
	void SetBlack();

	/// <summary>
	/// Return _isRed flag
	/// </summary>
	/// <returns>If node is red, return 1, else 0</returns>
	bool IsRed();

private:
	/// <summary>
	/// Flag for color of node
	/// </summary>
	bool _isRed;

};

