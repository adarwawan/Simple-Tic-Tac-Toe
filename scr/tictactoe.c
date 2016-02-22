#include "tictactoe.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void TulisTicTacToe (State S) {
	printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t         --====TIC TAC TOE====--        \n");
    printf("\t\t========================================\n");
    printf("\t\t --==1. Ahmad Darmawan  | 13513096 ==--\n");
    printf("\t\t --==2. Fiqie Ulya      | 13514602 ==--\n");
    printf("\t\t========================================\n");
	printf("\t\t\t======================\n");
    printf("\t\t\t||    TIC TAC TOE   ||\n");
	printf("\t\t\t======================\n");
	printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t|   %c  |   %c  |   %c  |\n",S.TabState[1],S.TabState[2],S.TabState[3]);
	printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t======================\n");
	printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t|   %c  |   %c  |   %c  |\n",S.TabState[4],S.TabState[5],S.TabState[6]);
	printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t======================\n");
	printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t|   %c  |   %c  |   %c  |\n",S.TabState[7],S.TabState[8],S.TabState[9]);
    printf("\t\t\t|      |      |      |\n");
	printf("\t\t\t======================\n");
	printf("\t\t\t|o = CPU   x = PLAYER|\n");
	printf("\t\t\t======================\n");
}
/*  I.S. S terdefinisi */
/*  F.S. State ditampilkan seperti matriks */

void newgame(int a, State *S){
    int random=0;
    //  Inisialisasi State awal

    (*S).TabState[0]='-';
    (*S).TabState[1]='-';
    (*S).TabState[2]='-';
    (*S).TabState[3]='-';
    (*S).TabState[4]='-';
    (*S).TabState[5]='-';
    (*S).TabState[6]='-';
    (*S).TabState[7]='-';
    (*S).TabState[8]='-';
    (*S).TabState[9]='-';
    (*S).TabState[10]='|';
    (*S).TabState[11]='-';
    (*S).Length=12;

    // Masukan pertama CPU jika CPU mendapat giliran pertama
    if(a==2)
        while((random!=1)&&(random!=3)&&(random!=7)&&(random!=9)){
            random=rand()%10;
        }
        (*S).TabState[random]='o';
}
/*  I.S. S sembarang, nilai a = 1 atau 2 */
/*  F.S. State S menjadi State awal permainan */

boolean validasiinput(State S, int x){
    return (S.TabState[x])=='-';
}
/*  Memvalidasi pada alamat x sudah terdaftar di state sebelumnya, bila terdaftar maka input tidak valid. */

State putar(State S)
{
    State Sout;
    Sout.Length=S.Length;
    Sout.TabState[1]=S.TabState[7];
    Sout.TabState[2]=S.TabState[4];
    Sout.TabState[3]=S.TabState[1];
    Sout.TabState[4]=S.TabState[8];
    Sout.TabState[5]=S.TabState[5];
    Sout.TabState[6]=S.TabState[2];
    Sout.TabState[7]=S.TabState[9];
    Sout.TabState[8]=S.TabState[6];
    Sout.TabState[9]=S.TabState[3];
    Sout.TabState[10]=S.TabState[10];
    Sout.TabState[11]=S.TabState[11];
    Sout.TabState[0]=S.TabState[0];
    return(Sout);
}
/*  Fungsi memutar state 1x searah jarum jam    */

void rotatep(State *S,int flag)
{
    int i;
    for (i=1;i<=flag;i++)
    *S=putar(*S);
}
/*  I.S. S sembarang    */
/*  F.S. Rotate sampai state terdefinisi di file eksternal   */

void backrotatep(State *S,int flag)
{
    int i;
    for (i=1;i<=(4-flag);i++)
    *S=putar(*S);
}
/*  I.S. S dalam keadaan terdefinisi di file eksternal  */
/*  F.S. Re-Rotate state terdefinisi ke bentuk semula   */

int rotateInput(int i, int flag)
{
    int in;
    in = i;
    while(flag>0){
    if (in==7) in=1;
    else if (in==4) in=2;
    else if (in==1) in=3;
    else if (in==8) in=4;
    else if (in==5) in=5;
    else if (in==2) in=6;
    else if (in==9) in=7;
    else if (in==6) in=8;
    else if (in==3) in=9;
    flag--;
    }
    return in;
}
/*  Rotate input jalan HUMAN dan CPU agar sesuai dengan state   */