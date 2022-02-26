#include <iostream>
#include <string>
#include "AVLTree.h"
#include "RBTree.h"
#include "..\Console\Console.h"
#include "..\Console\Console.cpp"
using namespace std;

string SPLITTER_STRING = "--------------------------"
"-----------------------"
"-----------------------";

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
	setlocale(LC_ALL, "ru");
	cout << SPLITTER_STRING << endl;
	cout << "Welcome to the program of working with"
		" self-balancing trees." << endl;
	cout << SPLITTER_STRING << endl;
	cout << "To choose the data structure, enter its number:" << endl;
	cout << "\t1\tRed-black tree." << endl;
	cout << "\t2\tAVL tree;" << endl;
	cout << "Use 0 to exit the program." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
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
				cout << "To choose the data structure, enter"
					" its number:" << endl;
				cout << "\t1\tRed black tree." << endl;
				cout << "\t2\tAVL tree;" << endl;
				break;
			}
			case Exit:
			{
				return 0;
			}
			default:
			{
				cout << endl;
				cout << SPLITTER_STRING << endl;
				cout << endl;
				cout << "Incorrect operation code. Enter 100 to"
					" get help." << endl;
				cout << "Repeat enter: ";
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
		SearchByKey = 3,
		Exit = 0,
		Help = 100,
	};
	setlocale(LC_ALL, "ru");
	cout << SPLITTER_STRING << endl;
	cout << "To choose operation type, enter its code:" << endl;
	cout << "\t1\tInsert the element" << endl;
	cout << "\t2\tDelete the element" << endl;
	cout << "\t3\tSearch element by the key" << endl;
	cout << "Use 0 to exit the program." << endl;
	cout << SPLITTER_STRING << endl;
	RbTree* tree = new RbTree;
	int operationCode = 1;
	while (operationCode)
	{
		cout << SPLITTER_STRING << endl;
		operationCode = Console::ReadInt("Enter operation code: ");
		switch (operationCode)
		{
			case Add:
			{
				try
				{
					int key = Console::ReadInt("Insert key:");
					string value =
						Console::ReadString("Insert value:");
					tree->Insert(tree->GetRoot(),
						key, value);
					PrintTree(tree->GetRoot(), tree->GetNil());
					break;
				}
				catch (const exception& error)
				{
					Console::Print(error.what());
				}
			}
			case Delete:
			{
				while (true)
				{
					try
					{
						tree->DeleteByKey(Console::ReadInt());
						Console::Print("The node successfuly deleted.");
						PrintTree(tree->GetRoot(), tree->GetNil());
						break;
					}
					catch (const exception& error)
					{
						Console::Print(error.what());
					}
				}
			}
			case SearchByKey:
			{
				try
				{
					string foundValue;
					foundValue =
						tree->SearchByKey(Console::ReadInt());
					Console::Print(foundValue);
					break;
				}
				catch (const exception& error)
				{
					Console::Print(error.what());
				}
			}
			case Help:
			{
				cout << SPLITTER_STRING << endl;
				cout << "To choose operation type, enter its code:"
					<< endl;
				cout << "\t1\tInsert the element" << endl;
				cout << "\t2\tDelete the element" << endl;
				cout << "\t3\tSearch element by the key" << endl;
				cout << "Use 0 to exit the program." << endl;
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				cout << endl;
				cout << SPLITTER_STRING << endl;
				cout << endl;
				cout << "Incorrect operation code. Enter 100 to"
					" get help." << endl;
				cout << "Repeat enter: ";
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
		SearchByKey = 3,
		Exit = 0,
		Help = 100,
	};
	setlocale(LC_ALL, "ru");
	cout << SPLITTER_STRING << endl;
	cout << "To choose operation type, enter its code:" << endl;
	cout << "\t1\tInsert the element" << endl;
	cout << "\t2\tDelete the element" << endl;
	cout << "\t3\tSearch element by the key" << endl;
	cout << "Use 0 to exit the program." << endl;
	cout << SPLITTER_STRING << endl;
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
						tree->DeleteByKey(Console::ReadInt());
						Console::Print("The node successfule deleted.");
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
			case SearchByKey:
			{
				while (true)
				{
					try
					{
						string foundValue;
						foundValue =
							tree->SearchByKey(Console::ReadInt());
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
				cout << SPLITTER_STRING << endl;
				cout << "To choose operation type, enter its code:"
					<< endl;
				cout << "\t1\tInsert the element" << endl;
				cout << "\t2\tDelete the element" << endl;
				cout << "\t3\tSearch element by the key" << endl;
				cout << "Use 0 to exit the program." << endl;
				cout << SPLITTER_STRING << endl;
				break;
			}
			case Exit:
			{
				return;
			}
			default:
			{
				cout << endl;
				cout << SPLITTER_STRING << endl;
				cout << endl;
				cout << "Incorrect operation code. Enter 100 to"
					" get help." << endl;
				cout << "Repeat enter: ";
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
	if (currentNode != nullptr)
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
			cout << "|\n";
		}
		if (currentNode->LeftSubtree == nil
			&&
			currentNode->RightSubtree != nil)
		{
			cout << "/\n";
		}
		if (currentNode->LeftSubtree != nil
			&&
			currentNode->RightSubtree == nil)
		{
			cout << "\\\n";
		}
		if (currentNode->LeftSubtree == nil
			&&
			currentNode->RightSubtree == nil)
		{
			cout << "\n";
		}
		PrintTree(currentNode->LeftSubtree, nil, tabCount + 1);
	}
}

void PrintTree(AvlTreeNode* currentNode, int tabCount)
{
	if (currentNode != nullptr)
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
			cout << "|\n";
		}
		if (currentNode->LeftSubtree == nullptr
			&&
			currentNode->RightSubtree != nullptr)
		{
			cout << "/\n";
		}
		if (currentNode->LeftSubtree != nullptr
			&&
			currentNode->RightSubtree == nullptr)
		{
			cout << "\\\n";
		}
		if (currentNode->LeftSubtree == nullptr
			&&
			currentNode->RightSubtree == nullptr)
		{
			cout << "\n";
		}
		PrintTree(currentNode->LeftSubtree, tabCount + 1);
	}
}
