#pragma once

/// <summary>
/// Node of the List
/// </summary>
struct Node
{
    /// <summary>
    /// Value of this node
    /// </summary>
    int Value = 0;

    /// <summary>
    /// Pointer to next node
    /// </summary>
    Node* Next = nullptr;

    /// <summary>
    /// Pointer to previous node
    /// </summary>
    Node* Previous = nullptr;
};

/// <summary>
/// Double linked list data structure
/// </summary>
class List
{
    /// <summary>
    /// Length of the list
    /// </summary>
    int _length = 0;
    /// <summary>
    /// Head node of the list
    /// </summary>
    Node* _head = nullptr;
    /// <summary>
    /// Tail node of the list
    /// </summary>
    Node* _tail = nullptr;

public:
    /// <summary>
    /// Getter function for current list lenght
    /// </summary>
    /// <returns>length</returns>
    int GetLength();

    /// <summary>
    /// Create and initialize list
    /// </summary>
    /// <param name="countOfNodes">List length</param>
    /// <param name="arrayOfValuesToInitialize">Values of each node in created list</param>
    void CreateList(int countOfNodes, int arrayOfValuesToInitialize[]);

    /// <summary>
    /// Add new node into list
    /// </summary>
    /// <param name="valueToPush">Value of new node</param>
    void AddNewNode(int valueToPush = 0);

    /// <summary>
    /// Remove node by the index
    /// </summary>
    /// <param name="indexOfRemovableNode">Index of removable node</param>
    void RemoveNode(int indexOfRemovableNode);

    /// <summary>
    /// Inserts new node before head node
    /// </summary>
    /// <param name="valueToPush">Value of new node</param>
    void PushForward(int valueToPush = 0);

    /// <summary>
    /// Inserts new node after tail node
    /// </summary>
    /// <param name="valueToPush">Value of new node</param>
    void PushBack(int valueToPush = 0);

    /// <summary>
    /// Inserts new node after node with index
    /// </summary>
    /// <param name="indexNodeToPushAfter">Index of node to push after</param>
    /// <param name="valueToPush">Value of new node</param>
    void PushAfterNode(int indexNodeToPushAfter, int valueToPush = 0);

    /// <summary>
    /// Inserts new node before node with index
    /// </summary>
    /// <param name="indexNodeToPushBefore">Index of node to push before</param>
    /// <param name="valueToPush">Value of new node</param>
    void PushBeforeNode(int indexNodeToPushBefore, int valueToPush = 0);

    /// <summary>
    /// Bubble sort of the list in descending order
    /// </summary>
    void Sort();

    /// <summary>
    /// Linear search in list
    /// </summary>
    /// <param name="valueToSearch">Searching value</param>
    /// <returns>If there is node with searching value, returns index of its node,
    ///  else returns -1</returns>
    int LinearSearch(int valueToSearch);

    /// <summary>
    /// Get value from node by the index
    /// </summary>
    /// <param name="indexOfNode">Index of node to get value from</param>
    /// <returns>Value of node by the index</returns>
    int GetValueByIndex(int indexOfNode);
};