#include "SortedLinkedList.h"
using namespace std;
int main() {
    SortedLinkedList sa, sb;
    sa.addItem(1);
    sa.addItem(19);
    sa.addItem(10);
    sb.addItem(2);
    sb.addItem(29);
    sa.joinList(sb);
    sa.reverseList();
    sa.showList();
    return 0;
}
