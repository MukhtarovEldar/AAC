#include <iostream>
#include <random>
#include <chrono>

int main() {
    using std::chrono::nanoseconds;
    std::random_device rd;
    std::mt19937 gen(rd());
    // TODO: Fix the code to correctly generate integers from the range [-n, n].
    int n = 10;
    std::uniform_int_distribution<int> dist(0, n/2);
    
    int max_times = 1000;

    for (unsigned int size = 100; size < 5000; size+=100) {
        nanoseconds total(0);
        int *haystack = new int[size];
        for (int times = 0; times < max_times; times++) {
            for (unsigned j = 0; j < size; j++) {
                haystack[j] = dist(gen);
            }

            int needle = dist(gen);

            auto start = std::chrono::steady_clock::now();

            for (unsigned j = 0; j < size; j++) {
                if (needle == haystack[j]) {
                    break;
                }
            }

            auto end = std::chrono::steady_clock::now();

            nanoseconds time_taken = std::chrono::duration_cast<nanoseconds>(end - start);

            total += time_taken;
        }
        total /= max_times;

        // std::cout << size << " " << total.count() << std::endl;

        std::cout << size << "," << total.count() << std::endl;


        delete [] haystack;
    }
}
