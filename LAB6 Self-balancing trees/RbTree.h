#pragma once
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
	
	/// <summary>
	/// Insert new node
	/// </summary>
	/// <param name="keyToInsert">Key of new node</param>
	/// <param name="valueToInsert">Value of new node</param>
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

	/// <summary>
	/// Getter for root node
	/// </summary>
	/// <returns>Root node of tree</returns>
	RbTreeNode* GetRoot();

	/// <summary>
	/// Getter for nil node
	/// </summary>
	/// <returns>Nil of this tree</returns>
	RbTreeNode* GetNil();

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
	/// Find node with next minimal key from current
	/// </summary>
	/// <param name="sourceNode">Source node to find node with 
	/// next minimal key</param>
	/// <returns></returns>
	RbTreeNode* FindNodeWithNextMinKey(RbTreeNode* sourceNode);

	/// <summary>
	/// Search for node with inserted key. 
	/// If there is no node with such key, throw excepion.
	/// </summary>
	/// <param name="keyToFind"></param>
	/// <returns>If there is node with inserted key, 
	/// return this node.</returns>
	RbTreeNode* AssertFindNodeByKey(int keyToFind);

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
	/// Set new root
	/// </summary>
	void SetRoot(RbTreeNode* newRoot);

	/// <summary>
	/// Set new nil
	/// </summary>
	/// <param name="newNil">Pointer to new nil</param>
	void SetNil(RbTreeNode* newNil);

	/// <summary>
	/// Getter for left subtree
	/// </summary>
	/// <param name="sourceNode">Node to get left node</param>
	/// <returns>Left subtree</returns>
	RbTreeNode* GetLeft(RbTreeNode* sourceNode);

	/// <summary>
	/// Getter for right subtree
	/// </summary>
	/// <param name="sourceNode">Node to get right node</param>
	/// <returns>Right subtree</returns>
	RbTreeNode* GetRight(RbTreeNode* sourceNode);

	/// <summary>
	/// Getter for brother of node
	/// </summary>
	/// <param name="sourceNode">Node to get brother</param>
	/// <returns>Brother of node if has</returns>
	RbTreeNode* GetBrother(RbTreeNode* sourceNode);

	/// <summary>
	/// Getter for parent of node
	/// </summary>
	/// <param name="sourceNode">Node to get parent</param>
	/// <returns>Parent of node if has</returns>
	RbTreeNode* GetParent(RbTreeNode* sourceNode);

	/// <summary>
	/// Getter for parent of node
	/// </summary>
	/// <param name="sourceNode">Node to get parent</param>
	/// <returns>Parent of node</returns>
	RbTreeNode* GetGrandparent(RbTreeNode* sourceNode);

	/// <summary>
	/// Getter for brother of parent of node
	/// </summary>
	/// <param name="sourceNode">Node to get uncle</param>
	/// <returns>Uncle of node</returns>
	RbTreeNode* GetUncle(RbTreeNode* sourceNode);

	/// <summary>
	/// Check if this node is nil
	/// </summary>
	/// <param name="sourceNode">Node to check</param>
	/// <returns>True if this node is nil, else false</returns>
	bool IsNil(RbTreeNode* sourceNode);

	/// <summary>
	/// Check if this node is a left child
	/// </summary>
	/// <param name="sourceNode">Node to check</param>
	/// <returns>True if this node is left a child, else false</returns>
	bool IsLeftChild(RbTreeNode* sourceNode);

	/// <summary>
	/// Check if this node is a right child
	/// </summary>
	/// <param name="sourceNode">Node to check</param>
	/// <returns>True if this node is a right child, else false</returns>
	bool IsRightChild(RbTreeNode* sourceNode);

	/// <summary>
	/// Check if this node
	/// </summary>
	/// <param name="sourceNode">Node to check</param>
	/// <returns>True if this node is root, else false</returns>
	bool IsRoot(RbTreeNode* sourceNode);

	/// <summary>
	/// Pointer to root node
	/// </summary>
	RbTreeNode* _root = nullptr;

	/// <summary>
	/// Fictional node for leafs
	/// </summary>
	RbTreeNode* _nil;

};

