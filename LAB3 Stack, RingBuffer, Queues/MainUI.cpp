#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueOnRingBuffer.h"
#include "QueueOnTwoStacks.h"

using namespace std;

/// <summary>
/// Print messageToPrint in console with user instructions
/// </summary>
void Hello();

/// <summary>
/// UI for stack
/// </summary>
void StackMenu();

/// <summary>
/// UI for ring buffer
/// </summary>
void RingBufferMenu();

/// <summary>
/// UI for queue on two stacks
/// </summary>
void QueueOnTwoStacksMenu();

/// <summary>
/// UI for queue on ring buffer
/// </summary>
void QueueOnRingBufferMenu();

/// <summary>
/// Get data from console and check if 
/// </summary>
/// <param name="messageToPrint">Printing messageToPrint</param>
/// <returns>User's data</returns>
int ReadIntValueFromConsole(string message);

template<typename T>

/// <summary>
/// Check if unit == nullptr and print message if it is
/// </summary>
/// <typeparam name="T">any type</typeparam>
/// <param name="unit">pointer on checking</param>
/// <param name="message">message that would be printed if unit == nullptr</param>
/// <returns>false if unit == nullptr and true otherwise</returns>
bool IsNullptr(T* unit, string message = "");

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Вас приветствует программа для работы с абстрактными "
		<< "структурами данных." << endl << endl;
	cout << "В программе представлены 4 типа структур, для работы с которыми "
		<< "введите соответствующий ей номер из списка." << endl;
	int structureCode;
	while (true)
	{
		cout << "Список структур:" << endl;
		cout << "\t1. Стэк;" << endl;
		cout << "\t2. Кольцевой буфер;" << endl;
		cout << "\t3. Очередь на кольцевом буфере;" << endl;
		cout << "\t4. Очередь на двух стэках." << endl;
		cout << "Чтобы выйти из программы, введите 0." << endl;
		cout << "Введите номер структуры: ";
		cin >> structureCode;
		while (structureCode != 1 && structureCode != 2
			&& structureCode != 3 && structureCode != 4 && structureCode != 0)
		{
			cout << "Неверный номер структуры. Повторите ввод: ";
			cin >> structureCode;
		}
		switch (structureCode)
		{
			case 1:
			{
				StackMenu();
				break;
			}
			case 2:
			{
				RingBufferMenu();
				break;
			}
			case 3:
			{
				QueueOnRingBufferMenu();
				break;
			}
			case 4:
			{
				QueueOnTwoStacksMenu();
				break;
			}
			case 0:
			{
				cout << "Программа завершила работу." << endl;
				return 0;
			}
		}
	}
	return 0;
}

void Hello()
{
	cout << "Вас приветствует программа для работы с абстрактными "
		<< "структурами данных." << endl << endl;
	cout << "В программе представлены 4 типа структур:" << endl;
	cout << "\t1. Стэк;" << endl;
	cout << "\t2. Кольцевой буфер;" << endl;
	cout << "\t3. Очередь на кольцевом буфере;" << endl;
	cout << "\t4. Очередь на двух стэках." << endl;
	cout << "Для работы со структурой, введите её номер из списка выше: "
		<< endl;
}

