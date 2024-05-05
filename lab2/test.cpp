#include "tr.h"
#include <gtest/gtest.h>

TEST(TreapTest, newNodeCreation) {
    TreapNode* testNode = createNode(10, 5);

    EXPECT_EQ(testNode->key, 10);
    EXPECT_EQ(testNode->priority, 5);
    EXPECT_EQ(testNode->left, nullptr);
    EXPECT_EQ(testNode->right, nullptr);
}

TEST(TreapTest, nodeRotateLeft) {
    TreapNode* root = createNode(10, 5);
    root->right = createNode(20, 7);
    root->left = nullptr;

    root = rotateLeft(root);

    EXPECT_EQ(root->key, 20);
    EXPECT_EQ(root->left->key, 10);
}

TEST(TreapTest, nodeRotateRight) {
    TreapNode* root = createNode(20, 7);
    root->left = createNode(10, 5);
    root->right = nullptr;

    root = rotateRight(root);

    EXPECT_EQ(root->key, 10);
    EXPECT_EQ(root->right->key, 20);
}

TEST(TreapTest, InsertNodeIntoTreap) {
    TreapNode* root = nullptr;
    root = insertNode(root, 10, 5);

    EXPECT_EQ(root->key, 10);
    EXPECT_EQ(root->priority, 5);
}

TEST(TreapTest, MergeTreaps) {
    TreapNode* leftTreap = createNode(10, 5);
    TreapNode* rightTreap = createNode(20, 7);

    TreapNode* mergedTreap = mergeTreaps(leftTreap, rightTreap);

    EXPECT_EQ(mergedTreap->key, 20);
    EXPECT_EQ(mergedTreap->left->key, 10);
}

TEST(TreapTest, SplitTreap) {
    TreapNode* root = createNode(20, 7);
    root->left = createNode(10, 5);
    root->right = createNode(30, 6);

    TreapNode* leftSplit = splitTreap(root, 15);

    EXPECT_EQ(leftSplit->key, 10);
    EXPECT_EQ(leftSplit->left, nullptr);
    EXPECT_EQ(leftSplit->right, nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
