#ifndef MENU_VALIDACIONES_H_
#define MENU_VALIDACIONES_H_

#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "ListaDobleEnlazada.h"
#include "Foto.h"

using namespace std;

class Menu {
    private:
        int opciones;
    
        int leerEntero(const string& mensaje) {
            string linea;
            int valor;
            while (true) {
                cout << mensaje;
                if (getline(cin, linea)) {
                    stringstream flujo(linea);
                    char sobrante;
                    // Si extrae el entero y no hay caracteres sobrantes
                    if ((flujo >> valor) && !(flujo >> sobrante)) {
                        return valor;
                    }
                }
                cout << "Entrada invalida. Por favor, ingrese un numero entero.\n";
            }
        }
    
        // Validaci�n robusta para n�meros decimales (espacio en MB)
        double leerDouble(const string& mensaje) {
            string linea;
            double valor;
            while (true) {
                cout << mensaje;
                if (getline(cin, linea)) {
                    stringstream flujo(linea);
                    char sobrante;
                    if ((flujo >> valor) && !(flujo >> sobrante)) {
                        return valor;
                    }
                }
                cout << "Entrada invalida. Por favor, ingrese un numero valido.\n";
            }
        }
    
    public:
        enum MENUS { Principal };
        enum OPCIONES { Mostrar, Eliminar };
    
    
        void agregarFoto(ListaDoble<Foto>& fotos) {
            string titulo, formato, ubicacion;
            int dia, mes, anio;
            double espacio;
        
            cout << "================== AGREGAR NUEVA FOTO ==================" << endl;
        
            cout << "Titulo de la foto: ";
            getline(cin >> ws, titulo); // ws limpia el buffer por si hay saltos de linea previos
        
            cout << "Introduzca formato (JPG, PNG): ";
            cin >> formato;
        
            cout << "Ubicacion del archivo: ";
            getline(cin >> ws, ubicacion);
        
            cout << "--- FECHA ---" << endl;
            // Uso de nuestras validaciones personalizadas
            dia = leerEntero("Dia: ");
            mes = leerEntero("Mes: ");
            anio = leerEntero("Anio: ");
            espacio = leerDouble("Espacio (MB): ");
        
            Fecha fecha(anio, mes, dia);
            fotos.enlistarCola(Foto(titulo, formato, fecha, ubicacion, espacio));
            cout << "Foto agregada exitosamente...\n";
            system("pause");
        }
    
        int crearMenu(MENUS Menu) {
            int seleccion = 0;
            int tecla;
        
            string principal[] = {
                "Agregar Foto",
                "Navegar en la Galeria",
                "Eliminar Foto",
                "Salir"
            };
        
            string* menu = nullptr;
            switch(Menu){
                case Principal:
                    opciones = sizeof(principal)/sizeof(principal[0]);
                    menu = principal;
                    break;
            }
        
            do {
                system("cls");
                switch(Menu){
                    case Principal: cout << "========== MENU ==========" << endl; break;
                }
            
                for(int i = 0; i < opciones; i++){
                    if(seleccion == i){
                        cout << "> " << menu[i] << endl;
                    }else{
                        cout << menu[i] << endl;
                    }
                }
            
                tecla = _getch();
                if(tecla == 80 && seleccion < opciones - 1) seleccion++;
                if(tecla == 72 && seleccion > 0) seleccion--;
            } while(tecla != 13);
            return seleccion;
        }
    
        void crearGaleria(OPCIONES _opciones, ListaDoble<Foto>& listaFotos) {
            ListaDoble<Foto> :: Nodo* actual = listaFotos.getCabeza();
            if(actual == nullptr){
                cout << "La Galeria esta Vacia" << endl;
                system("pause");
                return;
            }
        
            int seleccion = 0;
            int tecla;
        
            string navegacionMostrar[] = {
                "Anterior Foto",
                "Siguiente Foto",
                "Regresar"
            };
        
            string navegacionEliminar[] = {
                "Anterior Foto",
                "Eliminar Esta Foto",
                "Siguiente Foto",
                "Regresar"
            };
        
            string* navegacion = nullptr;
            switch(_opciones){
                case Mostrar:
                    navegacion = navegacionMostrar;
                    opciones = sizeof(navegacionMostrar)/sizeof(navegacionMostrar[0]);
                    break;
                case Eliminar:
                    navegacion = navegacionEliminar;
                    opciones = sizeof(navegacionEliminar)/sizeof(navegacionEliminar[0]);
                    break;
            }
        
            do {
                system("cls");
                cout << "================== GALERIA DE FOTOS ==================" << endl;
                listaFotos.mostrarLista(actual);
                cout << "====================== DETALLES ======================" << endl;
                listaFotos.mostrarElemento(actual);
                cout << "======================================================" << endl;
                for (int i = 0; i < opciones; i++) {
                    if (seleccion == i) {
                        cout << "> " << navegacion[i] << endl;
                    } else {
                        cout << navegacion[i] << endl;
                    }
                }
            
                tecla = _getch();
                if (tecla == 80 && seleccion < opciones - 1) seleccion++;
                if (tecla == 72 && seleccion > 0) seleccion--;
            
                if (tecla == 13) {
                    switch(_opciones){
                        case Mostrar:
                            switch (seleccion){
                                case 0: // Anterior Foto
                                    if (actual->anterior != nullptr){
                                        actual = actual->anterior;
                                    }else{
                                        cout << "Estas en la primera foto." << endl;
                                        system("pause");
                                    }
                                    break;
                                case 1: // Siguiente Foto
                                    if(actual->siguiente != nullptr){
                                        actual = actual->siguiente;
                                    }else{
                                        cout << "Estas en la ultima foto." << endl;
                                        system("pause");
                                    }
                                    break;
                                case 2: // Regresar
                                    return;
                            }
                            break;
                        
                        case Eliminar:
                            switch (seleccion){
                                case 0: // Anterior Foto
                                    if (actual->anterior != nullptr){
                                        actual = actual->anterior;
                                    }else{
                                        cout << "Estas en la primera foto." << endl;
                                        system("pause");
                                    }
                                    break;
                                case 1: // Eliminar Foto
                                    {
                                        ListaDoble<Foto>::Nodo* nodoABorrar = actual;
                                        if(actual->siguiente != nullptr) {
                                            actual = actual->siguiente;
                                        } else if (actual->anterior != nullptr) {
                                            actual = actual->anterior;
                                        } else {
                                            actual = nullptr;
                                        }
                                        listaFotos.eliminarNodo(nodoABorrar);
                                        cout << "FOTO ELIMINADA EXITOSAMENTE..." << endl;
                                        system("pause");
                                        if(actual == nullptr) return; // Regresa si qued� vac�a
                                    }
                                    break;
                                case 2: // Siguiente Foto
                                    if(actual->siguiente != nullptr){
                                        actual = actual->siguiente;
                                    }else{
                                        cout << "Estas en la ultima foto." << endl;
                                        system("pause");
                                    }
                                    break;
                                case 3: // Regresar
                                    return;
                            }
                            break;
                    }
                }
            } while (true);
        }
    
        int getOpciones(){return opciones;}
};

#endif /* MENU_H_ */
