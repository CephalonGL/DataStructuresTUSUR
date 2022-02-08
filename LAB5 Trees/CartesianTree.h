#pragma once
#include "CartesianTreeNode.h"

/// <summary>
/// Service struct for CartesianTree
/// </summary>
struct CartesianTreeNode
{
	int Key = 0;
	int Priority = 0;
	CartesianTreeNode* LeftNode = nullptr;
	CartesianTreeNode* RightNode = nullptr;
};

/// <summary>
/// Cartesian tree data struct
/// </summary>
struct CartesianTree
{
	CartesianTreeNode* RootNode = nullptr;
	/// <summary>
	/// Creates root node
	/// </summary>
	/// <param name="cartesianTree">Pointer to root node</param>
	/// <returns>Reference to pointer to node</returns>
	CartesianTree* CreateTree(CartesianTree*& cartesianTree);
	/// <summary>
	/// Split the tree on two subtrees
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to split</param>
	/// <param name="leftNode">Return here left subtree</param>
	/// <param name="rightNode">Return here right subtree</param>
	void Split(CartesianTreeNode* currentNode, int key,
		CartesianTreeNode*& leftNode, CartesianTreeNode*& rightNode);
	/// <summary>
	/// Merge two subtrees
	/// </summary>
	/// <param name="leftNode">Left subtree</param>
	/// <param name="rightNode">Right subtree</param>
	/// <returns>Merged tree</returns>
	CartesianTreeNode* Merge(CartesianTreeNode* leftNode,
		CartesianTreeNode* rightNode);
	/// <summary>
	/// Find node by key
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to search</param>
	/// <returns>Pointer to node with searchable key</returns>
	CartesianTreeNode* FindElement(CartesianTreeNode* currentNode, int key);
	/// <summary>
	/// Insert by one split and two merges
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Insertable key</param>
	/// <returns>Inserted node</returns>
	CartesianTree* UnoptimizedInsert(CartesianTreeNode* currentNode, int key);
	/// <summary>
	/// Insert by one split
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Insertable key</param>
	/// <param name="priority">Random priority</param>
	/// <returns>Root node</returns>
	CartesianTreeNode* OptimizedInsert(CartesianTreeNode* currentNode, int key,
		int priority);
	/// <summary>
	/// Delete by two splits and one merge
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to delete by</param>
	void UnoptimizedDelete(CartesianTreeNode*& currentNode, int key);
	/// <summary>
	/// Delete by one merge
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to delete by</param>
	/// <returns>Recurcive call inside</returns>
	CartesianTreeNode* OptimizedDelete(CartesianTreeNode* currentNode, int key);
	/// <summary>
	/// Delete tree and clear memory
	/// </summary>
	/// <param name="currentNode">Reference to root node</param>
	void ClearDelete(CartesianTreeNode*& currentNode);
};
