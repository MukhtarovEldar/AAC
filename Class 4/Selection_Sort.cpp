#include <iostream>
#include <vector>

#include "Selection_Sort.hpp"

void selectionSort(std::vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minInd = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        std::swap(arr[i], arr[minInd]);
    }
}
