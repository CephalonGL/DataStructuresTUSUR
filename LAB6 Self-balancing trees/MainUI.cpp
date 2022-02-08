#include <iostream>
#include <string>
#include <ctime>
#include "AVLTree.h"
#include "RBTree.h"
using namespace std;

//В каких случаях можно сокращать названия переменных?
//Можно ли сократить RedBlack до RB?
// 
//Как реализовать меню так, чтобы для выбора пункта можно было использовать
//тип string, а не int? switch принимает только int.

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
	cout << "Вас приветствует программа для работы с " <<
		"самобалансирующимися деревьями" << endl;
	cout << SPLITTER_STRING << endl;
	cout << "Для выбора структуры данных, введите её порядковый номер:" << endl;
	cout << "\t1. Красно-чёрное дерево." << endl;
	cout << "\t2. АВЛ-дерево;" << endl;
	cout << "Для выхода из программы, введите 0." << endl;
	cout << SPLITTER_STRING << endl;
	int operationCode = 1;
	while (operationCode)
	{
		cout << "Введите код операции: ";
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
			cout << "Для выбора структуры данных, ввежите её порядковый номер:"
				<< endl;
			cout << "\t1. Красно-чёрное дерево." << endl;
			cout << "\t2. АВЛ-дерево;" << endl;
			break;
		}
		case EXIT:
		{
			return 0;
		}
		default:
		{
			cout << endl;
			cout << "Неверный код операции. Для вызова справки, введите 100." << endl;
			cout << "Повторите ввод: ";
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
