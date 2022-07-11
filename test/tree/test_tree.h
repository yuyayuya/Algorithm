#ifndef _TEST_TREE_H
#define _TEST_TREE_H

#include <gtest/gtest.h>
#include "../../include/tree/avl_tree.h"

class TreeTest : public ::testing::Test {
protected:
    TreeTest() {}
    ~TreeTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif // _TEST_TREE_H