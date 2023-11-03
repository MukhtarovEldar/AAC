#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

#include "Merge_Sort.hpp"
#include "Selection_Sort.hpp"

int main() {
    const int m = 1000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 5000);

    using std::chrono::nanoseconds;

    for (int p = 1 ; p < 10000 ; p *= 10) {
		for (int d = 1 ; d < 10 ; d++) {
			int i = d * p;
            
            nanoseconds total_ms(0);
            nanoseconds total_ss(0);
            
            std::vector<int> arr(i);
            std::vector<int> arr2(i);

            for (int k = 0; k < m; k++) {
                for (int j = 0; j < i; j++) {
                    arr[j] = dist(gen);
                    arr2[j] = arr[j];
                }

                auto start_ms = std::chrono::steady_clock::now();
                mergeSort(arr);
                auto end_ms = std::chrono::steady_clock::now();

                auto start_ss = std::chrono::steady_clock::now();
                selectionSort(arr2);
                auto end_ss = std::chrono::steady_clock::now();

                nanoseconds time_taken_ms = std::chrono::duration_cast<nanoseconds>(end_ms - start_ms);
                nanoseconds time_taken_ss = std::chrono::duration_cast<nanoseconds>(end_ss - start_ss);

                total_ms += time_taken_ms;
                total_ss += time_taken_ss;
            }

            std::ofstream merge_output_file("MergeSortOutput_1_10000.txt", std::ios_base::app);
            merge_output_file << i << ", " << (total_ms / m).count() << '\n';
            merge_output_file.close();

            std::ofstream selection_output_file("SelectionSortOutput_1_10000.txt", std::ios_base::app);
            selection_output_file << i << ", " << (total_ss / m).count() << '\n';
            selection_output_file.close();
        }
    }
}