#pragma once

struct DynamicArray
{
	int countOfEmptySlots = 4;
	int currentArrayLength = 4;
	int* internalArray = new int[currentArrayLength];

	void InitializeArrayByInputStream();

	void AddElement();

	void DeleteElement();

	void PushFront();

	void PushBack();

	int PushAfterElement(int valueToPush, int indexToPush);

	void BubbleSort();

	int LinearSearch(int value);

	int BinarySearch(int searchValue);

	void DeleteArray();

	void FillRandom();
};