//---------------------------------------------------------------------------

#include <vcl.h>
#include <process.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int nmass = 20;
int mass[1000];
int ntime = 1000;
int count = 0;
HANDLE hthread1, hthread2, hthread3;
unsigned long threadid1, threadid2, threadid3;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Thread1( void* pParams ) {
	int i;

	Form1->Memo1->Lines->Clear();
	count = 0;
	randomize();
	for (int i = 0; i < nmass; i++ ) {
		count = i + 1;
		mass[i] = random(2000)-1000;
		Form1->Memo1->Lines->Add(IntToStr(mass[i]));
		Form1->ProgressBar1->Position = count*100/nmass;
		Sleep(ntime);
		if (count == nmass) {
			break;
		}
	}
	Form1->PrStop->Enabled = False;
	Form1->PrAction->Enabled = True;
	Form1->Edit1->Enabled = True;
	_endthread();
}
//---------------------------------------------------------------------------
void Thread2( void* pParams ) {
	int i, max, min, ccount;

	ccount = 0;
	Form1->Memo2->Lines->Clear();
	while (1) {
		if (ccount < count) {
			ccount = count;
			min = 999;
			max = -999;
			for (i = 0; i < ccount; i++) {
				if (mass[i] >= max) max = mass[i];
				if (mass[i] <= min) min = mass[i];
			}
			Form1->Memo2->Lines->Add(IntToStr(min)+" / "+IntToStr(max));
		}
		if (ccount == nmass) {
			_endthread();
			break;
		}
		Sleep(ntime-50);
	}
}
//---------------------------------------------------------------------------
void Thread3( void* pParams ) {
	int ccount, sum, i;

	ccount = 0;
	Form1->Memo3->Lines->Clear();
	while (1) {
		sum = 0;
		if (ccount < count) {
			ccount = count;
			for (int i = 0; i < ccount; i++ ) {
				sum = sum + mass[i];
			}
			Form1->Memo3->Lines->Add(IntToStr(mass[ccount-1] - sum/ccount) +"("+IntToStr(sum/ccount)+")");
		}
		if (ccount == nmass) {
			_endthread();
			break;
		}
		Sleep(ntime-30);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrActionExecute(TObject *Sender)
{
	if ((ntime = StrToInt(Form1->Edit1->Text))&&(nmass = StrToInt(Form1->Edit2->Text))) {
		if (ntime < 100) {
			ntime = 100;
		}
		hthread1 = (HANDLE)_beginthreadNT(Thread1, 4096, (void *)2, NULL, 0, &threadid1);
		hthread2 = (HANDLE)_beginthreadNT(Thread2, 4096, (void *)3, NULL, 0, &threadid2);
		hthread3 = (HANDLE)_beginthreadNT(Thread3, 4096, (void *)4, NULL, 0, &threadid3);
		Form1->PrAction->Enabled = False;
		Form1->PrStop->Enabled = True;
		Form1->Edit1->Enabled = False;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrStopExecute(TObject *Sender)
{
	TerminateThread(hthread1, 0);
	TerminateThread(hthread2, 0);
	TerminateThread(hthread3, 0);
	Form1->PrStop->Enabled = False;
	Form1->PrAction->Enabled = True;
	Form1->Edit1->Enabled = True;
	Form1->Memo1->Lines->Clear();
	Form1->Memo2->Lines->Clear();
	Form1->Memo3->Lines->Clear();
	Form1->ProgressBar1->Position = 0;
	count = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Edit1->Text = IntToStr(ntime);
	Form1->Edit2->Text = IntToStr(nmass);
	Form1->Memo1->Lines->Clear();
	Form1->Memo2->Lines->Clear();
	Form1->Memo3->Lines->Clear();
	Form1->PrStop->Enabled = False;
	Form1->PrAction->Enabled = True;
}
//---------------------------------------------------------------------------
