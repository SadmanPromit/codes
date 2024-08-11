#include <iostream>
using namespace std;

int GCD(int num1, int num2) {
    int lower, gcd;
    if (num1 < num2)
        lower = num1;
    else
        lower = num2;
    for (int i = 1; i <= lower; i++)
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    return gcd;
}

int main() {
    int gcd = GCD(6,5);
    cout << gcd;
}
