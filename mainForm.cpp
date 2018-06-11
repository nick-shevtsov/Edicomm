//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>

#pragma hdrstop

#include "mainForm.h"
#include "About.h"
#include "WarningForm.h"

#include "comsedit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMNForm *MNForm;

String CMPD = "_";
String strLine = "����� ";
String strColumn = ", ������ ";
String strLines = " ����� �� ";
String strChars = " ������� �������";

AnsiString MyFName = "default";

int line = 1, column = 0, lines = 1, chars = 1;
int ButtonTag = 0;

//---------------------------------------------------------------------------
__fastcall TMNForm::TMNForm(TComponent* Owner)
	: TForm(Owner)
{
TMNForm::Label2->Caption = CMPD + MyFName;
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N21Click(TObject *Sender)
{
ButtonTag = ((TButton*)Sender)->Tag;
if(RichEdit2->Text != "")
	WarnForm->Show();
else exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::RichEdit1Change(TObject *Sender)
{
try
{
N20->Enabled = true;
TMNForm::Label1->Caption = MyFName;
if	(MyFName == "default") TMNForm::Label2->Caption = CMPD + MyFName;
else TMNForm::Label2->Caption = CMPD + ExtractFileName(MyFName);

AnsiString source = RichEdit1->Lines->Text;
std::string src(source.c_str());
std::string dst;
Comsedit::Compress(dst, src);

RichEdit2->Lines->BeginUpdate();
RichEdit2->Lines->Text = AnsiString(dst.c_str());
RichEdit2->Lines->EndUpdate();

line = RichEdit1->CaretPos.Y;
column = RichEdit1->CaretPos.X;
StatusBar->SimpleText = strLine + (line + 1) + strColumn + column;
}
catch(Exception &e){}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N5Click(TObject *Sender)
{
	if (N5->Checked) Comsedit::singleLine = true;
	else  Comsedit::singleLine = false;
	RichEdit1Change(0);
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::N22Click(TObject *Sender)
{
	if (N22->Checked) Comsedit::singleRemove = false;
	else  Comsedit::singleRemove = true;
	RichEdit1Change(0);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N24Click(TObject *Sender)
{
	if (N24->Checked) Comsedit::multiLine = true;
	else  Comsedit::multiLine = false;
	RichEdit1Change(0);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N25Click(TObject *Sender)
{
	if (N25->Checked) Comsedit::multiRemove = false;
	else  Comsedit::multiRemove = true;
	RichEdit1Change(0);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N27Click(TObject *Sender)
{
	if (N27->Checked) Comsedit::emptyRemove = true;
	else  Comsedit::emptyRemove = false;
	RichEdit1Change(0);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::RichEdit1SelectionChange(TObject *Sender)
{
if (RichEdit1->SelText=="")
	{
	line = RichEdit1->CaretPos.Y;
	column = RichEdit1->CaretPos.X;
	StatusBar->SimpleText = strLine + (line + 1) + strColumn + column;
	}
else
	{
	lines = 1;
	int selStartY = SendMessage(RichEdit1->Handle, EM_LINEFROMCHAR, RichEdit1->SelStart,0);
	for (int i = RichEdit1->CaretPos.Y; i > selStartY ; i--)
		lines++;
	chars = RichEdit1->SelLength;
	StatusBar->SimpleText = IntToStr(lines) + strLines + IntToStr(chars) + strChars;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N17Click(TObject *Sender)
{
RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N20Click(TObject *Sender)
{
RichEdit1->SelStart = 0;
RichEdit2->SelStart = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::RichEdit2SelectionChange(TObject *Sender)
{
if (!RichEdit2->Focused()) return;
else{
if (RichEdit2->SelText=="")
		{
			line = RichEdit2->CaretPos.Y;
			column = RichEdit2->CaretPos.X;
			StatusBar->SimpleText = strLine + (line + 1) + strColumn + column;
		}
		else
		{
			lines = 1;
			int selStartY = SendMessage(RichEdit2->Handle, EM_LINEFROMCHAR, RichEdit2->SelStart,0);
			for (int i = RichEdit2->CaretPos.Y; i > selStartY; i--)
					lines++;
			chars = RichEdit2->SelLength;
			StatusBar->SimpleText = IntToStr(lines) + strLines + IntToStr(chars) + strChars;
		}
}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N7Click(TObject *Sender)
{
ButtonTag = ((TButton*)Sender)->Tag;
if(RichEdit2->Text != "")
	WarnForm->Show();

if (OpenDialog1->Execute())
	{
	MyFName = OpenDialog1->FileName;
	RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::N9Click(TObject *Sender)
{
	RichEdit2->Lines->SaveToFile(TMNForm::Label2->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N10Click(TObject *Sender)
{
if(SaveDialog1->Execute())
	{
	TMNForm::Label2->Caption = SaveDialog1->FileName;
	RichEdit2->Lines->SaveToFile(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N6Click(TObject *Sender)
{
ButtonTag = ((TButton*)Sender)->Tag;
if(RichEdit2->Text != "")
	WarnForm->Show();
else
	{
	RichEdit1->Clear();
	RichEdit2->Clear();

	MyFName = "default";
	Label1->Caption = MyFName;
	Label2->Caption = CMPD + MyFName;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N13Click(TObject *Sender)
{
	FindDialog1->FindText = RichEdit1->SelText;
	FindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::FindDialog1Find(TObject *Sender)
{
int FoundAt, StartPos, ToEnd;
TSearchTypes Option;
/* ���� ���� ���������, �� ����� ����, ������� � ��� ���������� �������, ����� � ������� ������� */
StartPos = RichEdit1->SelStart;
if(RichEdit1->SelLength)
	StartPos += RichEdit1->SelLength;
/* ToEnd - ����� ������, ������� � ������ ������� ������ � �� ����� */
ToEnd = RichEdit1->Text.Length() - StartPos;
/* ����� ������ ����� ��� ��� � ����������� �� ��������� ������������ */
if(FindDialog1->Options.Contains(frWholeWord))
	Option << stWholeWord;
else Option >> stWholeWord;
/* ����� � ������ ��� ��� ����� �������� � ����������� �� ��������� ������������ */
if(FindDialog1->Options.Contains(frMatchCase))
	Option << stMatchCase;
else Option >> stMatchCase;
FoundAt = RichEdit1->FindText(FindDialog1->FindText, StartPos, ToEnd, Option);
if(FoundAt != -1) // ���� �������
	{
	RichEdit1->SetFocus();
	RichEdit1->SelStart = FoundAt;
	RichEdit1->SelLength = FindDialog1->FindText.Length();
	}
else ShowMessage("����� '" + FindDialog1->FindText + "' �� ��������");
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::N34Click(TObject *Sender)
{
	ReplaceDialog1->FindText = RichEdit1->SelText;
	ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::ReplaceDialog1Find(TObject *Sender)
{
int FoundAt, StartPos, ToEnd;
TSearchTypes Option;
/* ���� ���� ���������, �� ����� ����, ������� � ��� ���������� �������, ����� � ������� ������� */
StartPos = RichEdit1->SelStart;
if(RichEdit1->SelLength)
	StartPos += RichEdit1->SelLength;
/* ToEnd - ����� ������, ������� � ������ ������� ������ � �� ����� */
ToEnd = RichEdit1->Text.Length() - StartPos;
/* ����� ������ ����� ��� ��� � ����������� �� ��������� ������������ */
if(ReplaceDialog1->Options.Contains(frWholeWord))
	Option << stWholeWord;
else Option >> stWholeWord;
/* ����� � ������ ��� ��� ����� �������� � ����������� �� ��������� ������������ */
if(ReplaceDialog1->Options.Contains(frMatchCase))
	Option << stMatchCase;
else Option >> stMatchCase;
FoundAt = RichEdit1->FindText(ReplaceDialog1->FindText, StartPos, ToEnd, Option);
if(FoundAt != -1) // ���� �������
	{
	RichEdit1->SetFocus();
	RichEdit1->SelStart = FoundAt;
	RichEdit1->SelLength = ReplaceDialog1->FindText.Length();
	}
else ShowMessage("����� '" + ReplaceDialog1->FindText + "' �� ��������");

  if ( ReplaceDialog1->Options.Contains(frReplaceAll))
	{
	ReplaceDialog1Replace(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::ReplaceDialog1Replace(TObject *Sender)
{
if(RichEdit1->SelText != "")
  {
	RichEdit1->SelText=ReplaceDialog1->ReplaceText;
  }
  else if (ReplaceDialog1->Options.Contains(frReplace))
  {
	ReplaceDialog1Find(Sender);
  }
if (ReplaceDialog1->Options.Contains(frReplaceAll))
	{
	ReplaceDialog1Find(Sender);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMNForm::FormCreate(TObject *Sender)
{
	StatusBar->SimpleText = strLine + line + strColumn + column;
}
//---------------------------------------------------------------------------


void __fastcall TMNForm::N37Click(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::FormClose(TObject *Sender, TCloseAction &Action)
{
ButtonTag = 0;
Action = caNone;
if(RichEdit2->Text != "")
	WarnForm->Show();
else exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TMNForm::N36Click(TObject *Sender)
{
ShellExecute( Handle, _T( "open" ), _T( "Help.chm" ), NULL, NULL, SW_NORMAL);
}
//---------------------------------------------------------------------------

