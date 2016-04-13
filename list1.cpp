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

LinkedList *findMaxWord(LinkedList *text, int *length) {
    LinkedList *maxWord = new LinkedList;
    int l = 0;
    *length = 0;
    Node *node = text->first;
    Node *curNode;
    LinkedList *curWord = new LinkedList; // current word

    while (node != NULL) {
        if (node->character != ' ') {
            curWord->first = node;
            while (node != NULL && node->character != ' ') {
                l++;
                curWord->last = node;
                node = node->next;
            }
            if (l > *length) {
                *length = l;
                curNode = curWord->first;
                while (curNode != curWord->last) {
                    addToEnd(maxWord, curNode->character);
                    curNode = curNode->next;
                }
                addToEnd(maxWord, curNode->character);
            }
            l = 0;
        }
        else {
            node = node->next;
        }
    }
    return maxWord;
}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Text:" << endl;
    readList(text);
    int length;

    LinkedList *maxWord = findMaxWord(text, &length);

    cout << "Longest word: ";
    printList(maxWord);
    cout << endl;
    cout << endl << "Length of longest word: " << length;

    return 0;
}