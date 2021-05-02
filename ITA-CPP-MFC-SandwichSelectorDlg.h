
// ITA-CPP-MFC-SandwichSelectorDlg.h: Headerdatei
//

#pragma once


// CITACPPMFCSandwichSelectorDlg-Dialogfeld
class CITACPPMFCSandwichSelectorDlg : public CDialogEx
{
// Konstruktion
public:
	CITACPPMFCSandwichSelectorDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITACPPMFCSANDWICHSELECTOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString V_Selection;
	CListBox CTL_LB_Bread;
	CString V_LB_Bread;
	CListBox CTL_LB_Sauce;
	CString V_LB_Sauce;
	CListBox CTL_LB_Topings;
	afx_msg void OnBnClickedReset();
	void EvalSelection();
	afx_msg void OnLbnSelchangeBread();
	afx_msg void OnLbnSelchangeSauce();
	afx_msg void OnLbnSelchangeToping();
};
