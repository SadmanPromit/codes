#include <iostream>
#include "dynarr.h"

using namespace std;

int main()
{
    dynArr d1();
    dynArr d2(5);
    cout << "Enter five values: " << endl;
    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        d2.setValue(i, temp);
    }
    cout << "Values entered are: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << d2.getValue(i) << endl;
    }

    return 0;
}
