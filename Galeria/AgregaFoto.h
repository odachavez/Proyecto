#ifndef AGREGAFOTO_H
#define AGREGAFOTO_H

//(*Headers(AgregaFoto)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class AgregaFoto: public wxFrame
{
    public:

        AgregaFoto(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~AgregaFoto();

        //(*Declarations(AgregaFoto)
        wxButton* btnAcept;
        wxButton* btnCancel;
        wxButton* btnSubirFoto;
        wxButton* btnUbicacion;
        wxPanel* panelAgregar;
        wxStaticText* txtDetalles;
        wxTextCtrl* titulo;
        wxTextCtrl* ubicacion;
        //*)

    protected:

        //(*Identifiers(AgregaFoto)
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_BUTTON3;
        static const wxWindowID ID_BUTTON4;
        static const wxWindowID ID_PANEL1;
        //*)

    private:
        wxString rutaOrigenFoto;
        //(*Handlers(AgregaFoto)
        void OnButton1Click(wxCommandEvent& event);
        void OnbtnUbicacionClick(wxCommandEvent& event);
        void OnbtnSubirFotoClick(wxCommandEvent& event);
        void OnbtnAceptClick(wxCommandEvent& event);
        void OnbtnCancelClick(wxCommandEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
