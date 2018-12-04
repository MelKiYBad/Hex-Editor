#include "CButton.h"

CButton::CButton(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height,const char *Title,unsigned long ButtonID){
	BtnID = ButtonID+40010;
	Button = CreateWindow(WC_BUTTON,Title,WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,X,Y,Width,Height,ParentWindow,(HMENU)BtnID,hInstance,NULL);
	HFONT pFont = CreateFont(16,0,0,0,0,NULL,NULL,NULL,DEFAULT_CHARSET,NULL,NULL,CLEARTYPE_QUALITY,NULL,"Arial");
	SendMessage(Button,WM_SETFONT,(WPARAM)pFont,NULL);
}

CButton::~CButton(void){
	DestroyWindow(Button);
}

int CButton::GetButtonID(void){
	return BtnID;
}

void CButton::SetButtonPosition(int X,int Y){
	SetWindowPos(Button,NULL,X,Y,GetButtonWidth(),GetButtonHeight(),0);
}

int CButton::GetButtonPositionX(void){
	RECT rct; GetClientRect(Button,&rct);
	MapWindowPoints(Button,GetParent(Button),(LPPOINT)&rct,2);
	return rct.left;
}

int CButton::GetButtonPositionY(void){
	RECT rct; GetClientRect(Button,&rct);
	MapWindowPoints(Button,GetParent(Button),(LPPOINT)&rct,2);
	return rct.top;
}

void CButton::SetButtonSize(int Width,int Height){
	SetWindowPos(Button,NULL,GetButtonPositionX(),GetButtonPositionY(),Width,Height,0);
}

int CButton::GetButtonWidth(void){
	RECT rct; GetClientRect(Button,&rct);
	MapWindowPoints(Button,GetParent(Button),(LPPOINT)&rct,2);
	return rct.right-rct.left;
}

int CButton::GetButtonHeight(void){
	RECT rct; GetClientRect(Button,&rct);
	MapWindowPoints(Button,GetParent(Button),(LPPOINT)&rct,2);
	return rct.bottom-rct.top;
}

HWND CButton::GetButtonWindow(void){
	return Button;
}
