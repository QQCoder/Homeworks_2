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

bool wordInText(LinkedList *text, LinkedList *pattern) {
    Node *tNode = text->first;
    Node *wNode = pattern->first;
    bool yes = false;

    while (tNode != NULL && !yes) {
        if (tNode->character == wNode->character) {
            while (wNode != NULL && tNode != NULL && tNode->character == wNode->character) {
                tNode = tNode->next;
                wNode = wNode->next;
            }
            if (wNode == NULL) {
                yes = true;
            }
            wNode = pattern->first;
        } else {
            tNode = tNode->next;
        }
    }
    return yes;
}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Text:" << endl;
    readList(text);

    LinkedList *pattern = new LinkedList;
    cout << "Pattern to find:" << endl;
    readList(pattern);

    bool answer = wordInText(text, pattern);

    if (answer) {
        cout << "Found :)" << endl;
    } else {
        cout << "Not found :(" << endl;
    }
    return 0;
}