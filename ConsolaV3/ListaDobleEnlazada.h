#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

template <typename T>
class ListaDoble {
    public:
        struct Nodo {
            T dato;
            Nodo* siguiente;
            Nodo* anterior;
        
            Nodo(const T& valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
        };
        
    private:
        Nodo* cabeza;
        Nodo* cola;
    
    public:
        ListaDoble();
        ~ListaDoble();
    
    
        ListaDoble(const ListaDoble&) = delete;
        ListaDoble& operator=(const ListaDoble&) = delete;
    
        Nodo* getCabeza() const;
        void enlistarCola(const T& valor);
        void enlistarCabeza(const T& valor);
        void eliminarNodo(Nodo* nodoAEliminar);
        void mostrarLista(Nodo* indice) const;
        void mostrarElemento(Nodo* indice) const;
};



#endif /* LISTADOBLEENLAZADA_H */
