#include "test_tree.h"

TEST_F(TreeTest, FunctionTest)
{
    AvlTree<int> *tree = new AvlTree<int>();
    EXPECT_TRUE(tree->Empty());
    EXPECT_TRUE(tree->Insert(1));
    EXPECT_TRUE(tree->Insert(2));
    EXPECT_TRUE(tree->Insert(3));
    EXPECT_TRUE(tree->Find(1));
    EXPECT_TRUE(tree->Find(2));
    EXPECT_TRUE(tree->Find(3));
    EXPECT_FALSE(tree->Find(4));
    tree->Clear();
}