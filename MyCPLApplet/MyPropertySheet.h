#pragma once
#include "MyFirstPropPage.h"
#include "MySecondPropPage.h"
#include "MyThirdPropPage.h"


// CMyPropertySheet

class CMyPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyPropertySheet)
private:
	CMyFirstPropPage m_ppFirst;
	CMySecondPropPage m_ppSecond;
	CMyThirdPropPage m_ppThird;
public:
	CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	//CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CMyPropertySheet();

protected:
	DECLARE_MESSAGE_MAP()
};


