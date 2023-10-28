#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

constexpr int max_times = 10000;
constexpr int max_size = 16769;

class Vector {
private:
    int capacity;
    int size;
    int *data;

public:
    Vector():
        capacity(1),
        size(1),
        data(new int[1])
    {
        data[0] = 1;
    }

    void push_back(int element){
        if(size < capacity){
            data[size] = element;
            size++;
        }
        else{
            int new_capacity = capacity * 2;
            int *new_data = new int[new_capacity];
            for(int i=0; i<size; i++){
                new_data[i] = data[i];
            }
            new_data[size] = element;
            if (data != nullptr) {
                delete []data;
            }
            data = new_data;
            capacity = new_capacity;
            size++;
        }
    }

    void push_back_1_5(int element){
        if(size < capacity){
            data[size] = element;
            size++;
        }
        else{
            int new_capacity = std::ceil((double)capacity * 1.5);
            int* new_data = new int[new_capacity];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            new_data[size] = element;
            if (data != nullptr) {
                delete []data;
            }
            data = new_data;
            capacity = new_capacity;
            size++;
        }
    }

    void push_back_1_15(int element) {
        if(size < capacity){
            data[size] = element;
            size++;
        }
        else{
            int new_capacity = std::ceil((double)capacity * 1.15);
            int* new_data = new int[new_capacity];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            new_data[size] = element;
            if (data != nullptr) {
                delete []data;
            }
            data = new_data;
            capacity = new_capacity;
            size++;
        }
    }

    void push_back_100(int element) {
        if (size < capacity) {
            data[size] = element;
            size++;
        }
        else {
            int new_capacity = capacity + 100;
            int* new_data = new int[new_capacity];
            for(int i=0; i<size; i++){
                new_data[i] = data[i];
            }
            new_data[size] = element;
            if (data != nullptr) {
                delete []data;
            }
            data = new_data;
            capacity = new_capacity;
            size++;
        }
    }

    ~Vector() {
        if (data != nullptr) {
            delete []data;
        }
    }
};

int main() {
    using std::chrono::nanoseconds;

    std::vector<nanoseconds> totals_2(max_size);
    std::vector<nanoseconds> totals_1_5(max_size);
    std::vector<nanoseconds> totals_1_15(max_size);
    std::vector<nanoseconds> totals_100(max_size);

    for(int times = 0; times < max_times; times++){
        Vector xs_2;
        Vector xs_1_5;
        Vector xs_1_15;
        Vector xs_100;
        for(int size = 1; size < max_size; size++ ){
            auto start = std::chrono::steady_clock::now();
            xs_2.push_back(1);
            auto end = std::chrono::steady_clock::now();

            nanoseconds time_taken =
                std::chrono::duration_cast<nanoseconds>(end - start);

            totals_2[size] += time_taken;

            start = std::chrono::steady_clock::now();
            xs_1_5.push_back_1_5(1);
            end = std::chrono::steady_clock::now();

            time_taken =
                std::chrono::duration_cast<nanoseconds>(end - start);

            totals_1_5[size] += time_taken;

            start = std::chrono::steady_clock::now();
            xs_1_15.push_back_1_15(1);
            end = std::chrono::steady_clock::now();

            time_taken =
                std::chrono::duration_cast<nanoseconds>(end - start);

            totals_1_15[size] += time_taken;

            start = std::chrono::steady_clock::now();
            xs_100.push_back_100(1);
            end = std::chrono::steady_clock::now();

            time_taken =
                std::chrono::duration_cast<nanoseconds>(end - start);

            totals_100[size] += time_taken;
        }
    }

    for(int size = 1; size < max_size; size++){
        std::cout << size << ", " << totals_100[size].count() / max_times << std::endl;
    }
}
