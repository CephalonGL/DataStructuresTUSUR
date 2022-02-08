#pragma once

class RingBuffer
{
	int _capacity;
	int _emptyCells;
	int _indexToWrite;
	int _indexToRead;
	int* _valueArray;
	bool _isInitialized;
public:
	/// <summary>
	/// Get capacity of ring buffer
	/// </summary>
	/// <returns>Capacity of ring buffer</returns>
	int GetCapacity();
	/// <summary>
	/// Get value from array by index
	/// </summary>
	/// <param name="i">Index of element to get</param>
	/// <returns>Value by index</returns>
	int GetValue(int i);
	/// <summary>
	/// Push value into ring buffer
	/// </summary>
	/// <param name="valueToPush">Value to push</param>
	void Push(int valueToPush);
	/// <summary>
	/// Pop value from ring buffer
	/// </summary>
	/// <returns>Value</returns>
	int Pop();
	/// <summary>
	/// Get count of empty cells in ring buffer
	/// </summary>
	/// <returns>Count of empty cells</returns>
	int GetEmptyCells();
	/// <summary>
	/// Get count of reserved cells in ring buffer
	/// </summary>
	/// <returns>Count of reserved cells</returns>
	int GetReservedCells();
	RingBuffer(int capacityOfBuffer);
	~RingBuffer();
};