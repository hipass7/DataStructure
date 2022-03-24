#include "PQType.h"

// The class definition for StackType using templates 
class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};

template<class ItemType>		
class StackType
{
public:
    StackType();
    ~StackType();
    StackType(int max);
    // Class constructor.
    bool IsFull() const;
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsEmpty() const;
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //       otherwise, newItem is at the top of the stack.
    void Pop();
    // Function: Removes top item from the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
    ItemType Top();
    // Function: Returns a copy of top item on the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
           
private: // 변경
    int timestamp;
    int max;
    PQType<ItemType> pq;
    ItemType*  items;
};

template<class ItemType>
StackType<ItemType>::StackType()
{
    max = 100;
    timestamp = -1;
    items = new ItemType[max];
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
  return (timestamp == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
  return (timestamp == max-1); // 변경
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) 
{
    if (IsFull())
throw FullStack();
    timestamp++;
    items[timestamp] = newItem;
    pq.Enqueue(newItem);
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  timestamp--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  ItemType temp;
  pq.Dequeue(temp);
  return temp;
}

template<class ItemType>
StackType<ItemType>::~StackType() // 추가
{
    delete[] items;
}