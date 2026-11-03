/***************************************************************
 * Name:      GaleriaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Cahd ()
 * Created:   2026-11-02
 * Copyright: Cahd ()
 * License:
 **************************************************************/

#include "GaleriaApp.h"

//(*AppHeaders
#include "GaleriaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GaleriaApp);

bool GaleriaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        GaleriaFrame* Frame = new GaleriaFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
