#pragma once
#include <string>
#include "AvlTreeNode.h"
using namespace std;

/// <summary>
/// AVL-tree the data structure
/// </summary>
class AvlTree
{
public:
	/// <summary>
	/// Inserts new node using recursive algorithm
	/// </summary>
	/// <param name="keyToInsert">Key of new node</param>
	/// <param name="valueToInsert">Value of new node</param>
	AvlTreeNode* Insert(AvlTreeNode* currentNode,
						int keyToInsert,
						string valueToInsert);

	/// <summary>
	/// Get value by inserted key
	/// </summary>
	/// <param name="keyToSearch">Key to search</param>
	/// <returns>Value</returns>
	string SearchByKey(int keyToSearch);

	/// <summary>
	/// Delete node by inserted key
	/// </summary>
	/// <param name="keyToDelete">Key of node to delete</param>
	void DeleteByKey(int keyToDelete);

	/// <summary>
	/// Initialize a tree
	/// </summary>
	/// <param name="rootKey">Key of root node</param>
	/// <param name="rootValue">Value of root node</param>
	AvlTree();

	/// <summary>
	/// Getter for root node
	/// </summary>
	/// <returns>Root node of tree</returns>
	AvlTreeNode* GetRoot();
private:
	/// <summary>
	/// Pointer to root node
	/// </summary>
	AvlTreeNode* _root = nullptr;

	/// <summary>
	/// Find node by the key
	/// </summary>
	/// <param name="keyToFind">Key to find node by</param>
	/// <returns>Pointer to node</returns>
	AvlTreeNode* _FindNodeByKey(int keyToFind);

	/// <summary>
	/// Balances subtrees of node
	/// </summary>
	/// <param name="node">Node to balance which subtrees</param>
	AvlTreeNode* _GoBalance(AvlTreeNode* node);

	/// <summary>
	/// Do small left rotation
	/// </summary>
	/// <returns>New root node</returns>
	AvlTreeNode* _SmallLeftRotation(AvlTreeNode* node);

	/// <summary>
	/// Do small right rotation
	/// </summary>
	/// <returns>New root node</returns>
	AvlTreeNode* _SmallRightRotation(AvlTreeNode* node);
};
