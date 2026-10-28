#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo{
    public:
        T dato;
        Nodo<T>* siguiente;
        Nodo<T>* anterior;

        Nodo(T valor):
            dato(valor), siguiente(nullptr), anterior(nullptr){}
};
#endif /* NODO_H */