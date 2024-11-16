#ifndef STACKTYPELL_CPP
#define STACKTYPELL_CPP
#include "StackTypeLL.h"

template<class ItemType>
StackTypeLL<ItemType>::StackTypeLL()
{
    cout<<"Constructing\n";
    tos=NULL;
}

template<class ItemType>
StackTypeLL<ItemType>::~StackTypeLL()
{
    cout<<"Destructing\n";
    makeEmpty();
}

template<class ItemType>
void StackTypeLL<ItemType>::makeEmpty()
{
    NodeType<ItemType> *temp;
    while(tos)
    {
        temp=tos;
        tos=tos->next;
        delete temp;
    }
}

template<class ItemType>
void StackTypeLL<ItemType>::Push(ItemType item)
{
    cout<<"Push::"<<item<<endl;
    NodeType<ItemType> *temp = new NodeType<ItemType>;
    temp->data = item;
    temp->next = tos;
    tos = temp;
}

template<class ItemType>
void StackTypeLL<ItemType>::pop(ItemType &item)
{
    NodeType<ItemType> *temp;
    temp = tos;
    tos = tos->next;
    item = temp->data;

    delete temp;
}

template<class ItemType>
void StackTypeLL<ItemType>::printStack() const
{
    NodeType<ItemType> *temp = tos;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

template<class ItemType>
bool StackTypeLL<ItemType>::isEmpty() const
{
    return (tos==NULL);
}

template<class ItemType>
bool StackTypeLL<ItemType>::isFull() const
{
    NodeType<ItemType> *temp;

    try
    {
        temp = new NodeType<ItemType>;
        delete temp;
        return false;
    }
    catch(bad_alloc e){
    return true;
    }

    return (tos==NULL);
}

#endif // STACKTYPELL_CPP
