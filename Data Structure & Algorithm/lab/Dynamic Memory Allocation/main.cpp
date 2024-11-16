#include "dynamicarray.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the size of the array: " << endl;
    int size;

    cin >> size;

    DynamicArray d(size);

    int temp;

    for (int i = 0; i < size; i++) {
        cout << "Enter value to be inserted at index = " << i << endl;
        cin >> temp;
        d.insertItem (i, temp);
    }

    cout << "The values stored are: ";

    int temp2;

    for(int i = 0; i < size; i++) {
        temp2 = d.getItem(i);
        cout << "Index = " << i; cout << ", Value = " << temp2 << endl;
    }

    return 0;
}
