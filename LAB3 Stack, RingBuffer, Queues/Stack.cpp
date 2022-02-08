#include "Stack.h"

Stack::Stack()
{
    _topElement = nullptr;
    _bufferOfPointers = nullptr;
    _stackLength = 0;
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

//bool Stack::IsEmpty()
//{
//    if (_topElement == _bufferOfPointers)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}