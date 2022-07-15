#ifndef _SHELL_SORT_H
#define _SHELL_SORT_H

#include <iterator>

static const size_t num_gaps = 8;
static const int gaps[num_gaps] = {701, 301, 132, 57, 23, 10, 4, 1};

template <typename T>
class ShellSort {
public:
    static void Sort(T *data, size_t size);
};

template <typename T>
static void
IntervalInsertionSort(T *data, size_t size, int gap)
{
    for (int i = gap; i < size; i+=gap) {
        T target = data[i];
        int j = i - gap;
        while ((j >= 0) && (data[j] > target)) {
            data[j + gap] = data[j]; 
            j-=gap;
        }
        data[j + gap] = target;
    }
}

template <typename T>
void
ShellSort<T>::Sort(T *data, size_t size)
{
    for (int i = 0; i < num_gaps; i++) {
        IntervalInsertionSort(data, size, gaps[i]);
    }
}

#endif