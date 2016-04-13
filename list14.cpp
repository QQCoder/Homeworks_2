#include <iostream>

using namespace std;

struct Node {
    double value;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void addToEnd (LinkedList *list, double value) {
    Node *node = new Node;
    node->value = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    }
    else {
        list->last->next = node;
        list->last = node;
    }
}

void readList(LinkedList *list) {
    double value;
    while (cin.peek() != '\n') {
        cin >> value;
        addToEnd(list, value);
    }
    cin.get();
}

void printList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->value << ' ';
        node = node->next;
    }
}

void reverse(LinkedList *list){
    Node *node = list->first;
    Node *PrevNode = NULL;
    Node *CurNodeNext = NULL;
    while (node != NULL) {
        PrevNode = node;
        node = node->next;
        PrevNode->next = CurNodeNext;
        CurNodeNext = PrevNode;
    }
    list->first = PrevNode;
}

void addToBegin(LinkedList *list, double value) {
    Node *node = new Node;
    node->value = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first = node;
    }
}

LinkedList *getReversed(LinkedList *list) {
    LinkedList *result = new LinkedList;
    Node *node = list->first;
    while (node != NULL) {
        addToBegin(result, node->value);
        node = node->next;
    }
    return result;
}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list:";
    readList(list);

    list = getReversed(list);

    printList(list);
    return 0;
}