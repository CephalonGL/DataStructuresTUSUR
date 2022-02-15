#include "RingBuffer.h"

int RingBuffer::GetCapacity()
{
	return _capacity;
}

int RingBuffer::GetValue(int i)
{
	return _valueArray[i];
}

void RingBuffer::Push(int valueToPush)
{
	_valueArray[_indexToWrite] = valueToPush;
	if (_indexToWrite == _capacity - 1)
	{
		_indexToWrite = 0;
	}
	else
	{
		_indexToWrite++;
	}
	_emptyCells--;
}

int RingBuffer::Pop()
{
	int valueToPop = _valueArray[_indexToRead];
	if (_indexToRead == _capacity - 1)
	{
		_indexToRead = 0;
	}
	else
	{
		_indexToRead++;
	}
	_emptyCells++;
	return valueToPop;
}

int RingBuffer::GetEmptyCells()
{
	return _emptyCells;
}

int RingBuffer::GetReservedCells()
{
	return _capacity - _emptyCells;
}

RingBuffer::RingBuffer(int capacityOfBuffer)
{
	_capacity = _emptyCells = capacityOfBuffer;
	_indexToRead = 0;
	_indexToWrite = 0;
	_valueArray = new int[_capacity] {};
}

RingBuffer::~RingBuffer()
{
	delete[] _valueArray;
}