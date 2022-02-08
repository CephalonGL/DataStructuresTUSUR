#pragma once
#include "RingBuffer.h"

class QueueOnRingBuffer
{
	RingBuffer* _ringBuffer;
	int _queueCapacity;
	int _queueLength;

public:
	QueueOnRingBuffer(int bufferCapacity);
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