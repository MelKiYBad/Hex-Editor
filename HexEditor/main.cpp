#include "main.h"

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,char *lpszCmdLine,int ShowCmd){
	pApplication = new CApplication(hInstance);
	pApplication->RunApplication();
	delete pApplication;
}