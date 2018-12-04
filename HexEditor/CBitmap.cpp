#include "CBitmap.h"

CBitmap::CBitmap(HINSTANCE hInstance,unsigned long Resource){
	pBitmap = (HBITMAP)LoadImage(hInstance,MAKEINTRESOURCE(Resource),IMAGE_BITMAP,0,0,NULL);
}

CBitmap::~CBitmap(void){
	DeleteObject(pBitmap);
	ReleaseDC(WindowFromDC(Dc),Dc);
}

void CBitmap::DrawBitmap(HWND ParentWindow,int X,int Y,int Width,int Height){
	Dc = GetDC(ParentWindow);
	pSrcImg = CreateCompatibleDC(Dc);
	GetObject(pBitmap,sizeof(BITMAP),&pBmp);
	SelectObject(pSrcImg,pBitmap);
	StretchBlt(Dc,0,0,Width,Height,pSrcImg,0,0,pBmp.bmWidth,pBmp.bmHeight,SRCCOPY);
	DeleteDC(pSrcImg);
	ReleaseDC(WindowFromDC(Dc),Dc);
}
