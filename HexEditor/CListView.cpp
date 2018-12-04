#include "CListView.h"

CListView::CListView(HINSTANCE hInstance,HWND ParentWindow,int X,int Y,int Width,int Height){
	SelectedRowID = 0;
	ListView = CreateWindowEx(WS_EX_CLIENTEDGE,WC_LISTVIEW,"",WS_VISIBLE|WS_CHILD|LVS_REPORT|LVS_SHOWSELALWAYS ,X,Y,Width,Height,ParentWindow,NULL,hInstance,NULL);
	ListView_SetExtendedListViewStyle(ListView,LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
}

CListView::~CListView(void){
	DestroyWindow(ListView);
}

void CListView::AddColumn(const char *Text,int Width,int iSubItem){
	LV_COLUMN p; 
	p.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	p.fmt = LVCFMT_LEFT;
	p.cx = Width;
	p.pszText = (LPSTR)Text;
	p.cchTextMax = 0;
	p.iSubItem = iSubItem;
	ListView_InsertColumn(ListView, iSubItem, &p);
}

int CListView::CreateRow(int ItemID){
	LVITEM lvi;
	memset(&lvi,0,sizeof(LVITEM));
	lvi.mask = LVIF_TEXT | LVIF_PARAM | LVIF_STATE; 
	lvi.state = 0;
	lvi.stateMask = 0;
	lvi.iItem = ItemID;
	lvi.iSubItem = 0;
	return ListView_InsertItem(ListView, &lvi);
}

void CListView::AddRow(const char *Text,int RowID,int ItemID){
	ListView_SetItemText(ListView,RowID,ItemID,(LPSTR)Text);
}

char *CListView::GetRowText(int RowID,int ItemID){
	char retstring[256];
	ListView_GetItemText(ListView,RowID,ItemID,retstring,256);
	return retstring;
	
}

void CListView::OnCLickCallback(int RowID){
	SelectedRowID = RowID;
}

int CListView::GetSelectedRowID(void){
	return SelectedRowID;
}

int CListView::GetPositionX(void){
	RECT rc; GetClientRect(ListView,&rc);
	MapWindowPoints(ListView,GetParent(ListView),(LPPOINT)&rc,2);
	return rc.left;
}

int CListView::GetPositionY(void){
	RECT rc; GetClientRect(ListView,&rc);
	MapWindowPoints(ListView,GetParent(ListView),(LPPOINT)&rc,2);
	return rc.top;
}

void CListView::SetListViewSize(int Width,int Height){
	SetWindowPos(ListView,NULL,GetPositionX()-2,GetPositionY()-2,Width,Height,0);
}

HWND CListView::GetListViewWindow(void){
	return ListView;
}