void StackMenu()
{
	cout << "Для работы со стеком, используйте следующий список операций"
		<< endl;
	cout << "\t1 - создание стека;" << endl;
	cout << "\t2 - помещение элемента в стек;" << endl;
	cout << "\t3 - извлечение элемента из стека;" << endl;
	cout << "\t0 - удаление стека и очистка памяти;" << endl;
	int operationCode;
	Stack* stackUnit = nullptr;
	while (true)
	{
		cout << "Введите код операции: ";
		cin >> operationCode;
		while (operationCode != 1 && operationCode != 2 && operationCode != 3
			&& operationCode != 0 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки,"
				<< " введите 100." << endl;
			cout << "Введите код операции: ";
			cin >> operationCode;
		}
		switch (operationCode)
		{
			case 1:
			{
				if (stackUnit != nullptr)
				{
					cout << "Ошибка. Стек уже создан." << endl;
					break;
				}
				else
				{
					stackUnit = new Stack;
					cout << "Стек успешно создан." << endl;
					break;
				}
			}
			case 2:
			{
				if (stackUnit == nullptr)
				{
					cout << "Ошибка. Стек не создан." << endl;
					break;
				}
				else
				{
					int valueToPush = ReadIntValueFromConsole("Введите число,"
						" помещаемое в стек: ");
					stackUnit->Push(valueToPush);
					cout << "Число " << valueToPush << " помещено в стек."
						<< endl;
					break;
				}
			}
			case 3:
			{
				if (stackUnit == nullptr)
				{
					cout << "Ошибка. Стек не создан." << endl;
					break;
				}
				else
				{
					if (stackUnit->GetStackLength() > 0)
					{
						cout << "Из стека извлечено число " << stackUnit->Pop()
							<< '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Стек пуст!" << endl;
						break;
					}
				}
			}
			case 0:
			{
				delete stackUnit;
				cout << "Стек успешно удалён." << endl;
				return;
			}
			case 100:
			{
				cout << "Для работы со стеком, используйте следующий список"
					<< " операций:" << endl;
				cout << "\t1 - создание стека;" << endl;
				cout << "\t2 - помещение элемент в стек;" << endl;
				cout << "\t3 - извлечение элемента из стека;" << endl;
				cout << "\t0 - удаление стека и очистка памяти." << endl;
			}
		}
	}
}

void RingBufferMenu()
{
	cout << "Для работы с кольцевым буфером, используйте следующий список"
		<< " операций:" << endl;
	cout << "1 - создать буфер;" << endl;
	cout << "2 - добавить элемент в кольцевой буфер;" << endl;
	cout << "3 - взять элемент из кольцевого буфера;" << endl;
	cout << "4 - вывести на экран свободное место;" << endl;
	cout << "5 - вывести на экран занятое место;" << endl;
	cout << "6 - вывести на экран весь буфер;" << endl;
	cout << "0 - удаление кольцевого буфера и очистка памяти;" << endl;
	int operationCode;
	RingBuffer* ringBufferUnit = nullptr;
	while (true)
	{
		cout << "Введите код операции: ";
		cin >> operationCode;
		switch (operationCode)
		{
			case 1:
			{
				if (!IsNullptr(ringBufferUnit, "Ошибка. Кольцевой буфер уже создан."))
				{
					break;
				}
				else
				{
					int bufferSize = ReadIntValueFromConsole("Введите целое"
						" количество элементов буфера: ");
					while (bufferSize <= 0)
					{
						cout << "Ошибка. Введите положительное число элементов.";
						cin >> bufferSize;
					}
					ringBufferUnit = new RingBuffer(bufferSize);
					cout << "Кольцевой буфер успешно создан." << endl;
					break;
				}
			}
			case 2:
			{
				if (IsNullptr(ringBufferUnit, "Ошибка. Кольцевой буфер не создан."))
				{
					break;
				}
				else
				{
					int valueToPush = ReadIntValueFromConsole("Введите число,"
						" помещаемое в Кольцевой буфер: ");
					ringBufferUnit->Push(valueToPush);
					cout << "Число " << valueToPush << " помещено в кольцевой"
						<< " буфер." << endl;
					break;
				}
			}
			case 3:
			{
				if (IsNullptr(ringBufferUnit, "Ошибка. Кольцевой буфер не создан."))
				{
					break;
				}
				else
				{
					if (ringBufferUnit->GetReservedCells() > 0)
					{
						cout << "Из кольцевого буфера извлечено число "
							<< ringBufferUnit->Pop() << '.' << endl;
						break;
					}
					else
					{
						cout << "Ошибка. Кольцевой буфер пуст!" << endl;
						break;
					}
				}
			}
			case 4:
			{
				cout << "В буфере " << ringBufferUnit->GetEmptyCells()
					<< " свободных ячеек." << endl;
				break;
			}
			case 5:
			{
				cout << "В буфере " << ringBufferUnit->GetReservedCells()
					<< " зарезервированых ячеек." << endl;
				break;
			}
			case 6:
			{	
				if (IsNullptr(ringBufferUnit, "Ошибка. Буфер не создан."))
				{
					break;
				}
				else
				{
					cout << "Буфер содержит сдледующие элементы:" << endl;
					for (int i = 0; i < ringBufferUnit->GetCapacity(); i++)
					{
						cout << ringBufferUnit->GetValue(i);
					}
					break;
				}
			}
			case 0:
			{
				if (IsNullptr(ringBufferUnit, "Кольцевой буфер не существует."))
				{
					delete ringBufferUnit;
					cout << "Кольцевой буфер успешно удалён." << endl;
				}
				return;
			}
			case 100:
			{
				cout << "Для работы с кольцевым буфером, используйте следующий"
					<< " список операций" << endl;
				cout << "1 - создать буфер;" << endl;
				cout << "2 - добавить элемент в кольцевой буфер;" << endl;
				cout << "3 - взять элемент из кольцевого буфера;" << endl;
				cout << "4 - вывести на экран свободное место;" << endl;
				cout << "5 - вывести на экран занятое место;" << endl;
				cout << "0 - удаление кольцевого буфера и очистка памяти;" 
					<< endl;
			}
			default:
			{
				cout << "Введён некорректный код операции. Для вызова справки,"
					<< " введите 100." << endl;
				break;
			}
		}
	}
}

