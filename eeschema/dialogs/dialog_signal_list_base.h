///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 24 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_SIGNAL_LIST_BASE_H__
#define __DIALOG_SIGNAL_LIST_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_SIGNAL_LIST_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_SIGNAL_LIST_BASE : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_signals;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onSignalAdd( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DIALOG_SIGNAL_LIST_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 424,535 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DIALOG_SIGNAL_LIST_BASE();
	
};

#endif //__DIALOG_SIGNAL_LIST_BASE_H__
