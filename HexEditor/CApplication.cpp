#include "CApplication.h"

CApplication::CApplication(HINSTANCE hInstance){
	DefaultInstance = hInstance;
	memset(&wcl,0,sizeof(WNDCLASSEX));
	memset(&msg,0,sizeof(MSG));

	InitCommonControls();
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hbrBackground = CreateSolidBrush(RGB(240,240,240));
	wcl.hCursor = LoadCursor(NULL,IDC_ARROW);
	wcl.hIcon = LoadIcon(hInstance,MAIN_ICON);
	wcl.hIconSm = LoadIcon(hInstance,MAIN_ICON);
	wcl.hInstance = hInstance;
	wcl.lpfnWndProc = MsgProc;
	wcl.lpszClassName = "THISWINDOW";
	wcl.lpszMenuName = MAIN_MENU;
	RegisterClassEx(&wcl);
	MainWindow = CreateWindow("THISWINDOW","Hex Editor",WS_OVERLAPPEDWINDOW,CENTER_X,CENTER_Y,WINDOW_WIDTH,WINDOW_HEIGHT,NULL,NULL,hInstance,NULL);
	pLogo = new CBitmap(hInstance,IDB_BITMAP1);

	ShowWindow(MainWindow,SW_SHOWNORMAL);
	UpdateWindow(MainWindow);
}

CApplication::~CApplication(void){
	for(int i = 0;i<16;i++){
		if(pEdit[i]){
			delete pEdit[i];
			pEdit[i] = NULL;
		}
	}

	if(pListView){
		delete pListView;
		pListView = NULL;
	}

	if(pFileStream){
		delete pFileStream;
		pFileStream = NULL;
	}
	
	if(pTextLabel){
		delete pTextLabel;
		pTextLabel = NULL;
	}

	if(pLogo){
		delete pLogo;
		pLogo = NULL;
	}

	DestroyWindow(MainWindow);
}

void CApplication::RunApplication(void){
	for(;;){
		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if(msg.message == WM_QUIT){
			break;
		}
		if((!pFileStream) && (pLogo)){
			pLogo->DrawBitmap(pApplication->GetApplicationWindow(),0,0,pApplication->GetApplicationWidth(),pApplication->GetApplicationHeight());
		}
	}
}

int CApplication::GetApplicationWidth(void){
	RECT rct; GetClientRect(MainWindow,&rct);
	return rct.right-rct.left;
}

int CApplication::GetApplicationHeight(void){
	RECT rct; GetClientRect(MainWindow,&rct);
	return rct.bottom-rct.top;
}

HWND CApplication::GetApplicationWindow(void){
	return MainWindow;
}

HINSTANCE CApplication::GetApplicationInstance(void){
	return DefaultInstance;
}

