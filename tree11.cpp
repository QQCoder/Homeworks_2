#include <iostream>

using namespace std;

// --------- Structures and functions ---------

struct ListNode {
    int value;
    ListNode *next = nullptr;
};

struct LinkedList {
    ListNode *first = nullptr;
    ListNode *last = nullptr;

};

void addToEnd(LinkedList *list, int v) {
    ListNode *node = new ListNode;
    node->value = v;
    node->next = nullptr;
    if (list->first == nullptr) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }
}

void printList(LinkedList *list) {
    ListNode *node = list->first;
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
}

struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

struct Tree {
    TNode *root;
};

struct QNode {
    TNode *node = nullptr;
    QNode *next = nullptr;
};

struct Queue {
    QNode *first = nullptr;
    QNode *last = nullptr;
};

void qAdd(Queue *q, TNode *n) {
    QNode *newNode = new QNode;
    newNode->node = n;
    if (q->first == nullptr) {
        q->first = newNode;
        q->last = newNode;
    } else {
        q->last->next = newNode;
        q->last = newNode;
    }
}

TNode *qGet(Queue *q) {
    if (q->first != nullptr) {
        TNode *result = q->first->node;
        if (q->first->next != nullptr) {
            q->first = q->first->next;
        } else {
            q->first = nullptr;
        }
        return result;
    } else {
        return nullptr;
    }
}

void tCreate(Tree *&tree) {
    tree = new Tree;
    tree->root = nullptr;
}

TNode* tInsertNode(TNode *root, int element) {
    if (root == nullptr) {
        root = new TNode;
        root->data = element;
        root->left = nullptr;
        root->right = nullptr;
    }

    else if (element <= root->data) {
        root->left = tInsertNode(root->left, element);
    } else {
        root->right = tInsertNode(root->right, element);
    }

    return root;
}

void tInsert(Tree *&tree, int element) {
    tree->root = tInsertNode(tree->root, element);
}

void _printTree(TNode *root, int level) {
    if (root != NULL) {
        _printTree(root->right, level + 1);

        for (int i = 0; i < level; i++) {
            cout << "--";
        }

        cout << root->data << endl;

        _printTree(root->left, level + 1);
    }
}

void printTree(Tree *tree) {
    _printTree(tree->root, 0);
}

void _tInOrderPrint(TNode *root) {
    if (root != nullptr) {
        _tInOrderPrint(root -> left);
        cout << root -> data << " ";
        _tInOrderPrint(root ->right);
    }
}

void tInOrderPrint(Tree *tree) {
    _tInOrderPrint(tree->root);
}

// ---------

Tree *getTree(LinkedList *list) {
    Tree *result;
    tCreate(result);
    ListNode *curNode = list->first;
    while (curNode != nullptr) {
        tInsert(result, curNode->value);
        curNode = curNode->next;
    }
    return result;
}

int main() {
    LinkedList *list = new LinkedList;
    for (int i = 0; i < 10; ++i) {
        addToEnd(list, rand() % 100 + 1);
    }
    printList(list);
    cout << endl << endl;
    Tree *tree = getTree(list);
    printTree(tree);
}