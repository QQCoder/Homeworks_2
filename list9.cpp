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

void addToEnd(LinkedList *list, double a) {
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

void readList(LinkedList *list) {
    double num;
    while (cin.peek() != '\n') {
        cin >> num;
        addToEnd(list, num);
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

LinkedList *getPositive(LinkedList *list) {
    LinkedList *result = new LinkedList;

    Node *node = list->first;

    while (node != NULL) {
        if (node->value >= 0) {
            addToEnd(result, node->value);
        }
        node = node->next;
    }

    return result;
}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list: ";
    readList(list);

    list = getPositive(list);

    cout << "Plus list:" << endl;
    printList(list);
    return 0;
}