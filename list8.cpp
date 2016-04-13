#include <iostream>
using namespace std;

struct Node {
    double value;
    Node *next = NULL;
    Node *prev = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void addToEnd(LinkedList *list, double value) {
    Node *node = new Node;
    node->value = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->prev = list->last;
        list->last->next = node;
    }
    list->last = node;
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

void insertNode(LinkedList *list, Node *node) {
    Node *curNode = list->last;
    Node *insertingNode = new Node;
    insertingNode->value = node->value;
    bool inserted = false;
    bool itIsSmallest = true;
    while (curNode != NULL && !inserted) {
        if (curNode->value > insertingNode->value) {
            curNode = curNode->prev;
        } else {
            if (curNode->next != NULL) {
                insertingNode->next = curNode->next;
                curNode->next = insertingNode;
            } else {
                curNode->next = insertingNode;
                list->last = insertingNode;
            }
            inserted = true;
            itIsSmallest = false;
        }
    }
    if (!inserted) {
        if (itIsSmallest) addToBegin(list, insertingNode->value);
        else addToEnd(list, insertingNode->value);
    }
}

LinkedList *inclusionSort(LinkedList *list) {

    LinkedList *result = new LinkedList;

    Node *node = list->first;
    while (node != NULL) {
        insertNode(result, node);
        node = node->next;
    }

    return result;
}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list" << endl;
    readList(list);

    LinkedList *sortedList = inclusionSort(list);
    cout << "Sorted list:" << endl;
    printList(sortedList);

    return 0;
}