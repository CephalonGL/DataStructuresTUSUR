#include "Stack.h"

int Stack::GetStackLength()
{
    return _stackLength;
}

void Stack::Push(int valueToPush)
{
    _bufferOfPointers = _topElement;
    _topElement = new StackNode;
    _topElement->SetValue(valueToPush);
    _topElement->SetPointerOfPreviousElement(_bufferOfPointers);
    _stackLength++;
}

int Stack::Pop()
{
    if (GetStackLength() == 0)
    {
        return 0;
    }
    int valueToPop = _topElement->GetValue();
    _bufferOfPointers = _topElement;
    _topElement = _topElement->GetPointerOfPreviousElement();
    delete _bufferOfPointers;
    _bufferOfPointers = nullptr;
    _stackLength--;
    return valueToPop;
}

Stack::~Stack()
{
    for (int i = 0; i < _stackLength; i++)
    {
        _bufferOfPointers = _topElement;
        _topElement = _topElement->GetPointerOfPreviousElement();
        if (_topElement == nullptr)
        {
            return;
        }
        delete _bufferOfPointers;
        _bufferOfPointers = nullptr;
    }
}