/***************************************************************
 * Name:      GaleriaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Cahd ()
 * Created:   2026-11-02
 * Copyright: Cahd ()
 * License:
 **************************************************************/
#include "ListaDobleEnlazada.h"
#include "Operaciones_ListaDoble.h"
#include "Foto.h"
#include "GaleriaMain.h"
#include "AgregaFoto.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include <wx/dirdlg.h>
#include <wx/image.h>
#include <string>
using namespace std;

//(*InternalHeaders(GaleriaFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GaleriaFrame)
const wxWindowID GaleriaFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID GaleriaFrame::ID_BUTTON1 = wxNewId();
const wxWindowID GaleriaFrame::ID_LISTBOX1 = wxNewId();
const wxWindowID GaleriaFrame::ID_STATICBITMAP2 = wxNewId();
const wxWindowID GaleriaFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID GaleriaFrame::ID_PANEL4 = wxNewId();
const wxWindowID GaleriaFrame::ID_BUTTON2 = wxNewId();
const wxWindowID GaleriaFrame::ID_BUTTON3 = wxNewId();
const wxWindowID GaleriaFrame::ID_BUTTON4 = wxNewId();
const wxWindowID GaleriaFrame::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GaleriaFrame,wxFrame)
    //(*EventTable(GaleriaFrame)
    //*)
END_EVENT_TABLE()

