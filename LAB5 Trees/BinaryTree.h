#pragma once
#include <string>
#include "BinaryTreeNode.h"

/// <summary>
/// Service struct for BinaryTree
/// </summary>
struct BinaryTreeNode
{
	int Key = 0;
	int Value = 0;
	BinaryTreeNode* LeftNode = nullptr;
	BinaryTreeNode* RightNode = nullptr;
	BinaryTreeNode* ParentNode = nullptr;
};

/// <summary>
/// Binary tree data struct
/// </summary>
struct BinaryTree
{
	BinaryTreeNode* RootNode = nullptr;
	/// <summary>
	/// Create root node of tree
	/// </summary>
	/// <param name="key">Key of node</param>
	/// <param name="value">Value of node</param>
	void CreateTree(int key, int value);
	/// <summary>
	/// Add new node into tree
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key of new node</param>
	/// <param name="value">Value of new node</param>
	/// <param name="parent">Pointer to parent node</param>
	/// <returns>Recurcive call inside. Always return nullptr</returns>
	BinaryTreeNode* AddElement(BinaryTreeNode* currentNode, int key, int value,
		BinaryTreeNode* parent = nullptr);
	/// <summary>
	/// Delete node by key
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to delete by</param>
	/// <returns>Recurcive call inside. Always return nullptr</returns>
	BinaryTreeNode* DeleteElement(BinaryTreeNode* currentNode, int key);
	/// <summary>
	/// Return node by key
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <param name="key">Key to find by</param>
	/// <returns>Recurcive call inside. Always return nullptr</returns>
	BinaryTreeNode* FindElement(BinaryTreeNode* currentNode, int key);
	/// <summary>
	/// Return node with maximum key
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <returns>Pointer to node with maximum key</returns>
	BinaryTreeNode* FindMax(BinaryTreeNode* currentNode);
	/// <summary>
	/// Return node with minimum value
	/// </summary>
	/// <param name="currentNode">Root node</param>
	/// <returns>Pointer to node with minimum key</returns>
	BinaryTreeNode* FindMin(BinaryTreeNode* currentNode);
};