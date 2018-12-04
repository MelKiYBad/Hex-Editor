/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с кнопкой,
	данный класс неиспользуется в данном приложении
*/

#ifndef _CBUTTON_H_
#define _CBUTTON_H_

#include <Windows.h>
#include <CommCtrl.h>

class CButton{
private:
	unsigned long BtnID; // ID кнопки, присваевается при создании
	HWND Button; // окно - кнопка
public:
	// создает кнопку
	CButton(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height,const char *Title,unsigned long ButtonID);
	
	// вызывается при удалении кнопки
	~CButton(void);
	
	// возвращяет ID кнопки
	int GetButtonID(void);
	
	// задаёт кнопки позицию по кординатам X и Y
	void SetButtonPosition(int X,int Y);
	
	// возвращает позицию кнопки по кординате X
	int GetButtonPositionX(void);
	
	// возвращает позицию кнопки по кординате Y
	int GetButtonPositionY(void);
	
	// задаёт размер размеры ширины и высоты кнопки
	void SetButtonSize(int Width,int Height);
	
	// возвращает ширину кнопки
	int GetButtonWidth(void);
	
	// возвращает высоту кнопки
	int GetButtonHeight(void);
	
	// возвращает окно кнопки
	HWND GetButtonWindow(void);

};

#endif