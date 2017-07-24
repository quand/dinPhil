//---------------------------------------------------------------------------

#ifndef DinnaryH
#define DinnaryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <string>
//---------------------------------------------------------------------------
class TDinner : public TForm
{
__published:	// IDE-managed Components
	TMemo *Events;
	TMainMenu *MainMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TTimer *Timer1;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	TMenuItem *N1;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDinner(TComponent* Owner);
};
char* setTitle(int i);
//---------------------------------------------------------------------------
extern PACKAGE TDinner *Dinner;
//---------------------------------------------------------------------------
#endif

//переменные
bool isAny = true; //состояние парикмахера спит/не спит
HANDLE Fork[5],Phil;  //дескриптор парикмахера
  //дескриптор клиентов