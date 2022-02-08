#include "QueueOnTwoStacks.h"

void QueueOnTwoStacks::Enqueue(int valueToPush)
{
	_inputStack->Push(valueToPush);
	_countOfNodes++;
}

int QueueOnTwoStacks::Unqueue()
{

	while (_inputStack->GetStackLength() != 0)
	{
		_outputStack->Push(_inputStack->Pop());
	}
	int valueToPop = _outputStack->Pop();
	while (_outputStack->GetStackLength() != 0)
	{
		_inputStack->Push(_outputStack->Pop());
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
	_inputStack = new Stack;
	_outputStack = new Stack;
	_countOfNodes = 0;
}

QueueOnTwoStacks::~QueueOnTwoStacks()
{
	delete _inputStack;
	delete _outputStack;
}
