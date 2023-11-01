#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
#include <fstream>

#include "Heap_Sort.hpp"

int main() {
    int n = 10000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    using std::chrono::nanoseconds;

    for (int i = 1; i <= n; ++i) {
        std::vector<int> arr(i);
        std::vector<int> arr2(i);
        for (int j = 0; j < i; ++j) {
            arr[j] = dist(gen);
            arr2[j] = arr[j];
        }
        
        // for (auto i: arr){
        //     std::cout << i << ' ';
        // }
        // std::cout << '\n';

        nanoseconds total_first(0);
        nanoseconds total_second(0);

        auto start_first = std::chrono::steady_clock::now();
        heap_sort_first(arr);
        auto end_first = std::chrono::steady_clock::now();
        
        // for (auto i: arr){
        //     std::cout << i << ' ';
        // }
        // std::cout << '\n';

        auto start_second = std::chrono::steady_clock::now();
        heap_sort_second(arr2);
        auto end_second = std::chrono::steady_clock::now();
        
        // for (auto i: arr){
        //     std::cout << i << ' ';
        // }
        // std::cout << '\n';

        nanoseconds time_taken_first = std::chrono::duration_cast<nanoseconds>(end_first - start_first);
        nanoseconds time_taken_second = std::chrono::duration_cast<nanoseconds>(end_second - start_second);

        total_first += time_taken_first;
        total_second += time_taken_second;
        

        std::ofstream heap_sort_first_output("Heap_Sort_First_1_10000.txt", std::ios_base::app);
        heap_sort_first_output << i << ", " << total_first.count() << '\n';
        heap_sort_first_output.close();

        std::ofstream heap_sort_second_output("Heap_Sort_Second_1_10000.txt", std::ios_base::app);
        heap_sort_second_output << i << ", " << total_second.count() << '\n';
        heap_sort_second_output.close();
    }
}
