#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#include <iterator>
#include <cassert>

template <typename T>
class MergeSort {
public:
    static void Sort(T *data, size_t size);
};

// Merge left array and right array
template <typename T>
static void
merge(const T *data_left, const T *data_right, const int left, const int right,
      T *data)
{
    int idx_left = 0;
    int idx_right = 0;
    int mid = (left + right) / 2;
    for (int i = left; i < right; i++) {
        if (idx_left < (mid - left) && (idx_right < (right - mid))) {
            if (data_left[idx_left] <= data_right[idx_right]) {
                data[i] = data_left[idx_left];
                idx_left++;
            } else {
                data[i] = data_right[idx_right];
                idx_right++;
            }
        } else if (idx_left < (mid - left)) {
            data[i] = data_left[idx_left];
            idx_left++;
        } else {
            data[i] = data_right[idx_right];
            idx_right++;
        }
    }
}

// MergeSort for range [left, right)
template <typename T>
static void
merge_sort(T *data, int left, int right)
{
    if (right - left == 1) return;
    assert(right > left);

    int mid = (left + right) / 2;

    merge_sort(data, left, mid);
    merge_sort(data, mid, right);

    T data_left[mid - left];
    T data_right[right - mid];
    for (int i = 0; i < (mid - left); i++) {
        data_left[i] = data[left + i];
    }
    for (int i = 0; i < (right - mid); i++) {
        data_right[i] = data[mid + i];
    }
    merge(data_left, data_right, left, right, data);
}

template <typename T>
void
MergeSort<T>::Sort(T *data, size_t size)
{
    merge_sort(data, 0, size);
}

#endif