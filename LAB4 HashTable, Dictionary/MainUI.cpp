#include <iostream>
#include <string>
#include "Dictionary.h"
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

//TODO: RSDN +
//TODO: XML +
/// <summary>
/// Enumeration for UI commands in main, HashTableUI and DictionarUI
/// </summary>
enum OperationCode
{
	Stop = 0,
	HashTableEnum = 1,
	Insert = 1,
	DictionaryEnum = 2,
	Remove = 2,
	Find = 3,
	Help = 100
};

/// <summary>
/// Printing hash table with its empty nodes.
/// </summary>
/// <param name="hashTable">Hash table to print</param>
void PrintHashTable(HashTable& hashTable);

/// <summary>
/// Printing hash table without its empty nodes.
/// </summary>
/// <param name="hashTable">Hash table to print</param>
void PrintDictionary(Dictionary& dictionary);

/// <summary>
/// Print message to console and then read from console
/// </summary>
/// <param name="messageToPrint">message to print before reading</param>
/// <returns>String inserted by user</returns>
string ReadStringValueFromConsole(string messageToPrint);

/// <summary>
/// Graphic user interface for hash table the data structure
/// </summary>
void HashTableUI();

/// <summary>
/// Graphic user interface for dictionary the data structure
/// </summary>
void DictionaryUI();

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Вас приветствует программа работы со словарём и хеш-таблицей." << endl;
	cout << "Для выбора структуры данных, введите соответствующий ей номер:" << endl;
	cout << "\t1. Хеш-таблица;" << endl;
	cout << "\t2. Словарь;" << endl;
	cout << "Для выхода из программы, введите 0." << endl;
	cout << "Введите код операции: " << endl;
	short int operationCode = 3;
	while (operationCode != 0)
	{
		cin >> operationCode;
		switch (operationCode)
		{
			case Stop:
			{
				break;
			}
			case HashTableEnum:
			{
				HashTableUI();
				operationCode = 0;
				break;
			}
			case DictionaryEnum:
			{
				DictionaryUI();
				operationCode = 0;
				break;
			}
			default:
			{
				cout << "Введён неверный код операции. Повторите ввод: ";
				break;
			}
		}
	}
	cout << "Программа успешно завершила своё выполнение";
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

void PrintDictionary(Dictionary& dictionary)
{
	PrintHashTable(*dictionary.GetHashTable());
}

string ReadStringValueFromConsole(string messageToPrint)
{
	cout << messageToPrint;
	string userValue;
	cin >> userValue;
	return userValue;
}

void HashTableUI()
{
	cout << "Для работы c хеш-таблицей, используйте следующий список команд:" << endl;
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
			//TODO: RSDN +
			case Stop:
			{
				cout << "Программа успешно завершила выполнение." << endl << endl;
				return;
			}
			case Insert:
			{
				//TODO: +
				string inputString = ReadStringValueFromConsole("Введите строку, которую хотите добавить: ");
				string key = ReadStringValueFromConsole("Введите ключ, по которому будет располагаться строка: ");
				try
				{
					hashTableUnit.HashTableInsert(key, inputString);
					cout << "Элемент успешно добавлен." << endl;
				}
				catch (string& error)
				{
					cout << error << endl;
					break;
				}
				PrintHashTable(hashTableUnit);
				break;
			}
			case Remove:
			{
				//TODO: +
				string key = ReadStringValueFromConsole("Введите ключ, по которому будет удалена строка: ");
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
				break;
			}
			case Find:
			{
				//TODO: +
				string key = ReadStringValueFromConsole("Введите ключ, по которому найдена строка: ");
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
				break;
			}
			case Help:
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
}

void DictionaryUI()
{
	cout << "Для работы cо словарём, используйте следующий список команд:" << endl;
	cout << "\t1. Добавить элемент;" << endl;
	cout << "\t2. Удалить элемент;" << endl;
	cout << "\t3. Найти элемент и вывести на экран." << endl;
	cout << "Для выхода из программы, введите 0." << endl;
	int operationCode;
	Dictionary dictionaryUnit;
	while (true)
	{
		cout << "Введите номер команды: ";
		cin >> operationCode;
		switch (operationCode)
		{
			//TODO: RSDN +
			case Stop:
			{
				cout << "Программа успешно завершила выполнение." << endl << endl;
				return;
			}
			case Insert:
			{
				//TODO: +
				string inputString = ReadStringValueFromConsole("Введите строку, которую хотите добавить: ");
				string key = ReadStringValueFromConsole("Введите ключ, по которому будет располагаться строка: ");
				try
				{
					dictionaryUnit.DictionaryInsert(key, inputString);
					cout << "Элемент успешно добавлен." << endl;
				}
				catch (string& error)
				{
					cout << error << endl;
					break;
				}
				PrintDictionary(dictionaryUnit);
				break;
			}
			case Remove:
			{
				//TODO: +
				string key = ReadStringValueFromConsole("Введите ключ, по которому будет удалена строка: ");
				try
				{
					dictionaryUnit.Remove(key);
					cout << "Элемент успешно удалён." << endl;
				}
				catch (string& error)
				{
					cout << error << endl;
					break;
				}
				PrintDictionary(dictionaryUnit);
				break;
			}
			case Find:
			{
				//TODO: +
				string key = ReadStringValueFromConsole("Введите ключ, по которому найдена строка: ");
				try
				{
					cout << "По ключу " << key << " находится значение "
						<< dictionaryUnit.Find(key);
					cout << endl;
				}
				catch (string& error)
				{
					cout << error << endl;
					break;
				}
				PrintDictionary(dictionaryUnit);
				break;
			}
			case Help:
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
}
