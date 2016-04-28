#pragma once


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
};
