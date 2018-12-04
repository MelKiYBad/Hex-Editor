/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ��������
*/

#ifndef _CLISTVIEW_H_
#define _CLISTVIEW_H_

#include <windows.h>
#include <CommCtrl.h>

class CListView{
private:
	int SelectedRowID; // �������� ������� ����������� ��� ������ OnCLickCallback
	HWND ListView; // ���� - �������
public:
	// ������ �������
	CListView(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height);
	
	// ���������� ��� �������� �������
	~CListView(void);
	
	// ��������� � ����� ������� ���������
	void AddColumn(const char *Text,int Width,int iSubItem);
	
	// ������ ������ � �������
	int CreateRow(int ItemID);
	
	// ��������� �������������� ��������� ������ � ��������� ���������
	void AddRow(const char *Text,int RowID,int ItemID);
	
	// ���������� ����� ������ ��������� ������ � ���������
	char *GetRowText(int RowID,int ItemID);
	
	// ����������� SelectedRowID RowID
	void OnCLickCallback(int RowID);
	
	// ���������� SelectedRowID
	int GetSelectedRowID(void);
	
	// ���������� ������� ������� �� ��������� X
	int GetPositionX(void);
	
	// ���������� ������� ������� �� ��������� Y
	int GetPositionY(void);
	
	// ����� ������ ������ � ������ �������
	void SetListViewSize(int Width,int Height);
	
	// ���������� ���� �������
	HWND GetListViewWindow(void);
};

#endif