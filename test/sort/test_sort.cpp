#include "test_sort.h"
#include <vector>
#include <algorithm>

TEST_F(SortTest, InsertionSortTest)
{
    const size_t size = 10;
    int data[size] = {3, 2, 1, 5, 4, 10, 6, 9, 8, 2};
    int data_ref[size];
    for (int i = 0; i < size; i++) {
        data_ref[i] = data[i];
    }
    std::sort(data_ref, data_ref + size);

    InsertionSort<int>::Sort(data, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Expect: " << data_ref[i] << ", Actual: " << data[i] << std::endl;
    }

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(data[i], data_ref[i]);
    }
}

TEST_F(SortTest, BubbleSortTest)
{
    const size_t size = 10;
    int data[size] = {3, 2, 1, 5, 4, 10, 6, 9, 8, 2};
    int data_ref[size];
    for (int i = 0; i < size; i++) {
        data_ref[i] = data[i];
    }
    std::sort(data_ref, data_ref + size);

    BubbleSort<int>::Sort(data, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Expect: " << data_ref[i] << ", Actual: " << data[i] << std::endl;
    }

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(data[i], data_ref[i]);
    }
}

TEST_F(SortTest, SelectionSortTest)
{
    const size_t size = 10;
    int data[size] = {3, 2, 1, 5, 4, 10, 6, 9, 8, 2};
    int data_ref[size];
    for (int i = 0; i < size; i++) {
        data_ref[i] = data[i];
    }
    std::sort(data_ref, data_ref + size);

    SelectionSort<int>::Sort(data, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Expect: " << data_ref[i] << ", Actual: " << data[i] << std::endl;
    }

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(data[i], data_ref[i]);
    }
}
