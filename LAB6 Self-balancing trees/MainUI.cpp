﻿#include <iostream>
#include <string>
#include "AVLTree.h"
#include "RBTree.h"
#include "..\Console\Console.h"
#include "..\Console\Console.cpp"
using namespace std;

string SPLITTER_STRING =
"------------------------"
"------------------------"
"------------------------";

/// <summary>
/// Console user interface for red-black tree 
/// </summary>
void RedBlackTreeUI();

/// <summary>
/// Console user interface for Avl-tree
/// </summary>
void AvlTreeUI();

/// <summary>
/// Print tree to console
/// </summary>
/// <param name="currentNode">Root of tree</param>
/// <param name="nil">Nil node of that tree</param>
/// <param name="tabCount">Counter of tabs to 
/// print before tree</param>
void PrintTree(RbTreeNode* currentNode,
			   RbTreeNode* nil,
			   int tabCount = 0);

/// <summary>
/// Print tree to console
/// </summary>
/// <param name="currentNode">Root of tree</param>
/// <param name="tabCount">Counter of tabs to 
/// print before tree</param>
void PrintTree(AvlTreeNode* currentNode, int tabCount = 0);

int main()
{
	/// <summary>
	/// Enum for main user interface
	/// </summary>
	/// <returns></returns>
	enum MainUI
	{
		Exit = 0,
		RedBlack = 1,
		Avl = 2,
		Help = 100,
	};
	Console::Print(SPLITTER_STRING);
	Console::Print("Welcome to the program of working with"
		" self-balancing trees.");
	Console::Print(SPLITTER_STRING);
	Console::Print("To choose the data structure"
				   ", enter its number:");
	Console::Print("\t1\tRed-black tree.");
	Console::Print("\t2\tAVL tree;");
	Console::Print("Use 0 to exit the program.");
	int operationCode = 1;
	while (operationCode)
	{
		Console::Print(SPLITTER_STRING);
		operationCode = Console::ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case RedBlack:
			{
				RedBlackTreeUI();
				break;
			}
			case Avl:
			{
				AvlTreeUI();
				break;
			}
			case Help:
			{
				Console::Print("To choose the data structure, enter"
					" its number:");
				Console::Print("\t1\tRed black tree.");
				Console::Print("\t2\tAVL tree;");
				break;
			}
			case Exit:
			{
				return 0;
			}
			default:
			{
				Console::Print("");
				Console::Print(SPLITTER_STRING);
				Console::Print("");
				Console::Print("Incorrect operation code. "
							   "Enter 100 to get help.");
				Console::Print("Repeat enter: ");
				break;
			}
		}
		return 0;
	}
}


void RedBlackTreeUI()
{
	/// <summary>
	/// Enum for red-black tree
	/// </summary>
	enum RedBlackUI
	{
		Add = 1,
		Delete = 2,
		GetValueByKey = 3,
		Exit = 0,
		Help = 100,
	};
	Console::Print(SPLITTER_STRING);
	Console::Print("To choose operation type, enter its code:");
	Console::Print("\t1\tInsert the element");
	Console::Print("\t2\tDelete the element");
	Console::Print("\t3\tSearch element by the key");
	Console::Print("Use 0 to exit the program.");
	RbTree* tree = new RbTree;
	int operationCode = 1;
	while (operationCode)
	{
		Console::Print(SPLITTER_STRING);
		operationCode = Console::ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case Add:
			{
				try
				{
					int key = Console::ReadInt("Insert key:");
					string value = Console::ReadString("Insert value:");
					tree->Insert(key, value);
					PrintTree(tree->GetRoot(), tree->GetNil());
				}
				catch (const exception& error)
				{
					Console::Print(error.what());
				}
				break;
			}
			case Delete:
			{
				try
				{
					Console::Print("Insert key of node to delete: ");
					tree->DeleteByKey(Console::ReadInt());
					Console::Print("The node successfuly deleted.");
					PrintTree(tree->GetRoot(), tree->GetNil());
				}
				catch (const exception& error)
				{
					Console::Print(error.what());
				}
				break;
			}
			case GetValueByKey:
			{
				try
				{
					string foundValue;
					foundValue =
						tree->GetValueByKey(Console::ReadInt());
					Console::Print(foundValue);
				}
				catch (const exception& error)
				{
					Console::Print(error.what());
				}
				break;
			}
			case Help:
			{
				Console::Print(SPLITTER_STRING);
				Console::Print("To choose operation type,"
							   " enter its code:");
				Console::Print("\t1\tInsert the element");
				Console::Print("\t2\tDelete the element");
				Console::Print("\t3\tSearch element by the key");
				Console::Print("Use 0 to exit the program.");
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				Console::Print("");
				Console::Print(SPLITTER_STRING);
				Console::Print("");
				Console::Print("Incorrect operation code. Enter 100 to"
					" get help.");
				Console::Print("Repeat enter: ");
				break;
			}
		}
	}
	return;
}

