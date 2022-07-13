#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

#include <utility>

template <typename T>
class SelectionSort {
public:
    static void Sort(T *data, size_t size);
};

template <typename T>
void
SelectionSort<T>::Sort(T *data, size_t size)
{
    for (int i = 0; i < size; i++) {
        int target_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[target_idx]) {
                target_idx = j;
            }
        }
        std::swap(data[i], data[target_idx]);
    }
}

#endif