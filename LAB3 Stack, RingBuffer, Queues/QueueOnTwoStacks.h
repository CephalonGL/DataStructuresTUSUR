#pragma once
#include "Stack.h"

class QueueOnTwoStacks
{
	Stack* _iStack;
	Stack* _oStack;
	int _countOfNodes;

public:
	/// <summary>
	/// Push new value into queue
	/// </summary>
	/// <param name="valueToPush">Value to push into queue</param>
	void Enqueue(int valueToPush);
	/// <summary>
	/// Pop value from queue
	/// </summary>
	/// <returns>Value from queue</returns>
	int Unqueue();
	/// <summary>
	/// Get length of queue
	/// </summary>
	/// <returns>Count of nodes in one stack</returns>
	int GetCountOfNodes();
	QueueOnTwoStacks();
	~QueueOnTwoStacks();
};

