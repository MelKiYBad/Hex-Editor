#include "CTextLabel.h"

CTextLabel::CTextLabel(HINSTANCE hInstance,HWND ParentWindow,const char *Label,int X, int Y,int Width,int Height){
	TextLabel = CreateWindow(WC_EDIT,Label,WS_CHILD|WS_VISIBLE|ES_READONLY,X,Y,Width,Height,ParentWindow,NULL,hInstance,NULL);
	HFONT pFont = CreateFont(16,0,0,0,0,0,0,0,DEFAULT_CHARSET,0,0,CLEARTYPE_QUALITY,0,"Arial");
	SendMessage(TextLabel,WM_SETFONT,(WPARAM)pFont,NULL);
}

CTextLabel::~CTextLabel(void){
	DestroyWindow(TextLabel);
}

void CTextLabel::SetTextLabelText(const char *Text){
	SetWindowText(TextLabel,Text);
}

char *CTextLabel::GetTextLabelText(void){
	char Text[260];
	GetWindowText(TextLabel,Text,260);
	return Text;
}

void CTextLabel::SetTextLabelPosition(int X, int Y){
	SetWindowPos(TextLabel,NULL,X,Y,GetTextLabelWidth(),GetTextLabelHeight(),NULL);
}

int CTextLabel::GetTextLabelPositionX(void){
	RECT rc; GetClientRect(TextLabel,&rc);
	MapWindowPoints(TextLabel,GetParent(TextLabel),(LPPOINT)&rc,2);
	return rc.left;
}

int CTextLabel::GetTextLabelPositionY(void){
	RECT rc; GetClientRect(TextLabel,&rc);
	MapWindowPoints(TextLabel,GetParent(TextLabel),(LPPOINT)&rc,2);
	return rc.top;
}

int CTextLabel::GetTextLabelWidth(void){
	RECT rct; GetClientRect(TextLabel,&rct);
	MapWindowPoints(TextLabel,GetParent(TextLabel),(LPPOINT)&rct,2);
	return rct.right-rct.left;
}

int CTextLabel::GetTextLabelHeight(void){
	RECT rct; GetClientRect(TextLabel,&rct);
	MapWindowPoints(TextLabel,GetParent(TextLabel),(LPPOINT)&rct,2);
	return rct.bottom-rct.top;
}

HWND CTextLabel::GetTextLabelWindow(void){
	return TextLabel;
}