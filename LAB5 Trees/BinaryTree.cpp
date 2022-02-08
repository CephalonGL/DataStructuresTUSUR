#include <string>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;

void BinaryTree::CreateTree(int key, int value)
{
	if (RootNode != nullptr)
	{
		string error = "Дерево уже создано.";
		throw error;
	}
	RootNode = new BinaryTreeNode;
	RootNode->Key = key;
	RootNode->Value = value;
}

BinaryTreeNode* BinaryTree::AddElement(BinaryTreeNode* currentNode
	,int key
	, int value,
	BinaryTreeNode* parent)
{
	if (currentNode == nullptr)
	{
		currentNode = new BinaryTreeNode;
		currentNode->Key = key;
		currentNode->Value = value;
		currentNode->LeftNode = nullptr;
		currentNode->RightNode = nullptr;
		currentNode->ParentNode = parent;
	}
	else if (currentNode->Key >= key)
	{
		currentNode->LeftNode = AddElement(currentNode->LeftNode, key, value,
			currentNode);
	}
	else
	{
		currentNode->RightNode = AddElement(currentNode->RightNode, key, value,
			currentNode);
	}
	return currentNode;
}

BinaryTreeNode* BinaryTree::DeleteElement(BinaryTreeNode* currentNode, int key)
{
	if (currentNode == nullptr)
	{
		string error = "[BinaryTree::DeleteElement] Дерево не создано"
			" или не существует.";
		throw error;
	}
	if (currentNode->Key > key)
	{
		currentNode->LeftNode = DeleteElement(currentNode->LeftNode, key);
	}
	else if (currentNode->Key < key)
	{
		currentNode->RightNode = DeleteElement(currentNode->RightNode, key);
	}
	else
	{
		if (currentNode->LeftNode == nullptr && currentNode->RightNode == nullptr)
		{
			delete currentNode;
			currentNode = nullptr;//Зачем присваивать nullptr?
		}
		else if (currentNode->LeftNode == nullptr && currentNode->RightNode != nullptr)
		{
			//Можно ли решить утечку памяти без объявления tmp?
			BinaryTreeNode* tmp = currentNode;
			currentNode = currentNode->RightNode;
			delete tmp;
			tmp = nullptr;
			return currentNode;
		}
		else if (currentNode->LeftNode != nullptr && currentNode->RightNode == nullptr)
		{
			BinaryTreeNode* tmp = currentNode;
			currentNode = currentNode->LeftNode;
			delete tmp;
			tmp = nullptr;
			return currentNode;
		}
		else if (currentNode->LeftNode != nullptr && currentNode->RightNode != nullptr)
		{
			BinaryTreeNode* minNode = FindMin(currentNode->RightNode);
			currentNode->Key = minNode->Key;
			currentNode->Value = minNode->Value;
			currentNode->RightNode = DeleteElement(currentNode->RightNode, minNode->Key);
		}
		else
		{
			string error = "[BinaryTree::DeleteElement] Неизвестная ошибка";
			throw error;
		}
	}
	return currentNode;
}

BinaryTreeNode* BinaryTree::FindElement(BinaryTreeNode* currentNode, int key)
{
	if (currentNode == nullptr)
	{
		string error = "[BinaryTree::FindElement] Дерево не создано"
			" или не существует.";
		throw error;
	}
	if (currentNode->Key > key)
	{
		return FindElement(currentNode->LeftNode, key);
	}
	if (currentNode->Key < key)
	{
		return FindElement(currentNode->RightNode, key);
	}
	if (currentNode->Key == key)
	{
		return currentNode;
	}
}

BinaryTreeNode* BinaryTree::FindMax(BinaryTreeNode* currentNode)
{
	if (currentNode == nullptr)
	{
		string error = "[BinaryTree::FindMax] Дерево не создано"
			" или не существует.";
		throw error;
	}
	while (currentNode->RightNode != nullptr)
	{
		currentNode = currentNode->RightNode;
	}
	return currentNode;
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* currentNode)
{
	if (currentNode == nullptr)
	{
		string error = "[BinaryTree::FindMin] Дерево не создано"
			" или не существует.";
		throw error;
	}
	while (currentNode->LeftNode != nullptr)
	{
		currentNode = currentNode->LeftNode;
	}
	return currentNode;
}