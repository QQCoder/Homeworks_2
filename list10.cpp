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

bool checkOrder(LinkedList *list) {
    Node *node = list->first;
    if (node == NULL || node->next == NULL) {
        return true;
    }
    else if (node->value > node->next->value) {
        node = node->next;
        while (node->next != NULL) {
            if (node->value < node->next->value) {
                return false;
            }
            node = node->next;
        }
        return true;
    }
    else {
        node = node->next;
        while (node->next != NULL) {
            if (node->value > node->next->value) {
                return false;
            }
            node = node->next;
        }
        return true;
    }
}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list" << endl;
    readList(list);

    if (checkOrder(list)) {
        cout << "This list is ordered.";
    }
    else {
        cout << "This list isn't ordered.";
    }

    return 0;
}