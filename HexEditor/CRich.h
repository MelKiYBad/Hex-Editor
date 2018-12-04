/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с текстовой панелью,
	данный класс неиспользуется в данном приложении
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
	vector<string> lines; // вектор строк
	HWND Rich; // окно текстовой панели
public:
	// создаёт текстовую панель
	CRich(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height);
	
	// вызывается при удалении текстовой панели
	~CRich(void);
	
	// добавляет строку в текстовую панель
	void AddString(const char *Text);
	
	// возвращает строку с текстовой панели по заданному индексу
	const char *GetString(int Index);
	
	// задаёт позицию текстовой панели по кординатам X и Y
	void SetRichPosition(int X,int Y);
	
	// возвращает кординату X позиции текстовой панели
	int GetRichPositionX(void);
	
	// возвращает кординату Y позиции текстовой панели
	int GetRichPositionY(void);
	
	// задаёт размер размеры ширины и высоты текстовой панели
	void SetRichSize(int Width,int Height);
	
	// возвращает ширину текстовой панели
	int GetRichWidth(void);
	
	// возвращает высоту текстовой панели
	int GetRichHeight(void);
	
	// возвращает окно текстовой панели
	HWND GetRichWindow(void);
};

#endif