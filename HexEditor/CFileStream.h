/*
	�����������: ����� �����
	����: 04.12.18
	��������: ����� ��� ������ � ������
*/

#ifndef _CFILESTREAM_H_
#define _CFILESTREAM_H_

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CFileStream{
private:
	ifstream File; // File ��� ������ � ������� � ������� ������
	unsigned char *Mem; // ������ - ������ ����������� �����
	int FileSize; // ������ ������������ �����
public:
	// ������ ����
	CFileStream(const char *FilePath);
	
	// ���������� ��� ��������
	~CFileStream(void);
	
	// ��������� ����
	bool SaveFile(const char *FilePath);
	
	// ����� ���� ������ � ������ ������ Mem �� ���������� �������
	void SetCharByIndex(unsigned char Byte,int Index);
	
	// ���������� ���� ������ � ������� ������ Mem �� ���������� �������
	unsigned char GetFileByIndex(int Byte);
	
	// ���������� ������ ������ ������������ ����� Mem
	unsigned char *GetFile(void);
	
	// ���������� ������ ������������ �����
	int GetFileSize(void);
};

#endif