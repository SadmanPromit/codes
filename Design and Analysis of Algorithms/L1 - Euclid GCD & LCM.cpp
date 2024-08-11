#include <iostream>
using namespace std;

int GCD(int i, int j) {
    while (i != j) {
        if (i > j)
            i -= j;
        else
            j -= i;
    }
    return i;
}

int LCM(int i, int j) {
    int lcm = i * j / GCD(i, j);
    return lcm;
}

int main() {
    int gcd = GCD(6,5), lcm = LCM(6,5);
    cout << "GCD: "<< gcd << endl;
    cout << "LCM: "<< lcm;
}