void AvlTreeUI()
{
	/// <summary>
	/// Enum for AvlUI-tree
	/// </summary>
	enum AvlUI
	{
		Add = 1,
		Delete = 2,
		GetValueByKey = 3,
		Exit = 0,
		Help = 100,
	};
	setlocale(LC_ALL, "ru");
	Console::Print(SPLITTER_STRING);
	Console::Print("To choose operation type, enter its code:");
	Console::Print("\t1\tInsert the element");
	Console::Print("\t2\tDelete the element");
	Console::Print("\t3\tSearch element by the key");
	Console::Print("Use 0 to exit the program.");
	Console::Print(SPLITTER_STRING);
	AvlTree* tree = new AvlTree;
	int operationCode = 1;
	while (operationCode)
	{
		Console::Print(SPLITTER_STRING);
		operationCode = Console::ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case Add:
			{
				while (true)
				{
					try
					{
						int key =
							Console::ReadInt("Enter key: ");
						string value =
							Console::ReadString("Enter value: ");
						tree->Insert(tree->GetRoot(),
									 key, value);
						PrintTree(tree->GetRoot());
						break;
					}
					catch (const exception& error)
					{
						Console::Print(error.what());
						break;
					}
				}
				break;
			}
			case Delete:
			{
				while (true)
				{
					try
					{
						tree->DeleteByKey(
							Console::ReadInt("Enter key:"));
						Console::Print("The node successfully deleted.");
						PrintTree(tree->GetRoot());
						break;
					}
					catch (const exception& error)
					{
						Console::Print(error.what());
					}
				}
				break;
			}
			case GetValueByKey:
			{
				while (true)
				{
					try
					{
						string foundValue;
						foundValue =
							tree->GetValueByKey(Console::ReadInt());
						Console::Print(foundValue);
						break;
					}
					catch (const exception& error)
					{
						Console::Print(error.what());
					}
				}
				break;
			}
			case Help:
			{
				Console::Print(SPLITTER_STRING);
				Console::Print("To choose operation type,"
							   " enter its code:");
				Console::Print("\t1\tInsert the element");
				Console::Print("\t2\tDelete the element");
				Console::Print("\t3\tSearch element by the key");
				Console::Print("Use 0 to exit the program.");
				Console::Print(SPLITTER_STRING);
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				Console::Print("");
				Console::Print(SPLITTER_STRING);
				Console::Print("");
				Console::Print("Incorrect operation code. Enter 100 to"
					" get help.");
				Console::Print("Repeat enter: ");
				break;
			}
		}
	}
	return;
}

void PrintTree(RbTreeNode* currentNode,
			   RbTreeNode* nil,
			   int tabCount)
{
	if (currentNode != nil)
	{
		PrintTree(currentNode->RightSubtree, nil, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << currentNode->Key << "; "
			<< currentNode->Value << ")";
		if (currentNode->LeftSubtree != nil
			&&
			currentNode->RightSubtree != nil)
		{
			cout << "|" << endl;
		}
		if (currentNode->LeftSubtree == nil
			&&
			currentNode->RightSubtree != nil)
		{
			cout << "/" << endl;
		}
		if (currentNode->LeftSubtree != nil
			&&
			currentNode->RightSubtree == nil)
		{
			cout << "\\" << endl;
		}
		if (currentNode->LeftSubtree == nil
			&&
			currentNode->RightSubtree == nil)
		{
			cout << endl;
		}
		PrintTree(currentNode->LeftSubtree, nil, tabCount + 1);
	}
}

void PrintTree(AvlTreeNode* currentNode,
			   int tabCount)
{
	if (currentNode)
	{
		PrintTree(currentNode->RightSubtree, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << currentNode->Key << "; "
			<< currentNode->Value << ")";
		if (currentNode->LeftSubtree != nullptr
			&&
			currentNode->RightSubtree != nullptr)
		{
			cout << "|" << endl;
		}
		if (currentNode->LeftSubtree == nullptr
			&&
			currentNode->RightSubtree != nullptr)
		{
			cout << "/" << endl;
		}
		if (currentNode->LeftSubtree != nullptr
			&&
			currentNode->RightSubtree == nullptr)
		{
			cout << "\\" << endl;
		}
		if (currentNode->LeftSubtree == nullptr
			&&
			currentNode->RightSubtree == nullptr)
		{
			cout << endl;
		}
		PrintTree(currentNode->LeftSubtree, tabCount + 1);
	}
}
