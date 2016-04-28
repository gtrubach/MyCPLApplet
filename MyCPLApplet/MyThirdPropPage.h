#pragma once


// CMyThirdPropPage dialog

class CMyThirdPropPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CMyThirdPropPage)

public:
	CMyThirdPropPage();
	virtual ~CMyThirdPropPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYTHIRDPROPPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
