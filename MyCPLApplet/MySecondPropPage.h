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
};
