#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
class HashTable {
private:
    int maxSize, length, * table;
public:
    HashTable(int size);
    ~HashTable();
    int find(int x);
    void insert(int x);
    void deleteItem(int x);
    void print();
    HashTable rehash();
};
#endif
