#ifndef OPERACIONES_LISTADOBLE_H
#define OPERACIONES_LISTADOBLE_H

#include <iostream>
#include "ListaDobleEnlazada.h"

using namespace std;

// Constructor
template<typename T>
ListaDoble<T>::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

// Destructor
template<typename T>
ListaDoble<T>::~ListaDoble() {
    while (cabeza) {
        Nodo* borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
    }
}

// Obtener Cabeza
template<typename T>
typename ListaDoble<T>::Nodo* ListaDoble<T>::getCabeza() const {
    return cabeza;
}

// Enlistar Cola
template<typename T>
void ListaDoble<T>::enlistarCola(const T& valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

// Enlistar Cabeza
template<typename T>
void ListaDoble<T>::enlistarCabeza(const T& valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cabeza->anterior = nuevo;
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
}

// Eliminar Nodo
template<typename T>
void ListaDoble<T>::eliminarNodo(Nodo* nodoAEliminar) {
    if (!cabeza || !nodoAEliminar) return;

    if (nodoAEliminar == cabeza) {
        cabeza = cabeza->siguiente;
        if (cabeza != nullptr) {
            cabeza->anterior = nullptr;
        } else {
            cola = nullptr;
        }
    } else if (nodoAEliminar == cola) {
        cola = cola->anterior;
        if (cola != nullptr) {
            cola->siguiente = nullptr;
        }
    } else {
        nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
        nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;
    }
    delete nodoAEliminar;
}

// Mostrar Elemento
template<typename T>
string ListaDoble<T>::mostrarElemento(Nodo* indice) const {
    if (indice != nullptr) {
        return indice->dato.mostrarDatos();
    }
    return "";
}

template<typename T>
void ListaDoble<T>::limpiar() {
    while (cabeza) {
        Nodo* borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
    }
    cola = nullptr;
}
#endif /* OPERACIONES_LISTADOBLE_H */
