#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <string>

using namespace std;

class HeapSort {
public:
    void sort(vector<string>& arr);

private:
    void heapify(vector<string>& arr, int n, int i);
};

#endif
