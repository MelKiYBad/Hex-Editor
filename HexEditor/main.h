#ifndef _MAIN_H_
#define _MAIN_H_
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <sdkddkver.h>
#include <Windows.h>
#include "CApplication.h"
#include "CFileStream.h"
#include "CTextLabel.h"
#include "CEdit.h"
#include "CListView.h"
#include "CButton.h"
#include "CBitmap.h"

// ���������
CApplication *pApplication; // �������� ����� ����������
CFileStream *pFileStream; // ����� ��� ������ � ������
CListView *pListView; // ����� ��� ������ � ��������
CEdit *pEdit[16]; // ����� ��� ������ � ��������� ������� 16 ����
CTextLabel *pTextLabel; // ����� ��� ������ � ��������� ��������
CBitmap *pLogo; // ����� ��� ������ � ���������

#endif