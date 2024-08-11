#include <iostream>
using namespace std;
void isPrime(int n);
int main() {
    cout << "All the prime numbers between 300 and 500:" << endl;
    for(int i = 300; i <= 500; ++i)
        isPrime(i);
    return 0;
}
void isPrime(int n) {
    for(int i = 2; i <= n / 2; ++i)
        if(!(n % i))
            return;
    cout << n << endl;
}

