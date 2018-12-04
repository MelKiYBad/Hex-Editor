#include "CEdit.h"

CEdit::CEdit(HINSTANCE hInstance,HWND ParentWindow,int cHeight,const char *Text,int X,int Y,int Width,int Height,int CharLimit,int cEditID,long Flag){
	Edit = CreateWindowEx(WS_EX_CLIENTEDGE,WC_EDIT,Text,WS_CHILD|WS_VISIBLE|Flag ,X,Y,Width,Height,ParentWindow,NULL,hInstance,NULL);
	HFONT pFont = CreateFont(16,0,0,0,0,NULL,NULL,NULL,DEFAULT_CHARSET,NULL,NULL,CLEARTYPE_QUALITY,NULL,"Arial");
	SendMessage(Edit,WM_SETFONT,(WPARAM)pFont,NULL);
	SendMessage(Edit,EM_SETLIMITTEXT,(WPARAM)CharLimit,NULL);
}

CEdit::~CEdit(void){
	DestroyWindow(Edit);
}

void CEdit::SetEditText(const char *Text){
	SetWindowText(Edit,Text);
}

char *CEdit::GetEditText(void){
	char retstr[256];
	GetWindowText(Edit,retstr,256);
	return retstr;
}

void CEdit::SetEditPosition(int X,int Y){
	SetWindowPos(Edit,NULL,X,Y,GetEditWidth(),GetEditHeight(),NULL);
}

int CEdit::GetEditPositionX(void){
	RECT rct; GetClientRect(Edit,&rct);
	MapWindowPoints(Edit,GetParent(Edit),(LPPOINT)&rct,2);
	return rct.left-2;
}

int CEdit::GetEditPositionY(void){
	RECT rct; GetClientRect(Edit,&rct);
	MapWindowPoints(Edit,GetParent(Edit),(LPPOINT)&rct,2);
	return rct.top-2;
}

void CEdit::SetEditSize(int Width,int Height){
	SetWindowPos(Edit,NULL,GetEditPositionX(),GetEditPositionY(),Width,Height,NULL);
}

int CEdit::GetEditWidth(void){
	RECT rct; GetClientRect(Edit,&rct);
	MapWindowPoints(Edit,GetParent(Edit),(LPPOINT)&rct,2);
	return (rct.right-rct.left)+4;
}

int CEdit::GetEditHeight(void){
	RECT rct; GetClientRect(Edit,&rct);
	MapWindowPoints(Edit,GetParent(Edit),(LPPOINT)&rct,2);
	return (rct.bottom-rct.top)+4;
}

int CEdit::GetEditTextSize(void){
	return strlen(GetEditText());
}

HWND CEdit::GetEditWindow(void){
	return Edit;
}