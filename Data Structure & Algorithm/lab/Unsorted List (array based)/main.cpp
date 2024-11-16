#include <iostream>
#include "unsortedtype.cpp"

using namespace std;

int main()
{
    UnsortedType<int> u;
    u.InsertItem(5);
    u.InsertItem(7);
    u.InsertItem(6);
    u.InsertItem(9);


    for (int i = 0; i < u.LengthIs(); i++) {
        int item;
        u.GetNextItem(item);
        cout << item << endl;
    }
    u.ResetList();
    cout << u.LengthIs() << endl;
    u.InsertItem(1);
    for (int i = 0; i < u.LengthIs(); i++) {
        int item;
        u.GetNextItem(item);
        cout << item << endl;
    }
    u.ResetList();
    bool found;
    int item = 4;
    u.RetrieveItem(item, found);
    if (found)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;
    item = 5;
    u.RetrieveItem(item, found);
    if (found)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;
    item = 9;
    u.RetrieveItem(item, found);
    if (found)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;
    item = 10;
    u.RetrieveItem(item, found);
    if (found)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;
    if (u.IsFull())
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
    u.DeleteItem(5);
    if (u.IsFull())
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
    u.DeleteItem(1);
    for (int i = 0; i < u.LengthIs(); i++) {
        int item;
        u.GetNextItem(item);
        cout << item << endl;
    }
    u.ResetList();
    u.DeleteItem(6);
    for (int i = 0; i < u.LengthIs(); i++) {
        int item;
        u.GetNextItem(item);
        cout << item << endl;
    }

}
