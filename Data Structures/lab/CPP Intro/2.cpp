#include <iostream>
using namespace std;
int main() {
    int a, factorial = 1;
    cout << "Enter a: ";
    cin >> a;
    for(int i = 2; i <= a; ++i)
        factorial *= i;
    cout << "Factorial = " << factorial << endl;
    return 0;
}
