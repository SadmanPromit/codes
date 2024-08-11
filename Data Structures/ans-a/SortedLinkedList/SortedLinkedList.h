#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include <iostream>
using namespace std;
const int MAX_ITEMS = 100;
struct Node {
    int value;
    Node * next;
};
class SortedLinkedList {
    public:
        SortedLinkedList();
        virtual ~SortedLinkedList();
        void addItem(int item);
        void removeItem(int item);
        bool searchItem(int item);
        void reverseList();
        void showList();
        void joinList(SortedLinkedList& list);
    private:
        Node * head, * tail;
};
#endif