void QueueOnTwoStacksMenu()
{
	cout << "Для работы с очередью на двух стеках, используйте следующий"
		<< " список операций:" << endl;
	cout << "\t1 - создание очереди;" << endl;
	cout << "\t2 - помещение элемента в очередь;" << endl;
	cout << "\t3 - извлечение элемента из очереди;" << endl;
	cout << "\t0 - удаление очереди и очистка памяти;" << endl;
	int operationCode;
	QueueOnTwoStacks* queueOnTwoStacksUnit = nullptr;
	while (true)
	{
		cout << "Введите код операции: ";
		cin >> operationCode;
		while (operationCode != 1 && operationCode != 2 && operationCode != 3
			&& operationCode != 0 && operationCode != 100)
		{
			cout << "Введён некорректный код операции. Для вызова справки,"
				<< " введите 100." << endl;
			cout << "Введите код операции: ";
			cin >> operationCode;
		}
		switch (operationCode)
		{
		case 1:
		{
			if (queueOnTwoStacksUnit != nullptr)
			{
				cout << "Ошибка. Очередь уже создана." << endl;
				break;
			}
			else
			{
				queueOnTwoStacksUnit = new QueueOnTwoStacks;
				cout << "Очередь успешно создана." << endl;
				break;
			}
		}
		case 2:
		{
			if (queueOnTwoStacksUnit == nullptr)
			{
				cout << "Ошибка. Очередь не создана." << endl;
				break;
			}
			else
			{
				int valueToPush = ReadIntValueFromConsole("Введите число,"
					" помещаемое в очередь: ");
				queueOnTwoStacksUnit->Enqueue(valueToPush);
				cout << "Число " << valueToPush << " помещено в очередь."
					<< endl;
				break;
			}
		}
		case 3:
		{
			if (queueOnTwoStacksUnit == nullptr)
			{
				cout << "Ошибка. Очередь не создана." << endl;
				break;
			}
			else
			{
				if (queueOnTwoStacksUnit->GetCountOfNodes() > 0)
				{
					cout << "Из очереди извлечено число "
						<< queueOnTwoStacksUnit->Unqueue() << '.' << endl;
					break;
				}
				else
				{
					cout << "Ошибка. Очередь пуста!" << endl;
					break;
				}
			}
		}
		case 0:
		{
			delete queueOnTwoStacksUnit;
			cout << "Очередь успешно удалена." << endl;
			return;
		}
		case 100:
		{
			cout << "Для работы со стеком, используйте следующий"
				<< " список операций" << endl;
			cout << "\t1 - создание очереди;" << endl;
			cout << "\t2 - помещение элемента в очередь;" << endl;
			cout << "\t3 - извлечение элемента из очереди;" << endl;
			cout << "\t0 - удаление очереди и очистка памяти." << endl;
		}
		}
	}
}

