// MyFirstPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "MyCPLApplet.h"
#include "MyFirstPropPage.h"
#include "afxdialogex.h"


// CMyFirstPropPage dialog

IMPLEMENT_DYNAMIC(CMyFirstPropPage, CPropertyPage)

CMyFirstPropPage::CMyFirstPropPage()
	: CPropertyPage(IDD_MYFIRSTPROPPAGE)
{

}

CMyFirstPropPage::~CMyFirstPropPage()
{
}

void CMyFirstPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyFirstPropPage, CPropertyPage)
	ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT_FIRSTNAME, IDC_EDIT_EMAIL, &CMyFirstPropPage::OnEnChangeEdit)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_SEX_MALE, IDC_RADIO_SEX_FEMALE, &CMyFirstPropPage::OnBnClickedRadioSex)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_CHECK_C, IDC_CHECK_GO,&CMyFirstPropPage::OnBnClickedCheck)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_BIRTHDAY, &CMyFirstPropPage::OnDtnDatetimechangeDatetimepickerBirthday)
END_MESSAGE_MAP()


// CMyFirstPropPage message handlers


BOOL CMyFirstPropPage::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class
	MessageBox(NULL, _T("Got it"), MB_OK);

	return CPropertyPage::OnApply();
}


void CMyFirstPropPage::OnEnChangeEdit(UINT id)
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	SetModified(TRUE);
}


void CMyFirstPropPage::OnBnClickedCheck(UINT id)
{
	// TODO: Add your control notification handler code here
	SetModified(TRUE);
}


void CMyFirstPropPage::OnBnClickedRadioSex(UINT id)
{
	// TODO: Add your control notification handler code here
	SetModified(TRUE);
}


void CMyFirstPropPage::OnDtnDatetimechangeDatetimepickerBirthday(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	SetModified(TRUE);
}
