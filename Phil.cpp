//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Dinnary.h"
#include "Phil.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
HANDLE left;
HANDLE right;
AnsiString name;
int rId,lastID=1;

HANDLE hThread;
DWORD dwThreadID,dwThrdParam = 1;
//---------------------------------------------------------------------------
DWORD WINAPI ThreadFunc(LPVOID lpParam){
int countEat=0;
while (countEat<5){

	Form2->Events->Lines->Add(name+" ������");
	Sleep(random(7000) + 3000);
	Form2->Events->Lines->Add(name+" ����� ����");

	WaitForSingleObject(Phil, INFINITE);
	Form2->Events->Lines->Add(name+" ����� � ��������");



	WaitForSingleObject(left, INFINITE);
	Form2->Events->Lines->Add(name+" ���� ����� �����");
	WaitForSingleObject(right, INFINITE);
	Form2->Events->Lines->Add(name+" ���� ������ �����");

	Form2->Events->Lines->Add(name+" ���");

	Sleep(random(5000) + 5000);

	ReleaseMutex(right);
	Form2->Events->Lines->Add(name+" ������� ������ �����");
	ReleaseMutex(left);
	Form2->Events->Lines->Add(name+" ������� ����� �����");

	ReleaseSemaphore(Phil, 1, NULL);
	Form2->Events->Lines->Add(name+" ���� � ����� ������");
	countEat++;
}
return 0;
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	STARTUPINFO si;
	GetStartupInfo(&si);
	Form2->Text=si.lpTitle;
	id=getID(Form2->Text);
	lastID=lastID < id ? id : lastID;
	name = Form2->Text;

	left = CreateMutex(NULL, false, "fork"+id);
	right = CreateMutex(NULL, false, "fork"+((id%4)+1));
	Phil = CreateSemaphore(NULL, lastID-1, lastID-1, "phil");


	hThread=CreateThread(NULL,0,ThreadFunc,&dwThrdParam,0,&dwThreadID);
	SetThreadPriority(hThread,THREAD_PRIORITY_NORMAL);
}
//---------------------------------------------------------------------------
 int getID(AnsiString name)
 {  char* Name[10]={"�����","������","����","����������","������",
"�������","ø��","������","�����","�����"};
	for (int i = 0; i < 10; i++) {
		if (name==Name[i]) {
			return i;
		}
	}
	return -1;
 }
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
	for(int i = 0; i < lastID+1; i++)
	{
		CloseHandle(Fork[i]);
	}
	CloseHandle(Phil);
	SuspendThread(hThread);
	TerminateThread(hThread,NULL);
	Close();
}

