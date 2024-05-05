#pragma once

#ifndef TR_H
#define TR_H

#include <stdio.h>
#include <stdlib.h>

struct TreapNode {
    int key, priority;
    struct TreapNode* left, * right;
};

TreapNode* createNode(int key, int priority);

TreapNode* rotateLeft(TreapNode* y);

TreapNode* rotateRight(TreapNode* x);

TreapNode* insertNode(TreapNode* root, int key, int priority);

TreapNode* mergeTreaps(TreapNode* leftTreap, TreapNode* rightTreap);

TreapNode* splitTreap(TreapNode* root, int key);

#endif