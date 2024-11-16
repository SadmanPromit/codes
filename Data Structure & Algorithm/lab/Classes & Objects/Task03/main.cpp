#include <iostream>
#include "dynarr.h"

using namespace std;

int main()
{
    cout << "Enter the number of rows and columns: " << endl;
    int row, column;
    cin >> row;
    cin >> column;
    dynArr d(row, column);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++) {
            cout << "Enter value at index[" << i << "][" << j << "]: " << endl;
            int temp;
            cin >> temp;
            d.setValue(i, j, temp);
        }
    cout << "Values entered are: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Value at index[" << i << "][" << j << "]: " << d.getValue(i, j) << endl;
        }
    }

    return 0;
}
