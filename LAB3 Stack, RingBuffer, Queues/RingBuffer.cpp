#include "RingBuffer.h"

//bool RingBuffer::IsInitialized()
//{
//	return _isInitialized;
//}

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

RingBuffer::RingBuffer(int lengthOfBuffer)
{
	_capacity = _emptyCells = lengthOfBuffer;
	_indexToRead = 0;
	_indexToWrite = 0;
	_valueArray = new int[_capacity] {};
	/*_isInitialized = false;*/
}

RingBuffer::~RingBuffer()
{
	delete[] _valueArray;
}