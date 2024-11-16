#include "SortedLinkedList.h"
SortedLinkedList::SortedLinkedList() {
    head = NULL;
}
SortedLinkedList::~SortedLinkedList() {
    Node * temp;
    while (head != NULL) {
        temp = head;
        head = head -> next;
        delete temp;
    }
}
void SortedLinkedList::addItem(int item) {
    Node * node = new Node();
    node -> value = item;
    node -> next = NULL;

    if (head == NULL || head -> value >= item) {
        node -> next = head;
        head = node;
    }
    else {
        Node * pos = head;
        while (pos -> next != NULL && pos -> next -> value < item) {
            pos = pos -> next;
        }
        node -> next = pos -> next;
        pos -> next = node;
    }
}
void SortedLinkedList::removeItem(int item) {
    if (head == NULL)
        return;
    else if (head -> value == item) {
        Node * temp = head;
        head = head -> next;
        delete temp;
    } else {
        Node * pos = head;
        while (pos -> next != NULL && pos -> next -> value != item) {
            pos = pos -> next;
        }
        if (pos -> next != NULL) {
            Node * temp = pos -> next;
            pos -> next = temp -> next;
            delete temp;
        }
    }
    return;
}
bool SortedLinkedList::searchItem(int item) {
    Node * pos = head;
    while (pos != NULL && pos-> value != item)
        pos = pos -> next;
    if (pos == NULL)
        return false;
    else
        return true;
}
void SortedLinkedList::reverseList() {
    Node * prev = NULL;
    Node * cur = head;
    Node * next = NULL;
    while (cur != NULL) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return;
}
void SortedLinkedList::showList() {
    Node * pos = head;
    while (pos != NULL) {
        cout << pos -> value << " ";
        pos = pos -> next;
    }
    cout << endl;
}
void SortedLinkedList::joinList(SortedLinkedList& list) {
    if (list.head == NULL) {
        return;
    }
    if (head == NULL) {
        head = new Node();
        head -> value = list.head -> value;
        Node * list1 = head;
        Node * list2 = list.head -> next;
        while (list2 != NULL) {
            list1 -> next = new Node();
            list1 = list1 -> next;
            list1 -> value = list2 -> value;
            list2 = list2 -> next;
        }
        list1 -> next = NULL;
    }
    else {
        Node * cur1 = head;
        Node * cur2 = list.head;
        Node * newHead = NULL;
        Node * tail = NULL;
        while (cur1 != NULL && cur2 != NULL) {
            Node * & listRef = (cur1 -> value < cur2 -> value) ? cur1 : cur2;
            if (newHead == NULL) {
                newHead = new Node();
                newHead -> value = listRef -> value;
                tail = newHead;
            } else {
                tail -> next = new Node();
                tail = tail -> next;
                tail -> value = listRef -> value;
            }
            listRef = listRef -> next;
        }
        Node* listRef = (cur1 != NULL) ? cur1 : cur2;
        while (listRef != NULL) {
            tail -> next = new Node();
            tail = tail -> next;
            tail -> value = listRef -> value;
            listRef = listRef -> next;
        }
        tail -> next = NULL;
        this -> ~SortedLinkedList();
        head = newHead;
    }
}
