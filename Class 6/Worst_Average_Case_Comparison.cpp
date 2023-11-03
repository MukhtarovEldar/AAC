#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>

#include "Quick_Sort.hpp"

int main() {
    const int m = 1000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 5000);

    using std::chrono::nanoseconds;
    
    for (int p = 1 ; p < 10000 ; p *= 10) {
		for (int d = 1 ; d < 10 ; d++) {
			int i = d * p;
            
            std::vector<int> arr(i);

            nanoseconds total_avg(0);
            nanoseconds total_wrs(0);

            for (int k = 0; k < m; k++) {
                for (int j = 0; j < i; j++) {
                    arr[j] = dist(gen);
                }
        
                // Average Case Scenario
                auto start_avg = std::chrono::steady_clock::now();
                Quick_Sort(arr, 0, arr.size() - 1);
                auto end_avg = std::chrono::steady_clock::now();

                nanoseconds time_taken_avg = std::chrono::duration_cast<nanoseconds>(end_avg - start_avg);

                total_avg += time_taken_avg;

                // Worst Case Scenario
                reverse(arr.begin(), arr.end());

                auto start_wrs = std::chrono::steady_clock::now();
                Quick_Sort(arr, 0, arr.size() - 1);
                auto end_wrs = std::chrono::steady_clock::now();

                nanoseconds time_taken_wrs = std::chrono::duration_cast<nanoseconds>(end_wrs - start_wrs);

                total_wrs += time_taken_wrs;
            }

            std::ofstream quick_sort_average_output("Quick_Sort_Average_1_10000.txt", std::ios_base::app);
            quick_sort_average_output << i << ", " << (total_avg / m).count() << '\n';
            quick_sort_average_output.close();

            std::ofstream quick_sort_worst_output("Quick_Sort_Worst_1_10000.txt", std::ios_base::app);
            quick_sort_worst_output << i << ", " << (total_wrs / m).count() << '\n';
            quick_sort_worst_output.close();
        }
    }
}
