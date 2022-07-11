#include <gtest/gtest.h>
#include "tree/test_tree.h"
#include "sort/test_sort.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}