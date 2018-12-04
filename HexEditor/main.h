#ifndef _MAIN_H_
#define _MAIN_H_
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <sdkddkver.h>
#include <Windows.h>
#include "CApplication.h"
#include "CFileStream.h"
#include "CTextLabel.h"
#include "CEdit.h"
#include "CListView.h"
#include "CButton.h"
#include "CBitmap.h"

// Указатели
CApplication *pApplication; // Основной класс приложения
CFileStream *pFileStream; // Класс для работы с файлом
CListView *pListView; // Класс для работы с таблицей
CEdit *pEdit[16]; // Класс для работы с текстовой строкой 16 штук
CTextLabel *pTextLabel; // Класс для работы с текстовой надписью
CBitmap *pLogo; // Класс для работы с картинкой

#endif