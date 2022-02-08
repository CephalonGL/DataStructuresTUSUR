#include <string>
#include <iostream>
#include <ctime>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "CartesianTree.h"
#include "CartesianTreeNode.h"

using namespace std;

/// <summary>
/// UI for binary tree
/// </summary>
void BinaryTreeUI();
/// <summary>
/// UI for cartesian tree
/// </summary>
void CartesianTreeUI();
/// <summary>
/// Print binary tree to console
/// </summary>
/// <param name="node">Root node</param>
/// <param name="tabCount">Count of tabulations between subtrees</param>
void PrintBinTree(BinaryTreeNode* node, int tabCount = 0);
/// <summary>
/// Print cartesian tree
/// </summary>
/// <param name="node">Root node</param>
/// <param name="tabCount">Count of tabulations between subtrees</param>
void PrintCartesianTree(CartesianTreeNode* node, int tabCount = 0);
/// <summary>
/// Return random value
/// </summary>
/// <returns>Random value</returns>
int RandomValue();

int main()
{
	enum MainUI
	{
		BINARY_TREE = 1,
		CARTESIAN_TREE = 2,
		STOP = 0
	};
	setlocale(LC_ALL, "ru");
	cout << "��� ������������ ��������� ��� ������ � ���������." << endl;
	cout << "�������� ��� ������, � ������� ������ ��������:" << endl;
	cout << "\t1. �������� ������;" << endl;
	cout << "\t2. ��������� ������." << endl;
	cout << "������� ��� ��������: ";
	int operationCode;
	while (true)
	{
		cin >> operationCode;
		switch (operationCode)
		{
		case BINARY_TREE:
		{
			BinaryTreeUI();
			return 0;
		}
		case CARTESIAN_TREE:
		{
			CartesianTreeUI();
			return 0;
		}
		case STOP:
		{
			cout << "��������� ������� ��������� ��� ����������." << endl;
			return 0;
		}
		default:
			cout << "������� �� ����������. ��������� ����: ";
			break;
		}
	}
}

