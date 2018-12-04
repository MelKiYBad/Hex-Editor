/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � �������,
	������ ����� �������������� � ������ ����������
*/

#ifndef _CBUTTON_H_
#define _CBUTTON_H_

#include <Windows.h>
#include <CommCtrl.h>

class CButton{
private:
	unsigned long BtnID; // ID ������, ������������� ��� ��������
	HWND Button; // ���� - ������
public:
	// ������� ������
	CButton(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height,const char *Title,unsigned long ButtonID);
	
	// ���������� ��� �������� ������
	~CButton(void);
	
	// ���������� ID ������
	int GetButtonID(void);
	
	// ����� ������ ������� �� ���������� X � Y
	void SetButtonPosition(int X,int Y);
	
	// ���������� ������� ������ �� ��������� X
	int GetButtonPositionX(void);
	
	// ���������� ������� ������ �� ��������� Y
	int GetButtonPositionY(void);
	
	// ����� ������ ������� ������ � ������ ������
	void SetButtonSize(int Width,int Height);
	
	// ���������� ������ ������
	int GetButtonWidth(void);
	
	// ���������� ������ ������
	int GetButtonHeight(void);
	
	// ���������� ���� ������
	HWND GetButtonWindow(void);

};

#endif