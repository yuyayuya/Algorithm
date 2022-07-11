#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H

#include <iterator>

template <typename T>
class InsertionSort {
public:
    static void Sort(T *data, size_t size);
};

template <typename T>
void
InsertionSort<T>::Sort(T *data, size_t size)
{
    for (int i = 1; i < size; i++) {
        int target = data[i];
        int j = i - 1;
        while ((j >= 0) && (data[j] > target)) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = target;
    }
}

#endif