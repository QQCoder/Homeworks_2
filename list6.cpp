#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next = NULL;
};

struct dNode {
    int value;
    dNode *next = NULL;
    dNode *prev = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

struct dLinkedList {
    dNode *first = NULL;
    dNode *last = NULL;
};

void addToEnd(LinkedList *list, int a) {
    Node *node = new Node;
    node->value = a;
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

void dAddToEnd(dLinkedList *list2, int a) {
    dNode *node = new dNode;
    node->value = a;
    node->next = NULL;
    if (list2->first == NULL) {
        list2->first = node;
        list2->last = node;
        node->prev = NULL;
    }
    else {
        node->prev = list2->last;
        list2->last->next = node;
        list2->last = node;
    }
}

LinkedList *readList() {
    LinkedList *list = new LinkedList;
    int num;
    while (cin.peek() != '\n') {
        cin >> num;
        addToEnd(list, num);
    }
    cin.get();
    return list;
}

dLinkedList *dReadList() {
    dLinkedList *list = new dLinkedList;
    int num;
    while (cin.peek() != '\n') {
        cin >> num;
        dAddToEnd(list, num);
    }
    cin.get();
    return list;
}

void dPrintList(dLinkedList *list) {
    dNode *node = list->first;
    while (node != NULL) {
        cout << node->value << ' ';
        node = node->next;
    }
}

void addAfter(dNode *node2, Node *node1) {
    dNode *NewNode = new dNode;
    NewNode->value = node1->value;
    NewNode->next = node2->next;
    NewNode->prev = node2;
    node2->next = NewNode;
}

void addToBeginning(Node *node1, dLinkedList *list2) {
    dNode *NewdNode = new dNode;
    NewdNode->value = node1->value;
    NewdNode->next = list2->first;
    list2->first = NewdNode;
    list2->first->next->prev = list2->first;
}

void addElements(dLinkedList *list2, LinkedList *list1) {
    Node *node1 = list1->first;
    dNode *node2;
    while (node1 != NULL) {
        node2 = list2->first;
        do {
            if (node1->value <= list2->first->value) {
                addToBeginning(node1, list2);
                node2 = NULL;
            } else if (node1->value >= list2->last->value) {
                dAddToEnd(list2, node1->value);
                node2 = NULL;
            } else if (node1->value >= node2->value && node1->value < node2->next->value) {
                addAfter(node2, node1);
                node2 = NULL;
            } else {
                node2 = node2->next;
            }
        } while (node2 != NULL);
        node1 = node1->next;
    }
}

int main() {
    cout << "Enter elements to add, via spaces:" << endl;
    LinkedList *list1 = readList();

    cout << "Enter elements of sorted list (in right order), via spaces:" << endl;
    dLinkedList *list2 = dReadList();

    addElements(list2, list1);

    cout << "Result:" << endl;
    dPrintList(list2);

    return 0;
}
