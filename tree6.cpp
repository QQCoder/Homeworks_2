#include <iostream>

using namespace std;

// --------- Structures and functions ---------

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

bool isStrictGrowing(Tree *tree) {
    TNode *curNode = tree->root;
    Queue *q = new Queue;
    while (curNode != nullptr) {
        if (curNode->left != nullptr) {
            if (curNode->left->data <= curNode->data) {
                return false;
            }
            qAdd(q, curNode->left);
        }
        if (curNode->right != nullptr) {
            if (curNode->right->data <= curNode->data) {
                return false;
            }
            qAdd(q, curNode->right);
        }
        curNode = qGet(q);
    }
    return true;
}

int main() {
    Tree *tree;
    tCreate(tree);
    for (int i = 0; i < 10; ++i) {
        tInsert(tree, rand() % 100 + 1);
    }
    int s = isStrictGrowing(tree);
    printTree(tree);
    cout << s << endl << endl;

    Tree *t = new Tree;
    t->root = new TNode;
    t->root->data = 4;
    t->root->left = new TNode;
    t->root->left->data = 5;
    t->root->right = new TNode;
    t->root->right->data = 6;
    t->root->right->left = new TNode;
    t->root->right->left->data = 7;
    printTree(t);
    s = isStrictGrowing(t);
    cout << s;
}