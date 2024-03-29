#ifndef _TEST_SORT_H
#define _TEST_SORT_H

#include <gtest/gtest.h>
#include "../../include/sort/insertion_sort.h"
#include "../../include/sort/bubble_sort.h"
#include "../../include/sort/selection_sort.h"
#include "../../include/sort/shell_sort.h"
#include "../../include/sort/merge_sort.h"
#include "../../include/sort/quick_sort.h"

class SortTest : public ::testing::Test {
protected:
    SortTest() {}
    ~SortTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif // _TEST_SORT_H