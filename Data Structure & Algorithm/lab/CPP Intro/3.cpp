#include <iostream>
using namespace std;
int main() {
    int input1, input2;
    char op;
    cout << "Enter input1, input2, operator: ";
    cin >> input1 >> input2 >> op;
    cout << input1 << " " << op << " " << input2 << " = ";
    switch(op) {
        case '+': cout << input1 + input2; break;
        case '-': cout << input1 - input2; break;
        case '*': cout << input1 * input2; break;
    }
    cout << endl;
    return 0;
}
