#include "UnsortedList.cpp"
int main() {
    UnsortedList<int> ul(3);
    ul.addItem(15);
    ul.addItem(2);
    int third = 7;
    ul.addItem(third);
    ul.addItem(8);
    ul.addItem(9);
    ul.addItem(10);
    ul.removeItem(third);
    for(int i = ul.lengthIs(), item; i > 0; i--) {
        ul.getNextItem(item);
        cout << item << endl;
    }
    return 0;
}
