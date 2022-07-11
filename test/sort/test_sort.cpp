#include "test_sort.h"

TEST_F(SortTest, FunctionTest)
{
    int data[10] = {3, 2, 1, 5, 4, 10, 6, 9, 8, 2};
    InsertionSort<int>::Sort(data, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << i << ": " << data[i] << std::endl;
    }
}