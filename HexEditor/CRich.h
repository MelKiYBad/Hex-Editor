/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ��������� �������,
	������ ����� �������������� � ������ ����������
*/

#ifndef _CRICH_H_
#define _CRICH_H_

#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <CommCtrl.h>

using namespace std;

class CRich{
private:
	vector<string> lines; // ������ �����
	HWND Rich; // ���� ��������� ������
public:
	// ������ ��������� ������
	CRich(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height);
	
	// ���������� ��� �������� ��������� ������
	~CRich(void);
	
	// ��������� ������ � ��������� ������
	void AddString(const char *Text);
	
	// ���������� ������ � ��������� ������ �� ��������� �������
	const char *GetString(int Index);
	
	// ����� ������� ��������� ������ �� ���������� X � Y
	void SetRichPosition(int X,int Y);
	
	// ���������� ��������� X ������� ��������� ������
	int GetRichPositionX(void);
	
	// ���������� ��������� Y ������� ��������� ������
	int GetRichPositionY(void);
	
	// ����� ������ ������� ������ � ������ ��������� ������
	void SetRichSize(int Width,int Height);
	
	// ���������� ������ ��������� ������
	int GetRichWidth(void);
	
	// ���������� ������ ��������� ������
	int GetRichHeight(void);
	
	// ���������� ���� ��������� ������
	HWND GetRichWindow(void);
};

#endif