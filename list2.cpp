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

void removeWord(LinkedList *text, LinkedList *word) {
    Node *tNode = text->first;
    Node *wNode = word->first;
    Node *lastNode = NULL;
    Node *preMatch = NULL;

    while (tNode != NULL) {
        if (tNode->character == wNode->character) {
            while (wNode != NULL && tNode != NULL && tNode->character == wNode->character) {
                lastNode = tNode;
                tNode = tNode->next;
                wNode = wNode->next;
            }
            if (wNode == NULL) {
                if (preMatch == NULL) {
                    if (tNode == NULL) {
                        text->first = NULL;
                        text->last = NULL;
                    } else {
                        text->first = tNode;
                    }
                } else {
                    if (tNode == NULL) {
                        preMatch->next = NULL;
                        text->last = preMatch;
                    } else {
                        preMatch->next = tNode;
                    }
                }
            }
            preMatch = lastNode;
            wNode = word->first;
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

    LinkedList *word = new LinkedList;
    cout << "Pattern to remove:" << endl;
    readList(word);

    removeWord(text, word);

    cout << "Final text:" << endl;
    printList(text);
    return 0;
};