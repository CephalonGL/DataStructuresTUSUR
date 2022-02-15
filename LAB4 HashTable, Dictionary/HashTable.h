#pragma once
#include "HashTableNode.h"
#include <cmath>
#include <string>
using namespace std;


/// <summary>
/// Hash table the data struct.
/// </summary>
class HashTable
{
protected:
	/// <summary>
	/// Constant parameter for hash function
	/// </summary>
	const short int _HASH_MULTIPLIER = 3;

	/// <summary>
	/// Base capacity of dynamic array for hash table
	/// </summary>
	const short int _BASE_CAPACITY = 10;

	/// <summary>
	/// Percentage of filling hash table 
	/// when rehashing will start
	/// </summary>
	const float _MAX_PERCENTAGE_OF_FILLING = 0.9;

	/// <summary>
	/// Growth factor for dynamic array of nodes
	/// </summary>
	const float _GROWTH_FACTOR = 1.5;

	/// <summary>
	/// Variable needed for hash function
	/// </summary>
	int _hashDivider = _BASE_CAPACITY;

	/// <summary>
	/// Current capacity of dynamic array of nodes
	/// </summary>
	int _capacity = _BASE_CAPACITY;

	/// <summary>
	/// Counter of recerved cells in array of nodes
	/// </summary>
	int _length = 0;

	/// <summary>
	/// Rehashing flag needed for rehash function
	/// </summary>
	bool _isRehashingNow = false;

public:
	/// <summary>
	/// Array of lists that stores nodes of hash table.
	/// </summary>
	HashTableNode* HashTableNodeArray = new HashTableNode[_BASE_CAPACITY];

	/// <summary>
	/// Getter function for capacity.
	/// </summary>
	/// <returns>_capacity</returns>
	int GetCapacity();

	/// <summary>
	/// Creates new node if get a collision and pushes key and value 
	/// into fields of node.
	/// </summary>
	/// <param name="key">Insertable key</param>
	/// <param name="value">Insertable value</param>
	void HashTableInsert(string key, string value);

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
	/// Hashes insertable key.
	/// </summary>
	/// <param name="key">Key to hash</param>
	/// <returns>Hash code</returns>
	int Hash(string key);

	/// <summary>
	/// Automatically rehash the hash table if needed.
	/// </summary>
	void Rehash();

	/// <summary>
	/// Delete array of hash table and clear memory
	/// </summary>
	~HashTable();
};