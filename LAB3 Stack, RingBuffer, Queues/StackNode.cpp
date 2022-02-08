#include "StackNode.h"

StackNode::StackNode()
{
    _value = 0;
    _previousElement = nullptr;
}

StackNode::~StackNode()
{
}

void StackNode::SetValue(int value)
{
    _value = value;
}

int StackNode::GetValue()
{
    return _value;
}

void StackNode::SetPointerOfPreviousElement(StackNode* adressToSet)
{
    _previousElement = adressToSet;
}

StackNode* StackNode::GetPointerOfPreviousElement()
{
    return _previousElement;
}