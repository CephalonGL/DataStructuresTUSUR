#include "Console.h"

int Console::ReadInt()
{
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
    cout << message;
}
