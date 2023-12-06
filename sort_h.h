#ifndef ALGORITHM_COMPLEX_PR1_SORT_H_H
#define ALGORITHM_COMPLEX_PR1_SORT_H_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

void SWAP(int &a, int &b);
void Hepify(std::vector <int> &xs, unsigned N, int  i);
void Heapsort(std::vector<int>&xs, int n);
void printArray(std::vector <int>&temp);
void insertion_sort(std::vector <int>&xs);
int partitioning(std::vector <int> &xs, int begin, int end);
void quicksort(std::vector<int>&xs, int begin, int end);
int get_max(std::vector <int> xs);
void countSort(std::vector <int> &xs, int place);
void RadixSort(std::vector<int> &xs);
//void random_gen(std::vector<int>&xs);
void hybrid_sort(std::vector <int> &xs,int begin, int end);

#endif //ALGORITHM_COMPLEX_PR1_SORT_H_H
