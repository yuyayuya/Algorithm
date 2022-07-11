#ifndef _TEST_SORT_H
#define _TEST_SORT_H

#include <gtest/gtest.h>
#include "../../include/sort/insertion_sort.h"

class SortTest : public ::testing::Test {
protected:
    SortTest() {}
    ~SortTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif // _TEST_SORT_H