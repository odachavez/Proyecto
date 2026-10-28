#include <iostream>
#include "Menu.h"
#include "ListaDobleEnlazada.h"
#include "Foto.h"
using namespace std;

void agregar(ListaDoble<Foto>& fotos){
    string titulo, formato, ubicacion;
    Fecha fecha;
    double espacio;

    cout << "================== AGREGAR NUEVA FOTO ==================" << endl;
    cout << "Titulo de la foto: ";
    cin >> titulo;
    cout << "Indroduzca formato (JPG, PNG): ";
    cin >> formato;
    cout << "Ubicacion de del archivo: ";
    cin >> ubicacion;
    cout << "FECHA" << endl;
    cout << "Dia: ";
    cin >> fecha.dia; 
    cout << "Mes: ";
    cin >> fecha.mes; 
    cout << "Anio: ";
    cin >> fecha.anio;
    cout << "Espacio (MB): ";
    cin >> espacio; 

    fotos.enlistarCola(Foto(titulo, formato, fecha, ubicacion, espacio));
}

int main(){
    ListaDoble<Foto> listaFotos;

    Menu menu;
    int opcion;
    do{
        opcion = menu.mostrar(Menu :: Principal);
        switch (opcion)
        {
            case 0: //Agregar Fotos
                system("cls");
                agregar(listaFotos);
                break;
            case 1:
                listaFotos.mostrarLista();
                system("pause");
                break;
            case 2:
                do{
                    opcion = menu.mostrar(Menu :: Galeria);
                    switch(opcion){

                        case 0:
                            
                            break;


                        case 1:

                            break;

                    }
                }while(opcion != menu.getOpciones() - 1);
                opcion = 0;
                break;
            default:
                break;
        }
    }while(opcion != menu.getOpciones() - 1);
}