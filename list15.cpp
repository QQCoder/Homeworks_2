#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    double r, phi;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void addToEnd (LinkedList *list, double r, double phi) {
    Node *node = new Node;
    node->r = r;
    node->phi = phi;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }
}

LinkedList *readPolarCoordsList () {
    LinkedList *list = new LinkedList;
    cout << "Enter r and phi in degrees (via spaces) in one line" << endl;
    double r, phi;
    while (cin.peek() != '\n') {
        cin >> r;
        if (cin.peek() != '\n') {
            cin >> phi;
            addToEnd(list, r, phi);
        }
    }
    cin.get();
    return list;
}

void readCoef(double &k, double &b) {
    cout << "y = k*x + b" << endl;
    cout << "Enter k: " << endl;
    cin >> k;
    cout << "Enter b: " << endl;
    cin >> b;
}

bool checkCoords(LinkedList *list, double k, double b) {
    Node *node = list->first;
    if (node != NULL) {
        while (node != NULL) {
            double A = (k*(node->r * cos(node->phi / 180 * M_PI)) + b)*0.00001;
            double B = (node->r * sin(node->phi / 180 * M_PI))*0.00001;
            if ( A == B ) {
                node = node->next;
            } else {
                return false;
            }
        }
        return true;
    } else {
        cout << "List is empty!";
        return false;
    }
}

int main() {
    LinkedList *list = readPolarCoordsList();

    double k, b;
    readCoef(k, b);

    if (checkCoords(list, k, b)) {
        cout << "Points lie on the line";
    } else {
        cout << "Points don't lie on the line";
    }

    return 0;
}