#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: " << endl;
    cin >> n;
    int a[n], sum;
    cout << "Enter sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter sum: " << endl;
    cin >> sum;
    for (int i = 0; a[i] <= sum && i < n; i++)
        for (int j = i + 1; a[j] <= sum && j < n; j++)
            if (sum == a[i] + a[j]) {
                cout << "There exists a pair of integer whose sum is equal to sum.";
                return 0;
            }
    cout << "There does not exist a pair of integer whose sum is equal to sum.";
}
