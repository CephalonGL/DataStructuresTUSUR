#pragma once
#include <string>
#include <exception>
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
	static int ReadInt();

	static void Print(string message);
};

