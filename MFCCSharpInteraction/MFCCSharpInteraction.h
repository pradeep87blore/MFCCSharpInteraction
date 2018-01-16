
// MFCCSharpInteraction.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCCSharpInteractionApp:
// See MFCCSharpInteraction.cpp for the implementation of this class
//

class CMFCCSharpInteractionApp : public CWinApp
{
public:
	CMFCCSharpInteractionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCCSharpInteractionApp theApp;