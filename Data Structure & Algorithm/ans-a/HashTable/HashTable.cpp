#include "HashTable.h"
#include <iostream>
HashTable::HashTable(int size) {
    maxSize = size;
    length = 0;
    table = new int[size];
    for(int i = 0; i < size; ++i)
        table[i] = -2;
}
HashTable::~HashTable() {
    delete [] table;
}
int HashTable::find(int x) {
    int index = x % maxSize;
    while (table[index] != -2 && table[index] != x)
        index = (index + 1) % maxSize;
    return (table[index] == x) ? index : -1;
}
void HashTable::insert(int x) {
    if (find(x) != -1) {
        std::cout << "Item already exists.\n";
        return;
    }
    if (length == maxSize) {
        std::cout << "the hash table is full and " << x << " cannot be inserted.\n";
        return;
    }
    int index = x % maxSize;
    while (table[index] != -2 && table[index] != -1)
        index = (index + 1) % maxSize;
    table[index] = x;
    ++length;
}

void HashTable::deleteItem(int x) {
    int index = find(x);
    if (index != -1) {
        table[index] = -1;
        --length;
    }
}
void HashTable::print() {
    for(int i = 0; i < maxSize; ++i)
        if (table[i] >= 0)
            std::cout << "Index " << i << ": " << table[i] << '\n';
}
HashTable HashTable::rehash() {
    HashTable hashTableNew(maxSize);
    for(int i = 0; i < maxSize; ++i)
        if (table[i] >= 0)
            hashTableNew.insert(table[i]);
    return hashTableNew;
}
