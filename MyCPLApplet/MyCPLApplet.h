// MyCPLApplet.h : main header file for the MyCPLApplet DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyCPLAppletApp
// See MyCPLApplet.cpp for the implementation of this class
//

class CMyCPLAppletApp : public CWinApp
{
public:
	CMyCPLAppletApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
