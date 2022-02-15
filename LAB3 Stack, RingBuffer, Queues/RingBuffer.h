#pragma once

/// <summary>
/// Ring buffer data structure based on dynamic array
/// </summary>
class RingBuffer
{
	/// <summary>
	/// Capacity of ring buffer
	/// </summary>
	int _capacity;

	/// <summary>
	/// Counter of empty cells in ring buffer
	/// </summary>
	int _emptyCells;

	/// <summary>
	/// Array index to write new elements to
	/// </summary>
	int _indexToWrite;

	/// <summary>
	/// Array index of element to read from
	/// </summary>
	int _indexToRead;

	/// <summary>
	/// Pointer to array of ring buffer
	/// </summary>
	int* _valueArray;

	/// <summary>
	/// Initialization flag
	/// </summary>
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

	/// <summary>
	/// Set base capacity of ring buffer and allocate memory from 
	/// heap for array
	/// </summary>
	/// <param name="capacityOfBuffer">Capacity of ring buffer to set</param>
	RingBuffer(int capacityOfBuffer);

	/// <summary>
	/// Delete array of values of ring buffer and clear memory
	/// </summary>
	~RingBuffer();
};