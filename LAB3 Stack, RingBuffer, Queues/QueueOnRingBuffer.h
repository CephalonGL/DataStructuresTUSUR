#pragma once
#include "RingBuffer.h"

/// <summary>
/// Queue data structure based on ring buffer
/// </summary>
class QueueOnRingBuffer
{
	/// <summary>
	/// Pointer on RingBuffet unit
	/// </summary>
	RingBuffer* _ringBuffer;

	/// <summary>
	/// Capacity of array of queue
	/// </summary>
	int _queueCapacity;

	/// <summary>
	/// Current length of queue
	/// </summary>
	int _queueLength;

public:

	/// <summary>
	/// Creates RingBuffer with bufferCapacity from heap
	/// </summary>
	/// <param name="bufferCapacity">Capacity to set</param>
	QueueOnRingBuffer(int bufferCapacity);

	/// <summary>
	/// Delete array of ring buffer and clear memory
	/// </summary>
	~QueueOnRingBuffer();

	/// <summary>
	/// Get count of empty cells
	/// </summary>
	/// <returns>Count of empty cells</returns>
	int GetEmptyCells();

	/// <summary>
	/// Push value into queue
	/// </summary>
	/// <param name="valueToPush">Value to push</param>
	void Enqueue(int valueToPush);

	/// <summary>
	/// Pop value from queue
	/// </summary>
	/// <returns>Value from queue</returns>
	int Unqueue();

	/// <summary>
	/// Get length of queue
	/// </summary>
	/// <returns>Length of queue</returns>
	int GetQueueLength();
};