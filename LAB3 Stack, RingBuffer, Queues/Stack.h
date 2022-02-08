#pragma once
#include "StackNode.h"

class Stack
{
	StackNode* _topElement;
	StackNode* _bufferOfPointers;
	int _stackLength;
public:
	Stack();
	~Stack();
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
};