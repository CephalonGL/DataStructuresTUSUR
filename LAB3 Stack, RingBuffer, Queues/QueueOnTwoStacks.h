#pragma once
#include "Stack.h"

/// <summary>
/// Queue on two stacks data structure
/// </summary>
class QueueOnTwoStacks
{
	/// <summary>
	/// Stack for user input
	/// </summary>
	Stack* _inputStack;

	/// <summary>
	/// Stack for user output
	/// </summary>
	Stack* _outputStack;

	/// <summary>
	/// Counter of nodes in each stack
	/// </summary>
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

	/// <summary>
	/// Allocates memory from heap for _inputStack and _outputStack.
	/// Set _countOfNodes to 0
	/// </summary>
	QueueOnTwoStacks();

	/// <summary>
	/// Delete _inputStack and _outputStack from heap
	/// </summary>
	~QueueOnTwoStacks();
};

