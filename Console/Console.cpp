#include "Console.h"

int Console::ReadInt(string message = "")
{

    Print(message);
    int inputValue;
    cin >> inputValue;
    if (cin.fail())
    {
        cin.clear();
        string stringToDelete;
        cin >> stringToDelete;
        throw exception("Error: incorrect input data.");
    }
    return inputValue;
}

void Console::Print(string message)
{
	if (message == "")
	{
		return;
	}
    cout << message << endl;
}
