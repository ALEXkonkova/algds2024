#include "tr.h"
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

typedef struct TreapNode TreapNode;

TreapNode* createNode(int key, int priority) {
    TreapNode* newNode = (TreapNode*)malloc(sizeof(TreapNode));
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreapNode* rotateLeft(TreapNode* y) {
    TreapNode* x = y->right;
    TreapNode* T2 = x->left;

    x->left = y;
    y->right = T2;

    return x;
}

TreapNode* rotateRight(TreapNode* x) {
    TreapNode* y = x->left;
    TreapNode* T2 = y->right;

    y->right = x;
    x->left = T2;

    return y;
}

TreapNode* insertNode(TreapNode* root, int key, int priority) {
    if (root == NULL) {
        return createNode(key, priority);
    }

    if (key <= root->key) {
        root->left = insertNode(root->left, key, priority);

        if (root->left->priority > root->priority) {
            root = rotateRight(root);
        }
    }
    else {
        root->right = insertNode(root->right, key, priority);

        if (root->right->priority > root->priority) {
            root = rotateLeft(root);
        }
    }

    return root;
}

TreapNode* mergeTreaps(TreapNode* leftTreap, TreapNode* rightTreap) {
    if (leftTreap == NULL) return rightTreap;
    if (rightTreap == NULL) return leftTreap;

    if (leftTreap->priority < rightTreap->priority) {
        rightTreap->left = mergeTreaps(leftTreap, rightTreap->left);
        return rightTreap;
    }
    else {
        leftTreap->right = mergeTreaps(leftTreap->right, rightTreap);
        return leftTreap;
    }
}

TreapNode* splitTreap(TreapNode* root, int key) {
    if (root == NULL) return NULL;

    if (root->key <= key) {
        TreapNode* rightSubtree = splitTreap(root->right, key);
        root->right = rightSubtree;
        return root;
    }
    else {
        TreapNode* leftSubtree = splitTreap(root->left, key);
        root->left = leftSubtree;
        return root;
    }
}