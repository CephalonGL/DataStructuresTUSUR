#include <iostream>
#include <string>
#include "List.h"

using namespace std;

/// <summary>
/// Print command list to console
/// </summary>
void Help();

/// <summary>
/// Get data from console and check if 
/// </summary>
/// <param name="messageToPrint">Printing messageToPrint</param>
/// <returns>User's data</returns>
int ReadIntValueFromConsole(string messageToPrint);

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "\tВас приветствует программа для работы с двусвязным списком." << endl;
	Help();
	List list;
	bool IfListInitialized = false;
	while (true)
	{
		int operationCode;
		cin >> operationCode;
		switch (operationCode)
		{
			case 0:
			{
				cout << "\nПрограмма успешно завершила свою работу\n\n";
				return 0;
			}
			case 1:
			{
				if (IfListInitialized)
				{
					cout << "Ошибка, список уже создан!";
					break;
				}
				int countOfNodes = ReadIntValueFromConsole("Для создания списка,"
					" введите количество узлов: ");
				cout << "Вводите инициализируемые значения для узлов:" << endl;
				int* arrayTmp = new int[countOfNodes];
				for (int i = 0; i < countOfNodes; i++)
				{
					cin >> arrayTmp[i];
				}
				list.CreateList(countOfNodes, arrayTmp);
				cout << "Количество узлов = " << list.GetLength() << endl;
				delete[] arrayTmp;
				cout << "Операция выполнена успешно" << endl;
				IfListInitialized = true;
				break;
			}
			case 2:
			{
				int valueToPush = ReadIntValueFromConsole("Введите значение нового узла: ");
				list.AddNewNode(valueToPush);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 3:
			{
				int indexOfRemovableNode = ReadIntValueFromConsole("Введите индекс"
					" удаляемого элемента: ");
				list.RemoveNode(indexOfRemovableNode);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 4:
			{
				int valueToPush = ReadIntValueFromConsole("Введите значение нового узла: ");
				list.PushForward(valueToPush);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 5:
			{
				int valueToPush = ReadIntValueFromConsole("Введите значение нового узла: ");
				list.PushBack(valueToPush);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 6:
			{
				int valueToPush = ReadIntValueFromConsole("Введите значение нового узла: ");
				int indexNodeToPushAfter = ReadIntValueFromConsole("Введите индекс,"
					" после которого хотите вставить элемент: ");
				list.PushAfterNode(indexNodeToPushAfter, valueToPush);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 7:
			{
				int valueToPush = ReadIntValueFromConsole("Введите значение нового узла: ");
				int indexNodeToPushBefore = ReadIntValueFromConsole("Введите индекс, перед которым хотите вставить элемент: ");
				list.PushBeforeNode(indexNodeToPushBefore, valueToPush);
				cout << "Операция выполнена успешно" << endl;
				break;
			}
			case 8:
			{
				list.Sort();
				cout << "Сортировка выполнена успешно" << endl;
				break;
			}
			case 9:
			{
				int valueToSearch = ReadIntValueFromConsole("Введите значение для поиска: ");
				int indexOfSearchinValue = list.LinearSearch(valueToSearch);
				if (indexOfSearchinValue == -1)
				{
					cout << "Такого элемента в списке нет." << endl;
				}
				else
				{
					cout << "Список содержит данный элемент по индексу: " <<
						indexOfSearchinValue << endl;
					break;
				}
			}
			case 10:
			{
				cout << "Список значений:" << endl;
				for (int i = 0; i < list.GetLength(); i++)
				{
					cout << "list[" << i << "] = " << list.GetValueByIndex(i) << endl;
				}
				break;
			}
			case 100:
			{
				Help();
				break;
			}
			default:
			{
				cout << endl;
				cout << "\tНеизвестный код команды. Для получения справки, введите 100.";
				cout << endl;
				break;
			}
		}
	}
	return 0;
}

void Help()
{
	cout << endl;
	cout << "Для выполнения команды, введите соответствующий ей номер." << endl;
	cout << "Список доступных команд:" << endl;
	cout << "1 - Создать список;" << endl;
	cout << "2 - Добавить элемент;" << endl;
	cout << "3 - Удалить элемент;" << endl;
	cout << "4 - Вставка элемента в начало;" << endl;
	cout << "5 - Вставка элемента в конец;" << endl;
	cout << "6 - Вставка элемента после заданного элемента;" << endl;
	cout << "7 - Вставка элемента перед заданным элементом;" << endl;
	cout << "8 - Сортировка списка;" << endl;
	cout << "9 - Линейный поиск элемента в списке;" << endl;
	cout << "10 - Вывести список по порядку;" << endl;
	cout << "0 - Остановка программы;" << endl;
	cout << "100 - Вывести справку." << endl;
	cout << endl;
}

int ReadIntValueFromConsole(string messageToPrint)
{
	cout << messageToPrint;
	int userValue;
	cin >> userValue;
	return userValue;
}