//TODO:
#pragma once
#include "HashTable.h"

/// <summary>
/// Dictionary based on hash table data structure
/// </summary>
class Dictionary
{
	/// <summary>
	/// Hash table unit for dictionary
	/// </summary>
	HashTable* _hashTable = new HashTable;

public:
	/// <summary>
	/// Creates new node if get a collision and pushes key and value 
	/// into fields of node.
	/// </summary>
	/// <param name="key">Insertable key</param>
	/// <param name="value">Insertable value</param>
	void DictionaryInsert(string key, string value);

	/// <summary>
	/// Clears data in node by the key and delete node if it's a collision and 
	/// then merge the list.
	/// </summary>
	/// <param name="key">Key to delete by</param>
	void Remove(string key);

	/// <summary>
	/// Searching value by the key.
	/// </summary>
	/// <param name="key">Key to search by</param>
	/// <returns>Value by the key</returns>
	string Find(string key);

	/// <summary>
	/// Delete hash table and clear up the memory
	/// </summary>
	~Dictionary();
};