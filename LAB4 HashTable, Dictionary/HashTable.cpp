#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

int HashTable::GetCapacity()
{
	return _capacity;
}

void HashTable::HashTableInsert(string key, string value)
{
	Rehash();
	int hash = Hash(key);
	HashTableNode* currentNode = &HashTableNodeArray[hash];
	if (currentNode->Key == "")
	{
		currentNode->Key = key;
		currentNode->Value = value;
		_length++;
	}
	else
	{
		while (currentNode->NextCollision != nullptr)
		{
			if (currentNode->Key == key)
			{
				if (currentNode->Value == value)
				{
					//TODO: encoding
					string error = "Ошибка! Дубликат key-value";
					throw error;
				}
				else
				{
					//TODO: encoding
					string error = "Ошибка! Обнаружено свопадение key-key. "
						"По данному ключу записано значение: ";
					error.append(currentNode->Value);
					throw error;
				}
			}
			else
			{
				currentNode = currentNode->NextCollision;
			}
		}
		currentNode->NextCollision = new HashTableNode;
		currentNode->NextCollision->Key = key;
		currentNode->NextCollision->Value = value;
	}
}
using namespace std;

void HashTable::Remove(string key)
{
	HashTableNode* currentNode = &HashTableNodeArray[Hash(key)];
	if (currentNode == nullptr)
	{
		//TODO: encoding
		string error = "Ошибка! По данному ключу нет значений";
		throw error;
	}
	else if (currentNode->NextCollision == nullptr)
	{
		if (currentNode->Key == key)
		{
			currentNode->Key = "";
			currentNode->Value = "";
			_length--;
		}
		else
		{
			//TODO: encoding
			string error = "Ошибка! По данному ключу нет значений";
			throw error;
		}
	}
	else
	{
		HashTableNode* previousNode = currentNode;
		while (currentNode->Key != key)
		{
			previousNode = currentNode;
			currentNode = currentNode->NextCollision;
		}
		if (previousNode == currentNode)
		{
			currentNode->Key = currentNode->NextCollision->Key;
			currentNode->Value = currentNode->NextCollision->Value;
			currentNode->NextCollision = currentNode->NextCollision->NextCollision;
			delete currentNode->NextCollision;
		}
		else
		{
			previousNode->NextCollision = currentNode->NextCollision;
			delete currentNode;
		}
	}
}

string HashTable::Find(string key)
{
	int hash = Hash(key);
	HashTableNode* currentNode = &HashTableNodeArray[hash];
	while (currentNode->Key != key)
	{
		if (currentNode == nullptr || currentNode->NextCollision == nullptr)
		{
			//TODO: encoding
			string error = "Ошибка! Такого элемента нет.";
			throw error;
		}
		//Лучше убрать else или оставить?
		else
		{
			currentNode = currentNode->NextCollision;
		}
	}
	return currentNode->Value;
}

int HashTable::Hash(string key)
{
	int i = 0;
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += key[i] * pow(_HASH_MULTIPLIER, i);
		i++;
	}
	hash %= _hashDivider;
	return hash;
}

void HashTable::Rehash()
{
	//TODO: to const +
	if (_isRehashingNow || _length / _capacity < _PERCENTAGE_OF_FILLING)
	{
		return;
	}
	_isRehashingNow = true;
	int oldCapacity = _capacity;
	_capacity = int(_capacity * _GROWTH_FACTOR);
	_length = 0;
	_hashDivider = _capacity;
	HashTableNode* oldArray = HashTableNodeArray;
	HashTableNodeArray = new HashTableNode[_capacity];
	for (int i = 0; i < oldCapacity; i++)
	{
		if (&oldArray[i].Key != nullptr)
		{
			do
			{
				HashTableInsert(oldArray[i].Key, oldArray[i].Value);
			} while (oldArray->NextCollision != nullptr);
		}
	}
	delete[] oldArray;
	_isRehashingNow = false;
}

HashTable::~HashTable()
{
	delete[] HashTableNodeArray;
}
