#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input:" << endl;
    cin >> n;
    --n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1, j; i <= n + 1; i++) {
        for (j = 0; j < n; j++) {
            if (i == a[j]) {
                break;
            }
        }
        if (j == n) {
            cout << "Output:" << endl;
            cout << i;
            break;
        }
    }
}
