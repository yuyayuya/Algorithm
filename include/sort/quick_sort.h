#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <iterator>
#include <utility>

template <typename T>
class QuickSort {
public:
    static void Sort(T *data, size_t size);
};

template <typename T>
static int
partition(T *data, int left, int right)
{
    // TODO: pivot should be selected randomlly.
    int i = left - 1;
    for (int j = left; j < right - 1; j++) {
        if (data[j] <= data[right - 1]) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right - 1]);
    return i + 1;
}

template <typename T>
static void
quick_sort(T *data, int left, int right)
{
    if (right - left <= 1) return;

    int div = partition(data, left, right);

    quick_sort(data, left, div);
    quick_sort(data, div + 1, right);
}

template <typename T>
void
QuickSort<T>::Sort(T *data, size_t size)
{
    quick_sort(data, 0, size);
}

#endif