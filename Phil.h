//---------------------------------------------------------------------------

#ifndef PhilH
#define PhilH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Events;
	TProgressBar *Work;
	void __fastcall N2Click(TObject *Sender);
private:	void takeForks();// User declarations
public:	
// User declarations
	__fastcall TForm2(TComponent* Owner);
};
int getID(AnsiString name);
int id;
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
