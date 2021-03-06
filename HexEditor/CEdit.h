/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с текстовой строкой
*/

#ifndef _CEDIT_H_
#define _CEDIT_H_

#include <Windows.h>
#include <CommCtrl.h>

class CEdit{
private:
	HWND Edit; // окно - текстовая строка
public:
	 // создаёт текстовую строку
	CEdit(HINSTANCE hInstance,HWND ParentWindow,int cHeight,const char *Text,int X,int Y,int Width,int Height,int CharLimit,int cEditID,long Flag);
	
	// вызывается при удалении текстовой строки
	~CEdit(void);

	// задаёт текст текстовой строки
	void SetEditText(const char *Text); 
	
	// возвращает текст с текстовой строки
	char *GetEditText(void);
	
	// задаёт позицию текстовой строки по кординатам X и Y
	void SetEditPosition(int X,int y);
	
	// возвращает кординату X позиции текстовой строки
	int GetEditPositionX(void);
	
	// возвращает кординату Y позиции текстовой строки
	int GetEditPositionY(void);
	
	// задаёт размер размеры ширины и высоты текстовой строки
	void SetEditSize(int Width,int Height);
	
	// возвращает ширину текстовой строки
	int GetEditWidth(void);
	
	// возвращает высоту текстовой строки
	int GetEditHeight(void);
	
	// возвращает кол-во символов в текстовой строке
	int GetEditTextSize(void);
	
	// возвращает окно текстовой строки
	HWND GetEditWindow(void);
};

#endif