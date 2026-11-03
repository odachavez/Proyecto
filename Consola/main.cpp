#include <iostream>
#include "Menu_Validaciones.h"
#include "ListaDobleEnlazada.h"
#include "Operaciones_ListaDoble.h"
#include "Foto.h"

using namespace std;

int main() {
    ListaDoble<Foto> listaFotos;
    Menu menu;
    int opcion;

    do {
        opcion = menu.crearMenu(Menu::Principal);
        switch (opcion) {
            case 0: // Agregar Fotos
                system("cls");
                menu.agregarFoto(listaFotos);
                break;
            case 1: // Mostrar una Foto de la Galeria
                menu.crearGaleria(Menu::Mostrar, listaFotos);
                break;
            case 2: // Eliminar una Foto de la Galeria
                menu.crearGaleria(Menu::Eliminar, listaFotos);
                break;
            default:
                break;
        }
    } while(opcion != menu.getOpciones() - 1);

    return 0;
}
