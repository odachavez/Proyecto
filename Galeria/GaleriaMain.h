/***************************************************************
 * Name:      GaleriaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Cahd ()
 * Created:   2026-11-02
 * Copyright: Cahd ()
 * License:
 **************************************************************/

#ifndef GALERIAMAIN_H
#define GALERIAMAIN_H

#include "ListaDobleEnlazada.h"
#include "Operaciones_ListaDoble.h"
#include "Foto.h"
//(*Headers(GaleriaFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class GaleriaFrame: public wxFrame
{
    public:

        GaleriaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GaleriaFrame();

        void ActualizarLista();
        ListaDoble<Foto>& getListaFotos(){return listaFotos;}

    private:
        ListaDoble<Foto> listaFotos;
        //(*Handlers(GaleriaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnAgregarClick(wxCommandEvent& event);
        void OnbtnLocalizaClick(wxCommandEvent& event);
        void OnListBoxSelect(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnbtnAnteClick(wxCommandEvent& event);
        void OnbtnSigClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(GaleriaFrame)
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_LISTBOX1;
        static const wxWindowID ID_STATICBITMAP2;
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_PANEL4;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON3;
        static const wxWindowID ID_BUTTON4;
        static const wxWindowID ID_BUTTON5;
        //*)

        //(*Declarations(GaleriaFrame)
        wxButton* Button1;
        wxButton* btnAnte;
        wxButton* btnEliminar;
        wxButton* btnLocaliza;
        wxButton* btnSig;
        wxListBox* ListBox1;
        wxPanel* Panel2;
        wxStaticBitmap* mostrarFoto;
        wxStaticText* Localizacion;
        wxStaticText* txtDatos;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GALERIAMAIN_H
