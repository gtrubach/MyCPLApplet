#pragma once


// CMySecondPropPage dialog

class CMySecondPropPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CMySecondPropPage)

public:
	CMySecondPropPage();
	virtual ~CMySecondPropPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYSECONDPROPPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnApply();
	afx_msg void OnEnChangeEditServerName();
	afx_msg void OnIpnFieldchangedIpAddressServer(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckSsl();
	afx_msg void OnBnClickedCheckShow();
};
