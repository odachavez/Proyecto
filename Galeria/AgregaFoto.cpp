#include <wx/dirdlg.h>
#include <wx/textctrl.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include "AgregaFoto.h"
#include "GaleriaMain.h"

//(*InternalHeaders(AgregaFoto)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(AgregaFoto)
const wxWindowID AgregaFoto::ID_TEXTCTRL1 = wxNewId();
const wxWindowID AgregaFoto::ID_TEXTCTRL2 = wxNewId();
const wxWindowID AgregaFoto::ID_BUTTON1 = wxNewId();
const wxWindowID AgregaFoto::ID_BUTTON2 = wxNewId();
const wxWindowID AgregaFoto::ID_STATICTEXT1 = wxNewId();
const wxWindowID AgregaFoto::ID_BUTTON3 = wxNewId();
const wxWindowID AgregaFoto::ID_BUTTON4 = wxNewId();
const wxWindowID AgregaFoto::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AgregaFoto,wxFrame)
    //(*EventTable(AgregaFoto)
    //*)
END_EVENT_TABLE()

AgregaFoto::AgregaFoto(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(AgregaFoto)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    panelAgregar = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(461,303), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panelAgregar->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, panelAgregar, _("Título"));
    titulo = new wxTextCtrl(panelAgregar, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(473,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBoxSizer1->Add(titulo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, panelAgregar, _("Guardar en:"));
    ubicacion = new wxTextCtrl(panelAgregar, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(119,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(ubicacion, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnUbicacion = new wxButton(panelAgregar, ID_BUTTON1, _T("..."), wxDefaultPosition, wxSize(38,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer2->Add(btnUbicacion, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
    btnSubirFoto = new wxButton(panelAgregar, ID_BUTTON2, _("Subir Foto"), wxDefaultPosition, wxSize(128,26), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(btnSubirFoto, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, panelAgregar, _("Detalles"));
    txtDetalles = new wxStaticText(panelAgregar, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(473,52), 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer3->Add(txtDetalles, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    btnAcept = new wxButton(panelAgregar, ID_BUTTON3, _("Aceptar"), wxDefaultPosition, wxSize(75,21), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(btnAcept, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(panelAgregar, ID_BUTTON4, _("Cancelar"), wxDefaultPosition, wxSize(75,20), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer3->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_RIGHT, 5);
    panelAgregar->SetSizer(BoxSizer2);
    BoxSizer1->Add(panelAgregar, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&AgregaFoto::OnbtnUbicacionClick);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&AgregaFoto::OnbtnSubirFotoClick);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&AgregaFoto::OnbtnAceptClick);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&AgregaFoto::OnbtnCancelClick);
    //*)
}

AgregaFoto::~AgregaFoto()
{
    //(*Destroy(AgregaFoto)
    //*)
}

void AgregaFoto::OnbtnUbicacionClick(wxCommandEvent& event)
{
    wxDirDialog dlg(this, _("Selecciona la ubicación de destino"), "");

    if (dlg.ShowModal() == wxID_OK)
    {
        wxString ruta = dlg.GetPath(); // Obtiene el string de la ruta
        ubicacion->SetValue(ruta);     // Inserta la ruta en el wxTextCtrl
    }
}

void AgregaFoto::OnbtnSubirFotoClick(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Selecciona una foto"), "", "",
                               "Archivos de imagen (*.jpg;*.png;*.jpeg)|*.jpg;*.png;*.jpeg",
                               wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK)
    {
        rutaOrigenFoto = openFileDialog.GetPath();

        // Obtener detalles del archivo seleccionado
        wxFileName archivoInfo(rutaOrigenFoto);
        wxString formato = archivoInfo.GetExt();
        wxULongLong tamanoBytes = archivoInfo.GetSize();
        double tamanoKB = (double)tamanoBytes.GetValue() / 1024.0;

        // Mostrar los detalles en el wxStaticText (txtDetalles)
        wxString detalles = wxString::Format("Formato: .%s\nTamaño: %.2f KB",
                                             formato,
                                             tamanoKB);
        txtDetalles->SetLabel(detalles);
    }
}

void AgregaFoto::OnbtnAceptClick(wxCommandEvent& event)
{
    wxString rutaDestinoDir = ubicacion->GetValue();
    if (rutaDestinoDir.IsEmpty() || rutaOrigenFoto.IsEmpty() || titulo->GetValue().IsEmpty())
    {
        wxMessageBox(_("Por favor, completa todos los campos y selecciona una foto."), _("Aviso"), wxOK | wxICON_WARNING);
        return;
    }

    wxString tituloFoto = titulo->GetValue();
    wxFileName archivoInfo(rutaOrigenFoto);
    wxString formato = archivoInfo.GetExt();
    wxString nombreArchivoFinal = tituloFoto + "." + formato;
    wxString rutaFinal = rutaDestinoDir + wxFileName::GetPathSeparator() + nombreArchivoFinal;

    if (wxCopyFile(rutaOrigenFoto, rutaFinal))
    {
        // Obtener la ventana principal y registrar la foto en tu estructura de datos
        GaleriaFrame* principal = dynamic_cast<GaleriaFrame*>(GetParent());
        if (principal)
        {
            double tamanoMB = (double)archivoInfo.GetSize().GetValue() / (1024.0 * 1024.0);
            Fecha fechaDefault(2026, 11, 3);

            Foto nuevaFoto(tituloFoto.ToStdString(), formato.ToStdString(), fechaDefault, rutaFinal.ToStdString(), tamanoMB);

            // Añadir a la Lista Doble de consola
           principal->getListaFotos().enlistarCola(nuevaFoto);

            // Refrescar visualmente el ListBox
            principal->ActualizarLista();
        }

        wxMessageBox(_("¡Foto guardada exitosamente!"), _("Éxito"), wxOK | wxICON_INFORMATION);
        Close();
    }
    else
    {
        wxMessageBox(_("No se pudo guardar la foto."), _("Error"), wxOK | wxICON_ERROR);
    }
}

void AgregaFoto::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
}
