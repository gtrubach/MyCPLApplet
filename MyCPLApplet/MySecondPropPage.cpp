// MySecondPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "MyCPLApplet.h"
#include "MySecondPropPage.h"
#include "afxdialogex.h"


// CMySecondPropPage dialog

IMPLEMENT_DYNAMIC(CMySecondPropPage, CPropertyPage)

CMySecondPropPage::CMySecondPropPage()
	: CPropertyPage(IDD_MYSECONDPROPPAGE)
{

}

CMySecondPropPage::~CMySecondPropPage()
{
}

void CMySecondPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMySecondPropPage, CPropertyPage)
	ON_EN_CHANGE(IDC_EDIT_SERVERNAME, &CMySecondPropPage::OnEnChangeEditServerName)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS_SERVER, &CMySecondPropPage::OnIpnFieldchangedIpAddressServer)
	ON_BN_CLICKED(IDC_CHECK_SHOW, &CMySecondPropPage::OnBnClickedCheckShow)
	ON_BN_CLICKED(IDC_CHECK_SSL, &CMySecondPropPage::OnBnClickedCheckSsl)
END_MESSAGE_MAP()


// CMySecondPropPage message handlers


BOOL CMySecondPropPage::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class

	return CPropertyPage::OnApply();
}


void CMySecondPropPage::OnEnChangeEditServerName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	SetModified(TRUE);
}


void CMySecondPropPage::OnIpnFieldchangedIpAddressServer(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	SetModified(TRUE);
}


void CMySecondPropPage::OnBnClickedCheckSsl()
{
	// TODO: Add your control notification handler code here
	SetModified(TRUE);
}


void CMySecondPropPage::OnBnClickedCheckShow()
{
	// TODO: Add your control notification handler code here
}
