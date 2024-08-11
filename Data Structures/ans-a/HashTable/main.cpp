#include "HashTable.cpp"
#include <iostream>
int main() {
    // task 1
    HashTable hashTable(20);

    // task 2
    hashTable.insert(1001);
    hashTable.insert(1101);
    hashTable.insert(1201);

    hashTable.insert(1302);
    hashTable.insert(1402); // mid1
    hashTable.insert(1502); // mid2

    hashTable.insert(1603);
    hashTable.insert(1703);
    hashTable.insert(1803);
    hashTable.insert(1903);
    std::cout << "insert();... print():\n";
    hashTable.print();
    std::cout << "\nfind(1001): " << hashTable.find(1001) << "\nfind(1903): " << hashTable.find(1903);
    hashTable.deleteItem(1402);
    hashTable.deleteItem(1502);

    // task 3
    HashTable hashTableNew = hashTable.rehash();
    std::cout << "\n\ndeleteItem(1402); deleteItem(1502); rehash(); print():\n";
    hashTableNew.print();
    return 0;
}
