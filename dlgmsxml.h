// dlgmsxml.h : main header file for the DLGMSXML application
//

#if !defined(AFX_DLGMSXML_H__7D8CCE23_6F9B_41F5_82BC_FD9358161DDD__INCLUDED_)
#define AFX_DLGMSXML_H__7D8CCE23_6F9B_41F5_82BC_FD9358161DDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgmsxmlApp:
// See dlgmsxml.cpp for the implementation of this class
//

class CDlgmsxmlApp : public CWinApp
{
public:
	CDlgmsxmlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgmsxmlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgmsxmlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMSXML_H__7D8CCE23_6F9B_41F5_82BC_FD9358161DDD__INCLUDED_)
