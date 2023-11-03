#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>

int Pivot_Partition(std::vector<int> &arr, int l, int r) {
    int piv_ind = l;
    int pivot = arr[l];
    while (l < r) {
        while (arr[l] < pivot) {
            l++;
        }
        while (arr[r] > pivot) {
            r--;
        }
        if (l < r) {
            std::swap(arr[l++], arr[r--]);
        }
    }
    std::swap(arr[piv_ind], arr[r]);
    return r;
}

void Quick_Sort(std::vector<int> &arr, int l, int r) {
    if (l < r) {
        int p = Pivot_Partition(arr, l, r);
        Quick_Sort(arr, l, p);
        Quick_Sort(arr, p + 1, r);
    }
}

// 3	13	7	8	2	8	9	1	5
// 3	1	2	8	7	8	9	13	5

#endif // QUICK_SORT_HPP
