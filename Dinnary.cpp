//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Phil.h"
#include "Dinnary.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define MAX_COUNT 10
int countPhil;

TDinner *Dinner;
//---------------------------------------------------------------------------
__fastcall TDinner::TDinner(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TDinner::N2Click(TObject *Sender)
{
ShowMessage ("В столовой имеются  кресла для еды и N вилок.\nЕсли посетитель может занять место за столом он его занимает,\nесли мест нет, он уходит.\nДля начала работы нужно ввести количетсо философоф");
}
//---------------------------------------------------------------------------

void __fastcall TDinner::N3Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TDinner::Button1Click(TObject *Sender)
{
	if (Edit1->Text.ToInt()>MAX_COUNT||Edit1->Text.ToInt()<2){
	  ShowMessage("Введите число от 2 до 10");
	}else
	countPhil=Edit1->Text.ToInt();
	Dinner->N1->Enabled = true;
}
//---------------------------------------------------------------------------
char* setTitle(int i){
 char* Name[10]={"Ницше","Сократ","Кант","Аристотель","Платон",
"Спиноза","Гёте","Декарт","Кафка","Маркс"};

 return Name[i];
}

void __fastcall TDinner::N1Click(TObject *Sender)
{   for (int i = 0; i < countPhil; i++) {
	Fork[i] = CreateMutex(NULL, false, "fork"+i);
	}
	Phil = CreateSemaphore(NULL, countPhil-1, countPhil-1, "phil");
	for (int i = 0; i < countPhil; i++) {
	STARTUPINFO si;PROCESS_INFORMATION pi;
		ZeroMemory(&si,sizeof(STARTUPINFO));
		si.cb=sizeof(STARTUPINFO);
		si.lpTitle = setTitle(i);
		CreateProcess(NULL, "Phil1.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	}
Dinner->Events->Lines->Add("Столовая открыта");
Dinner->N1->Enabled = false; //кнопка начала работы недоступна
}
//---------------------------------------------------------------------------

