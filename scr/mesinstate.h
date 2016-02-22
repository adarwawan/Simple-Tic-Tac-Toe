#ifndef MESINSTATE_H_INCLUDED
#define MESINSTATE_H_INCLUDED

#include "boolean.h"
#include "mesinkar.h"
#define enter '\n'
#define NMax 50
#define BLANK ' '

typedef struct{
    char TabState[NMax+1];
    int Length;
}State;

/*State Mesin State*/
extern boolean EndState;
extern State CState;

void IgnoreBlank();
/*Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang
    F.S. : CC != BLANK atau CC= MARK*/
void STARTSTATE();
/*I.S. : CC sembarang
  F.S. : EndState=true,dan CC= Mark;
    atau EndState = false, CState adalah State yang sudah
    diakuisisi,
    CC karakter pertama sesudah karakter terakhir State*/
void ADVSTATE();
/*I.S. : CC adalah karakter pertama state yang akan diakuisisi
  F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
         CC adalah karakter pertama dari state berikutnya,
         mungkin MARK
Proses : Akuisisi state menggunakan procedure SalinState*/
void SalinState();
/*Mengakuisisi state, menyimpan dalam CState
I.S : CC adalah karakter pertama dari state
F.S : CState berisi state yang sudah diakuisisi;
      CC = BLANK atau CC= MARK;
      CC adalah karakter sesudah karakter terakhir yang diakuisisi*/
boolean IsStateSama  (State K1, State  K2 );
/*  Mengembalikan  true  jika  K1  =  K2;  dua  state  dikatakan  sama  jika  panjangnya  sama  dan
        urutan  karakter  yang  menyusun  state  juga  sama  */
void Transisi(State *GameState, int flag, int *output);
/*  Pemutusan jalan CPU */
/*  I.S. : CC sembarang
    F.S. : output berisi indeks untuk jalan CPU selanjutnya yang optimal
        GameState dalam keadaan terotate, perlu di re-rotate  */        
int c2i(char C);
/* Mengubah karakter menjadi integer  */
char i2c(int I);
/*  Mengubah integer menjadi karakter */
#endif