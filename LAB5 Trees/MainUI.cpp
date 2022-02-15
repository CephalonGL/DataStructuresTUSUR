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
		Stop = 0
	};
	setlocale(LC_ALL, "ru");
	cout << "Вас приветствует программа для работы с деревьями." << endl;
	cout << "Выберите вид дерева, с которым хотите работать:" << endl;
	cout << "\t1. Бинарное дерево;" << endl;
	cout << "\t2. Декартово дерево." << endl;
	cout << "Введите код операции: ";
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
		case Stop:
		{
			cout << "Программа успешно завершила своё выполнение." << endl;
			return 0;
		}
		default:
			cout << "Команда не распознана. Повторите ввод: ";
			break;
		}
	}
}

void BinaryTreeUI()
{
	enum BinaryTreeUI
	{
		Stop = 0,
		CREATE_TREE = 1,
		ADD_ELEMENT = 2,
		DELETE_ELEMENT = 3,
		FIND_ELEMENT = 4,
		FIND_MAX = 5,
		FIND_MIN = 6,
		PRINT = 7,
		Help = 100
	};
	cout << "Для работы с бинарным деревом, используйте "
		<< "следующий список команд" << endl;
	cout << "\t1. Создать дерево;" << endl;
	cout << "\t2. Добавить элемент;" << endl;
	cout << "\t3. Удалить элемент;" << endl;
	cout << "\t4. Найти элемент;" << endl;
	cout << "\t5. Найти максимум дерева;" << endl;
	cout << "\t6. Найти минимум дерева;" << endl;
	cout << "\t7. Вывести дерево на экран." << endl;
	cout << "Для завершения работы программы, введите 0" << endl;
	int operationCode;
	BinaryTree binaryTree;
	while (true)
	{
		cout << "Введите код операции:";
		cin >> operationCode;
		switch (operationCode)
		{
		case CREATE_TREE:
		{
			try
			{
				int key;
				cout << "Введите ключ корневого узла: ";
				cin >> key;
				int value;
				cout << "Введите значение корневого узла: ";
				cin >> value;
				binaryTree.CreateTree(key, value);
				cout << "Дерево успешно создано." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case ADD_ELEMENT:
		{
			try
			{
				if (binaryTree.RootNode == nullptr)
				{
					string error = "Корневой узел был равен nullptr, создайте дерево.";
					throw error;
				}
				int key;
				cout << "Введите ключ корневого узла: ";
				cin >> key;
				int value;
				cout << "Введите значение корневого узла: ";
				cin >> value;
				binaryTree.AddElement(binaryTree.RootNode, key, value);
				cout << "Элемент успешно добавлен." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case DELETE_ELEMENT:
		{
			try
			{
				int key;
				cout << "Введите ключ корневого узла: ";
				cin >> key;
				binaryTree.DeleteElement(binaryTree.RootNode, key);
				cout << "Элемент успешно удалён." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case FIND_ELEMENT:
		{
			try
			{
				int key;
				cout << "Введите ключ искомого узла: ";
				cin >> key;
				cout << "По ключу " << key << " находится значение "
					<< binaryTree.FindElement(binaryTree.RootNode, key)->Value << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case FIND_MAX:
		{
			try
			{
				cout << "Максимальное значение дерева: "
					<< binaryTree.FindMax(binaryTree.RootNode)->Value << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case FIND_MIN:
		{
			try
			{
				cout << "Минимальное значение дерева: "
					<< binaryTree.FindMin(binaryTree.RootNode)->Value << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
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
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case Help:
		{
			cout << "Список команд:" << endl;
			cout << "\t1. Создать дерево;" << endl;
			cout << "\t2. Добавить элемент;" << endl;
			cout << "\t3. Удалить элемент;" << endl;
			cout << "\t4. Найти элемент;" << endl;
			cout << "\t5. Найти максимум дерева;" << endl;
			cout << "\t6. Найти минимум дерева" << endl;
			cout << "\t7. Вывести дерево на экран." << endl;
			cout << "Для завершения работы программы, введите 0" << endl;
			break;
		}
		case Stop:
		{
			cout << "Программа успешно завершила свою работу." << endl;
			return;
		}
		default:
			cout << "Команда не распознана. "
				<< "Для вызова справки, введите 100." << endl;
			break;
		}
	}
}

void CartesianTreeUI()
{
	srand(time(NULL));
	enum CartesianTreeUI
	{
		Stop = 0,
		FIND_ELEMENT = 1,
		INSERT_NON_OPTIMIZED = 2,
		INSERT_OPTIMIZED = 3,
		PRINT = 4,
		DELETE_NON_OPTIMIZED = 5,
		DELETE_OPTIMIZED = 6,
		DELETE_AND_CLEAR_MEMORY = 7,
		FILL_RANDOM = 8,
		SPLIT_AND_PRINT = 9,
		Help = 100
	};
	cout << "Для работы с Декартовым деревом, используйте "
		<< "следующий список команд" << endl;
	cout << "\t1. Найти элемент;" << endl;
	cout << "\t2. Добавление(неоптимизированный, 1 Split, 2 Merge);" << endl;
	cout << "\t3. Добавление(оптимизированный, 1 Split);" << endl;
	cout << "\t4. Вывести дерево на экран;" << endl;
	cout << "\t5. Удаление(неоптимизированный, 2 Split, 1 Merge);" << endl;
	cout << "\t6. Удаление(оптимизированный, 1 Merge);" << endl;
	cout << "\t7. Удаление элемента дерева с очисткой памяти;" << endl;
	cout << "\t8. Случайное заполнение дерева(10 элементов);" << endl;
	cout << "\t9. Разрезать по ключу и вывести поддеревья;" << endl;
	cout << "Для завершения работы программы, введите 0" << endl;
	int operationCode;
	CartesianTree* cartesianTree = new CartesianTree;
	while (true)
	{
		cout << "Введите код операции:";
		cin >> operationCode;
		switch (operationCode)
		{
		case FIND_ELEMENT:
		{
			try
			{
				cout << "Введите ключ для поиска: " << endl;
				int key;
				cin >> key;
				cout << "Элемент по данному ключу: " << endl;
				cout << '('
					<< cartesianTree->FindElement(cartesianTree->RootNode, key)->Key
					<< '; '
					<< cartesianTree->FindElement(cartesianTree->RootNode, key)->Priority
					<< ')';
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case INSERT_NON_OPTIMIZED:
		{
			try
			{
				cout << "Введите ключ для вставки: " << endl;
				int key;
				cin >> key;
				cartesianTree = cartesianTree->UnoptimizedInsert(cartesianTree->RootNode,
					key);
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case INSERT_OPTIMIZED:
		{
			try
			{
				cout << "Введите ключ для вставки: " << endl;
				int key;
				cin >> key;
				int priority = rand() % 100 + 1;
				cartesianTree->RootNode =
					cartesianTree->OptimizedInsert(cartesianTree->RootNode, key, priority);
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
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
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case DELETE_NON_OPTIMIZED:
		{
			try
			{
				int key;
				cout << "Введите ключ удаляемого узла: ";
				cin >> key;
				cartesianTree->UnoptimizedDelete(cartesianTree->RootNode, key);
				cout << "Неоптимизированное удаление завершено." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case DELETE_OPTIMIZED:
		{
			try
			{
				int key;
				cout << "Введите ключ удаляемого узла: ";
				cin >> key;
				cartesianTree->RootNode =
					cartesianTree->OptimizedDelete(cartesianTree->RootNode, key);
				cout << "Оптимизированное удаление завершено." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case DELETE_AND_CLEAR_MEMORY:
		{
			try
			{
				cartesianTree->ClearDelete(cartesianTree->RootNode);
				cout << "Очистка памяти успешно завершена." << endl;
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
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
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case SPLIT_AND_PRINT:
		{
			try
			{
				cout << "Введите ключ, по которому хотите разрезать: ";
				int key;
				cin >> key;
				CartesianTreeNode* leftTree;
				CartesianTreeNode* rightTree;
				cartesianTree->Split(cartesianTree->RootNode, key, leftTree, rightTree);
				cout << "__________________________________________________" << endl;
				cout << "Левое поддерево имеет вид:" << endl << endl;
				PrintCartesianTree(leftTree);
				cout << "__________________________________________________" << endl;
				cout << "Правое поддерево имеет вид:" << endl << endl;
				PrintCartesianTree(rightTree);
				cout << "__________________________________________________" << endl;
				cartesianTree->Merge(leftTree, rightTree);
			}
			catch (string& message)
			{
				cout << "Ошибка! " << message << endl;
			}
			break;
		}
		case Help:
		{
			cout << "Список команд:" << endl;
			cout << "\t1. Найти элемент;" << endl;
			cout << "\t2. Добавление(неоптимизированный, 1 Split, 2 Merge);" << endl;
			cout << "\t3. Добавление(оптимизированный, 1 Split);" << endl;
			cout << "\t4. Вывести дерево на экран;" << endl;
			cout << "\t5. Удаление(неоптимизированный, 2 Split, 1 Merge);" << endl;
			cout << "\t6. Удаление(оптимизированный, 1 Merge);" << endl;
			cout << "\t7. Удаление элемента дерева с очисткой памяти;" << endl;
			cout << "Для завершения работы программы, введите 0" << endl;
			break;
		}
		case Stop:
		{
			cout << "Программа успешно завершила свою работу." << endl;
			return;
		}
		default:
			cout << "Команда не распознана. "
				<< "Для вызова справки, введите 100." << endl;
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
