#include "List.h"

int List::GetLength()
{
	return _length;
}

void List::CreateList(int countOfNodes, int arrayOfValuesToInitialize[])
{
	for (int i = 0; i < countOfNodes; i++)
	{
		AddNewNode(arrayOfValuesToInitialize[i]);
	}
}

void List::AddNewNode(int valueToPush)
{
	if (_head == nullptr && _tail == nullptr)
	{
		_head = _tail = new Node;
	}
	else if (_head->Next == nullptr)
	{
		_tail = new Node;
		_head->Next = _tail;
		_tail->Previous = _head;
	}
	else
	{
		_tail->Next = new Node;
		_tail->Next->Previous = _tail;
		_tail = _tail->Next;
	}
	_tail->Value = valueToPush;
	_length++;
}

void List::RemoveNode(int indexOfRemovableNode)
{
	if (_head == _tail)
	{
		delete _head;
	}
	else if (indexOfRemovableNode == 0)
	{
		Node* currentNode = _head;
		currentNode->Next->Previous = nullptr;
		_head = currentNode->Next;
		delete currentNode;
	}
	else if (indexOfRemovableNode == _length - 1)
	{
		Node* currentNode = _tail;
		currentNode->Previous->Next = nullptr;
		_tail = currentNode->Previous;
		delete currentNode;
	}
	else if (indexOfRemovableNode < _length - 1)
	{
		Node* currentNode = _head;
		for (int i = 0; i < indexOfRemovableNode; i++)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Next->Previous = currentNode->Previous;
		currentNode->Previous->Next = currentNode->Next;
		delete currentNode;
	}
	else
	{
		Node* currentNode = _tail;
		for (int i = 0; i < _length - indexOfRemovableNode; i++)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Next->Previous = currentNode->Previous;
		currentNode->Previous->Next = currentNode->Next;
		delete currentNode;
	}
	_length--;
}

void List::PushForward(int valueToPush)
{
	if (_length == 0)
	{
		AddNewNode(valueToPush);
		return;
	}
	_head->Previous = new Node;
	_head->Previous->Next = _head;
	_head = _head->Previous;
	_head->Value = valueToPush;
	_length++;
}

void List::PushBack(int valueToPush)
{
	AddNewNode(valueToPush);
}

void List::PushAfterNode(int indexNodeToPushAfter, int valueToPush)
{
	if (indexNodeToPushAfter == _length - 1)
	{
		PushBack(valueToPush);
	}
	else
	{
		Node* currentNode = _head;
		for (int i = 0; i < indexNodeToPushAfter; i++)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Next->Previous = new Node;
		currentNode->Next->Previous->Previous = currentNode;
		currentNode->Next->Previous->Next = currentNode->Next;
		currentNode->Next = currentNode->Next->Previous;
		currentNode->Next->Value = valueToPush;
		_length++;
	}
}

void List::PushBeforeNode(int indexNodeToPushBefore, int valueToPush)
{
	if (indexNodeToPushBefore == 0)
	{
		PushForward(valueToPush);
	}
	else
	{
		Node* currentNode = _head;
		for (int i = 0; i < indexNodeToPushBefore; i++)
		{
			currentNode = currentNode->Next;
		}
		currentNode->Previous->Next = new Node;
		currentNode->Previous->Next->Next = currentNode;
		currentNode->Previous->Next->Previous = currentNode->Previous;
		currentNode->Previous = currentNode->Previous->Next;
		currentNode->Previous->Value = valueToPush;
		_length++;
	}
}

void List::Sort()
{
	Node* currentNode = _head;
	for (int i = 0; i < _length-1; i++)
	{
		for (int j = 0; j < _length-1; j++)
		{
			//TODO:
			int tmp;
			if (currentNode->Value > currentNode->Next->Value)
			{
				tmp = currentNode->Value;
				currentNode->Value = currentNode->Next->Value;
				currentNode->Next->Value = tmp;
			}
			else
			{
				currentNode = currentNode->Next;
			}
		}
		currentNode = _head;
	}
}

int List::LinearSearch(int valueToSearch)
{
	Node* currentNode = _head;
	for (int i = 0; i < _length; i++)
	{
		if (currentNode->Value == valueToSearch)
		{
			return i;
		}
		else
		{
			currentNode = currentNode->Next;
		}
	}
	return -1;
}

int List::GetValueByIndex(int indexOfNode)
{
	Node* currentNode = _head;
	for (int i = 0; i < indexOfNode; i++)
	{
		currentNode = currentNode->Next;
	}
	return currentNode->Value;
}
