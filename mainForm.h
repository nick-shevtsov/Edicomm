//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TMNForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N12;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TStatusBar *StatusBar;
	TPanel *Panel1;
	TRichEdit *RichEdit1;
	TPanel *Panel2;
	TRichEdit *RichEdit2;
	TLabel *Label1;
	TLabel *Label2;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N21;
	TMenuItem *N5;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TActionList *ActionList1;
	TPopupMenu *PopupMenu1;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TEditSelectAll *EditSelectAll1;
	TEditUndo *EditUndo1;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TEditDelete *EditDelete1;
	TMenuItem *N33;
	TMenuItem *Delete1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TFindDialog *FindDialog1;
	TReplaceDialog *ReplaceDialog1;
	TMenuItem *N13;
	TMenuItem *N34;
	TMenuItem *N35;
	TMenuItem *N36;
	TMenuItem *N37;
	TSplitter *Splitter1;
	void __fastcall N21Click(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall RichEdit1SelectionChange(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall RichEdit2SelectionChange(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall FindDialog1Find(TObject *Sender);
	void __fastcall N34Click(TObject *Sender);
	void __fastcall ReplaceDialog1Find(TObject *Sender);
	void __fastcall ReplaceDialog1Replace(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N37Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N36Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TMNForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMNForm *MNForm;
//---------------------------------------------------------------------------
#endif
