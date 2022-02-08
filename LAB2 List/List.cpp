#include "List.h"

List::List()
{
	_length = 0;
	_head = nullptr;
	_tail = nullptr;
}

List::~List()
{
}

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
		Node* pCurrentNode = _head;
		pCurrentNode->Next->Previous = nullptr;
		_head = pCurrentNode->Next;
		delete pCurrentNode;
	}
	else if (indexOfRemovableNode == _length - 1)
	{
		Node* pCurrentNode = _tail;
		pCurrentNode->Previous->Next = nullptr;
		_tail = pCurrentNode->Previous;
		delete pCurrentNode;
	}
	else if (indexOfRemovableNode < _length - 1)
	{
		Node* pCurrentNode = _head;
		for (int i = 0; i < indexOfRemovableNode; i++)
		{
			pCurrentNode = pCurrentNode->Next;
		}
		pCurrentNode->Next->Previous = pCurrentNode->Previous;
		pCurrentNode->Previous->Next = pCurrentNode->Next;
		delete pCurrentNode;
	}
	else
	{
		Node* pCurrentNode = _tail;
		for (int i = 0; i < _length - indexOfRemovableNode; i++)
		{
			pCurrentNode = pCurrentNode->Next;
		}
		pCurrentNode->Next->Previous = pCurrentNode->Previous;
		pCurrentNode->Previous->Next = pCurrentNode->Next;
		delete pCurrentNode;
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
		Node* pCurrentNode = _head;
		for (int i = 0; i < indexNodeToPushAfter; i++)
		{
			pCurrentNode = pCurrentNode->Next;
		}
		pCurrentNode->Next->Previous = new Node;
		pCurrentNode->Next->Previous->Previous = pCurrentNode;
		pCurrentNode->Next->Previous->Next = pCurrentNode->Next;
		pCurrentNode->Next = pCurrentNode->Next->Previous;
		pCurrentNode->Next->Value = valueToPush;
		_length++;
	}
	else
	{
		Node* pCurrentNode = pTail;
		for (int i = 0; i < Length - indexNodeToPushAfter; i++)
		{
			pCurrentNode = pCurrentNode->Previous;
		}
		pCurrentNode->Next->Previous = new Node;
		pCurrentNode->Next = pCurrentNode->Next->Previous;
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
		Node* pCurrentNode = _head;
		for (int i = 0; i < indexNodeToPushBefore; i++)
		{
			pCurrentNode = pCurrentNode->Next;
		}
		pCurrentNode->Previous->Next = new Node;
		pCurrentNode->Previous->Next->Next = pCurrentNode;
		pCurrentNode->Previous->Next->Previous = pCurrentNode->Previous;
		pCurrentNode->Previous = pCurrentNode->Previous->Next;
		pCurrentNode->Previous->Value = valueToPush;
		_length++;
	}
	else
	{
		Node* pCurrentNode = pTail;
		for (int i = 0; i < Length - indexNodeToPushBefore; i++)
		{
			pCurrentNode = pCurrentNode->Previous;
		}
		pCurrentNode->Next->Previous = new Node;
		pCurrentNode->Next = pCurrentNode->Next->Previous;
		pCurrentNode->Value = valueToPush;
		Length++;
	}
}

void List::Sort()
{
	Node* pCurrentNode = _head;
	int tmp;
	for (int i = 0; i < _length-1; i++)
	{
		for (int j = 0; j < _length-1; j++)
		{
			if (pCurrentNode->Value > pCurrentNode->Next->Value)
			{
				tmp = pCurrentNode->Value;
				pCurrentNode->Value = pCurrentNode->Next->Value;
				pCurrentNode->Next->Value = tmp;
			}
			else
			{
				pCurrentNode = pCurrentNode->Next;
			}
		}
		pCurrentNode = _head;
	}
}

int List::LinearSearch(int valueToSearch)
{
	Node* pCurrentNode = _head;
	for (int i = 0; i < _length; i++)
	{
		if (pCurrentNode->Value == valueToSearch)
		{
			return i;
		}
		else
		{
			pCurrentNode = pCurrentNode->Next;
		}
	}
	return -1;
}

int List::GetValueByIndex(int indexOfNode)
{
	Node* pCurrentNode = _head;
	for (int i = 0; i < indexOfNode; i++)
	{
		pCurrentNode = pCurrentNode->Next;
	}
	return pCurrentNode->Value;
}


Node::Node()
{
	Value = 0;
	Next = nullptr;
	Previous = nullptr;
}

Node::~Node()
{
}
