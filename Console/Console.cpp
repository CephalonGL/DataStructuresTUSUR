#include "Console.h"

int Console::ReadInt(string message)
{

    WriteLine(message);
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

string Console::ReadString(string message)
{
    WriteLine(message);
    string inputValue;
    cin >> inputValue;
    return inputValue;
}

void Console::WriteLine(string message)
{
	if (message == "")
	{
		return;
	}
    cout << message << endl;
}
