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
	, m_strFirstName(_T(""))
	, m_strLastName(_T(""))
	, m_odBirth(COleDateTime::GetCurrentTime())
	, m_bSex(FALSE)
{
	ReadFromReg();
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
	/*DDX_Control(pDX, IDC_CHECK_C, m_checkC);
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
	DDX_Control(pDX, IDC_CHECK_SQL, m_checkSQL);*/
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_strFirstName);
	DDV_MaxChars(pDX, m_strFirstName, 255);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_strLastName);
	DDV_MaxChars(pDX, m_strLastName, 255);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTHDAY, m_odBirth);
	DDX_Radio(pDX, IDC_RADIO_SEX_MALE, m_bSex);
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
	//MessageBox(NULL, _T("Got it"), MB_OK);

	if (!SaveToReg()) return FALSE;

	return CPropertyPage::OnApply();
}


void CMyFirstPropPage::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateData(TRUE);
	SaveToReg();

	CPropertyPage::OnOK();
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

BOOL CMyFirstPropPage::SaveToReg()
{
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&sa, sizeof(sa));
	DWORD disposition;
	HKEY hKey;
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, _T("Software\\MyCPLApplet\\MyCPLApplet"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, &sa, &hKey, &disposition) == ERROR_SUCCESS)
	{
		if (RegSetValueEx(hKey, _T("First Name"), 0, REG_SZ, (LPBYTE)(LPCTSTR)m_strFirstName, (m_strFirstName.GetLength() + 1) * sizeof(TCHAR)) != ERROR_SUCCESS ||
			RegSetValueEx(hKey, _T("Last Name"), 0, REG_SZ, (LPBYTE)(LPCTSTR)m_strLastName, (m_strLastName.GetLength() + 1) * sizeof(TCHAR)) != ERROR_SUCCESS ||
			RegSetValueEx(hKey, _T("Birthday"), 0, REG_BINARY, (LPBYTE)&m_odBirth.m_dt, sizeof(double)) != ERROR_SUCCESS ||
			RegSetValueEx(hKey, _T("Sex"), 0, REG_DWORD, (LPBYTE)&m_bSex, sizeof(BOOL)) != ERROR_SUCCESS ||
			RegSetValueEx(hKey, _T("Email"), 0, REG_SZ, (LPBYTE)(LPCTSTR)m_strEmail, (m_strEmail.GetLength() + 1) * sizeof(TCHAR)) != ERROR_SUCCESS)
		{
			return FALSE;
		}

		RegCloseKey(hKey);
		return TRUE;
	}
	return FALSE;
}

void CMyFirstPropPage::ReadFromReg()
{
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&sa, sizeof(sa));
	DWORD disposition;
	HKEY hKey;
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, _T("Software\\MyCPLApplet\\MyCPLApplet"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_QUERY_VALUE, &sa, &hKey, &disposition) == ERROR_SUCCESS)
	{
		if (disposition == REG_OPENED_EXISTING_KEY)
		{
			wchar_t data[1024];
			DWORD size = sizeof(data) * sizeof(TCHAR);

			if (RegQueryValueEx(hKey, _T("First Name"), 0, NULL, (LPBYTE)data, &size) == ERROR_SUCCESS) {
				m_strFirstName = data;
			}

			size = sizeof(data) * sizeof(TCHAR);
			if (RegQueryValueEx(hKey, _T("Last Name"), 0, NULL, (LPBYTE)data, &size) == ERROR_SUCCESS) {
				m_strLastName = data;
			}

			double date;
			size = sizeof(double);
			if (RegQueryValueEx(hKey, _T("Birthday"), 0, NULL, (LPBYTE)&date, &size) == ERROR_SUCCESS) {
				m_odBirth.m_dt = date;
			}

			DWORD dwData;
			size = sizeof(DWORD);
			if (RegQueryValueEx(hKey, _T("Sex"), 0, NULL, (LPBYTE)&dwData, &size) == ERROR_SUCCESS) {
				m_bSex = dwData;
			}

			size = sizeof(data) * sizeof(TCHAR);
			if (RegQueryValueEx(hKey, _T("Email"), 0, NULL, (LPBYTE)data, &size) == ERROR_SUCCESS) {
				m_strEmail = data;
			}
		}

		RegCloseKey(hKey);
	}
}
