#pragma once
#include <string>
using namespace std;

///<summary>
///Node of hash table that stores key, value and pointer to next collision.
///</summary>
struct HashTableNode
{
	//TODO: XML +
	/// <summary>
	/// Key of current node
	/// </summary>
	string Key = "";

	/// <summary>
	/// Value of current node
	/// </summary>
	string Value = "";

	/// <summary>
	/// Pointer to node of next collision
	/// </summary>
	HashTableNode* NextCollision = nullptr;
};