//---------------------------------------------------------------------------

#ifndef WarningFormH
#define WarningFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TWarnForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *AttentionLabel;
	TImage *WarningImage;
	TSpeedButton *YesButt;
	TSpeedButton *NoButt;
	TSpeedButton *DeclineButt;
	void __fastcall YesButtClick(TObject *Sender);
	void __fastcall DeclineButtClick(TObject *Sender);
	void __fastcall NoButtClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWarnForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWarnForm *WarnForm;
//---------------------------------------------------------------------------
#endif