LRESULT WINAPI CApplication::MsgProc(HWND Window,UINT MessageID,WPARAM wParam,LPARAM lParam){
	switch(MessageID){
		case WM_DESTROY:{
			PostQuitMessage(0);
		} break;

		case WM_COMMAND:{
			for(int i = 0;i<16;i++){
				if(pEdit[i]){
					if(CHECK_EDIT(pEdit[i])){
						char LabText[64]; sprintf(LabText,"%.8X+%.2X | %.8X",pListView->GetSelectedRowID(),i,pListView->GetSelectedRowID()+i);
						pTextLabel->SetTextLabelText(LabText);

						HWND focus = GetFocus();
						if(focus == pEdit[i]->GetEditWindow()){
							if(HIWORD(wParam) == EN_CHANGE){
								if(strlen(pEdit[i]->GetEditText()) > 0){
									if(strlen((const char*)pEdit[i]->GetEditText()) > 1){
										if(focus == pEdit[i]->GetEditWindow()){
											if(i != 15){
												SetFocus(pEdit[i+1]->GetEditWindow());
												SendMessage(pEdit[i+1]->GetEditWindow(), EM_SETSEL, 2, 0);
											}
										}
									}

									bool canedit = true;
									for(int k = 0;k<2;k++){
										if(!isxdigit(pEdit[i]->GetEditText()[k])){
											canedit = false;
										}
									}

									if(canedit){
										unsigned long value = stoul(pEdit[i]->GetEditText(),NULL,16);
										char shex[8]; sprintf(shex,"%.2X",value);
										pListView->AddRow(shex,pListView->GetSelectedRowID(),i+1);
										
										istringstream hxd(shex);
										unsigned int c; vector<unsigned char>bytes;
										while(hxd >> hex >> c){
											bytes.push_back(c);
										} pFileStream->SetCharByIndex(bytes[0],(pListView->GetSelectedRowID()*16)+i);

										string TextTxt;
										for(int k = 0;k<16;k++){
											TextTxt.push_back(pFileStream->GetFileByIndex((pListView->GetSelectedRowID()*16)+k));
										} pListView->AddRow((char*)TextTxt.c_str(),pListView->GetSelectedRowID(),17);
									}
								}
							}
						}
					}
				}
			}

			switch(wParam){
				case ID_40001:{
					if(!pFileStream){
						OPENFILENAME OpenFile;
						memset(&OpenFile,0,sizeof(OPENFILENAME));
						char FileName[260] = {0};
						OpenFile.lStructSize = sizeof(OpenFile);
						OpenFile.hwndOwner = Window;
						OpenFile.lpstrFile = FileName;
						OpenFile.nMaxFile = sizeof(FileName);
						OpenFile.lpstrFilter = "All\0*.*\0";
						OpenFile.nFilterIndex = 1;
						OpenFile.lpstrFileTitle = NULL;
						OpenFile.nMaxFileTitle = 0;
						OpenFile.lpstrInitialDir = NULL;
						OpenFile.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;
						if(GetOpenFileName(&OpenFile)){
							SetWindowText(Window,"Загрузка файла...");
							pFileStream = new CFileStream(OpenFile.lpstrFile);
							
							pListView = new CListView(pApplication->GetApplicationInstance(),Window,0,0,pApplication->GetApplicationWidth(),pApplication->GetApplicationHeight()-20);
							pListView->AddColumn("Смещение",80,0);
							pListView->AddColumn("00",35,1);
							pListView->AddColumn("01",35,2);
							pListView->AddColumn("02",35,3);
							pListView->AddColumn("03",35,4);
							pListView->AddColumn("04",35,5);
							pListView->AddColumn("05",35,6);
							pListView->AddColumn("06",35,7);
							pListView->AddColumn("07",35,8);
							pListView->AddColumn("08",35,9);
							pListView->AddColumn("09",35,10);
							pListView->AddColumn("0A",35,11);
							pListView->AddColumn("0B",35,12);
							pListView->AddColumn("0C",35,13);
							pListView->AddColumn("0D",35,14);
							pListView->AddColumn("0E",35,15);
							pListView->AddColumn("0F",35,16);
							pListView->AddColumn("Текст",125,17);

							for(int i = 0;i<pFileStream->GetFileSize();i+=16){
								char RowTxt[64]; sprintf(RowTxt,"%.8X",i);
								int rw = pListView->CreateRow(i/16);
								pListView->AddRow(RowTxt,rw,0);

								for(int j = 0;j<16;j++){
									char c = pFileStream->GetFileByIndex(i+j);
									char ItemTxt[8]; sprintf(ItemTxt,"%.2X",pFileStream->GetFileByIndex(i+j));
									pListView->AddRow(ItemTxt,rw,1+j);
								}

								string TextTxt;
								for(int k = 0;k<16;k++){
									TextTxt.push_back(pFileStream->GetFileByIndex(i+k));
								} pListView->AddRow((char*)TextTxt.c_str(),rw,17);
							} SetWindowText(Window,OpenFile.lpstrFile);

							for(int i = 1;i<17;i++){
								pEdit[i-1] = new CEdit(pApplication->GetApplicationInstance(),Window,16,pListView->GetRowText(0,i),i+(30*(i-1)),pApplication->GetApplicationHeight()-19,30,19,2,i,ES_UPPERCASE);
							} pTextLabel = new CTextLabel(pApplication->GetApplicationInstance(),Window,"00000000+00",17+(30*(17-1))+5,pApplication->GetApplicationHeight()-19,200,19);

							InvalidateRect(Window,NULL,true);
							char text[1024]; sprintf(text,"Файл: %s\nРазмер: %d байт.",OpenFile.lpstrFile,pFileStream->GetFileSize());
							MessageBox(NULL,text,"Чтение файла:",MB_OK|MB_ICONINFORMATION);
						}
					}else{
						MessageBox(NULL,"Файл уже открыт.","Чтение файла:",MB_OK|MB_ICONERROR);
					}
				} break;

				case ID_40002:{
					if(pFileStream){
						OPENFILENAME OpenFile;
						memset(&OpenFile,0,sizeof(OPENFILENAME));
						char FileName[260] = {0};
						OpenFile.lStructSize = sizeof(OpenFile);
						OpenFile.hwndOwner = Window;
						OpenFile.lpstrFile = FileName;
						OpenFile.nMaxFile = sizeof(FileName);
						OpenFile.lpstrFilter = "All\0*.*\0";
						OpenFile.nFilterIndex = 1;
						OpenFile.lpstrFileTitle = NULL;
						OpenFile.nMaxFileTitle = 0;
						OpenFile.lpstrInitialDir = NULL;
						OpenFile.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST;
						if(GetSaveFileName(&OpenFile)){
							if(!pFileStream->SaveFile(OpenFile.lpstrFile)){
								MessageBox(NULL,"Невозможно сохранить файл.","Сохранение файла:",MB_OK|MB_ICONERROR);
							}else{
								char text[1024]; sprintf(text,"Файл успешно сохранён.");
								MessageBox(NULL,text,"Сохранение файла:",MB_OK|MB_ICONINFORMATION);
							}
						}
					}else{
						MessageBox(NULL,"В данный момент нет открытых файлов.","Сохранение файла:",MB_OK|MB_ICONERROR);
					}
				} break;

				case ID_40004:{
					if(pFileStream){
						for(int i = 0;i<16;i++){
							delete pEdit[i];
							pEdit[i] = NULL;
						}

						delete pListView;
						pListView = NULL;

						delete pFileStream;
						pFileStream = NULL;

						delete pTextLabel;
						pTextLabel = NULL;

						SetWindowText(Window,"Hex Editor");
					}else{
						MessageBox(NULL,"В данный момент нет открытых файлов.","Закрытие файла:",MB_OK|MB_ICONERROR);
					}
				} break;

				case ID_40008:{
					MessageBox(NULL,"Программа для редактирования файлов.\nCopyright (C) AppInvest 2018","О программе:",MB_OK|MB_ICONINFORMATION);
				} break;

				case ID_40009:{
					if(pFileStream){
						delete pFileStream;
						pFileStream = NULL;
					}
					DestroyWindow(Window);
				} break;
			};
		} break;

		case WM_SIZE:{
			pTextLabel->SetTextLabelPosition(pTextLabel->GetTextLabelPositionX(),pApplication->GetApplicationHeight()-19);
			pListView->SetListViewSize(pApplication->GetApplicationWidth(),pApplication->GetApplicationHeight()-20);
			for(int i = 0;i<16;i++){
				pEdit[i]->SetEditPosition(pEdit[i]->GetEditPositionX(),pApplication->GetApplicationHeight()-19);
			}
		} break;

		case WM_NOTIFY:{
			LV_DISPINFO *pLvdi = (LV_DISPINFO*)lParam;
			switch(pLvdi->hdr.code){
				case NM_CLICK:{
					NM_LISTVIEW *pNm = (NM_LISTVIEW*)lParam;
					pListView->OnCLickCallback(pNm->iItem);
					for(int i = 0;i<16;i++){
						pEdit[i]->SetEditText(pListView->GetRowText(pListView->GetSelectedRowID(),i+1));
					}
				} break;
			}
		} break;
	}
	return DefWindowProc(Window,MessageID,wParam,lParam);
}