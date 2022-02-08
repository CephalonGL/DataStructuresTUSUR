#pragma once
#include <string>
using namespace std;

///<summary>
///Node of hash table that stores key, value and pointer to next collision.
///</summary>
struct HashTableNode
{
	//TODO: XML
	string Key = "";
	string Value = "";
	HashTableNode* NextCollision = nullptr;
};