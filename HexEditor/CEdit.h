/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ��������� �������
*/

#ifndef _CEDIT_H_
#define _CEDIT_H_

#include <Windows.h>
#include <CommCtrl.h>

class CEdit{
private:
	HWND Edit; // ���� - ��������� ������
public:
	 // ������ ��������� ������
	CEdit(HINSTANCE hInstance,HWND ParentWindow,int cHeight,const char *Text,int X,int Y,int Width,int Height,int CharLimit,int cEditID,long Flag);
	
	// ���������� ��� �������� ��������� ������
	~CEdit(void);

	// ����� ����� ��������� ������
	void SetEditText(const char *Text); 
	
	// ���������� ����� � ��������� ������
	char *GetEditText(void);
	
	// ����� ������� ��������� ������ �� ���������� X � Y
	void SetEditPosition(int X,int y);
	
	// ���������� ��������� X ������� ��������� ������
	int GetEditPositionX(void);
	
	// ���������� ��������� Y ������� ��������� ������
	int GetEditPositionY(void);
	
	// ����� ������ ������� ������ � ������ ��������� ������
	void SetEditSize(int Width,int Height);
	
	// ���������� ������ ��������� ������
	int GetEditWidth(void);
	
	// ���������� ������ ��������� ������
	int GetEditHeight(void);
	
	// ���������� ���-�� �������� � ��������� ������
	int GetEditTextSize(void);
	
	// ���������� ���� ��������� ������
	HWND GetEditWindow(void);
};

#endif