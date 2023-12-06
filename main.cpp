#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "sort_h.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    //data harvesting parameters
    int maxSize = 10000;
    //int sizeStep = 100;
    int maxTimes = 100;

    //proper randomisation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, maxSize / 10);

    //time measurement
    using clock = std::chrono::steady_clock;
    using ns = std::chrono::nanoseconds;

    //record file
    std::ofstream file_out;
    file_out.open("hybrid.txt");
   // file_out << "size, insert qucik heap radix" << std::endl;
   file_out << "size, hybrid"<<std::endl;
    for (int size = 100; size <= maxSize; size += 100)
    {
        ns hybrid_time(0), insertion_time(0), quicksort_time(0), heapsort_time(0), radixsort_time(0);


        for (int times = 0; times < maxTimes; ++times)
        {
            std::vector<int> list;
            list.reserve(size);

            for (int i = 0; i < size; ++i)
            {
                list.push_back(dist(gen));
                //std::cout<<list[i]<<std::endl;
            }

           /* auto insertion_start = clock::now();
            insertion_sort(list);
            auto insertion_end = clock::now();
            insertion_time += std::chrono::duration_cast<ns>(insertion_end - insertion_start);

            std::shuffle(list.begin(), list.end(), gen);

            auto quicksort_start = clock::now();
            quicksort(list, 0, list.size() - 1);
            auto quicksort_end = clock::now();
            quicksort_time += std::chrono::duration_cast<ns>(quicksort_end - quicksort_start);

            std::shuffle(list.begin(), list.end(), gen);

            auto heapsort_start = clock::now();
            Heapsort(list, list.size());
            auto heapsort_end = clock::now();
            heapsort_time += std::chrono::duration_cast<ns>(heapsort_end - heapsort_start);

            std::shuffle(list.begin(), list.end(), gen);

            auto radixsort_start = clock::now();
            RadixSort(list);
            auto radixsortEnd = clock::now();
            radixsort_time += std::chrono::duration_cast<ns>(radixsortEnd - radixsort_start); */

            auto hybrid_start =clock::now();
            hybrid_sort(list, 0, list.size() - 1);
            auto hybrid_end = clock::now();
            hybrid_time += std::chrono::duration_cast<ns>(hybrid_end-hybrid_start);


           // std::shuffle(list.begin(), list.end(), gen);

            // Uncomment the following lines when you have a RadixSort implementation

          //  std::shuffle(list.begin(), list.end(), gen);


           // hybrid_time += std::chrono::duration_cast<ns>(end - start);
        }


        file_out << size << ' ' << hybrid_time.count() / maxSize<< std::endl;
    }

    file_out.close();




    return 0;
}
