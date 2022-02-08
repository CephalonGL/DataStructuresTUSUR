#include "QueueOnTwoStacks.h"

void QueueOnTwoStacks::Enqueue(int valueToPush)
{
	_iStack->Push(valueToPush);
	_countOfNodes++;
}

int QueueOnTwoStacks::Unqueue()
{

	while (_iStack->GetStackLength() != 0)
	{
		_oStack->Push(_iStack->Pop());
	}
	int valueToPop = _oStack->Pop();
	while (_oStack->GetStackLength() != 0)
	{
		_iStack->Push(_oStack->Pop());
	}
	_countOfNodes--;
	return valueToPop;
}

int QueueOnTwoStacks::GetCountOfNodes()
{
	return _countOfNodes;
}

QueueOnTwoStacks::QueueOnTwoStacks()
{
	_iStack = new Stack;
	_oStack = new Stack;
	_countOfNodes = 0;
}

QueueOnTwoStacks::~QueueOnTwoStacks()
{
	delete _iStack;
	delete _oStack;
}
