#include <iostream>
#include "DynamicArray.h"

using namespace std;

void PrintArrayToConsole(DynamicArray& unit);
void Help();
void AnalizeOperationCode(DynamicArray& unit, int operationCode);

int main()
{
	setlocale(LC_ALL, "ru");
	int operationCode;
	DynamicArray unit;
	cout << "\tВас приветсвует программа для работы с динамическим массивом."
		<< endl << endl;
	Help();
	while (true)
	{
		cout << "Введите код команды: ";
		cin >> operationCode;
		if (operationCode == 0)
		{
			cout << endl;
			cout << "Конечный массив:" << endl;
			PrintArrayToConsole(unit);
			cout << endl;
			cout << "\tПрограмма завершила работу. Для выхода нажмите Ввод." << endl;
			unit.DeleteArray();
			break;
		}
		else
		{
			AnalizeOperationCode(unit, operationCode);
		}
		cout << endl;
	}
	return 0;
}

void Help()
{
	cout << "Для создания и инициализаци полей, введите 1." << endl;
	cout << "Для добавления элемента в массив, введите 2." << endl;
	cout << "Для удаления элемента из массива, введите 3." << endl;
	cout << "Для вставки элеента в начало, введите 4." << endl;
	cout << "Для вставки элемента в конец, введите 5." << endl;
	cout << "Для вставки после определённого элемена, нажмите 6." << endl;
	cout << "Для сортировки массива, введите 7." << endl;
	cout << "Для линейного поиска в массиве, введите 8." << endl;
	cout << "Для бинарного поиска, введите 9." << endl;
	cout << "Для вывода массива на экран, введите 10." << endl;
	cout << "Для остановки программы, введите 0." << endl;
	cout << "Для просмотра функционала, введите любое другое значение."
		<< endl << endl;
}

void PrintArrayToConsole(DynamicArray& unit)
{
	for (int i = 0; i < unit.currentArrayLength; i++)
	{
		cout << "arr[" << i << "] = " << unit.internalArray[i] << endl;
	}
}

void AnalizeOperationCode(DynamicArray& unit, int operationCode)
{
	switch (operationCode)
	{
	case 1:
	{
		cout << "Инициализируйте начальный массив из " << unit.currentArrayLength
			<< " символов:" << endl;
		unit.InitializeArrayByInputStream();
		break;
	}
	case 2:
	{
		unit.AddElement();
		cout << "К массиву добавлен новый элемент массива." << endl;
		break;
	}
	case 3:
	{
		unit.DeleteElement();
		cout << "Последний элемент массива удалён." << endl;
		break;
	}
	case 4:
	{
		cout << "Введите значение, которое хотите поместить первым: ";
		unit.PushFront();
		break;
	}
	case 5:
	{
		cout << "Введите значение, которое хотите поместить последним: ";
		unit.PushBack();
		break;
	}
	case 6:
		//PushAfterElement
	{
		cout << "Введите значение, которое хотите поместить: ";
		int valueToPush;
		cin >> valueToPush;
		cout << "Введите индекс элемента от 0 до " << unit.currentArrayLength - 1
			<< ", после которого хотите поместить значение: ";
		int indexToPush;
		cin >> indexToPush;
		switch (unit.PushAfterElement(valueToPush, indexToPush))
		{
		case 0:
			cout << "Операция выполнена успешно.";
			break;
		case 1:
			cout << "Значение индекса вышло за границы массива";
			break;
		default:
			cout << "Ошибка!";
		}
		break;
	}
	case 7:
	{
		unit.BubbleSort();
		cout << "Операция выполнена успешно.";
		break;
	}
	case 8:
		//LinearSearch
	{
		cout << "Введите значение для поиска: ";
		int valueToSearch;
		cin >> valueToSearch;
		int returnableIndex = unit.LinearSearch(valueToSearch);
		if (returnableIndex != -1)
		{
			cout << "Данный элемент находится под индексом " << returnableIndex << endl;
		}
		else
		{
			cout << "Такого элемента нет в массиве";
		}
		break;
	}
	case 9:
		//BinarySearch
	{
		unit.BubbleSort();
		cout << "Массив отсортирован, введите значение для бинарного поиска: ";
		int searchValue;
		cin >> searchValue;
		int returnableIndex = unit.BinarySearch(searchValue);
		if (returnableIndex != -1)
		{
			cout << "Данный элемент находится под индексом " << returnableIndex << endl;
		}
		else
		{
			cout << "Такого элемента нет в массиве";
		}
		break;
	}
	case 10:
	{
		PrintArrayToConsole(unit);
		break;
	}
	default:
	{
		Help();
		break;
	}
	}
}