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
            if (2 * j + 1 < n && arr[2 * j + 1] > arr[j]) {
                std::swap(arr[j], arr[2 * j + 1]);
                j = 2 * j + 1;
            }
            if (2 * j + 2 < n && arr[2 * j + 2] > arr[j]) {
                std::swap(arr[j], arr[2 * j + 2]);
                j = 2 * j + 2;
            } else {
                break;
            }
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

// 8	1	7	5	0	9	3	2	4  | i = 0
// 8	5	7	1	0	9	3	2	4  | i = 1
// 9	5	8	1	0	7	3	2	4  | i = 2
// 9	5	8	4	0	7	3	1	2  | i = 3


//                  9
//                 /\
//                5  8
//               /\  /\
//              4  0 7 3
//             /\
//            1  2
