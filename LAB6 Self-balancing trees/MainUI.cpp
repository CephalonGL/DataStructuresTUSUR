#include <iostream>
#include <string>
#include <ctime>
#include "AVLTree.h"
#include "RBTree.h"
using namespace std;

//� ����� ������� ����� ��������� �������� ����������?
//����� �� ��������� RedBlack �� RB?
// 
//��� ����������� ���� ���, ����� ��� ������ ������ ����� ���� ������������
//��� string, � �� int? switch ��������� ������ int.

string SPLITTER_STRING = "-------------------------------------------------"
"-----------------------";

void RbTreeUI();

void AvlTreeUI();

int main()
{
	enum MainUI
	{
		EXIT = 0,
		RED_BLACK = 1,
		AVL = 2,
		Help = 100,
	};
	setlocale(LC_ALL, "ru");
	cout << SPLITTER_STRING << endl;
	cout << "��� ������������ ��������� ��� ������ � " <<
		"�������������������� ���������" << endl;
	cout << SPLITTER_STRING << endl;
	cout << "��� ������ ��������� ������, ������� � ���������� �����:" << endl;
	cout << "\t1. ������-������ ������." << endl;
	cout << "\t2. ���-������;" << endl;
	cout << "��� ������ �� ���������, ������� 0." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
		cout << "������� ��� ��������: ";
		cin >> operationCode;
		switch (operationCode)
		{
		case RED_BLACK:
		{
			break;
		}
		case AVL:
		{
			break;
		}
		case Help:
		{
			cout << "��� ������ ��������� ������, ������� � ���������� �����:"
				<< endl;
			cout << "\t1. ������-������ ������." << endl;
			cout << "\t2. ���-������;" << endl;
			break;
		}
		case EXIT:
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


void RbTreeUI()
{
	enum RedBlack
	{
		EXIT = 0,
		Help = 100,
	};
	return;
}

void AvlTreeUI()
{
	enum AVL
	{
		EXIT = 0,
		Help = 100,
	};
	return;
}
