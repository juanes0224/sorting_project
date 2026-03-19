#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <string>

using namespace std;

// estructura de un nodo del arbol AVL
struct Nodo {
    string palabra;
    Nodo* izq;
    Nodo* der;
    int altura;

    Nodo(string p) {
        palabra = p;
        izq = nullptr;
        der = nullptr;
        altura = 1;
    }
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insertar(string palabra);
    vector<string> obtenerOrdenado();
    int getCantidad();

private:
    Nodo* raiz;
    int cantidad;

    int altura(Nodo* nodo);
    int balance(Nodo* nodo);
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    Nodo* insertarNodo(Nodo* nodo, string palabra);
    void inorder(Nodo* nodo, vector<string>& resultado);
    void destruir(Nodo* nodo);
};

#endif
