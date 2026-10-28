#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include <iostream>
#include "Nodo.h"
using namespace std;

template <typename T>
class ListaDoble{
    private:
        Nodo<T>* cabeza;
        Nodo<T>* cola;
    
    public:
        ListaDoble():
            cabeza(nullptr), cola(nullptr){}

        ~ListaDoble(){
            while(cabeza){
                Nodo<T>* borrar = cabeza;
                cabeza = cabeza->siguiente;
                delete borrar;
            }
        }

        Nodo<T>* getCabeza(){return cabeza;}

        void enlistarCola(T valor){
            Nodo<T>* nuevo = new Nodo<T>(valor);
            //Se ingresa el primer elemento, la cabeza y cola es el mismo nodo
            if(!cabeza){
                cabeza = nuevo;
                cola = nuevo;
            }else{
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                cola = nuevo;
            }
        }

        void enlistarCabeza(T valor){
            Nodo<T>* nuevo = new Nodo<T>(valor);
            //Se ingresa el primer elemento, la cabeza y cola es el mismo nodo
            if(!cabeza){
                cabeza = nuevo;
                cola = nuevo;
            }else{
                cabeza->anterior = nuevo;
                nuevo->siguiente = cabeza;
                cabeza = nuevo;
            }
        }

        void eliminarNodo(Nodo<T>* nodoAEliminar) {
            if (!cabeza || !nodoAEliminar) return; // Si la lista está

            if(nodoAEliminar == cabeza){
                cabeza = cabeza->siguiente;
                if (cabeza != nullptr) {
                    cabeza->anterior = nullptr;
                } else {
                    cola = nullptr;
                }
            }else if(nodoAEliminar == cola){
                cola = cola->anterior;
                if (cola != nullptr) {
                    cola->siguiente = nullptr;
                }
            }else{
                nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
                nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;
            }

            delete nodoAEliminar;
        }

        void mostrarLista(Nodo<T>* indice){
            int contador = 1;
            if(!cabeza) return;

            Nodo<T>* copia = cabeza;
            while(copia){
                if(copia == indice){
                    cout << "-> [IMAGEN " << contador << "]" << endl;
                }else{
                    cout << "[IMAGEN " << contador << "]" << endl;
                }
                copia = copia->siguiente;
                contador++;
            }
        }

        void mostrarElemento(Nodo<T>* indice){
            Nodo<T>* actual = cabeza;
            int contador = 0;

            while(actual){
                if(actual == indice) {
                    actual->dato.mostrarDatos();
                    return;
                }
                actual = actual->siguiente;
                contador++;
            }
        }
};
#endif /* LISTADOBLEENLAZADA_H */