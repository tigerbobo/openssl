
// openssl_test.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Copenssl_testApp:
// See openssl_test.cpp for the implementation of this class
//

class Copenssl_testApp : public CWinApp
{
public:
	Copenssl_testApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Copenssl_testApp theApp;