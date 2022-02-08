#include "CartesianTree.h"
#include "CartesianTreeNode.h"
#include <string>
using namespace std;

CartesianTree* CartesianTree::CreateTree(CartesianTree*& cartesianTree)
{
	return cartesianTree = new CartesianTree;
}

void CartesianTree::Split(CartesianTreeNode * currentNode, int key,
	CartesianTreeNode*& leftNode, CartesianTreeNode*& rightNode)
{
	if (currentNode == nullptr)
	{
		leftNode = nullptr;
		rightNode = nullptr;
	}
	else if (currentNode->Key <= key)
	{
		Split(currentNode->RightNode, key, currentNode->RightNode, rightNode);
		leftNode = currentNode;
	}
	else if (currentNode->Key > key)
	{
		Split(currentNode->LeftNode, key, leftNode, currentNode->LeftNode);
		rightNode = currentNode;
	}
	else
	{
		string error = "Split: неизвестная ошибка.";
		throw error;
	}
}

CartesianTreeNode* CartesianTree::Merge(CartesianTreeNode* leftNode,
	CartesianTreeNode* rightNode)
{
	if (leftNode == nullptr || rightNode == nullptr)
	{
		return leftNode == nullptr ? rightNode : leftNode;
	}
	if (leftNode->Priority > rightNode->Priority)
	{
		leftNode->RightNode = Merge(leftNode->RightNode, rightNode);
		return leftNode;
	}
	rightNode->LeftNode = Merge(leftNode, rightNode->LeftNode);
	return rightNode;
}

CartesianTreeNode* CartesianTree::FindElement(CartesianTreeNode* currentNode, int key)
{
	if (currentNode == nullptr)
	{
		string error = "FindElement: дерево не инициализировано,"
			" currentNode == nullptr.";
		throw error;
	}
	if (currentNode->Key == key)
	{
		return currentNode;
	}
	if (currentNode->Key > key)
	{
		return FindElement(currentNode->LeftNode, key);
	}
	if (currentNode->Key < key)
	{
		return FindElement(currentNode->RightNode, key);
	}
}

CartesianTree* CartesianTree::UnoptimizedInsert(CartesianTreeNode* currentNode, int key)
{
	CartesianTree* newNode = CreateTree(newNode);
	newNode->RootNode = new CartesianTreeNode;
	newNode->RootNode->Key = key;
	newNode->RootNode->Priority = rand() % 100 + 1;
	CartesianTree* leftNode = CreateTree(leftNode);
	CartesianTree* rightNode = CreateTree(rightNode);
	Split(currentNode, key, leftNode->RootNode, rightNode->RootNode);
	newNode->RootNode = Merge(leftNode->RootNode, newNode->RootNode);
	newNode->RootNode = Merge(newNode->RootNode, rightNode->RootNode);
	return newNode;
}

CartesianTreeNode* CartesianTree::OptimizedInsert(CartesianTreeNode* currentNode, int key, int priority)
{
	if (currentNode != nullptr && currentNode->Priority >= priority)
	{
		if (key <= currentNode->Key)
		{
			currentNode->LeftNode = OptimizedInsert(currentNode->LeftNode, key, priority);
		}
		if (key > currentNode->Key)
		{
			currentNode->RightNode = OptimizedInsert(currentNode->RightNode, key, priority);
		}
		return currentNode;
	}
	CartesianTree* left = CreateTree(left);
	CartesianTree* right = CreateTree(right);
	Split(currentNode, key, left->RootNode, right->RootNode);
	CartesianTree* newNode = CreateTree(newNode);
	newNode->RootNode = new CartesianTreeNode;
	newNode->RootNode->Key = key;
	newNode->RootNode->Priority = priority;
	newNode->RootNode->LeftNode = left->RootNode;
	newNode->RootNode->RightNode = right->RootNode;
	return newNode->RootNode;
}

void CartesianTree::UnoptimizedDelete(CartesianTreeNode*& currentNode, int key)
{
	if (currentNode == nullptr)
	{
		string error = "UnoptimizedDelete: дерево не инициализировано,"
			" currentNode == nullptr.";
		throw error;
	}
	CartesianTreeNode* leftNode = nullptr;
	CartesianTreeNode* rightNode = nullptr;
	Split(currentNode, key, leftNode, rightNode);
	CartesianTreeNode* newLeftNode = nullptr;
	CartesianTreeNode* nodeToDelete = nullptr;
	Split(leftNode, key - 1, newLeftNode, nodeToDelete);
	currentNode = Merge(newLeftNode, rightNode);
	delete nodeToDelete;
	nodeToDelete = nullptr;
}

CartesianTreeNode* CartesianTree::OptimizedDelete(CartesianTreeNode* currentNode, int key)
{
	if (currentNode == nullptr)
	{
		string error = "OptimizedDelete: дерево не инициализировано,"
			" currentNode == nullptr.";
		throw error;
	}
	else
	{
		if (key < currentNode->Key)
		{
			currentNode->LeftNode = OptimizedDelete(currentNode->LeftNode, key);
		}
		if (key > currentNode->Key)
		{
			currentNode->RightNode = OptimizedDelete(currentNode->RightNode, key);
		}
		if (key == currentNode->Key)
		{
			currentNode = Merge(currentNode->LeftNode, currentNode->RightNode);
		}
		return currentNode;
	}
}

void CartesianTree::ClearDelete(CartesianTreeNode*& currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}
	ClearDelete(currentNode->LeftNode);
	ClearDelete(currentNode->RightNode);
	delete currentNode;
	currentNode = nullptr;
}
