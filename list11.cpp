#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    double value;
    Node *next = NULL;
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

LinkedList *getIntersection(LinkedList *list1, LinkedList *list2) {
    LinkedList *list = new LinkedList;
    Node *node1 = list1->first;
    Node *node2 = list2->first;
    while (node1 != NULL && node2 != NULL) {
        if (node1->value > node2->value) {
            node2 = node2->next;
        }
        else if (node1->value < node2->value) {
            node1 = node1->next;
        }
        else {
            addToEnd(list, node1->value);
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    return list;
}

int main() {
    LinkedList *list1 = new LinkedList;
    cout << "Enter elements of first list" << endl;
    readList(list1);

    LinkedList *list2 = new LinkedList;
    cout << "Enter elements of second list" << endl;
    readList(list2);

    LinkedList *list = getIntersection(list1, list2);

    cout << "Elements of intersection:" << endl;
    printList(list);
    return 0;
}