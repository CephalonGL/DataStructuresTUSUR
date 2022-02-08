#pragma once
#include "StackNode.h"


/// <summary>
/// Stack data structure
/// </summary>
class Stack
{
	/// <summary>
	/// Pointer to top node of stack
	/// </summary>
	StackNode* _topElement = nullptr;
	/// <summary>
	/// Buffer pointer for internal operations
	/// </summary>
	StackNode* _bufferOfPointers = nullptr;
	/// <summary>
	/// Counter of nodes in stack
	/// </summary>
	int _stackLength = 0;

public:
	/// <summary>
	/// Push value into stack
	/// </summary>
	/// <param name="valueToPush">Value to push</param>
	void Push(int valueToPush);

	/// <summary>
	/// Pop value from stack
	/// </summary>
	/// <returns>Value to pop</returns>
	int Pop();

	/// <summary>
	/// Get length of stack
	/// </summary>
	/// <returns>Length of stack</returns>
	int GetStackLength();

	/// <summary>
	/// Delete every element in stack and clear memory
	/// </summary>
	~Stack();
};