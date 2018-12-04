/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с файлом
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
	ifstream File; // File для работы с записью и чтением файлов
	unsigned char *Mem; // массив - данные загруженого файла
	int FileSize; // размер загруженного файла
public:
	// читает файл
	CFileStream(const char *FilePath);
	
	// вызывается при удалении
	~CFileStream(void);
	
	// сохраняет файл
	bool SaveFile(const char *FilePath);
	
	// задаёт байт данных в массив данных Mem по указанному индексу
	void SetCharByIndex(unsigned char Byte,int Index);
	
	// возвращяет байт данныс с массива данных Mem по указанному индексу
	unsigned char GetFileByIndex(int Byte);
	
	// возвращяет массив данных загруженного файла Mem
	unsigned char *GetFile(void);
	
	// возвращает размер загруженного файла
	int GetFileSize(void);
};

#endif