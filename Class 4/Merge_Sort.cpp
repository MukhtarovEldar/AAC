#include <iostream>
#include <vector>

#include "Merge_Sort.hpp"

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right){
    int l = 0, r = 0;
    std::vector<int> output;
    while (l != left.size() && r != right.size()) 
    {
        if (left[l] <= right[r])
        {
            output.push_back(left[l++]);
        }
        else
        {
            output.push_back(right[r++]);
        }
    }
    
    while (l != left.size()) {
        output.push_back(left[l++]);
    }

    while (r != right.size())
    {
        output.push_back(right[r++]);
    }
    
    return output;
}

void mergeSort(std::vector<int> &arr){
    if (arr.size() == 1)
    {
        return;
    }
    
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    mergeSort(left);
    mergeSort(right);

    arr = merge(left, right);
}