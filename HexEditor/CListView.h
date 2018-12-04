/*
	Разработчик: Попов Павел
	Дата: 04.12.18
	Описание: Класс для работы с таблицей
*/

#ifndef _CLISTVIEW_H_
#define _CLISTVIEW_H_

#include <windows.h>
#include <CommCtrl.h>

class CListView{
private:
	int SelectedRowID; // выбраная таблица назначается при вызове OnCLickCallback
	HWND ListView; // окно - таблица
public:
	// создаёт таблицу
	CListView(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height);
	
	// вызывается при удалении таблицы
	~CListView(void);
	
	// добавляет в шапку таблицы категорию
	void AddColumn(const char *Text,int Width,int iSubItem);
	
	// создаёт строку в таблице
	int CreateRow(int ItemID);
	
	// добавляет подкатегориюна указанную строку в указанную категорию
	void AddRow(const char *Text,int RowID,int ItemID);
	
	// возвращает текст ячейки указанной строки и категории
	char *GetRowText(int RowID,int ItemID);
	
	// присваевает SelectedRowID RowID
	void OnCLickCallback(int RowID);
	
	// возвращает SelectedRowID
	int GetSelectedRowID(void);
	
	// возвращает позицию таблицы по кординате X
	int GetPositionX(void);
	
	// возвращает позицию таблицы по кординате Y
	int GetPositionY(void);
	
	// задаёт размер ширины и высоты таблицы
	void SetListViewSize(int Width,int Height);
	
	// возвращает окно таблицы
	HWND GetListViewWindow(void);
};

#endif