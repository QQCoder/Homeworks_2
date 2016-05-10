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

int getMaxOfLevel(Queue *&q, int &curLevelCount, bool &end) {
    int n = curLevelCount;
    end = true;
    curLevelCount = 0;
    TNode *node = qGet(q);
    qAdd(q, node);
    int max = node->data;
    for (int i = 0; i < n; i++) {
        if (node != nullptr) {
            if (node->data > max) {
                max = node->data;
            }
            if (node->left != nullptr) {
                qAdd(q, node->left);
                curLevelCount++;
                end = false;
            }
            if (node->right != nullptr) {
                qAdd(q, node->right);
                curLevelCount++;
                end = false;
            }
        }
        node = qGet(q);
        qAdd(q, node);
    }
    return max;
}

int getMinOfLevel(Queue *&q, int &curLevelCount, bool &end) {
    int n = curLevelCount;
    end = true;
    curLevelCount = 0;
    TNode *node = qGet(q);
    int min = node->data;
    for (int i = 0; i < n; i++) {
        if (node != nullptr) {
            if (node->data < min) {
                min = node->data;
            }
            if (node->left != nullptr) {
                qAdd(q, node->left);
                curLevelCount++;
                end = false;
            }
            if (node->right != nullptr) {
                qAdd(q, node->right);
                curLevelCount++;
                end = false;
            }
        }
        node = qGet(q);
    }
    return min;
}

bool isGrowing(Tree *tree) {
    bool answer = true;
    bool end = false;
    Queue *q = new Queue;
    TNode *node = tree->root;
    qAdd(q, node);
    int prev;
    int cur;
    int curLevelCount = 1;

    while (!end && answer) {
        prev = getMaxOfLevel(q, curLevelCount, end);
        cur = getMinOfLevel(q, curLevelCount, end);
        if (cur <= prev) {
            answer = false;
        }
    }
    return answer;
}

int main() {
    Tree *tree;
    tCreate(tree);
    for (int i = 0; i < 3; ++i) {
        tInsert(tree, rand() % 100 + 1);
    }
    printTree(tree);
    bool s = isGrowing(tree);
    cout << s << endl << endl;

    Tree *tree1;
    tCreate(tree1);
    for (int i = 0; i < 6; ++i) {
        tInsert(tree1, rand() % 100 + 1);
    }
    printTree(tree1);
    s = isGrowing(tree1);
    cout << s << endl << endl;

    Tree *tree2;
    tCreate(tree2);
    for (int i = 0; i < 10; ++i) {
        tInsert(tree2, rand() % 100 + 1);
    }
    printTree(tree2);
    s = isGrowing(tree2);
    cout << s << endl << endl;

    Tree *tree3 = new Tree;
    tree3->root = new TNode;
    tree3->root->data = 1;
    tree3->root->left = new TNode;
    tree3->root->left->data = 8;
    tree3->root->right = new TNode;
    tree3->root->right->data = 3;
    printTree(tree3);
    s = isGrowing(tree3);
    cout << s;
}