#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

#include <utility>

template <typename T>
class BubbleSort {
public:
    static void Sort(T *data, size_t size);
};

template <typename T>
void
BubbleSort<T>::Sort(T *data, size_t size)
{
    int sorted_idx = 0;
    bool swap_flag = true;
    while (swap_flag) {
        swap_flag = false;
        for (int i = size - 1; i > sorted_idx; i--) {
            if (data[i] < data[i-1]) {
                std::swap(data[i], data[i-1]);
                swap_flag = true;
            }
        }
        if (!swap_flag) break;
        sorted_idx++;
    }
}

#endif