#pragma once
#include <string>
#include <exception>
#include <iostream>
using namespace std;

namespace Console
{
	/// <summary>
	/// Print message to console
	/// </summary>
	/// <param name="message">Message to print</param>
	void WriteLine(string message);

	/// <summary>
	/// Print message if got, then read
	/// value from console and check if it is int.
	/// </summary>
	/// <param name="message">Message to print before reading</param>
	/// <returns>Int input value from console</returns>
	int ReadInt(string message = "");

	/// <summary>
	/// Read value from console
	/// </summary>
	/// <param name="message">Message to print before reading</param>
	/// <returns>Input string</returns>
	string ReadString(string message = "");

	/// <summary>
	/// Check if this string a digit
	/// </summary>
	/// <param name="stringToCheck">String to check</param>
	/// <returns>True if it is digit,
	///  else false</returns>
	bool IsDigit(string stringToCheck);
}