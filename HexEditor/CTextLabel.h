/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ��������� ��������,
	������ �� �������� � CEdit �.� ����� ����������� � ������������ ���� ����� ����� ������
*/

#ifndef _CTEXTLABEL_H_
#define _CTEXTLABEL_H_

#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>

class CTextLabel{
private:
	HWND TextLabel; // ���� - ��������� �������
public:
	// ������ ��������� �������
	CTextLabel(HINSTANCE hInstance,HWND ParentWindow,const char *Label,int X, int Y,int Width,int Height); 
	
	// ���������� ��� �������� ��������� �������
	~CTextLabel(void);
	
	// ������ ����� ��������� �������
	void SetTextLabelText(const char *Text);
	
	// ���������� ����� ��������� �������
	char *GetTextLabelText(void);
	
	// ����� ������� ��������� ������� �� ���������� X � Y
	void SetTextLabelPosition(int X,int Y);
	
	// ���������� ��������� X ������� ��������� �������
	int GetTextLabelPositionX(void);
	
	// ���������� ��������� Y ������� ��������� �������
	int GetTextLabelPositionY(void);
	
	// ���������� ������ ��������� �������
	int GetTextLabelWidth(void);
	
	// ���������� ������ ��������� �������
	int GetTextLabelHeight(void);
	
	// ���������� ���� ��������� �������
	HWND GetTextLabelWindow(void);
};

#endif