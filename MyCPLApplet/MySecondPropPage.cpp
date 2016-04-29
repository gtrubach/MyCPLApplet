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
END_MESSAGE_MAP()


// CMySecondPropPage message handlers


BOOL CMySecondPropPage::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class

	return CPropertyPage::OnApply();
}
