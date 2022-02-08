//TODO:
#include "Dictionary.h"





//void Dictionary::DictionaryInsert(string key, string value)
//{
//	Rehash();
//	int hash = Hash(key);
//	HashTableNode* currentNode = &HashTableNodeArray[hash];
//	if (currentNode->Key == "")
//	{
//		currentNode->Key = key;
//		currentNode->Value = value;
//		_length++;
//	}
//	else
//	{
//		while (currentNode->NextCollision != nullptr)
//		{
//			if (currentNode->Key == key)
//			{
//				if (currentNode->Value == value)
//				{
//					string error = "Ошибка! Дубликат key-value";
//					throw error;
//				}
//				else
//				{
//					string error = "Ошибка! Обнаружено свопадение key-key. "
//						"По данному ключу записано значение: ";
//					error.append(currentNode->Value);
//					throw error;
//				}
//			}
//			else
//			{
//				currentNode = currentNode->NextCollision;
//			}
//		}
//		currentNode->NextCollision = new HashTableNode;
//		currentNode->NextCollision->Key = key;
//		currentNode->NextCollision->Value = value;
//	}
//}
