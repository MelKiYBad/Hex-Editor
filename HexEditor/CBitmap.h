/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ���������
*/

#ifndef _CBITMAP_H_
#define _CBITMAP_H_

#include <Windows.h>

class CBitmap{
private:
	HDC Dc; // HDC �� HWND ����� ���� ������ �������� BMP
	HDC pSrcImg; // ��� pDevice
	HBITMAP pBitmap; // �������� BMP
	BITMAP pBmp; // ���������� �� �������� BMP
public:
	// ��������� � ������ �������� BMP �� �������
	CBitmap(HINSTANCE hInstance,unsigned long Resource);
	
	// ���������� ��� �������� �������� BMP
	~CBitmap(void);
	
	// ������ �������� BMP �� ��������� ����
	void DrawBitmap(HWND ParentWindow,int X,int Y,int Width,int Height);
};

#endif