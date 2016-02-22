#include "mesinstate.h"
#include <stdio.h>
boolean EndState;
State CState;
#include "tictactoe.h"
void IgnoreBlank()
/*Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC != BLANK atau CC= MARK*/
{
    //Kamus Lokal
    //Algoritma
    while (((CC==BLANK)||(CC==10))&&(CC!=MARK)){
        ADV();
        //if(CC==enter) ADV();
    }/*CC != BLANK or CC = MARK*/
}

void STARTSTATE()
/*I.S. : CC sembarang
  F.S. : EndState=true,dan CC= Mark;
    atau EndState = false, CState adalah kata yang sudah
    diakuisisi,
    CC karakter pertama sesudah karakter terakhir state */
{   
    //Kamus Lokal
    //Algoritma
    START();
    IgnoreBlank();
    if (CC==MARK) {
        EndState = true;
    } else /*CC!=MARK*/{
        EndState = false;
        SalinState();
    }

}

void ADVSTATE()
/*I.S. : CC adalah karakter pertama state yang akan diakuisisi
  F.S. : CState adalah state terakhir yang sudah diakuisisi,
         CC adalah karakter pertama dari state berikutnya,
         mungkin MARK
Proses : Akuisisi state menggunakan procedure SalinState*/
{
    //Kamus Lokal
    //Algoritma
    IgnoreBlank();
    if(CC == MARK){
        EndState=true;
    } else /*CC1= MARK*/{
        SalinState();
    }
}
void SalinState()
/*Mengakuisisi state, menyimpan dalam CState
I.S : CC adalah karakter pertama dari State
F.S : CState berisi state yang sudah diakuisisi;
      CC = BLANK atau CC= MARK;
      CC adalah karakter sesudah karakter terakhir yang diakuisisi*/
{
     //Kamus Lokal
     int i = 0; //inisialisasi
     //Algoritma
     for(;;) {
        CState.TabState[i]=CC;
        ADV();
        if ((CC==MARK)||(CC==BLANK)||(CC==10)) break;
        else i++;
     }
     CState.Length=i;
}
boolean IsStateSama (State K1, State K2)
/*  Mengembalikan  true  jika  K1  =  K2;  dua  state  dikatakan  sama  jika  panjangnya  sama  dan
        urutan  karakter  yang  menyusun  state  juga  sama  */
{
      int i=1;
      boolean x=true;
      while (i<=9 && x) {
          if (K1.TabState[i] != K2.TabState[i]) x=false;
          else i++;
      }
      if((K1.TabState[11] != K2.TabState[11])) x=false;

      return x;
}

void Transisi(State *GameState, int flag, int *output){
      int i;
      STARTSTATE();
      if(flag!=-99)
      rotatep(GameState,flag);
      while (!IsStateSama((*GameState),CState) && !EndState) {
          ADVSTATE();

      }
      if (IsStateSama((*GameState),CState)){
          (*output)= c2i(CState.TabState[13]) ;
          (*GameState).TabState[0]=CState.TabState[0];
      }
}
/*  Pemutusan akan kemana jalan CPU */
/*  I.S. : CC sembarang
    F.S. : output berisi indeks untuk jalan CPU selanjutnya yang optimal
        GameState dalam keadaan terotate, perlu di re-rotate  */

int c2i(char C) {
      return (C-'0');
}
/* Mengubah karakter menjadi integer  */

char i2c(int I){
    return (I+'0');
}
/*  Mengubah integer menjadi karakter */