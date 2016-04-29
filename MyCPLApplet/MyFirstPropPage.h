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
	CEdit m_editEmail;
	CEdit m_editFirstName;
	CEdit m_editLastName;
	CDateTimeCtrl m_dateBirth;
	CButton m_checkC;
	CButton m_checkCPP;
	CButton m_checkR;
	CButton m_checkCS;
	CButton m_checkJava;
	CButton m_checkScala;
	CButton m_checkOC;
	CButton m_checkJS;
	CButton m_checkVB;
	CButton m_checkSwift;
	CButton m_checkPHP;
	CButton m_checkPerl;
	CButton m_checkRuby;
	CButton m_checkPython;
	CButton m_checkGo;
	CButton m_checkHtml;
	CButton m_checkCSS;
	CButton m_checkSQL;

	CString m_strFirstName;
	CString m_strLastName;
	COleDateTime m_odBirth;
	CString m_strEmail;
	bool m_bSexM;
	bool m_bSexF;
};
