#include <iostream>
#include "./sort_h.h"


void SWAP (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Hepify(std::vector <int> &xs, unsigned N, int  i)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    int large = i;

    if(L < N && xs[L] > xs[i])
    {
        large = L;
    }
    if(R < N && xs[R] > xs[large])
    {
        large = R;
    }

    if(i != large)
    {
        SWAP(xs[i], xs[large]);
        Hepify(xs,N, large);
    }
}

void Heapsort(std::vector<int>&xs, int n)
{
    for(int i = (n / 2 - 1); i >= 0; i--)
    {
        Hepify(xs, n, i);
    }

    for(int i = n - 1; i > 0; i--)
    {
        SWAP(xs[0], xs[i]);
        Hepify(xs, i, 0);
    }
}
void printArray(std::vector <int> &temp)
{
    for (int i : temp)
        std::cout << i << " ";
    std::cout << "\n";
}

void insertion_sort(std::vector <int>&xs)
{
    /*if vecotr is empty abort it */
   // assert(xs.empty());
    for(int i = 1; i < xs.size(); i++)
    {
        int temp = xs[i];
        int j = i - 1;

        while(j >= 0 && xs[j] > temp)
        {
            xs[j+1] = xs[j];
            j--;
        }
        xs[j+1] = temp;
    }
}
int partitioning(std::vector <int> &xs, int begin, int end)
{
    int pivot = xs[end];
    int i = begin - 1;

    for(int t = begin; t <= end; t++)
    {
        if(xs[t] < pivot)
        {
            i++;
            SWAP(xs[i], xs[t]);
        }
    }
    i++;
    SWAP(xs[i], xs[end]);
    return i;

}

void quicksort(std::vector<int>&xs, int begin, int end)
{
    //assert(end <= begin);
    if(end <= begin) return;
    int pivot = partitioning(xs, begin, end);
    quicksort(xs, begin, pivot - 1);
    quicksort(xs, pivot+1, end);


}
int get_max(std::vector <int> xs)
{
    int max = xs[0];
    for(int i =1; i < xs.size(); i++)
    {
        if(xs[i] > max){
            max = xs[i];
        }
    }
    return max;
}
void countSort(std::vector <int> &xs, int place)
{
    std::vector<int> result(xs.size());
    std::vector<int> count(10, 0);

    for (int x : xs)
        count[(x / place) % 10]++;

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = xs.size() - 1; i >=0; i--)
    {
        result[count[(xs[i] / place) % 10] - 1] = xs[i];
        count[(xs[i] / place) % 10]--;

    }

    for(int i =0; i < xs.size(); i++)
    {
        xs[i] = result[i];
        assert(xs[i] == result[i]);
    }

}
void RadixSort(std::vector<int> &xs)
{
    int max = get_max(xs);
    for(int i = 1; (max / i) > 0; i*=10)
    {
        countSort(xs, i);
    }
}

void hybrid_sort(std::vector <int> &xs,int begin, int end)
{// If the size of the subarray is small (<= 40), use insertion sort
    if (end - begin <= 40)
    {
        int val;
        // Insertion sort
        for (int i = begin; i <= end; ++i)
        {
            val = xs[i];
            for (int j = i - 1; j + 1 >= begin; --j)
            {
                if (j >= begin && val < xs[j])
                {
                    xs[j + 1] = xs[j];
                }
                else
                {
                    xs[j + 1] = val;
                    break;
                }
            }
        }
    }
    else {
        // Quicksort


        int pivot = begin;
        int left = begin + 1;
        int right = end;

        // Partition the array
        while (left < right) {
            while (xs[left] <= xs[pivot] && left < right) {
                ++left;
            }

            while (xs[right] > xs[pivot]) {
                --right;
            }

            if (left <= right) {
                SWAP(xs[left], xs[right]);
            }
        }


        SWAP(xs[pivot], xs[right]);
        pivot = right;


        if (pivot - begin > 1) {
            hybrid_sort(xs, begin, pivot - 1);
        }

        if (end - pivot > 1) {
            hybrid_sort(xs, pivot + 1, end);
        }
    }
}

