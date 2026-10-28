#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <conio.h>
using namespace std;

class Menu{
	private:
		int opciones;

	public:
		enum Paneles{Principal, Galeria};
        
		int crearMenu(Paneles Menu){
            int seleccion = 0;
            int tecla;

            string principal []= {
                "Agregar Foto",
                "Mostrar Fotos",
                "Seleccionar Foto",
                "Eliminar Foto",
                "Salir"
            };

            string navegacion[] = {
                "Anterior Foto",
                "Siguiente Foto",
                "Regresar"
            };
            
            string* menu = nullptr;
            switch(Menu){
                case Principal:
                    opciones = sizeof(principal)/sizeof(principal[0]);
                    menu = principal;
                    break;

                case Galeria:
                    opciones = sizeof(navegacion)/sizeof(navegacion[0]);
                    menu = navegacion;
                    break;
            }

			do{
				system("cls");
				switch(Menu){
					case Principal: cout << "========== MENU ==========" << endl; break;
					case Galeria: cout << "========== NAVEGACION DE GALERIA ==========" << endl; break;
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

		int mostrar(Paneles menu){
			int opc = crearMenu(menu);
			return opc;
		}

		int getOpciones(){return opciones;}

};
#endif /* MENU_H_ */