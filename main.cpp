/*
 * Practica I - Ordenamiento de un gran conjunto de datos
 * ST0245 - Estructuras de Datos y Algoritmos
 * EAFIT University
 *
 * Este programa ordena 100,000 palabras usando tres estrategias:
 * 1. QuickSort sobre un vector
 * 2. HeapSort con Binary Heap
 * 3. Arbol AVL con recorrido inorder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#include "QuickSort.h"
#include "HeapSort.h"
#include "AVLTree.h"

using namespace std;
using namespace std::chrono;

// funcion para cargar las palabras del archivo
// el dataset puede venir en UTF-16 (windows) asi que hay que limpiarlo
vector<string> cargarDataset(string archivo) {
    vector<string> palabras;

    ifstream file(archivo, ios::binary);
    if (!file.is_open()) {
        cout << "Error: no se pudo abrir " << archivo << endl;
        return palabras;
    }

    // leer todo el archivo de una vez
    string contenido((istreambuf_iterator<char>(file)),
                      istreambuf_iterator<char>());
    file.close();

    // separar por lineas y limpiar caracteres raros
    string palabraActual = "";
    for (int i = 0; i < contenido.size(); i++) {
        char c = contenido[i];
        if (c == '\n') {
            // limpiar: solo quedarnos con letras ASCII normales
            string limpia = "";
            for (int j = 0; j < palabraActual.size(); j++) {
                unsigned char ch = palabraActual[j];
                if (ch >= 32 && ch < 127) {
                    limpia += ch;
                }
            }
            if (limpia.size() > 0) {
                palabras.push_back(limpia);
            }
            palabraActual = "";
        } else {
            palabraActual += c;
        }
    }

    // ultima linea por si no termina en \n
    string limpia = "";
    for (int j = 0; j < palabraActual.size(); j++) {
        unsigned char ch = palabraActual[j];
        if (ch >= 32 && ch < 127) {
            limpia += ch;
        }
    }
    if (limpia.size() > 0) {
        palabras.push_back(limpia);
    }

    return palabras;
}

// verifica que un vector este ordenado
bool estaOrdenado(vector<string>& v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) return false;
    }
    return true;
}

// guardar resultado en archivo
void guardarResultado(vector<string>& v, string archivo) {
    ofstream out(archivo);
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << endl;
    }
    out.close();
}

int main() {
    cout << "============================================" << endl;
    cout << "  Practica I - Sorting Large Dataset" << endl;
    cout << "  ST0245 - Estructuras de Datos - EAFIT" << endl;
    cout << "============================================" << endl;

    // cargar dataset
    cout << "\nCargando dataset..." << endl;
    vector<string> original = cargarDataset("dataset.txt");
    int n = original.size();
    cout << "Se cargaron " << n << " palabras" << endl;

    if (n == 0) {
        cout << "Error: no se pudieron cargar las palabras" << endl;
        return 1;
    }

    // mostrar las primeras 5 para verificar
    cout << "Primeras 5: ";
    for (int i = 0; i < 5 && i < n; i++) {
        cout << original[i] << " ";
    }
    cout << endl;

    double tiempoQS, tiempoHS, tiempoAVL;

    // ============================================
    // A) QUICKSORT
    // ============================================
    {
        cout << "\n--- A) QUICKSORT ---" << endl;

        vector<string> datos = original;  // copia para no modificar el original

        auto inicio = high_resolution_clock::now();
        QuickSort qs;
        qs.sort(datos);
        auto fin = high_resolution_clock::now();

        tiempoQS = duration_cast<microseconds>(fin - inicio).count() / 1000.0;
        cout << "Tiempo: " << tiempoQS << " ms" << endl;
        cout << "Ordenado correctamente: " << (estaOrdenado(datos) ? "SI" : "NO") << endl;

        guardarResultado(datos, "sorted_quicksort.txt");
    }

    // ============================================
    // B) HEAPSORT
    // ============================================
    {
        cout << "\n--- B) HEAPSORT ---" << endl;

        vector<string> datos = original;

        auto inicio = high_resolution_clock::now();
        HeapSort hs;
        hs.sort(datos);
        auto fin = high_resolution_clock::now();

        tiempoHS = duration_cast<microseconds>(fin - inicio).count() / 1000.0;
        cout << "Tiempo: " << tiempoHS << " ms" << endl;
        cout << "Ordenado correctamente: " << (estaOrdenado(datos) ? "SI" : "NO") << endl;

        guardarResultado(datos, "sorted_heapsort.txt");
    }

    // ============================================
    // C) ARBOL AVL
    // ============================================
    {
        cout << "\n--- C) ARBOL AVL ---" << endl;

        auto inicio = high_resolution_clock::now();

        AVLTree arbol;
        for (int i = 0; i < original.size(); i++) {
            arbol.insertar(original[i]);
        }
        vector<string> ordenado = arbol.obtenerOrdenado();

        auto fin = high_resolution_clock::now();

        tiempoAVL = duration_cast<microseconds>(fin - inicio).count() / 1000.0;
        cout << "Tiempo: " << tiempoAVL << " ms" << endl;
        cout << "Ordenado correctamente: " << (estaOrdenado(ordenado) ? "SI" : "NO") << endl;
        cout << "Nodos en el arbol: " << arbol.getCantidad() << endl;

        if (arbol.getCantidad() < n) {
            cout << "Nota: " << (n - arbol.getCantidad()) << " palabras eran duplicadas" << endl;
        }

        guardarResultado(ordenado, "sorted_avl.txt");
    }

    // ============================================
    // ANALISIS DE MEMORIA
    // ============================================
    cout << "\n============================================" << endl;
    cout << "  ANALISIS DE MEMORIA" << endl;
    cout << "============================================" << endl;

    cout << "\nsizeof(string): " << sizeof(string) << " bytes" << endl;
    cout << "sizeof(Nodo AVL): " << sizeof(Nodo) << " bytes" << endl;

    // estimacion: cada string ocupa sizeof(string) + ~8 bytes de contenido
    int promedio = 8;  // longitud promedio de las palabras
    long memVector = n * (sizeof(string) + promedio);
    long memAVL = n * (sizeof(Nodo) + promedio);

    cout << "\nMemoria estimada:" << endl;
    cout << "  QuickSort (vector): " << memVector / 1024 << " KB" << endl;
    cout << "  HeapSort (vector):  " << memVector / 1024 << " KB" << endl;
    cout << "  AVL Tree (nodos):   " << memAVL / 1024 << " KB" << endl;

    cout << "\nEspacio adicional:" << endl;
    cout << "  QuickSort: O(log n) por la recursion" << endl;
    cout << "  HeapSort:  O(1) - ordena in-place" << endl;
    cout << "  AVL Tree:  O(n) - cada nodo tiene punteros" << endl;

    // ============================================
    // ANALISIS COMPARATIVO
    // ============================================
    cout << "\n============================================" << endl;
    cout << "  ANALISIS COMPARATIVO" << endl;
    cout << "============================================" << endl;

    cout << "\nComplejidad Big O:" << endl;
    cout << "  QuickSort -> Mejor: O(n log n) | Promedio: O(n log n) | Peor: O(n^2)" << endl;
    cout << "  HeapSort  -> Mejor: O(n log n) | Promedio: O(n log n) | Peor: O(n log n)" << endl;
    cout << "  AVL Tree  -> Insercion: O(n log n) + Inorder: O(n) = O(n log n)" << endl;

    cout << "\nTiempos reales:" << endl;
    cout << "  QuickSort: " << tiempoQS << " ms" << endl;
    cout << "  HeapSort:  " << tiempoHS << " ms" << endl;
    cout << "  AVL Tree:  " << tiempoAVL << " ms" << endl;

    // determinar el ganador
    string ganador = "QuickSort";
    double mejor = tiempoQS;
    if (tiempoHS < mejor) { mejor = tiempoHS; ganador = "HeapSort"; }
    if (tiempoAVL < mejor) { mejor = tiempoAVL; ganador = "AVL Tree"; }

    cout << "\nAlgoritmo mas rapido: " << ganador << " (" << mejor << " ms)" << endl;

    cout << "\nPor que la teoria difiere de la practica?" << endl;
    cout << "- QuickSort es mas rapido por cache locality (accede a memoria secuencial)" << endl;
    cout << "- HeapSort salta entre posiciones padre-hijo (mala localidad)" << endl;
    cout << "- AVL necesita allocar memoria con 'new' para cada nodo (costoso)" << endl;
    cout << "- Big O ignora las constantes multiplicativas" << endl;

    cout << "\n============================================" << endl;
    cout << "  PROGRAMA FINALIZADO" << endl;
    cout << "============================================" << endl;

    return 0;
}
