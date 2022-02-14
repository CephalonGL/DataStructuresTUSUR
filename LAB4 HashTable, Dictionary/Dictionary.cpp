//TODO: +
#include "Dictionary.h"
#include "HashTable.h"
#include <string>

using namespace std;

const HashTable* Dictionary::GetHashTable()
{
	return _hashTable;
}

void Dictionary::DictionaryInsert(string key, string value)
{
	HashTableNode* currentNode = &_hashTable->HashTableNodeArray[_hashTable->Hash(key)];
	while (currentNode)
	{
		if (currentNode->Key == key)
		{
			throw string("Ошибка: в словаре уже есть элемент с таким ключём");
		}
		else
		{
			currentNode = currentNode->NextCollision;
		}
	}
	_hashTable->HashTableInsert(key, value);
}

void Dictionary::Remove(string key)
{
	_hashTable->Remove(key);
}

string Dictionary::Find(string key)
{
	return _hashTable->Find(key);
}

Dictionary::~Dictionary()
{
	delete _hashTable;
}
