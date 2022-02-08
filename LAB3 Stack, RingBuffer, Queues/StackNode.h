#pragma once
class StackNode
{
	int _value;
	StackNode* _previousElement;
public:
	StackNode();
	~StackNode();
	/// <summary>
	/// Set node value
	/// </summary>
	/// <param name="value">Value to set</param>
	void SetValue(int value);
	/// <summary>
	/// Get value from node
	/// </summary>
	/// <returns>Value of node</returns>
	int GetValue();
	/// <summary>
	/// Set previous node pointer
	/// </summary>
	/// <param name="adressToSet">Pointer to set</param>
	void SetPointerOfPreviousElement(StackNode* adressToSet);
	/// <summary>
	/// Get previous node pointer
	/// </summary>
	/// <returns>Pointer of previous node</returns>
	StackNode* GetPointerOfPreviousElement();
};

