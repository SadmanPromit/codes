#include <iostream>
#include "dynarr.cpp"

using namespace std;

int main()
{
    dynArr<char> d(5);
    cout << "Enter five values: " << endl;
    for (int i = 0; i < 5; i++) {
        char temp;
        cin >> temp;
        d.setValue(i, temp);
    }
    cout << "The values entered are: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << d.getValue(i) << endl;
    }

    return 0;
}
