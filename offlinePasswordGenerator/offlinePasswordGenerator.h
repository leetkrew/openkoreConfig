
// offlinePasswordGenerator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CofflinePasswordGeneratorApp:
// See offlinePasswordGenerator.cpp for the implementation of this class
//

class CofflinePasswordGeneratorApp : public CWinApp
{
public:
	CofflinePasswordGeneratorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CofflinePasswordGeneratorApp theApp;
