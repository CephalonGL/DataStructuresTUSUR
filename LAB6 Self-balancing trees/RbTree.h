﻿#pragma once
#include "RbTreeNode.h"

using namespace std;

/// <summary>
/// Red black tree the data structure
/// </summary>
class RbTree
{
public:
	/// <summary>
	/// Initialize a tree
	/// </summary>
	RbTree();
	
	void Insert(int keyToInsert,
				string valueToInsert);

	/// <summary>
	/// Delete node by inserted key
	/// </summary>
	/// <param name="keyToDelete">Key of node to delete</param>
	void DeleteByKey(int keyToDelete);

	/// <summary>
	/// Get value by inserted key
	/// </summary>
	/// <param name="keyToSearch">Key to search</param>
	/// <returns>Value</returns>
	string GetValueByKey(int keyToSearch);


private:
	/// <summary>
	/// Inserts new node using recursive algorithm
	/// </summary>
	/// <param name="currentNode"></param>
	/// <param name="keyToInsert">Key of new node</param>
	/// <param name="valueToInsert">Value of new node</param>
	/// <returns>New root</returns>
	RbTreeNode* Insert(RbTreeNode* currentNode,
					   int keyToInsert,
					   string valueToInsert);

	/// <summary>
	/// Fix balancing of tree after insertion new node
	/// </summary>
	/// <param name="insertedNode">Node to fix balance</param>
	void GoBalanceAfterInsertion(RbTreeNode* insertedNode);

	/// <summary>
	/// Fix balancing of tree after deletion new node
	/// </summary>
	/// <param name="nodeToBalance">Node to fix balance</param>
	void GoBalanceAfterDeletion(RbTreeNode* nodeToBalance);

	/// <summary>
	/// Do small left rotation
	/// </summary>
	/// <returns>New root node</returns>
	RbTreeNode* RotateLeft(RbTreeNode* node);

	/// <summary>
	/// Do small right rotation
	/// </summary>
	/// <returns>New root node</returns>
	RbTreeNode* RotateRight(RbTreeNode* node);

	/// <summary>
	/// Getter for root node
	/// </summary>
	/// <returns>Root node of tree</returns>
	RbTreeNode* GetRoot();

	/// <summary>
	/// Set new root
	/// </summary>
	void SetRoot(RbTreeNode* newRoot);

	/// <summary>
	/// Getter for nil node
	/// </summary>
	/// <returns>Nil of this tree</returns>
	RbTreeNode* GetNil();

	void SetNil(RbTreeNode* newNil);

	RbTreeNode* GetLeftChild(RbTreeNode* sourceNode);

	RbTreeNode* GetRightChild(RbTreeNode* sourceNode);

	RbTreeNode* GetBrother(RbTreeNode* sourceNode);

	RbTreeNode* GetParent(RbTreeNode* sourceNode);

	RbTreeNode* GetGrandparent(RbTreeNode* sourceNode);

	RbTreeNode* GetUncle(RbTreeNode* sourceNode);

	bool IsNil(RbTreeNode* sourceNode);

	bool IsLeftChild(RbTreeNode* sourceNode);

	bool IsRightChild(RbTreeNode* sourceNode);

	/// <summary>
	/// Pointer to root node
	/// </summary>
	RbTreeNode* _root = nullptr;

	/// <summary>
	/// Fictional node for leafs
	/// </summary>
	RbTreeNode* _nil;

};