void QueueOnRingBufferMenu()
{

	cout << "Для работы с очередью на кольцевом буфере, используйте"
		<< " следующий список операций:" << endl;
	cout << "\t1 - создание очереди;" << endl;
	cout << "\t2 - помещение элемента в очередь;" << endl;
	cout << "\t3 - извлечение элемента из очереди;" << endl;
	cout << "\t0 - удаление очереди и очистка памяти;" << endl;
	int operationCode;
	QueueOnRingBuffer* queueOnRingBufferUnit = nullptr;
	while (true)
	{
		operationCode = ReadIntValueFromConsole("Введите код операции: ");
		do
		{
			operationCode = ReadIntValueFromConsole("Введён некорректный код операции. "
				"Для вызова справки, введите 100.\nВведите код операции : ");
		} while (operationCode != 1 && operationCode != 2 && operationCode != 3
			&& operationCode != 4 && operationCode != 5 && operationCode != 0
			&& operationCode != 100);
		switch (operationCode)
		{
		case 1:
		{
			if (queueOnRingBufferUnit != nullptr)
			{
				cout << "Ошибка. Очередь уже создана." << endl;
				break;
			}
			else
			{
				int queueCapacity = ReadIntValueFromConsole("Введите размер очереди: ");
				while (queueCapacity <= 0)
				{
					queueCapacity = ReadIntValueFromConsole("Ошибка. Введите"
						" положительное число элементов");
				}
				queueOnRingBufferUnit = new QueueOnRingBuffer(queueCapacity);
				cout << "Очередь успешно создана." << endl;
				break;
			}
		}
		case 2:
		{
			if (queueOnRingBufferUnit == nullptr)
			{
				cout << "Ошибка. Очередь не создана." << endl;
				break;
			}
			else
			{
				if (!queueOnRingBufferUnit->GetEmptyCells())
				{
					cout << "Ошибка. Очередь заполнена!" << endl;
					break;
				}
				if (queueOnRingBufferUnit->GetQueueLength() > 0)
				{
					int valueToPush = ReadIntValueFromConsole("Введите число,"
						" помещаемое в очередь: ");
					queueOnRingBufferUnit->Enqueue(valueToPush);
					cout << "Число " << valueToPush << 
						" помещено в очередь." << endl;
					break;
				}
				int valueToPush = ReadIntValueFromConsole("Введите число, помещаемое в очередь: ");
				queueOnRingBufferUnit->Enqueue(valueToPush);
				cout << "Число " << valueToPush << " помещено в очередь."
					<< endl;
				break;
			}
		}
		case 3:
		{
			if (queueOnRingBufferUnit == nullptr)
			{
				cout << "Ошибка. Очередь не создана." << endl;
				break;
			}
			else
			{
				if (queueOnRingBufferUnit->GetQueueLength() > 0)
				{
					cout << "Из очереди извлечено число "
						<< queueOnRingBufferUnit->Unqueue() << '.' << endl;
					break;
				}
				else
				{
					cout << "Ошибка. Очередь пуста!" << endl;
					break;
				}
			}
		}
		case 0:
		{
			if (!IsNullptr(queueOnRingBufferUnit))
			{
				delete queueOnRingBufferUnit;
				cout << "Очередь успешно удалена." << endl;
			}
			return;
		}
		case 100:
		{
			cout << "Для работы с очередью, используйте следующий"
				<< " список операций" << endl;
			cout << "\t1 - создание очереди;" << endl;
			cout << "\t2 - помещение элемента в очередь;" << endl;
			cout << "\t3 - извлечение элемента из очереди;" << endl;
			cout << "\t0 - удаление очереди и очистка памяти." << endl;
		}
		}
	}
}

int ReadIntValueFromConsole(string messageToPrint)
{
	cout << messageToPrint;
	int userValue;
	cin >> userValue;
	return userValue;
}

template<typename T>
bool IsNullptr(T* unit, string message = "")
{
	if (unit == nullptr)
	{
		cout << message;
		return false;
	}
	else
	{
		return true;
	}
}
