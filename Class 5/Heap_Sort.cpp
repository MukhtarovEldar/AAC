#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
#include <fstream>

#include "Heap_Sort.hpp"

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
            std::vector<int> arr2(i);

            nanoseconds total_first(0);
            nanoseconds total_second(0);

            for (int k = 0; k < m; k++) {
                for (int j = 0; j < i; j++) {
                    arr[j] = dist(gen);
                    arr2[j] = arr[j];
                }

                auto start_first = std::chrono::steady_clock::now();
                heap_sort_first(arr);
                auto end_first = std::chrono::steady_clock::now();

                auto start_second = std::chrono::steady_clock::now();
                heap_sort_second(arr2);
                auto end_second = std::chrono::steady_clock::now();
                
                nanoseconds time_taken_first = std::chrono::duration_cast<nanoseconds>(end_first - start_first);
                nanoseconds time_taken_second = std::chrono::duration_cast<nanoseconds>(end_second - start_second);

                total_first += time_taken_first;
                total_second += time_taken_second;
            }
            
            std::ofstream heap_sort_first_output("Heap_Sort_First_1_10000.txt", std::ios_base::app);
            heap_sort_first_output << i << ", " << (total_first / m).count() << '\n';
            heap_sort_first_output.close();

            std::ofstream heap_sort_second_output("Heap_Sort_Second_1_10000.txt", std::ios_base::app);
            heap_sort_second_output << i << ", " << (total_second / m).count() << '\n';
            heap_sort_second_output.close();
        }
    }
}
