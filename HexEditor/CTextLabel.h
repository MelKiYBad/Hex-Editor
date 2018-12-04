/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с текстовой надписью,
	сделан по аналокии с CEdit т.к немог разобраться с перересовкой окна после смены текста
*/

#ifndef _CTEXTLABEL_H_
#define _CTEXTLABEL_H_

#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>

class CTextLabel{
private:
	HWND TextLabel; // окно - текстовая надпись
public:
	// создаёт текстовую надпись
	CTextLabel(HINSTANCE hInstance,HWND ParentWindow,const char *Label,int X, int Y,int Width,int Height); 
	
	// вызывается при удалении текстовой надписи
	~CTextLabel(void);
	
	// задает текст текстовой надписи
	void SetTextLabelText(const char *Text);
	
	// возвращает текст текстовой надписи
	char *GetTextLabelText(void);
	
	// задаёт позицию текстовой надписи по кординатам X и Y
	void SetTextLabelPosition(int X,int Y);
	
	// возвращает кординату X позиции текстовой надписи
	int GetTextLabelPositionX(void);
	
	// возвращает кординату Y позиции текстовой надписи
	int GetTextLabelPositionY(void);
	
	// возвращает ширину текстовой надписи
	int GetTextLabelWidth(void);
	
	// возвращает высоту текстовой надписи
	int GetTextLabelHeight(void);
	
	// возвращает окно текстовой надписи
	HWND GetTextLabelWindow(void);
};

#endif