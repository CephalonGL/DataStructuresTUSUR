#include <iostream>
#include <string>
#include <ctime>
#include "AVLTree.h"
#include "RBTree.h"
using namespace std;

string SPLITTER_STRING = "-------------------------------------------------"
"-----------------------";

/// <summary>
/// Console user interface for red-black tree 
/// </summary>
void RedBlackTreeUI();

/// <summary>
/// Console user interface for Avl-tree
/// </summary>
void AvlTreeUI();

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
	cout << "��� ������������ ��������� ��� ������ � " <<
		"�������������������� ���������" << endl;
	cout << SPLITTER_STRING << endl;
	cout << "��� ������ ��������� ������, ������� � ���������� �����:" << endl;
	cout << "\t1\t������-������ ������." << endl;
	cout << "\t2\t���-������;" << endl;
	cout << "��� ������ �� ���������, ������� 0." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
		cout << "������� ��� ��������: ";
		cin >> operationCode;
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
				cout << "��� ������ ��������� ������, ������� � ���������� �����:"
					<< endl;
				cout << "\t1\t������-������ ������." << endl;
				cout << "\t2\t���-������;" << endl;
				break;
			}
			case Exit:
			{
				return 0;
			}
			default:
			{
				cout << endl;
				cout << "�������� ��� ��������. ��� ������ �������, ������� 100." << endl;
				cout << "��������� ����: ";
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
	cout << "��� ������ �������, ������� � ���������� �����:" << endl;
	cout << "\t1\t������� ��������" << endl;
	cout << "\t2\t�������� ��������" << endl;
	cout << "\t3\t����� �������� �� �����" << endl;
	cout << "\t100\t�������" << endl;
	cout << "��� ������ �� ���������, ������� 0." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
		cout << SPLITTER_STRING << endl;
		cout << "������� ��� ��������: ";
		cin >> operationCode;
		switch (operationCode)
		{
			case Add:
			{
				break;
			}
			case Delete:
			{
				break;
			}
			case SearchByKey:
			{
				break;
			}
			case Help:
			{
				cout << SPLITTER_STRING << endl;
				cout << "��� ������ �������, ������� � ���������� �����:" << endl;
				cout << "\t1\t������� ��������" << endl;
				cout << "\t2\t�������� ��������" << endl;
				cout << "\t3\t����� �������� �� �����" << endl;
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
				cout << "�������� ��� ��������. ��� ������ �������, ������� 100." << endl;
				cout << "��������� ����: ";
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
	cout << "��� ������ �������, ������� � ���������� �����:" << endl;
	cout << "\t1\t������� ��������" << endl;
	cout << "\t2\t�������� ��������" << endl;
	cout << "\t3\t����� �������� �� �����" << endl;
	cout << "\t100\t�������" << endl;
	cout << "��� ������ �� ���������, ������� 0." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
		cout << SPLITTER_STRING << endl;
		cout << "������� ��� ��������: ";
		cin >> operationCode;
		switch (operationCode)
		{
			case Add:
			{
				break;
			}
			case Delete:
			{
				break;
			}
			case SearchByKey:
			{
				break;
			}
			case Help:
			{
				cout << SPLITTER_STRING << endl;
				cout << "��� ������ �������, ������� � ���������� �����:" << endl;
				cout << "\t1\t������� ��������" << endl;
				cout << "\t2\t�������� ��������" << endl;
				cout << "\t3\t����� �������� �� �����" << endl;
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
				cout << "�������� ��� ��������. ��� ������ �������, ������� 100." << endl;
				cout << "��������� ����: ";
				break;
			}
		}
	}
	return;
}
