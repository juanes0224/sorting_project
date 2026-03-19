#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

using namespace std;

class QuickSort {
public:
    void sort(vector<string>& arr);

private:
    void quickSort(vector<string>& arr, int low, int high);
    int partition(vector<string>& arr, int low, int high);
};

#endif
