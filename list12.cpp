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

void readList (LinkedList *list) {
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

LinkedList *merge(LinkedList *l1, LinkedList *l2) {
    LinkedList *result = new LinkedList;
    Node *l1Node = l1->first;
    Node *l2Node = l2->first;

    while (l1Node != NULL && l2Node != NULL) {
        if (l1Node->value > l2Node->value) {
            addToEnd(result, l2Node->value);
            l2Node = l2Node->next;
        } else {
            addToEnd(result, l1Node->value);
            l1Node = l1Node->next;
        }
    }
    while (l1Node != NULL) {
        addToEnd(result, l1Node->value);
        l1Node = l1Node->next;
    }
    while (l2Node != NULL) {
        addToEnd(result, l2Node->value);
        l2Node = l2Node->next;
    }

    return result;
}

int main() {
    LinkedList *list1 = new LinkedList;
    cout << "First list (elements via spaces):" << endl;
    readList(list1);

    LinkedList *list2 = new LinkedList;
    cout << "Second list (elements via spaces):" << endl;
    readList(list2);

    LinkedList *list = merge(list1, list2);

    cout << "Association:" << endl;
    printList(list);
    return 0;
}