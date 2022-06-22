#ifndef _TEST_AVL_TREE_H
#define _TEST_AVL_TREE_H

#include <gtest/gtest.h>
#include "../../Tree/BinaryIndexTree/AVLTree/avl_tree.h"

class AvlTreeTest : public ::testing::Test {
protected:
    AvlTreeTest() {}
    ~AvlTreeTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif // _TEST_AVL_TREE_H