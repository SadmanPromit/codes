#include "UnsortedList.h"
template <typename ItemType>
UnsortedList<ItemType>::UnsortedList() {
    max_length = ini_length = 100; // Initial size 100
    data = new ItemType[ini_length];
    length = 0;
    currentPos = -1;
}
template <typename ItemType>
UnsortedList<ItemType>::UnsortedList(int n) {
    max_length = ini_length = n;
    data = new ItemType[ini_length]; // Initial size n
    length = 0;
    currentPos = -1;
}
template <typename ItemType>
void UnsortedList<ItemType>::makeEmpty() {
    length = 0;
    currentPos = -1;
}
template <typename ItemType>
bool UnsortedList<ItemType>::isFull() {
    return (length == max_length);
}
template <typename ItemType>
int UnsortedList<ItemType>::lengthIs() {
    return length;
}
template <typename ItemType>
void UnsortedList<ItemType>::addItem(ItemType item) {
    if(length == max_length) {
        max_length += ini_length;    // Update max size
        ItemType * newData = new ItemType[max_length];  // Temporary
        for(int i = 0; i < length; i++)
            newData[i] = data[i];   // Swap
        delete[] data;
        data = newData;
    }
    *(data + length) = item;
    length = length + 1;
}
template <typename ItemType>
void UnsortedList<ItemType>::removeItem(ItemType item) {
    int i;
    for (i=0; i < length; i++)
        if (* (data + i) == item)
            break;
    if (i<length) {
        * (data + i) = *(data + length - 1);
        length = length - 1;
    }
}
template <typename ItemType>
bool UnsortedList<ItemType>::findItem(ItemType item) {
    int i;
    for (i = 0; i < length; i++)
        if (* (data + i) == item)
            return true;
    return false;
}
template <typename ItemType>
void UnsortedList<ItemType>::resetList() {
    currentPos = -1;
}
template <typename ItemType>
void UnsortedList<ItemType>::getNextItem(ItemType& item) {
    currentPos = currentPos + 1;
    item = *(data + currentPos);
    return;
}
