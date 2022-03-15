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

	/// <summary>
	/// Set parent for node
	/// </summary>
	/// <param name="newParent">New parent</param>
	void SetParent(RbTreeNode* newParent);

	/// <summary>
	/// Set left child for node
	/// </summary>
	/// <param name="newLeftChild">New left child</param>
	void SetLeft(RbTreeNode* newLeftChild);

	/// <summary>
	/// Set right child for node
	/// </summary>
	/// <param name="newRightChild">New child</param>
	void SetRight(RbTreeNode* newRightChild);

	/// <summary>
	/// Get key of node
	/// </summary>
	/// <returns>Key of this node</returns>
	int GetKey();

	/// <summary>
	/// Set key to this node
	/// </summary>
	/// <param name="keyToSet">Key to set</param>
	void SetKey(int keyToSet);

	/// <summary>
	/// Get gey of this node
	/// </summary>
	/// <returns>Value of this node</returns>
	string GetValue();

	/// <summary>
	/// Set value to this node
	/// </summary>
	/// <param name="valueToSet">Value to set</param>
	void SetValue(string valueToSet);

	/// <summary>
	/// Get black height for his node
	/// </summary>
	/// <returns>Black height of this node</returns>
	unsigned int GetHeightBlack();

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
	/// Return color flag
	/// </summary>
	/// <returns>If node is red, returns true, else false</returns>
	bool IsRed();

	/// <summary>
	/// Return color flag
	/// </summary>
	/// <returns>If node is black, returns true, else false</returns>
	bool IsBlack();

private:
	/// <summary>
	/// Flag for color of node
	/// </summary>
	bool _isRed;

};

