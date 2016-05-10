#include <iostream>
using namespace std;
using namespace std;

struct Node {
    double x, y;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void AddToEnd (LinkedList *list, double x, double y) {
    Node *node = new Node;
    node->x = x;
    node->y = y;
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

LinkedList *ReadList () {
    LinkedList *list = new LinkedList;
    cout << "Enter coordinates(x and y, through the gaps) of list" << endl;
    double r, phi;
    while (cin.peek() != '\n') {
        cin >> r;
        if (cin.peek() != '\n') {
            cin >> phi;
            AddToEnd(list, r, phi);
        }
    }
    cin.get();
    return list;
}

bool CheckCoord(LinkedList *list, double r){
    Node *node = list->first;
    if (node != NULL) {
        while (node != NULL) {
            if (r * r == (node->x * node->x) + (node->y * node->y)){
                node = node->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
    else {
        cout << "List is emty!";
        return false;
    }
}

int main() {
    LinkedList *list = ReadList();

    double r;
    cout << "Enter r of circle" << endl;
    cin >> r;

    if (CheckCoord(list, r)) {
        cout << "Coordinates lie on a given line.";
    }
    else {
        cout << "Coordinates don't lie on a given line.";
    }

    return 0;
}