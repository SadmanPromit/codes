#include <iostream>
using namespace std;

int find_a(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] == 'a')
            return i;
    }
    return -1;
}

int main() {
    char str[] = "never";
    int x = find_a(str);
    cout << x;
}
