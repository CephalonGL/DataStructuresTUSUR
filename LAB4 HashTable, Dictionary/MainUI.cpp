﻿#include <iostream>
#include <string>
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

enum OperationCode { STOP, INSERT, REMOVE, FIND, HELP = 100 };

/// <summary>
/// Printing hash table with its empty nodes.
/// </summary>
/// <param name="hashTable">Hash table to print</param>
void PrintHashTable(HashTable& hashTable);
/// <summary>
/// Printing hash table without its empty nodes.
/// </summary>
/// <param name="hashTable">Hash table to print</param>
void PrintDictionary(HashTable& hashTable);

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Вас приветствует программа работы со словарём и хеш-таблицей." << endl;
	cout << "Для работы используйте следующий список команд:" << endl;
	cout << "\t1. Добавить элемент;" << endl;
	cout << "\t2. Удалить элемент;" << endl;
	cout << "\t3. Найти элемент и вывести на экран." << endl;
	cout << "Для выхода из программы, введите 0." << endl;
	int operationCode;
	HashTable hashTableUnit;
	while (true)
	{
		cout << "Введите номер команды: ";
		cin >> operationCode;
		switch (operationCode)
		{
		case STOP:
		{
			cout << "Программа успешно завершила выполнение." << endl << endl;
			return 0;
		}
		case INSERT:
		{
			cout << "Введите строку, которую хотите добавить: ";
			string iString;
			cin >> iString;
			cout << "Введите ключ, по которому будет располагаться строка: ";
			string key;
			cin >> key;
			try
			{
				hashTableUnit.HashTableInsert(key, iString);
				cout << "Элемент успешно добавлен." << endl;
			}
			catch (string& error)
			{
				cout << error << endl;
				break;
			}
			PrintHashTable(hashTableUnit);
			PrintDictionary(hashTableUnit);
			break;
		}
		case REMOVE:
		{
			cout << "Введите ключ, по которому будет удалена строка: ";
			string key;
			cin >> key;
			try
			{
				hashTableUnit.Remove(key);
				cout << "Элемент успешно удалён." << endl;
			}
			catch (string& error)
			{
				cout << error << endl;
				break;
			}
			PrintHashTable(hashTableUnit);
			PrintDictionary(hashTableUnit);
			break;
		}
		case FIND:
		{
			cout << "Введите ключ, по которому найдена строка: ";
			string key;
			cin >> key;
			try
			{
				cout << "По ключу " << key << " находится значение "
					<< hashTableUnit.Find(key);
				cout << endl;
			}
			catch (string& error)
			{
				cout << error << endl;
				break;
			}
			PrintHashTable(hashTableUnit);
			PrintDictionary(hashTableUnit);
			break;
		}
		case HELP:
		{
			cout << "Для работы используйте следующий список команд:" << endl;
			cout << "\t1. Добавить элемент;" << endl;
			cout << "\t2. Удалить элемент;" << endl;
			cout << "\t3. Найти элемент и вывести на экран." << endl;
			cout << "Для выхода из программы, введите 0." << endl;
			break;
		}
		default:
		{
			cout << "Введён неверный код операции. "
				<< "Для вызова справки, введите 100." << endl;
			break;
		}
		}
	}
	return 0;
}

void PrintHashTable(HashTable& hashTable)
{
	cout << "Значения хеш-таблицы:" << endl;
	cout << "Хеш\tКлюч\tЗначение\t" << endl;
	HashTableNode* currentNode = nullptr;
	for (int i = 0; i < hashTable.GetCapacity(); i++)
	{
		currentNode = &hashTable.HashTableNodeArray[i];
		do
		{
			cout << i << '\t';
			if (currentNode->Key == "")
			{
				cout << "empty" << endl;
			}
			else
			{
				cout << currentNode->Key << '\t';
				cout << currentNode->Value << '\t' << endl;
			}
			currentNode = currentNode->NextCollision;
		} while (currentNode != nullptr);
	}
}

void PrintDictionary(HashTable& hashTable)
{
	cout << "Значения словаря:" << endl;
	cout << "Ключ\tЗначение\t" << endl;
	HashTableNode* currentNode = nullptr;
	for (int i = 0; i < hashTable.GetCapacity(); i++)
	{
		currentNode = &hashTable.HashTableNodeArray[i];
		do
		{
			if (currentNode->Key != "")
			{
				cout << currentNode->Key << '\t';
				cout << currentNode->Value << '\t' << endl;
			}
			currentNode = currentNode->NextCollision;
		} while (currentNode != nullptr);
	}
}