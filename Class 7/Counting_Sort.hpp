#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <vector>
#include <algorithm>

std::vector<int> counting_sort(const std::vector<int> &arr) {
    if (arr.empty()) {
        return std::vector<int>();
    }

    auto mx = std::max_element(arr.begin(), arr.end());

    std::vector<int> cnt(*mx + 1, 0);
    for (auto x: arr) {
        cnt[x]++;
    }

    for (int i = 1; i <= *mx; i++) {
        cnt[i] += cnt[i - 1];
    }

    int n = arr.size();
    std::vector<int> output (n, 0);
    for (int i = n - 1; i >= 0; i--) {
        cnt[arr[i]]--;
        output[cnt[arr[i]]] = arr[i];
    }

    return output;
}

#endif // COUNTING_SORT_HPP
