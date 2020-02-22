//---------------------------------------------------------------------------

#include <vcl.h>
#include <process.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int amount_number = 20;
int a_array[500];
int time_sleep = 500;
int count = 0;
const int number_max = 999;
const int number_min = -999;
HANDLE hthread1, hthread2, hthread3;
unsigned long threadid1, threadid2, threadid3;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {
}
//---------------------------------------------------------------------------
void Thread1( void* pParams ) {
	int i;
	String localStr;

	Form1->Memo1->Lines->Clear();
	Form1->ProgressBar1->Position = 0;
	randomize();
	for (int i = 0; i < amount_number; i++ ) {
		count = i + 1;
		a_array[i] = random(2 * number_max) + number_min;
		if (count < 10) { localStr = "0"; } else { localStr = ""; }
		localStr += IntToStr(count)+". ";
		Form1->Memo1->Lines->Add(localStr+IntToStr(a_array[i]));
		Form1->ProgressBar1->Position = count*100/amount_number;
		Sleep(time_sleep);
		if (count == amount_number) {
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
	int i, value_min, value_max;
	int c = 0;
	String localStr;

	Form1->Memo2->Lines->Clear();
	while (1) {
		if (c < count) {
			c++;
			value_min = number_max;
			value_max = number_min;
			for (i = 0; i < c; i++) {
				if (a_array[i] >= value_max) value_max = a_array[i];
				if (a_array[i] <= value_min) value_min = a_array[i];
			}
			if (c < 10) { localStr = "0"; } else { localStr = ""; }
			localStr += IntToStr(c)+". ";
			Form1->Memo2->Lines->Add(localStr+"ћинимальное: "
			+IntToStr(value_min)+", максимальное: "+IntToStr(value_max));
		}
		if (c == amount_number) {
			_endthread();
			break;
		}
		Sleep(time_sleep);
	}
}
//---------------------------------------------------------------------------
void Thread3( void* pParams ) {
	int i, sum;
	int c = 0;
	String localStr;

	Form1->Memo3->Lines->Clear();
	while (1) {
		sum = 0;
		if (c < count) {
			c++;
			for (int i = 0; i < c; i++ ) {
				sum = sum + a_array[i];
			}
			if (c < 10) { localStr = "0"; } else { localStr = ""; }
			localStr += IntToStr(c)+". ";
			Form1->Memo3->Lines->Add(localStr+"ќклонение числа "
			+IntToStr(a_array[c-1])+" от среднего значени€ "+IntToStr(sum/c)
			+" составл€ет "+IntToStr(a_array[c-1] - sum/c));
		}
		if (c == amount_number) {
			_endthread();
			break;
		}
		Sleep(time_sleep);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrActionExecute(TObject *Sender) {
	if ((time_sleep = StrToInt(Form1->Edit1->Text))&&
	(amount_number = StrToInt(Form1->Edit2->Text))) {
		count = 0;
		hthread1 = (HANDLE)_beginthreadNT(Thread1, 4096, (void *)2, NULL, 0, &threadid1);
		hthread2 = (HANDLE)_beginthreadNT(Thread2, 4096, (void *)3, NULL, 0, &threadid2);
		hthread3 = (HANDLE)_beginthreadNT(Thread3, 4096, (void *)4, NULL, 0, &threadid3);
		Form1->PrAction->Enabled = False;
		Form1->PrStop->Enabled = True;
		Form1->Edit1->Enabled = False;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrStopExecute(TObject *Sender) {
	TerminateThread(hthread1, 0);
	TerminateThread(hthread2, 0);
	TerminateThread(hthread3, 0);
	Form1->PrStop->Enabled = False;
	Form1->PrAction->Enabled = True;
	Form1->Edit1->Enabled = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Form1->Edit1->Text = IntToStr(time_sleep);
	Form1->Edit2->Text = IntToStr(amount_number);
	Form1->PrStop->Enabled = False;
	Form1->PrAction->Enabled = True;
}
//---------------------------------------------------------------------------
