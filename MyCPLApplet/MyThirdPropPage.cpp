// MyThirdPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "MyCPLApplet.h"
#include "MyThirdPropPage.h"
#include "afxdialogex.h"


// CMyThirdPropPage dialog

IMPLEMENT_DYNAMIC(CMyThirdPropPage, CPropertyPage)

CMyThirdPropPage::CMyThirdPropPage()
	: CPropertyPage(IDD_MYTHIRDPROPPAGE)
{

}

CMyThirdPropPage::~CMyThirdPropPage()
{
}

void CMyThirdPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyThirdPropPage, CPropertyPage)
END_MESSAGE_MAP()


// CMyThirdPropPage message handlers
