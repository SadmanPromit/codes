#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#include <iostream>
using namespace std;
template <typename ItemType>
class UnsortedList {
    public:
        UnsortedList();
        UnsortedList(int n);
        void makeEmpty();
        bool isFull();
        int lengthIs();
        void addItem(ItemType item);
        void removeItem(ItemType item);
        bool findItem(ItemType item);
        void resetList();
        void getNextItem(ItemType& item);
    private:
        ItemType *data;
        int length;
        int max_length;
        int ini_length;
        int currentPos;
};
#endif // UNSORTEDLISTTYPE_H
