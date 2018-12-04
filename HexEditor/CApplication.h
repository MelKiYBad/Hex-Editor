/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Основной класс приложения
*/

#ifndef _CAPPLICATION_H_
#define _CAPPLICATION_H_

#include <Windows.h>
#include <sstream>
#include "CFileStream.h"
#include "CTextLabel.h"
#include "CEdit.h"
#include "CRich.h"
#include "CListView.h"
#include "CButton.h"
#include "CBitmap.h"
#include "resource.h"

using namespace std;

#define WINDOW_WIDTH 805 // размер окна ширина
#define WINDOW_HEIGHT 600 // размер окна высота
#define CENTER_X ((GetSystemMetrics(SM_CXSCREEN)/2)-(WINDOW_WIDTH/2)) // макрос для определения центра по оси X
#define CENTER_Y ((GetSystemMetrics(SM_CYSCREEN)/2)-(WINDOW_HEIGHT/2)) // макрос для определения центра по оси Y
#define MAIN_ICON MAKEINTRESOURCE(IDI_ICON1) // главная иконка приложения
#define MAIN_MENU MAKEINTRESOURCE(IDR_MENU1) // ресурс меню
#define CHECK_BUTTON(Button) (int)wParam == Button->GetButtonID() // макрос для опредения ID кнопки
#define CHECK_EDIT(Edit) (HWND)lParam == Edit->GetEditWindow() // макрос для определения окна CEdit

class CApplication{
private:
	HINSTANCE DefaultInstance; // hInstance
	HWND MainWindow; // дескриптор окна приложения (главное окно)
	WNDCLASSEX wcl; // класс главного окна
	MSG msg; // дескриптор обработчика Windows сообщений
public:
	// создаёт приложение
	CApplication(HINSTANCE hInstance);
	
	// вызывается при удалении приложения
	~CApplication(void);
	
	// запускает приложение
	void RunApplication(void);
	
	// возвращает ширину главного окна
	int GetApplicationWidth(void);
	
	// возвращает высоту главного окна
	int GetApplicationHeight(void);
	
	// возвращает главное окно приложения
	HWND GetApplicationWindow(void);
	
	// возвращает HINSTANCE приложения
	HINSTANCE GetApplicationInstance(void);
	
	// обработчик Windows сообщений
	static LRESULT WINAPI MsgProc(HWND Window,UINT MessageID,WPARAM wParam,LPARAM lParam);
};

// Указатели (объявленные в main.h)
extern CApplication *pApplication; // Основной класс приложения
extern CFileStream *pFileStream; // Класс для работы с файлом
extern CListView *pListView; // Класс для работы с таблицей
extern CEdit *pEdit[16]; // Класс для работы с текстовой строкой 16 штук
extern CTextLabel *pTextLabel; // Класс для работы с текстовой надписью
extern CBitmap *pLogo; // Класс для работы с картинкой

#endif