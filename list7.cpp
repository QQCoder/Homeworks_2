#include <iostream>

using namespace std;

struct Node {
    char character;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};


void addToEnd(LinkedList *list, char c) {
    Node *node = new Node;
    node->character = c;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }
}

void readList(LinkedList *list) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        addToEnd(list, s[i]);
    }
    if (list->first == NULL) {
        readList(list);
    }
}


void printList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->character;
        node = node->next;
    }
}

void insertAfterAll(LinkedList *text, Node *pattern, Node *node) {
    Node *pre = NULL;

    Node *tNode = text->first;

    while (tNode != NULL) {
        if (pattern->character == tNode->character) {
            Node *newNode = new Node;
            newNode->character = node->character;
            if (pre != NULL) {
                newNode->next = tNode;
                pre->next = newNode;
            } else {
                newNode->next = text->first;
                text->first = newNode;
            }
        }
        pre = tNode;
        tNode = tNode->next;
    }
}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Text:" << endl;
    readList(text);

    Node *pattern = new Node;
    cout << "Pattern:" << endl;
    cin >> pattern->character;

    Node *node = new Node;
    cout << "Inserting value:" << endl;
    cin >> node->character;

    insertAfterAll(text, pattern, node);

    cout << "Final text:" << endl;
    printList(text);
    return 0;
}