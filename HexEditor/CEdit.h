/*
	–азработчик: ѕопов ѕавел
	ƒата: 04.12.18
	ќписание:  ласс дл€ работы с текстовой строкой
*/

#ifndef _CEDIT_H_
#define _CEDIT_H_

#include <Windows.h>
#include <CommCtrl.h>

class CEdit{
private:
	HWND Edit; // окно - текстова€ строка
public:
	 // создаЄт текстовую строку
	CEdit(HINSTANCE hInstance,HWND ParentWindow,int cHeight,const char *Text,int X,int Y,int Width,int Height,int CharLimit,int cEditID,long Flag);
	
	// вызываетс€ при удалении текстовой строки
	~CEdit(void);

	// задаЄт текст текстовой строки
	void SetEditText(const char *Text); 
	
	// возвращает текст с текстовой строки
	char *GetEditText(void);
	
	// задаЄт позицию текстовой строки по кординатам X и Y
	void SetEditPosition(int X,int y);
	
	// возвращает кординату X позиции текстовой строки
	int GetEditPositionX(void);
	
	// возвращает кординату Y позиции текстовой строки
	int GetEditPositionY(void);
	
	// задаЄт размер размеры ширины и высоты текстовой строки
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