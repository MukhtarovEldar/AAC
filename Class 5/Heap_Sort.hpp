#ifndef HEAPSORT_HPP

#include <vector>

void sift_up(std::vector<int> &arr, int n){
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n && arr[i] < arr [2 * i + 1]) {
            std::swap(arr[i], arr[2 * i + 1]);
        }
        if (2 * i + 2 < n && arr[i] < arr [2 * i + 2]) {
            std::swap(arr[i], arr[2 * i + 2]);
        }
        
        // Loop over all the parents for comparison
        int j = i;
        while (arr[j] > arr[(j - 1) / 2]) {
            std::swap(arr[j], arr[(j - 1) / 2]);
            j = (j - 1) / 2;
        }
    }
}

void sift_down(std::vector<int> &arr, int n){
    for (int i = n / 2; i >= 0; i--) {
        int j = i;
        while (true) {
            int mx_idx = j;
            if (2 * j + 1 < n && arr[2 * j + 1] > arr[mx_idx]) {
                mx_idx = 2 * j + 1;
            }
            if (2 * j + 2 < n && arr[2 * j + 2] > arr[mx_idx]) {
                mx_idx = 2 * j + 2;
            }
            if (mx_idx == j) {
                break;
            }
            std::swap(arr[j], arr[mx_idx]);
            j = mx_idx;
        }
    }
}

void heap_sort_first(std::vector<int> &arr) {
    int n = arr.size();
    sift_up(arr, n);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[i], arr[0]);
        sift_up(arr, i);
    }
}

void heap_sort_second(std::vector<int> &arr) {
    int n = arr.size();
    sift_down(arr, n);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[i], arr[0]);
        sift_down(arr, i);
    }
}

#endif
