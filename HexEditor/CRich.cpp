#include "CRich.h"

CRich::CRich(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height){
	Rich = CreateWindowEx(WS_EX_CLIENTEDGE,WC_EDIT,"",WS_CHILD|WS_VISIBLE|ES_LEFT|ES_MULTILINE|WS_VSCROLL|ES_AUTOVSCROLL,X,Y,Width,Height,ParentWindow,NULL,hInstance,NULL);
	HFONT pFont = CreateFont(16,0,0,0,0,NULL,NULL,NULL,DEFAULT_CHARSET,NULL,NULL,CLEARTYPE_QUALITY,NULL,"Arial");
	SendMessage(Rich,WM_SETFONT,(WPARAM)pFont,NULL);
}

CRich::~CRich(void){
	DestroyWindow(Rich);
}

void CRich::AddString(const char *Text){
	string input = Text; input += "\r\n";
	lines.push_back(input);

	string out;
	for(int i = 0;i<(int)lines.size();i++){
		out += lines[i];
	}

	SetWindowText(Rich,out.c_str());
}

void CRich::SetRichPosition(int X,int Y){
	SetWindowPos(Rich,NULL,X,Y,GetRichWidth(),GetRichHeight(),0);
}

int CRich::GetRichPositionX(void){
	RECT rct; GetClientRect(Rich,&rct);
	MapWindowPoints(Rich,GetParent(Rich),(LPPOINT)&rct,2);
	return rct.left;
}

int CRich::GetRichPositionY(void){
	RECT rct; GetClientRect(Rich,&rct);
	MapWindowPoints(Rich,GetParent(Rich),(LPPOINT)&rct,2);
	return rct.top;
}

void CRich::SetRichSize(int Width,int Height){
	SetWindowPos(Rich,NULL,GetRichPositionX(),GetRichPositionY(),Width,Height,0);
}

int CRich::GetRichWidth(void){
	RECT rct; GetClientRect(Rich,&rct);
	MapWindowPoints(Rich,GetParent(Rich),(LPPOINT)&rct,2);
	return rct.right-rct.left;
}

int CRich::GetRichHeight(void){
	RECT rct; GetClientRect(Rich,&rct);
	MapWindowPoints(Rich,GetParent(Rich),(LPPOINT)&rct,2);
	return rct.bottom-rct.top;
}

const char *CRich::GetString(int Index){
	return lines[Index].c_str();
}

HWND CRich::GetRichWindow(void){
	return Rich;
}