void BinaryTreeUI()
{
	enum BinaryTreeUI
	{
		STOP = 0,
		CREATE_TREE = 1,
		ADD_ELEMENT = 2,
		DELETE_ELEMENT = 3,
		FIND_ELEMENT = 4,
		FIND_MAX = 5,
		FIND_MIN = 6,
		PRINT = 7,
		HELP = 100
	};
	cout << "��� ������ � �������� �������, ����������� "
		<< "��������� ������ ������" << endl;
	cout << "\t1. ������� ������;" << endl;
	cout << "\t2. �������� �������;" << endl;
	cout << "\t3. ������� �������;" << endl;
	cout << "\t4. ����� �������;" << endl;
	cout << "\t5. ����� �������� ������;" << endl;
	cout << "\t6. ����� ������� ������;" << endl;
	cout << "\t7. ������� ������ �� �����." << endl;
	cout << "��� ���������� ������ ���������, ������� 0" << endl;
	int operationCode;
	BinaryTree binaryTree;
	while (true)
	{
		cout << "������� ��� ��������:";
		cin >> operationCode;
		switch (operationCode)
		{
		case CREATE_TREE:
		{
			try
			{
				int key;
				cout << "������� ���� ��������� ����: ";
				cin >> key;
				int value;
				cout << "������� �������� ��������� ����: ";
				cin >> value;
				binaryTree.CreateTree(key, value);
				cout << "������ ������� �������." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case ADD_ELEMENT:
		{
			try
			{
				if (binaryTree.RootNode == nullptr)
				{
					string error = "�������� ���� ��� ����� nullptr, �������� ������.";
					throw error;
				}
				int key;
				cout << "������� ���� ��������� ����: ";
				cin >> key;
				int value;
				cout << "������� �������� ��������� ����: ";
				cin >> value;
				binaryTree.AddElement(binaryTree.RootNode, key, value);
				cout << "������� ������� ��������." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case DELETE_ELEMENT:
		{
			try
			{
				int key;
				cout << "������� ���� ��������� ����: ";
				cin >> key;
				binaryTree.DeleteElement(binaryTree.RootNode, key);
				cout << "������� ������� �����." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case FIND_ELEMENT:
		{
			try
			{
				int key;
				cout << "������� ���� �������� ����: ";
				cin >> key;
				cout << "�� ����� " << key << " ��������� �������� "
					<< binaryTree.FindElement(binaryTree.RootNode, key)->Value << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case FIND_MAX:
		{
			try
			{
				cout << "������������ �������� ������: "
					<< binaryTree.FindMax(binaryTree.RootNode)->Value << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case FIND_MIN:
		{
			try
			{
				cout << "����������� �������� ������: "
					<< binaryTree.FindMin(binaryTree.RootNode)->Value << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}

		case PRINT:
		{
			try
			{
				cout << endl;
				PrintBinTree(binaryTree.RootNode);
				cout << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case HELP:
		{
			cout << "������ ������:" << endl;
			cout << "\t1. ������� ������;" << endl;
			cout << "\t2. �������� �������;" << endl;
			cout << "\t3. ������� �������;" << endl;
			cout << "\t4. ����� �������;" << endl;
			cout << "\t5. ����� �������� ������;" << endl;
			cout << "\t6. ����� ������� ������" << endl;
			cout << "\t7. ������� ������ �� �����." << endl;
			cout << "��� ���������� ������ ���������, ������� 0" << endl;
			break;
		}
		case STOP:
		{
			cout << "��������� ������� ��������� ���� ������." << endl;
			return;
		}
		default:
			cout << "������� �� ����������. "
				<< "��� ������ �������, ������� 100." << endl;
			break;
		}
	}
}

void CartesianTreeUI()
{
	srand(time(NULL));
	enum CartesianTreeUI
	{
		STOP = 0,
		FIND_ELEMENT = 1,
		INSERT_NON_OPTIMIZED = 2,
		INSERT_OPTIMIZED = 3,
		PRINT = 4,
		DELETE_NON_OPTIMIZED = 5,
		DELETE_OPTIMIZED = 6,
		DELETE_AND_CLEAR_MEMORY = 7,
		FILL_RANDOM = 8,
		SPLIT_AND_PRINT = 9,
		HELP = 100
	};
	cout << "��� ������ � ���������� �������, ����������� "
		<< "��������� ������ ������" << endl;
	cout << "\t1. ����� �������;" << endl;
	cout << "\t2. ����������(������������������, 1 Split, 2 Merge);" << endl;
	cout << "\t3. ����������(����������������, 1 Split);" << endl;
	cout << "\t4. ������� ������ �� �����;" << endl;
	cout << "\t5. ��������(������������������, 2 Split, 1 Merge);" << endl;
	cout << "\t6. ��������(����������������, 1 Merge);" << endl;
	cout << "\t7. �������� �������� ������ � �������� ������;" << endl;
	cout << "\t8. ��������� ���������� ������(10 ���������);" << endl;
	cout << "\t9. ��������� �� ����� � ������� ����������;" << endl;
	cout << "��� ���������� ������ ���������, ������� 0" << endl;
	int operationCode;
	CartesianTree* cartesianTree = new CartesianTree;
	while (true)
	{
		cout << "������� ��� ��������:";
		cin >> operationCode;
		switch (operationCode)
		{
		case FIND_ELEMENT:
		{
			try
			{
				cout << "������� ���� ��� ������: " << endl;
				int key;
				cin >> key;
				cout << "������� �� ������� �����: " << endl;
				cout << '('
					<< cartesianTree->FindElement(cartesianTree->RootNode, key)->Key
					<< '; '
					<< cartesianTree->FindElement(cartesianTree->RootNode, key)->Priority
					<< ')';
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case INSERT_NON_OPTIMIZED:
		{
			try
			{
				cout << "������� ���� ��� �������: " << endl;
				int key;
				cin >> key;
				cartesianTree = cartesianTree->UnoptimizedInsert(cartesianTree->RootNode,
					key);
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case INSERT_OPTIMIZED:
		{
			try
			{
				cout << "������� ���� ��� �������: " << endl;
				int key;
				cin >> key;
				int priority = rand() % 100 + 1;
				cartesianTree->RootNode =
					cartesianTree->OptimizedInsert(cartesianTree->RootNode, key, priority);
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case PRINT:
		{
			try
			{
				cout << endl;
				PrintCartesianTree(cartesianTree->RootNode);
				cout << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case DELETE_NON_OPTIMIZED:
		{
			try
			{
				int key;
				cout << "������� ���� ���������� ����: ";
				cin >> key;
				cartesianTree->UnoptimizedDelete(cartesianTree->RootNode, key);
				cout << "������������������ �������� ���������." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case DELETE_OPTIMIZED:
		{
			try
			{
				int key;
				cout << "������� ���� ���������� ����: ";
				cin >> key;
				cartesianTree->RootNode =
					cartesianTree->OptimizedDelete(cartesianTree->RootNode, key);
				cout << "���������������� �������� ���������." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case DELETE_AND_CLEAR_MEMORY:
		{
			try
			{
				cartesianTree->ClearDelete(cartesianTree->RootNode);
				cout << "������� ������ ������� ���������." << endl;
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case FILL_RANDOM:
		{
			try
			{
				for (int i = 0; i < 10; i++)
				{
					cartesianTree->RootNode = cartesianTree->OptimizedInsert(
						cartesianTree->RootNode, RandomValue(), RandomValue());
				}
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case SPLIT_AND_PRINT:
		{
			try
			{
				cout << "������� ����, �� �������� ������ ���������: ";
				int key;
				cin >> key;
				CartesianTreeNode* leftTree;
				CartesianTreeNode* rightTree;
				cartesianTree->Split(cartesianTree->RootNode, key, leftTree, rightTree);
				cout << "__________________________________________________" << endl;
				cout << "����� ��������� ����� ���:" << endl << endl;
				PrintCartesianTree(leftTree);
				cout << "__________________________________________________" << endl;
				cout << "������ ��������� ����� ���:" << endl << endl;
				PrintCartesianTree(rightTree);
				cout << "__________________________________________________" << endl;
				cartesianTree->Merge(leftTree, rightTree);
			}
			catch (string& message)
			{
				cout << "������! " << message << endl;
			}
			break;
		}
		case HELP:
		{
			cout << "������ ������:" << endl;
			cout << "\t1. ����� �������;" << endl;
			cout << "\t2. ����������(������������������, 1 Split, 2 Merge);" << endl;
			cout << "\t3. ����������(����������������, 1 Split);" << endl;
			cout << "\t4. ������� ������ �� �����;" << endl;
			cout << "\t5. ��������(������������������, 2 Split, 1 Merge);" << endl;
			cout << "\t6. ��������(����������������, 1 Merge);" << endl;
			cout << "\t7. �������� �������� ������ � �������� ������;" << endl;
			cout << "��� ���������� ������ ���������, ������� 0" << endl;
			break;
		}
		case STOP:
		{
			cout << "��������� ������� ��������� ���� ������." << endl;
			return;
		}
		default:
			cout << "������� �� ����������. "
				<< "��� ������ �������, ������� 100." << endl;
			break;
		}
	}
}

void PrintBinTree(BinaryTreeNode* currentNode, int tabCount)
{
	if (currentNode != nullptr)
	{
		PrintBinTree(currentNode->RightNode, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << currentNode->Key << "; " << currentNode->Value << ")";
		if (currentNode->LeftNode != nullptr && currentNode->RightNode != nullptr)
		{
			cout << "|\n";
		}
		if (currentNode->LeftNode == nullptr && currentNode->RightNode != nullptr)
		{
			cout << "/\n";
		}
		if (currentNode->LeftNode != nullptr && currentNode->RightNode == nullptr)
		{
			cout << "\\\n";
		}
		if (currentNode->LeftNode == nullptr && currentNode->RightNode == nullptr)
		{
			cout << "\n";
		}
		PrintBinTree(currentNode->LeftNode, tabCount + 1);
	}
}

void PrintCartesianTree(CartesianTreeNode* currentNode, int tabCount)
{
	if (currentNode != nullptr)
	{
		PrintCartesianTree(currentNode->RightNode, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << currentNode->Key << "; " << currentNode->Priority << ")";
		if (currentNode->LeftNode != nullptr && currentNode->RightNode != nullptr)
		{
			cout << "|\n";
		}
		if (currentNode->LeftNode == nullptr && currentNode->RightNode != nullptr)
		{
			cout << "/\n";
		}
		if (currentNode->LeftNode != nullptr && currentNode->RightNode == nullptr)
		{
			cout << "\\\n";
		}
		if (currentNode->LeftNode == nullptr && currentNode->RightNode == nullptr)
		{
			cout << "\n";
		}
		PrintCartesianTree(currentNode->LeftNode, tabCount + 1);
	}
}

int RandomValue()
{
	return rand() % 100 + 1;
}
