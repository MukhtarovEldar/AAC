#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

#include "Counting_Sort.hpp"
#include "../Class 6/Quick_Sort.hpp"


int main() {
    const int m = 1000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10);

    using std::chrono::nanoseconds;
    
    for (int p = 1 ; p < 1'000'000 ; p *= 10) {
		for (int d = 1 ; d < 10 ; d++) {
			int i = d * p;

            std::vector<int> arr(i);

            nanoseconds total_cs(0);
            nanoseconds total_qs(0);

            for (int k = 0; k < m; k++) {
                for (int j = 0; j < i; j++) {
                    arr[j] = dist(gen);
                }

                std::vector<int> output;
                // Counting Sort
                auto start_cs = std::chrono::steady_clock::now();
                output = counting_sort(arr);
                auto end_cs = std::chrono::steady_clock::now();

                nanoseconds time_taken_cs = std::chrono::duration_cast<nanoseconds>(end_cs - start_cs);

                total_cs += time_taken_cs;

                // Quick Sort
                auto start_qs = std::chrono::steady_clock::now();
                Quick_Sort(arr, 0, arr.size() - 1);
                auto end_qs = std::chrono::steady_clock::now();

                nanoseconds time_taken_qs = std::chrono::duration_cast<nanoseconds>(end_qs - start_qs);

                total_qs += time_taken_qs;
            }

            std::ofstream counting_sort_output("Counting_Sort_1_1000000.txt", std::ios_base::app);
            counting_sort_output << i << ", " << (total_cs / m).count() << '\n';
            counting_sort_output.close();

            std::ofstream quick_sort_output("Quick_Sort_1_1000000.txt", std::ios_base::app);
            quick_sort_output << i << ", " << (total_qs / m).count() << '\n';
            quick_sort_output.close();
        }
    }
}