GaleriaFrame::GaleriaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GaleriaFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Ubicación"));
    Localizacion = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxSize(715,20), wxBORDER_SIMPLE, _T("ID_STATICTEXT2"));
    Localizacion->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBoxSizer1->Add(Localizacion, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    btnLocaliza = new wxButton(this, ID_BUTTON1, _T("..."), wxDefaultPosition, wxSize(44,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(btnLocaliza, 0, wxALL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(393,436), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer3->Add(ListBox1, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    mostrarFoto = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxDefaultPosition, wxSize(387,320), wxBORDER_SUNKEN, _T("ID_STATICBITMAP2"));
    mostrarFoto->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    BoxSizer5->Add(mostrarFoto, 1, wxALL|wxEXPAND, 5);
    Panel2 = new wxPanel(this, ID_PANEL4, wxDefaultPosition, wxSize(389,139), wxBORDER_SIMPLE, _T("ID_PANEL4"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    txtDatos = new wxStaticText(Panel2, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(377,93), 0, _T("ID_STATICTEXT1"));
    BoxSizer6->Add(txtDatos, 1, wxALL, 5);
    Panel2->SetSizer(BoxSizer6);
    BoxSizer5->Add(Panel2, 0, wxALL|wxEXPAND, 4);
    BoxSizer3->Add(BoxSizer5, 0, wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    btnAnte = new wxButton(this, ID_BUTTON2, _("Anterior"), wxDefaultPosition, wxSize(161,25), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(btnAnte, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON3, _("Agregar Foto"), wxDefaultPosition, wxSize(127,25), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnEliminar = new wxButton(this, ID_BUTTON4, _("Eliminar Foto"), wxDefaultPosition, wxSize(150,24), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer4->Add(btnEliminar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSig = new wxButton(this, ID_BUTTON5, _("Siguiente"), wxDefaultPosition, wxSize(159,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer4->Add(btnSig, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GaleriaFrame::OnbtnLocalizaClick);
    Connect(ID_LISTBOX1, wxEVT_COMMAND_LISTBOX_SELECTED, (wxObjectEventFunction)&GaleriaFrame::OnListBox1Select);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GaleriaFrame::OnbtnAnteClick);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GaleriaFrame::OnbtnAgregarClick);
    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GaleriaFrame::OnButton2Click);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GaleriaFrame::OnbtnSigClick);
    //*)
}

GaleriaFrame::~GaleriaFrame(){
    //(*Destroy(GaleriaFrame)
    //*)
}

void GaleriaFrame::OnQuit(wxCommandEvent& event){
    Close();
}

void GaleriaFrame::OnAbout(wxCommandEvent& event){
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void GaleriaFrame::OnbtnAgregarClick(wxCommandEvent& event){
    AgregaFoto* ventAgregar = new AgregaFoto(this);
    ventAgregar->Show(true);
}

void GaleriaFrame::ActualizarLista(){
    wxString ruta = Localizacion->GetLabel();

    if (!ruta.IsEmpty()){
        ListBox1->Clear();
        listaFotos.limpiar();

        wxDir dir(ruta);
        if (dir.IsOpened()){
            wxString filename;
            bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);

            while (cont){
                wxString ext = wxFileName(filename).GetExt().Lower();
                if (ext == "jpg" || ext == "jpeg" || ext == "png" || ext == "bmp"){
                    ListBox1->Append(filename);

                    wxString rutaCompleta = ruta + wxFileName::GetPathSeparator() + filename;
                    wxFileName archivoInfo(rutaCompleta);
                    double tamanioMB = (double)archivoInfo.GetSize().GetValue()/(1024.0*1024.0);
                    Fecha fechaDefault(2026,11,3);

                    // Guardamos el nombre completo del archivo como título para que concuerde perfectamente
                    listaFotos.enlistarCola(Foto(filename.ToStdString(),
                                                 ext.ToStdString(),
                                                 fechaDefault,
                                                 rutaCompleta.ToStdString(),
                                                 tamanioMB));
                }
                cont = dir.GetNext(&filename);
            }
        }
    }
}

void GaleriaFrame::OnbtnLocalizaClick(wxCommandEvent& event)
{
    wxDirDialog dlg(this, _("Selecciona una ruta"), "");

    if (dlg.ShowModal() == wxID_OK)
    {
        wxString ruta = dlg.GetPath();
        Localizacion->SetLabel(ruta);

        // Llama a la función para escanear archivos y cargarlos a la lista doble
        ActualizarLista();
    }
}


//Eliminar
void GaleriaFrame::OnButton2Click(wxCommandEvent& event)
{
    int seleccion = ListBox1->GetSelection();
    if (seleccion == wxNOT_FOUND)
    {
        wxMessageBox(_("Por favor, selecciona una foto de la lista para eliminar."), _("Aviso"), wxOK | wxICON_WARNING);
        return;
    }

    wxString nombreArchivo = ListBox1->GetStringSelection();
    wxString rutaDirectorio = Localizacion->GetLabel();
    wxString rutaCompleta = rutaDirectorio + wxFileName::GetPathSeparator() + nombreArchivo;

    int respuesta = wxMessageBox(_("¿Estás seguro de que deseas eliminar el archivo:\n") + nombreArchivo + _("?"),
                                  _("Confirmar eliminación"), wxYES_NO | wxICON_QUESTION);

    if (respuesta == wxYES)
    {
        if (wxRemoveFile(rutaCompleta))
        {
            // Sincronizar: Buscar el nodo en ListaDoble y eliminarlo
            auto actual = listaFotos.getCabeza();
            while (actual != nullptr)
            {
                if (actual->dato.getUbicacion() == rutaCompleta.ToStdString())
                {
                    listaFotos.eliminarNodo(actual);
                    break;
                }
                actual = actual->siguiente;
            }

            ListBox1->Delete(seleccion);
            mostrarFoto->SetBitmap(wxNullBitmap);
            mostrarFoto->Refresh();
            txtDatos->SetLabel(wxEmptyString);

            wxMessageBox(_("Foto eliminada correctamente."), _("Éxito"), wxOK | wxICON_INFORMATION);
        }
        else
        {
            wxMessageBox(_("No se pudo eliminar el archivo del disco."), _("Error"), wxOK | wxICON_ERROR);
        }
    }
}


void GaleriaFrame::OnListBox1Select(wxCommandEvent& event)
{
    int seleccion = ListBox1->GetSelection();
    if (seleccion == wxNOT_FOUND) return;

    //Recorremos la Lista Doble hasta el nodo seleccionado
    auto actual = listaFotos.getCabeza();
    int indiceActual = 0;

    while (actual != nullptr && indiceActual < seleccion)
    {
        actual = actual->siguiente;
        indiceActual++;
    }

    if (actual != nullptr)
    {
        //Cargar y escalar la imagen
        wxString rutaCompleta(actual->dato.getUbicacion());
        wxImage imagen;
        if (imagen.LoadFile(rutaCompleta))
        {
            int maxWidth, maxHeight;
            mostrarFoto->GetClientSize(&maxWidth, &maxHeight);

            if (maxWidth <= 0) maxWidth = 380;
            if (maxHeight <= 0) maxHeight = 310;

            int origWidth = imagen.GetWidth();
            int origHeight = imagen.GetHeight();

            double widthRatio = (double)maxWidth / origWidth;
            double heightRatio = (double)maxHeight / origHeight;
            double scaleRatio = (widthRatio < heightRatio) ? widthRatio : heightRatio;

            int nuevoAncho = (int)(origWidth * scaleRatio);
            int nuevoAlto = (int)(origHeight * scaleRatio);

            if (nuevoAncho < 1) nuevoAncho = 1;
            if (nuevoAlto < 1) nuevoAlto = 1;

            wxImage imagenEscalada = imagen.Scale(nuevoAncho, nuevoAlto, wxIMAGE_QUALITY_HIGH);
            mostrarFoto->SetBitmap(wxBitmap(imagenEscalada));
            mostrarFoto->Refresh();
        }

        //Extraer los datos usando directamente los métodos get de la clase Foto
        string titulo = actual->dato.getTitulo();
        string formato = actual->dato.getFormato();
        string ubicacion = actual->dato.getUbicacion();
        Fecha fecha = actual->dato.getFecha();
        double espacio = actual->dato.getEspacio();

        //Formatear el texto nativamente con wxString
        wxString textoDatos = wxString::Format(
            "Título: %s\nFormato: .%s\nUbicación: %s\nFecha: %d/%d/%d\nEspacio: %.2f MB",
            titulo,
            formato,
            ubicacion,
            fecha.anio, fecha.mes, fecha.dia,
            espacio
        );

        //Asignarlo al wxStaticText y actualizar el panel
        txtDatos->SetLabel(textoDatos);

        int anchoPanel, altoPanel;
        Panel2->GetClientSize(&anchoPanel, &altoPanel);
        txtDatos->Wrap(anchoPanel - 20);

        Panel2->Layout();
        Panel2->Refresh();
        txtDatos->Refresh();
    }
}

void GaleriaFrame::OnbtnAnteClick(wxCommandEvent& event)
{
    int seleccionActual = ListBox1->GetSelection();
    int totalElementos = ListBox1->GetCount();
    if (totalElementos == 0) return;

    if (seleccionActual == wxNOT_FOUND)
    {
        ListBox1->SetSelection(totalElementos - 1);
    }
    else if (seleccionActual > 0)
    {
        auto actual = listaFotos.getCabeza();
        int idx = 0;
        while (actual != nullptr && idx < seleccionActual)
        {
            actual = actual->siguiente;
            idx++;
        }

        //Usar el puntero 'anterior' del nodo si existe
        if (actual != nullptr && actual->anterior != nullptr)
        {
            auto nodoAnterior = actual->anterior;

            //Encontrar el índice numérico correspondiente al nodo anterior para el ListBox
            auto it = listaFotos.getCabeza();
            int nuevoIdx = 0;
            while (it != nullptr && it != nodoAnterior)
            {
                it = it->siguiente;
                nuevoIdx++;
            }

            ListBox1->SetSelection(nuevoIdx);
        }
    }

    // Sincronizar y actualizar la vista
    wxCommandEvent evt(wxEVT_COMMAND_LISTBOX_SELECTED, ListBox1->GetId());
    evt.SetEventObject(ListBox1);
    ProcessEvent(evt);
}

void GaleriaFrame::OnbtnSigClick(wxCommandEvent& event)
{
    int seleccionActual = ListBox1->GetSelection();
    int totalElementos = ListBox1->GetCount();
    if (totalElementos == 0) return;

    if (seleccionActual == wxNOT_FOUND)
    {
        ListBox1->SetSelection(0);
    }
    else if (seleccionActual < totalElementos - 1)
    {
        auto actual = listaFotos.getCabeza();
        int idx = 0;
        while (actual != nullptr && idx < seleccionActual)
        {
            actual = actual->siguiente;
            idx++;
        }

        if (actual != nullptr && actual->siguiente != nullptr)
        {
            auto nodoSiguiente = actual->siguiente;

            auto it = listaFotos.getCabeza();
            int nuevoIdx = 0;
            while (it != nullptr && it != nodoSiguiente)
            {
                it = it->siguiente;
                nuevoIdx++;
            }

            ListBox1->SetSelection(nuevoIdx);
        }
    }

    wxCommandEvent evt(wxEVT_COMMAND_LISTBOX_SELECTED, ListBox1->GetId());
    evt.SetEventObject(ListBox1);
    ProcessEvent(evt);
}
