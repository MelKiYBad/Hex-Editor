#include "CFileStream.h"

CFileStream::CFileStream(const char *FilePath){
	File.open(FilePath,ios::in|ios::binary|ios::ate);
	if(!File){
		char text[512]; sprintf(text,"Невозможно открыть файл:\n%s.",FilePath);
		MessageBox(NULL,text,"Ошибка:",MB_OK|MB_ICONERROR);
	}else{
		FileSize = (int)File.tellg();
		File.seekg(0,ios::beg);
		Mem = new unsigned char[FileSize];
		File.read((char*)Mem,FileSize);
	}
}

CFileStream::~CFileStream(void){
	FileSize = 0;
	delete Mem;
	File.close();
}

bool CFileStream::SaveFile(const char *FilePath){
	ofstream file(FilePath,ios::out|ios::binary|ios::ate);
	if(!file){
		return false;
	}
	if(Mem == NULL){
		return false;
	}
	file.write((char*)Mem,FileSize);
	file.close();
	return true;
}

void CFileStream::SetCharByIndex(unsigned char Byte,int Index){
	Mem[Index] = Byte;
}

unsigned char CFileStream::GetFileByIndex(int Byte){
	return Mem[Byte];
}

unsigned char *CFileStream::GetFile(void){
	return Mem;
}

int CFileStream::GetFileSize(void){
	return FileSize;
}
