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
	/// <param name="rootKey">Key of root node</param>
	/// <param name="rootValue">Value of root node</param>
	RbTree(int rootKey, string rootValue);
	
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
	/// Delete node by inserted key
	/// </summary>
	/// <param name="keyToDelete">Key of node to delete</param>
	void DeleteByKey(int keyToDelete);

	/// <summary>
	/// Get value by inserted key
	/// </summary>
	/// <param name="keyToSearch">Key to search</param>
	/// <returns>Value</returns>
	string SearchByKey(int keyToSearch);
	
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
	RbTreeNode* _SmallLeftRotation(RbTreeNode* node);

	/// <summary>
	/// Do small right rotation
	/// </summary>
	/// <returns>New root node</returns>
	RbTreeNode* _SmallRightRotation(RbTreeNode* node);



	/// <summary>
	/// Getter for root node
	/// </summary>
	/// <returns>Root node of tree</returns>
	RbTreeNode* GetRoot();
private:
	/// <summary>
	/// Pointer to root node
	/// </summary>
	RbTreeNode* _root = nullptr;

	/// <summary>
	/// Fictional node for leafs
	/// </summary>
	RbTreeNode* _nil;

};

