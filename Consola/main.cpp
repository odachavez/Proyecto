#include <iostream>
#include "Menu.h"
#include "ListaDobleEnlazada.h"
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
            case 2: // Buscar una foto (Pendiente)
                break;
            case 3: // Eliminar una Foto de la Galeria
                menu.crearGaleria(Menu::Eliminar, listaFotos);
                break;
            default:
                break;
        }
    } while(opcion != menu.getOpciones() - 1);

    return 0;
}
