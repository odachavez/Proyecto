#ifndef FOTO_H
#define FOTO_H
#include <iostream>
using namespace std;
struct Fecha {
    int anio;
    int mes;
    int dia;

    Fecha(): 
        anio(0), mes(0), dia(0){}
        
    Fecha(int _anio, int _mes, int _dia):
        anio(_anio), mes(_mes), dia(_dia) {}
};

class Foto{
    private:
        string titulo;
        string formato;
        Fecha fecha;
        string ubicacion;
        double espacio;

    public:
        Foto():
            titulo(""), formato(""), fecha(), ubicacion(""), espacio(0.0) {}

        Foto(string _titulo, string _formato, Fecha _fecha, string _ubicacion, double _espacio):
            titulo(_titulo), formato(_formato), fecha(_fecha), ubicacion(_ubicacion), espacio(_espacio) {}

        string getTitulo(){return titulo;}
        string getFormato(){return formato;}
        Fecha getFecha(){return fecha;}
        string getUbicacion(){return ubicacion;}
        double getEspacio(){return espacio;}

        void setTitulo(string _titulo){titulo = _titulo;}
        void setFormato(string _formato){formato = _formato;}
        void setFecha(Fecha _fecha){fecha = _fecha;}
        void setUbicacion(string _ubicacion){ubicacion = _ubicacion;}
        void setEspacio(double _espacio){espacio = _espacio;}

        void mostrarDatos(){
            cout << "Titulo: " << titulo << endl
                 << "Formato: " << formato << endl
                 << "Ubicacion de del archivo: " << ubicacion << endl
                 << "FECHA: " << fecha.anio << "/" << fecha.mes << "/" << fecha.dia << endl
                 << "Espacio (MB): " << espacio << endl;
        }
};
#endif /* FOTO_H */