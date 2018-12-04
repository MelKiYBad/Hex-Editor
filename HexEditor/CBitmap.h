/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с картинкой
*/

#ifndef _CBITMAP_H_
#define _CBITMAP_H_

#include <Windows.h>

class CBitmap{
private:
	HDC Dc; // HDC от HWND место куда рисуем картинку BMP
	HDC pSrcImg; // как pDevice
	HBITMAP pBitmap; // картинка BMP
	BITMAP pBmp; // информация по картинке BMP
public:
	// загружает и создаёт картинку BMP из ресурса
	CBitmap(HINSTANCE hInstance,unsigned long Resource);
	
	// вызывается при удалении картинки BMP
	~CBitmap(void);
	
	// рисует картинку BMP на указанное окно
	void DrawBitmap(HWND ParentWindow,int X,int Y,int Width,int Height);
};

#endif