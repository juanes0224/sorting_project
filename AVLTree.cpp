#include "AVLTree.h"
#include <algorithm>

AVLTree::AVLTree() {
    raiz = nullptr;
    cantidad = 0;
}

AVLTree::~AVLTree() {
    destruir(raiz);
}

// elimina todos los nodos para no tener memory leaks
void AVLTree::destruir(Nodo* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izq);
    destruir(nodo->der);
    delete nodo;
}

int AVLTree::altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

// factor de balance = altura izquierda - altura derecha
// si es > 1 o < -1, hay que rotar
int AVLTree::balance(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

int AVLTree::getCantidad() {
    return cantidad;
}

// rotacion a la derecha (cuando esta cargado a la izquierda)
//      y                x
//     / \              / \
//    x   T3   -->    T1   y
//   / \                  / \
//  T1  T2              T2   T3
Nodo* AVLTree::rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;

    // actualizar alturas (y primero porque quedo mas abajo)
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;

    return x;  // nueva raiz
}

// rotacion a la izquierda (cuando esta cargado a la derecha)
Nodo* AVLTree::rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;

    return y;
}

// metodo publico para insertar
void AVLTree::insertar(string palabra) {
    raiz = insertarNodo(raiz, palabra);
}

// insercion recursiva con balanceo
Nodo* AVLTree::insertarNodo(Nodo* nodo, string palabra) {
    // caso base: llegamos a un espacio vacio, crear nodo
    if (nodo == nullptr) {
        cantidad++;
        return new Nodo(palabra);
    }

    // buscar donde insertar (como en un BST normal)
    if (palabra < nodo->palabra)
        nodo->izq = insertarNodo(nodo->izq, palabra);
    else if (palabra > nodo->palabra)
        nodo->der = insertarNodo(nodo->der, palabra);
    else
        return nodo;  // palabra repetida, no insertar

    // actualizar la altura de este nodo
    nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));

    // revisar si se desbalanceo
    int bal = balance(nodo);

    // caso LL: cargado a la izquierda y la palabra fue a la izq de la izq
    if (bal > 1 && palabra < nodo->izq->palabra)
        return rotarDerecha(nodo);

    // caso RR: cargado a la derecha
    if (bal < -1 && palabra > nodo->der->palabra)
        return rotarIzquierda(nodo);

    // caso LR: cargado a la izq pero la palabra fue a la derecha del hijo izq
    if (bal > 1 && palabra > nodo->izq->palabra) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    // caso RL: cargado a la der pero la palabra fue a la izq del hijo der
    if (bal < -1 && palabra < nodo->der->palabra) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;  // no hubo desbalance
}

// recorrido inorder: izquierda -> nodo -> derecha
// en un BST esto da los elementos en orden ascendente
vector<string> AVLTree::obtenerOrdenado() {
    vector<string> resultado;
    resultado.reserve(cantidad);
    inorder(raiz, resultado);
    return resultado;
}

void AVLTree::inorder(Nodo* nodo, vector<string>& resultado) {
    if (nodo == nullptr) return;
    inorder(nodo->izq, resultado);
    resultado.push_back(nodo->palabra);
    inorder(nodo->der, resultado);
}
