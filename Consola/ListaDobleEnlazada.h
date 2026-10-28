#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include "Nodo.h"

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

        int obtenerLongitud(){
            int contador = 0;
            Nodo<T>* actual = cabeza;
            
            while(actual != nullptr){
                contador++;
                actual = actual->siguiente;
            }
            
            return contador;
        }

        void mostrarLista(){
            if(!cabeza){
                cout << "Galeria vacia" << endl;
                return;
            }

            Nodo<T>* copia = cabeza;
            while(copia){
                copia->dato.mostrarDatos();
                copia = copia->siguiente;
            }
        }
};
#endif /* LISTADOBLEENLAZADA_H */