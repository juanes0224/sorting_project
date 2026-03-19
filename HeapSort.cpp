#include "HeapSort.h"

// heapify: se asegura que el nodo i sea mayor que sus hijos
// si no, los intercambia y sigue bajando
void HeapSort::heapify(vector<string>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // comparar con hijo izquierdo
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // comparar con hijo derecho
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // si algun hijo era mayor, intercambiar y seguir bajando
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort::sort(vector<string>& arr) {
    int n = arr.size();

    // paso 1: construir el max-heap
    // empezamos desde el ultimo nodo padre (n/2 - 1) hacia la raiz
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // paso 2: ir sacando el maximo (arr[0]) y ponerlo al final
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // el mayor va al final
        heapify(arr, i, 0);     // restaurar el heap con tamaño reducido
    }
}
