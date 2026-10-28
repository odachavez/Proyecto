#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <conio.h>
#include "ListaDobleEnlazada.h"
#include "Foto.h"
using namespace std;

class Menu{
	private:
		int opciones;

	public:
		enum MENUS{Principal};
        
		int crearMenu(MENUS Menu){
            int seleccion = 0;
            int tecla;

            string principal []= {
                "Agregar Foto",
                "Navegar en la Galeria",
				"Buscar Foto",
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

			do{
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
			}while(tecla != 13);
			return seleccion;
		}

		enum OPCIONES{Mostrar, Eliminar};

		void crearGaleria(OPCIONES _opciones,ListaDoble<Foto>& listaFotos){
			Nodo<Foto>* actual = listaFotos.getCabeza();
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
				"Seleccionar Foto",
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

								case 1: // Mostrar Foto/Eliminar Foto
									if(actual->siguiente != nullptr){
										actual = actual->siguiente;
									}else{
										cout << "Estas en la ultima foto." << endl;
										system("pause");
									}
									break;

								case 2:
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

								case 1: // Mostrar Foto/Eliminar Foto
									cout << "FOTO ELIMINADA..." << endl;
									break;
								
								case 2:
									if(actual->siguiente != nullptr){
										actual = actual->siguiente;
									}else{
										cout << "Estas en la ultima foto." << endl;
										system("pause");
									}
									break;
								
								case 3:
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