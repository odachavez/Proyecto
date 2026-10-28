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
        opcion = menu.crearMenu(Menu :: Principal);
        switch (opcion)
        {
            case 0: //Agregar Fotos
                system("cls");
                agregar(listaFotos);
                break;
            case 1://Mostrar una Foto de la Galeria
                menu.crearGaleria(Menu :: Mostrar, listaFotos);
                break;
            case 2://Buscar una foto por un parametro dado
               break;

            case 3://Eliminar una Foto de la Galeria
                menu.crearGaleria(Menu :: Eliminar, listaFotos);
                
                break;
            default:
                break;
        }
    }while(opcion != menu.getOpciones() - 1);
}