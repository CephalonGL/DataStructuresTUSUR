#pragma once
#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// Manage console input and output and check its correct
/// </summary>
class Console
{
private:

public:
	/// <summary>
	/// Read value from console and check if it's int.
	/// </summary>
	/// <returns></returns>
	int ReadInt();

	void Print(string message);
};

