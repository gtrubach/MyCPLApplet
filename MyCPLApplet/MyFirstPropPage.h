#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "ATLComTime.h"


// CMyFirstPropPage dialog

class CMyFirstPropPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CMyFirstPropPage)

public:
	CMyFirstPropPage();
	virtual ~CMyFirstPropPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFIRSTPROPPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnApply();
	afx_msg void OnEnChangeEditName(UINT id);
	afx_msg void OnEnChangeEditEmail();
	afx_msg void OnBnClickedRadioSex(UINT id);
	afx_msg void OnBnClickedCheck(UINT id);
	afx_msg void OnDtnDatetimechangeDatetimepickerBirthday(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	CString m_strFirstName;
	CString m_strLastName;
	COleDateTime m_odBirth;
	CString m_strEmail;
	BOOL m_bSex;

	BOOL SaveToReg();
	void ReadFromReg();
};
