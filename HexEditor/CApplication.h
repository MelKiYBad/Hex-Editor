/*
	�����������: ����� �����
	����: 04.12.18
	��������: �������� ����� ����������
*/

#ifndef _CAPPLICATION_H_
#define _CAPPLICATION_H_

#include <Windows.h>
#include <sstream>
#include "CFileStream.h"
#include "CTextLabel.h"
#include "CEdit.h"
#include "CRich.h"
#include "CListView.h"
#include "CButton.h"
#include "CBitmap.h"
#include "resource.h"

using namespace std;

#define WINDOW_WIDTH 805 // ������ ���� ������
#define WINDOW_HEIGHT 600 // ������ ���� ������
#define CENTER_X ((GetSystemMetrics(SM_CXSCREEN)/2)-(WINDOW_WIDTH/2)) // ������ ��� ����������� ������ �� ��� X
#define CENTER_Y ((GetSystemMetrics(SM_CYSCREEN)/2)-(WINDOW_HEIGHT/2)) // ������ ��� ����������� ������ �� ��� Y
#define MAIN_ICON MAKEINTRESOURCE(IDI_ICON1) // ������� ������ ����������
#define MAIN_MENU MAKEINTRESOURCE(IDR_MENU1) // ������ ����
#define CHECK_BUTTON(Button) (int)wParam == Button->GetButtonID() // ������ ��� ��������� ID ������
#define CHECK_EDIT(Edit) (HWND)lParam == Edit->GetEditWindow() // ������ ��� ����������� ���� CEdit

class CApplication{
private:
	HINSTANCE DefaultInstance; // hInstance
	HWND MainWindow; // ���������� ���� ���������� (������� ����)
	WNDCLASSEX wcl; // ����� �������� ����
	MSG msg; // ���������� ����������� Windows ���������
public:
	// ������ ����������
	CApplication(HINSTANCE hInstance);
	
	// ���������� ��� �������� ����������
	~CApplication(void);
	
	// ��������� ����������
	void RunApplication(void);
	
	// ���������� ������ �������� ����
	int GetApplicationWidth(void);
	
	// ���������� ������ �������� ����
	int GetApplicationHeight(void);
	
	// ���������� ������� ���� ����������
	HWND GetApplicationWindow(void);
	
	// ���������� HINSTANCE ����������
	HINSTANCE GetApplicationInstance(void);
	
	// ���������� Windows ���������
	static LRESULT WINAPI MsgProc(HWND Window,UINT MessageID,WPARAM wParam,LPARAM lParam);
};

// ��������� (����������� � main.h)
extern CApplication *pApplication; // �������� ����� ����������
extern CFileStream *pFileStream; // ����� ��� ������ � ������
extern CListView *pListView; // ����� ��� ������ � ��������
extern CEdit *pEdit[16]; // ����� ��� ������ � ��������� ������� 16 ����
extern CTextLabel *pTextLabel; // ����� ��� ������ � ��������� ��������
extern CBitmap *pLogo; // ����� ��� ������ � ���������

#endif