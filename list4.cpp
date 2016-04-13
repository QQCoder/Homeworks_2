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
}

void printList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->character;
        node = node->next;
    }
}

void insertWordAfter(LinkedList *text, LinkedList *pattern, LinkedList *replacement) {
    Node *tNode = text->first;
    Node *wNode = pattern->first;
    Node *lastNode = NULL;
    Node *preMatch = NULL;
    bool yes = false;

    while (tNode != NULL && !yes) {
        if (tNode->character == wNode->character) {
            while (wNode != NULL && tNode != NULL && tNode->character == wNode->character) {
                lastNode = tNode;
                tNode = tNode->next;
                wNode = wNode->next;
            }
            if (wNode == NULL) {
                if (preMatch == NULL) {
                    if (tNode == NULL) {
                        text->first = replacement->first;
                        text->last = replacement->last;
                    } else {
                        text->first = replacement->first;
                        replacement->last->next = tNode;
                    }
                } else {
                    if (tNode == NULL) {
                        preMatch->next = replacement->first;
                        text->last = replacement->last;
                    } else {
                        preMatch->next = replacement->first;
                        replacement->last->next = tNode;
                    }
                }
                yes = true;
            }
            preMatch = lastNode;
            wNode = replacement->first;
        } else {
            preMatch = tNode;
            tNode = tNode->next;
        }
    }
}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Text:" << endl;
    readList(text);

    LinkedList *pattern = new LinkedList;
    cout << "Pattern to find:" << endl;
    readList(pattern);

    LinkedList *replacement = new LinkedList;
    cout << "Replacement:" << endl;
    readList(replacement);

    insertWordAfter(text, pattern, replacement);

    cout << "Final text:" << endl;
    printList(text);
    return 0;
};