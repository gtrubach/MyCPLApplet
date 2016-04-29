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
	, m_strEmail(_T(""))
	, m_bSexM(false)
	, m_bSexF(false)
	, m_strFirstName(_T(""))
	, m_strLastName(_T(""))
	, m_odBirth(COleDateTime::GetCurrentTime())
{

}

CMyFirstPropPage::~CMyFirstPropPage()
{
}

void CMyFirstPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EMAIL, m_editEmail);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDV_MaxChars(pDX, m_strEmail, 255);
	DDX_Control(pDX, IDC_EDIT_FIRSTNAME, m_editFirstName);
	DDX_Control(pDX, IDC_EDIT_LASTNAME, m_editLastName);
	DDX_Control(pDX, IDC_DATETIMEPICKER_BIRTHDAY, m_dateBirth);
	DDX_Control(pDX, IDC_CHECK_C, m_checkC);
	DDX_Control(pDX, IDC_CHECK_CPP, m_checkCPP);
	DDX_Control(pDX, IDC_CHECK_R, m_checkR);
	DDX_Control(pDX, IDC_CHECK_CS, m_checkCS);
	DDX_Control(pDX, IDC_CHECK_JAVA, m_checkJava);
	DDX_Control(pDX, IDC_CHECK_SCALA, m_checkScala);
	DDX_Control(pDX, IDC_CHECK_OC, m_checkOC);
	DDX_Control(pDX, IDC_CHECK_JS, m_checkJS);
	DDX_Control(pDX, IDC_CHECK_VB, m_checkVB);
	DDX_Control(pDX, IDC_CHECK_SWIFT, m_checkSwift);
	DDX_Control(pDX, IDC_CHECK_PHP, m_checkPHP);
	DDX_Control(pDX, IDC_CHECK_PERL, m_checkPerl);
	DDX_Control(pDX, IDC_CHECK_RUBY, m_checkRuby);
	DDX_Control(pDX, IDC_CHECK_PYTHON, m_checkPython);
	DDX_Control(pDX, IDC_CHECK_GO, m_checkGo);
	DDX_Control(pDX, IDC_CHECK_HTML, m_checkHtml);
	DDX_Control(pDX, IDC_CHECK_CSS, m_checkCSS);
	DDX_Control(pDX, IDC_CHECK_SQL, m_checkSQL);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_strFirstName);
	DDV_MaxChars(pDX, m_strFirstName, 255);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_strLastName);
	DDV_MaxChars(pDX, m_strLastName, 255);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTHDAY, m_odBirth);
}


BEGIN_MESSAGE_MAP(CMyFirstPropPage, CPropertyPage)
	ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT_FIRSTNAME, IDC_EDIT_LASTNAME, &CMyFirstPropPage::OnEnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_EMAIL, &CMyFirstPropPage::OnEnChangeEditEmail)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_SEX_MALE, IDC_RADIO_SEX_FEMALE, &CMyFirstPropPage::OnBnClickedRadioSex)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_CHECK_C, IDC_CHECK_GO,&CMyFirstPropPage::OnBnClickedCheck)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_BIRTHDAY, &CMyFirstPropPage::OnDtnDatetimechangeDatetimepickerBirthday)
END_MESSAGE_MAP()


// CMyFirstPropPage message handlers


BOOL CMyFirstPropPage::OnApply()
{
	// TODO: Add your specialized code here and/or call the base class
	MessageBox(NULL, _T("Got it"), MB_OK);

	UpdateData(TRUE);

	return CPropertyPage::OnApply();
}


void CMyFirstPropPage::OnEnChangeEditName(UINT id)
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	SetModified(TRUE);
}


void CMyFirstPropPage::OnEnChangeEditEmail()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	//SetModified(TRUE);

	CString strEmail;
	m_editEmail.GetWindowTextW(strEmail);

	/*if (m_strEmail != strEmail)
	{*/
		SetModified(TRUE);
	//}
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
