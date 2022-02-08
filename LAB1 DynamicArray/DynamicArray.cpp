#include <iostream>
#include "DynamicArray.h"

using namespace std;

void FillRandom(DynamicArray* dynamicArray)
{
	srand(time(NULL));
	for (int i = 0; i < dynamicArray->currentArrayLength; i++)
	{
		dynamicArray->internalArray[i] = rand() % 100;
	}
}

void DynamicArray::InitializeArrayByInputStream()
{
	for (int i = 0; i < currentArrayLength; i++)
	{
		cin >> internalArray[i];
	}
	countOfEmptySlots = 0;
}

void DynamicArray::AddElement()
{
	int* newArray = new int[currentArrayLength + 1];
	for (int i = 0; i < currentArrayLength; i++)
	{
		newArray[i] = internalArray[i];
	}
	delete[] internalArray;
	internalArray = newArray;
	newArray = nullptr;
	currentArrayLength++;
	countOfEmptySlots++;
}

void DynamicArray::DeleteElement()
{
	int* arrNew = new int[currentArrayLength - 1];
	for (int i = 0; i < currentArrayLength - 1; i++)
	{
		arrNew[i] = internalArray[i];
	}
	delete[] internalArray;
	internalArray = arrNew;
	arrNew = nullptr;
	currentArrayLength--;
	countOfEmptySlots--;
}

void DynamicArray::PushFront()
{
	int valueToPush;
	cin >> valueToPush;
	cout << endl;
	while (countOfEmptySlots < 1)
	{
		AddElement();
	}
	for (int i = currentArrayLength - 1; i > 0; i--)
	{
		internalArray[i] = internalArray[i - 1];
	}
	internalArray[0] = valueToPush;
	countOfEmptySlots--;
}

void DynamicArray::PushBack()
{
	int valueToPush;
	cin >> valueToPush;
	cout << endl;
	while (countOfEmptySlots < 1)
	{
		AddElement();
	}
	internalArray[currentArrayLength - 1] = valueToPush;
	countOfEmptySlots--;
}

int DynamicArray::PushAfterElement(int valueToPush, int indexToPush)
{
	if (indexToPush < 0 || indexToPush >= currentArrayLength)
	{
		return 1;
	}
	if (indexToPush == 0)
	{
		PushFront();
		return 0;
	}
	if (indexToPush == currentArrayLength - 1)
	{
		PushBack();
		return 0;
	}
	while (countOfEmptySlots < 1)
	{
		AddElement();
	}
	for (int i = currentArrayLength - 1; i > indexToPush; i--)
	{
		internalArray[i] = internalArray[i - 1];
	}
	internalArray[indexToPush] = valueToPush;
	countOfEmptySlots--;
	return 0;
}

void DynamicArray::BubbleSort()
{
	int tmp;
	for (int i = 0; i < currentArrayLength - 1; i++)
	{
		for (int j = i + 1; j < currentArrayLength; j++)
		{
			if (internalArray[i] > internalArray[j])
			{
				tmp = internalArray[j];
				internalArray[j] = internalArray[i];
				internalArray[i] = tmp;
			}
		}
	}
}

int DynamicArray::LinearSearch(int value)
{
	for (int i = 0; i < currentArrayLength; i++)
	{
		if (internalArray[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int DynamicArray::BinarySearch(int searchValue)
{
	int indexLeftBoundary = 0;
	int indexRightBoundary = currentArrayLength - 1;
	while (indexLeftBoundary <= indexRightBoundary)
	{
		int indexMidValue = (indexLeftBoundary + indexRightBoundary) / 2;
		if (internalArray[indexMidValue] == searchValue)
		{
			return indexMidValue;
		}
		else if (searchValue > internalArray[indexMidValue])
		{
			indexLeftBoundary = indexMidValue + 1;
		}
		else
		{
			indexRightBoundary = indexMidValue - 1;
		}
	}
	return -1;
}

void DynamicArray::DeleteArray()
{
	delete[] internalArray;
}

void DynamicArray::FillRandom()
{
	srand(time(NULL));
	for (int i = 0; i < currentArrayLength; i++)
	{
		internalArray[i] = rand() % 100;
	}
}
