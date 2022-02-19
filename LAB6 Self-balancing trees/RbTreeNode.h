#pragma once
#include <string>

using namespace std;

/// <summary>
/// 
/// </summary>
class RbTreeNode
{
public:
	RbTreeNode(int key, string value)
	{
		_key = key;
		_value = value;
	}



private:
	/// <summary>
	/// Key of node
	/// </summary>
	int _key;

	/// <summary>
	/// Value of node
	/// </summary>
	string _value;

	/// <summary>
	/// Flag for color of node
	/// </summary>
	bool _isBlack;

	/// <summary>
	/// Height of node. Counter of black nodes up to NILL
	/// </summary>
	unsigned int _heightBlack;
};

