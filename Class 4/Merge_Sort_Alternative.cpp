#include <iostream>
#include <vector>

void Merge_Sort(std::vector<int> &lst) {
    int n = lst.size();
    int portion = 1;
    while (portion < n) {
        std::vector<int> temp;
        int left = 0;
        while (left + portion < n) {
            int right = left + portion;
            int left_end = right - 1;
            int right_end = (left_end + portion < n) ? left_end + portion : n - 1;
            int i = left;
            int j = right;
            while (i <= left_end && j <= right_end) {
                if (lst[i] < lst[j]) {
                    temp.push_back(lst[i++]);
                }
                else {
                    temp.push_back(lst[j++]);
                }
            }
            while (i <= left_end) {
                temp.push_back(lst[i++]);
            }
            while (j <= right_end) {
                temp.push_back(lst[j++]);
            }
            left += 2 * portion;
        }
        portion *= 2;
        for (int i = 0; i <= right_end; i++) {
            lst[i] = temp[i];
        }
    }
}

int main() {
    std::vector<int> lst = { 3, 2, 1, 5, 4, 7, 6, 9, 10, 8 };
    Merge_Sort(lst);
    for (int i = 0; i < lst.size(); i++) {
        std::cout << lst[i] << " ";
    }
    return 0;
}
