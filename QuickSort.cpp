#include "QuickSort.h"

// metodo publico para ordenar
void QuickSort::sort(vector<string>& arr) {
    if (arr.size() <= 1) return;
    quickSort(arr, 0, arr.size() - 1);
}

// funcion partition: elige el ultimo elemento como pivote
// y reacomoda el arreglo para que los menores queden a la izquierda
int QuickSort::partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];  // pivote = ultimo elemento
    int i = low - 1;  // indice de la zona de menores

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // poner pivote en su lugar
    return i + 1;
}

// quicksort recursivo
void QuickSort::quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);   // ordenar izquierda
        quickSort(arr, pi + 1, high);   // ordenar derecha
    }
}
