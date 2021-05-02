
// ITA-CPP-MFC-SandwichSelector.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CITACPPMFCSandwichSelectorApp:
// Siehe ITA-CPP-MFC-SandwichSelector.cpp für die Implementierung dieser Klasse
//

class CITACPPMFCSandwichSelectorApp : public CWinApp
{
public:
	CITACPPMFCSandwichSelectorApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CITACPPMFCSandwichSelectorApp theApp;
