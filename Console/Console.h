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
	/// Print message if got, then read
	/// value from console and check if it is int.
	/// </summary>
	/// <param name="message">Message to print before reading</param>
	/// <returns>Int input value from console</returns>
	static int ReadInt(string message = "");

	/// <summary>
	/// Read value from console
	/// </summary>
	/// <param name="message">Message to print before reading</param>
	/// <returns>Input string</returns>
	static string ReadString(string message = "");

	/// <summary>
	/// Print message to console
	/// </summary>
	/// <param name="message">Message to print</param>
	static void WriteLine(string message);
};

