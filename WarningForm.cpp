//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WarningForm.h"
#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWarnForm *WarnForm;

extern int ButtonTag;
extern AnsiString MyFName;
extern String CMPD;
//---------------------------------------------------------------------------
__fastcall TWarnForm::TWarnForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TWarnForm::YesButtClick(TObject *Sender)
{
MNForm->RichEdit2->PlainText=true;
if(MNForm->SaveDialog1->Execute())
	{
	MNForm->Label2->Caption = MNForm->SaveDialog1->FileName;
	MNForm->RichEdit2->Lines->SaveToFile(MNForm->SaveDialog1->FileName);
	}
MNForm->RichEdit2->PlainText=false;
NoButtClick(0);
}
//---------------------------------------------------------------------------

void __fastcall TWarnForm::DeclineButtClick(TObject *Sender)
{
WarnForm->Close();
MNForm->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TWarnForm::NoButtClick(TObject *Sender)
{
if(ButtonTag==1||ButtonTag==2)
	{
	MNForm->RichEdit1->Clear();
	MNForm->RichEdit2->Clear();

	MyFName = "default";
	MNForm->Label1->Caption = MyFName;
	MNForm->Label2->Caption = CMPD + MyFName;

	WarnForm->Close();
	MNForm->SetFocus();
	}
else
	exit(0);
}
//---------------------------------------------------------------------------

