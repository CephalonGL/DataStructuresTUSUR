#include <iostream>
#include <string>
#include "AVLTree.h"
#include "RBTree.h"
#include "..\Console\Console.h"
#include "..\Console\Console.cpp"

using namespace std;
using namespace Console;

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
	WriteLine(SPLITTER_STRING);
	WriteLine("Welcome to the program of working with"
			  " self-balancing trees.");
	WriteLine(SPLITTER_STRING);
	WriteLine("To choose the data structure, enter its number:");
	WriteLine("\t1\tRed-black tree.");
	WriteLine("\t2\tAVL tree;");
	WriteLine("Use 0 to exit the program.");
	int operationCode = 1;
	while (operationCode)
	{
		WriteLine(SPLITTER_STRING);
		operationCode = ReadInt("Enter operation code: ");
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
				WriteLine("To choose the data structure, enter"
					" its number:");
				WriteLine("\t1\tRed black tree.");
				WriteLine("\t2\tAVL tree;");
				break;
			}
			case Exit:
			{
				return 0;
			}
			default:
			{
				WriteLine("");
				WriteLine(SPLITTER_STRING);
				WriteLine("");
				WriteLine("Incorrect operation code. "
							   "Enter 100 to get help.");
				WriteLine("Repeat enter: ");
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
	WriteLine(SPLITTER_STRING);
	WriteLine("To choose operation type, enter its code:");
	WriteLine("\t1\tInsert the element");
	WriteLine("\t2\tDelete the element");
	WriteLine("\t3\tSearch element by the key");
	WriteLine("Use 0 to exit the program.");
	RbTree* tree = new RbTree;
	int operationCode = 1;
	while (operationCode)
	{
		WriteLine(SPLITTER_STRING);
		operationCode = ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case Add:
			{
				try
				{
					int key = ReadInt("Insert key:");
					string value = ReadString("Insert value:");
					tree->Insert(key, value);
					PrintTree(tree->GetRoot(), tree->GetNil());
				}
				catch (const exception& error)
				{
					WriteLine(error.what());
				}
				break;
			}
			case Delete:
			{
				try
				{
					WriteLine("Insert key of node to delete: ");
					tree->DeleteByKey(ReadInt());
					WriteLine("The node successfuly deleted.");
					PrintTree(tree->GetRoot(), tree->GetNil());
				}
				catch (const exception& error)
				{
					WriteLine(error.what());
				}
				break;
			}
			case GetValueByKey:
			{
				try
				{
					string foundValue;
					foundValue =
						tree->GetValueByKey(ReadInt());
					WriteLine(foundValue);
				}
				catch (const exception& error)
				{
					WriteLine(error.what());
				}
				break;
			}
			case Help:
			{
				WriteLine(SPLITTER_STRING);
				WriteLine("To choose operation type, enter its code:");
				WriteLine("\t1\tInsert the element");
				WriteLine("\t2\tDelete the element");
				WriteLine("\t3\tSearch element by the key");
				WriteLine("Use 0 to exit the program.");
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				WriteLine("");
				WriteLine(SPLITTER_STRING);
				WriteLine("");
				WriteLine("Incorrect operation code. Enter 100 to"
					" get help.");
				WriteLine("Repeat enter: ");
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
	WriteLine(SPLITTER_STRING);
	WriteLine("To choose operation type, enter its code:");
	WriteLine("\t1\tInsert the element");
	WriteLine("\t2\tDelete the element");
	WriteLine("\t3\tSearch element by the key");
	WriteLine("Use 0 to exit the program.");
	WriteLine(SPLITTER_STRING);
	AvlTree* tree = new AvlTree;
	int operationCode = 1;
	while (operationCode)
	{
		WriteLine(SPLITTER_STRING);
		operationCode = ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case Add:
			{
				while (true)
				{
					try
					{
						int key = ReadInt("Enter key: ");
						string value = ReadString("Enter value: ");
						tree->Insert(tree->GetRoot(),
									 key, value);
						PrintTree(tree->GetRoot());
						break;
					}
					catch (const exception& error)
					{
						WriteLine(error.what());
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
						tree->DeleteByKey(ReadInt("Enter key:"));
						WriteLine("The node successfully deleted.");
						PrintTree(tree->GetRoot());
						break;
					}
					catch (const exception& error)
					{
						WriteLine(error.what());
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
							tree->GetValueByKey(ReadInt());
						WriteLine(foundValue);
						break;
					}
					catch (const exception& error)
					{
						WriteLine(error.what());
					}
				}
				break;
			}
			case Help:
			{
				WriteLine(SPLITTER_STRING);
				WriteLine("To choose operation type,"
							   " enter its code:");
				WriteLine("\t1\tInsert the element");
				WriteLine("\t2\tDelete the element");
				WriteLine("\t3\tSearch element by the key");
				WriteLine("Use 0 to exit the program.");
				WriteLine(SPLITTER_STRING);
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				WriteLine("");
				WriteLine(SPLITTER_STRING);
				WriteLine("");
				WriteLine("Incorrect operation code. Enter 100 to"
					" get help.");
				WriteLine("Repeat enter: ");
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
