
// ITA-CPP-MFC-SandwichSelectorDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "ITA-CPP-MFC-SandwichSelector.h"
#include "ITA-CPP-MFC-SandwichSelectorDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CITACPPMFCSandwichSelectorDlg-Dialogfeld



CITACPPMFCSandwichSelectorDlg::CITACPPMFCSandwichSelectorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ITACPPMFCSANDWICHSELECTOR_DIALOG, pParent)
	, V_Selection(_T(""))
	, V_LB_Bread(_T(""))
	, V_LB_Sauce(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CITACPPMFCSandwichSelectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, TB_Selection, V_Selection);
	DDX_Control(pDX, LB_Bread, CTL_LB_Bread);
	DDX_LBString(pDX, LB_Bread, V_LB_Bread);
	DDX_Control(pDX, LB_Sauce, CTL_LB_Sauce);
	DDX_LBString(pDX, LB_Sauce, V_LB_Sauce);
	DDX_Control(pDX, LB_Toping, CTL_LB_Topings);
}

BEGIN_MESSAGE_MAP(CITACPPMFCSandwichSelectorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(B_Reset, &CITACPPMFCSandwichSelectorDlg::OnBnClickedReset)
	ON_LBN_SELCHANGE(LB_Bread, &CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeBread)
	ON_LBN_SELCHANGE(LB_Sauce, &CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeSauce)
	ON_LBN_SELCHANGE(LB_Toping, &CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeToping)
END_MESSAGE_MAP()


// CITACPPMFCSandwichSelectorDlg-Meldungshandler

BOOL CITACPPMFCSandwichSelectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen
	CTL_LB_Bread.AddString(_T("Normales"));
	CTL_LB_Bread.AddString(_T("Sesam"));
	CTL_LB_Bread.AddString(_T("Vollkorn"));

	CTL_LB_Sauce.AddString(_T("Butter"));
	CTL_LB_Sauce.AddString(_T("Senf"));
	CTL_LB_Sauce.AddString(_T("Mayonaise"));

	CTL_LB_Topings.AddString(_T("Gurke"));
	CTL_LB_Topings.AddString(_T("Tomate"));
	CTL_LB_Topings.AddString(_T("Schinken"));
	CTL_LB_Topings.AddString(_T("Mettwurst"));
	CTL_LB_Topings.AddString(_T("Gouda"));
	CTL_LB_Topings.AddString(_T("Emmentaler"));

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CITACPPMFCSandwichSelectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CITACPPMFCSandwichSelectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CITACPPMFCSandwichSelectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CITACPPMFCSandwichSelectorDlg::OnBnClickedReset()
{
	UpdateData();

	V_Selection = "";
	
	CTL_LB_Bread.SetCurSel(-1);
	CTL_LB_Sauce.SetCurSel(-1);

	for (int i = 0; i < CTL_LB_Topings.GetCount(); i++) {
		CTL_LB_Topings.SetSel(i, 0);
	}

	UpdateData(0);
}


void CITACPPMFCSandwichSelectorDlg::EvalSelection()
{
	UpdateData();

	V_Selection = "";

	if (V_LB_Bread == "") { UpdateData(0); return; }
	V_Selection += V_LB_Bread;
	V_Selection += "broetchen ";
	
	if (V_LB_Sauce == "") { UpdateData(0); return; }
	V_Selection += "mit ";
	V_Selection += V_LB_Sauce;
	V_Selection += " bestrichen ";

	CString temp, topings = _T("und belegt mit ");
	for (int i = 0; i < CTL_LB_Topings.GetCount(); i++) {
		if (!CTL_LB_Topings.GetSel(i)) continue;
		CTL_LB_Topings.GetText(i, temp);
		topings += temp;
		topings += ", ";
	}

	if (topings == "und belegt mit ") { UpdateData(0); return; }
	V_Selection += topings;
	
	UpdateData(0);
}


void CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeBread()
{
	EvalSelection();
}


void CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeSauce()
{
	EvalSelection();
}


void CITACPPMFCSandwichSelectorDlg::OnLbnSelchangeToping()
{
	EvalSelection();
}
