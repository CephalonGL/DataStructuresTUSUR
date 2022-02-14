//TODO:
#include "Dictionary.h"
#include <string>

using namespace std;

void Dictionary::DictionaryInsert(string key, string value)
{
}

void Dictionary::Remove(string key)
{
	_hashTable->Remove(key);
}

string Dictionary::Find(string key)
{
	return _hashTable->Find(key);
}
