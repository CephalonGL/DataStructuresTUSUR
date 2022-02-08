#include "QueueOnRingBuffer.h"
#include "RingBuffer.h"

QueueOnRingBuffer::QueueOnRingBuffer(int bufferCapacity)
{
	_ringBuffer = new RingBuffer(bufferCapacity);
}

QueueOnRingBuffer::~QueueOnRingBuffer()
{
	delete _ringBuffer;
}

int QueueOnRingBuffer::GetEmptyCells()
{
	return _ringBuffer->GetEmptyCells();
}

void QueueOnRingBuffer::Enqueue(int valueToPush)
{
	_ringBuffer->Push(valueToPush);
}

int QueueOnRingBuffer::Unqueue()
{
	return _ringBuffer->Pop();
}

int QueueOnRingBuffer::GetQueueLength()
{
	return _ringBuffer->GetReservedCells();
}
