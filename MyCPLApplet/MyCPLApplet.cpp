// MyCPLApplet.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "MyCPLApplet.h"

#include "resource.h"
#include "MyPropertySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CMyCPLAppletApp

BEGIN_MESSAGE_MAP(CMyCPLAppletApp, CWinApp)
END_MESSAGE_MAP()


// CMyCPLAppletApp construction

CMyCPLAppletApp::CMyCPLAppletApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMyCPLAppletApp object

CMyCPLAppletApp theApp;


// CMyCPLAppletApp initialization

BOOL CMyCPLAppletApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

extern "C" LONG APIENTRY CPlApplet(
	HWND hwndCPL,       // handle of Control Panel window
	UINT uMsg,          // message
	LONG_PTR lParam1,       // first message parameter
	LONG_PTR lParam2        // second message parameter
)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LPCPLINFO lpCPlInfo;
	LONG retCode = 0;

	switch (uMsg)
	{
	case CPL_INIT:              // first message, sent once
		return TRUE;

	case CPL_GETCOUNT:          // second message, sent once
		return 1L;                // (LONG)NUM_APPLETS;

	case CPL_INQUIRE:        // third message, sent once per app
		lpCPlInfo = (LPCPLINFO)lParam2;

		lpCPlInfo->idIcon = IDI_SAMPLE_CPL;
		lpCPlInfo->idName = IDS_SAMPLE_CPL_NAME;
		lpCPlInfo->idInfo = IDS_SAMPLE_CPL_DESCRIPTION;
		lpCPlInfo->lData = 0L;
		break;

	case CPL_DBLCLK:            // application icon double-clicked
	{
		CWnd wndCPL;
		BOOL b = wndCPL.Attach(hwndCPL);
		CMyPropertySheet propSheet(IDS_SAMPLE_CPL_NAME, &wndCPL);

		// This is where you would retrieve information from the property
		// sheet if propSheet.DoModal() returned IDOK.  We aren't doing
		// anything for simplicity.

		propSheet.DoModal();
		wndCPL.Detach();
	}
	break;
	}
	return retCode;
}
