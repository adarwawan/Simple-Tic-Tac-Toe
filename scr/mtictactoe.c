#include "tictactoe.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mesinstate.h"
int main() {
    State Si;
	int play,player,mainlagi,HasilTransisi,inputrotasi;
	int flag;
	do {
		system("cls");
		printf("\n");
    	printf("\t\t========================================\n");
    	printf("\t\t         --====TIC TAC TOE====--        \n");
    	printf("\t\t========================================\n");
    	printf("\t\t --==1. Ahmad Darmawan  | 13513096 ==--\n");
    	printf("\t\t --==2. Fiqie Ulya      | 13514602 ==--\n");
    	printf("\t\t========================================\n");

    	printf("\n\n");

		printf("\t\t\t     [PILIH PLAYER]    \n");
		printf("\t\t\t========================\n");
		printf("\t\t\t| Player (x) -- CPU (o)|\n");
		printf("\t\t\t========================\n");
		printf("\t\t\t|1. Player 1           |\n\t\t\t|2. Player 2           |\n");
		printf("\t\t\t========================\n");
		do{
			printf("\n\t\t\t[PILIH] : ");scanf("%d",&player);
			if (!((player==1) || (player==2))) {
				printf("\n\t\t\t|Maaf inputan tidak valid|");
			}
			printf("\n\t\t\t======================\n");
    	} while (!((player==1) || (player==2))); // Validasi masukan urutan jalan player valid
    	
    	newgame(player, &Si); //Membentuk state awal
    	//jika player = 1, maka state awal ---------
    	//jika player = 2, maka state awal o--------
    	flag = -99;

    	system("cls");
		TulisTicTacToe(Si);
		do {
		//PLAYER JALAN dengan memasukan inputan 1..9
			do{
				printf("\t\t\t[INPUT] : "); scanf("%d",&play);
				if(!validasiinput(Si,play)) {
					printf("\n\t\t\t|Maaf inputan tidak valid|");
				}
				printf("\n\t\t\t======================\n");
			} while(!validasiinput(Si,play));
			//	Pengulangan hingga inputan dinyatakan valid
        	//	Jika inputan tervalidasi maka kita tentukan besar flag untuk merotate
			
			if((flag==-99)&&(player==2)){
            	if((Si.TabState[1]=='o')||(Si.TabState[5]=='o')||(Si.TabState[2]=='o')) flag=0;
            	else if((Si.TabState[3]=='o')||(Si.TabState[6]=='o')) flag=3;
            	else if((Si.TabState[9]=='o')||(Si.TabState[8]=='o')) flag=2;
            	else if((Si.TabState[7]=='o')||(Si.TabState[4]=='o')) flag=1;
			} // Penentuan berapa kali rotate dilakukan berdasarkan jalan pertama CPU
		
			if((flag==-99)&&(player==1)){
            	if((play==1)||(play==5)||(play==2)) flag=0;
            	else if((play==6)||(play==3)) flag=3;
            	else if((play==9)||(play==8)) flag=2;
            	else if((play==7)||(play==4)) flag=1;
			} // Penentuan berapa kali rotate dilakukan berdasarkan jalan pertama HUMAN

			inputrotasi=rotateInput(play,flag); // Konversi input ke yang sudah di rotate
        	Si.TabState[11]=i2c(inputrotasi); // Konversi input ke character
        	Transisi(&Si,flag,&HasilTransisi); // Melakukan rotate dan mencari jalan optimal CPU untuk jalan selanjutnya
        	Si.TabState[inputrotasi]='x'; // Memasukkan jalan dari HUMAN / PLAYER
			Si.TabState[HasilTransisi]='o'; // Memasukkan jalan dari CPU berdasarkan pencarian input optimal tadi
			backrotatep(&Si,flag); // Balikan Rotate ke posisi semula
			system("cls");
			TulisTicTacToe(Si);
		} while (Si.TabState[0] == '-');

        if (Si.TabState[0] =='d'){
        	printf("\n\t\t\t<[SELAMAT ANDA SERI!]>\n");
        } // Jika permainan seri
        if (Si.TabState[0] =='w'){
            printf("\n\t\t\t-=[MAAF ANDA KALAH]=-\n");
        } // Jika permainan dimenangkan CPU
        printf("\n\n\t\t\t[NEW GAME?] (1. ya, 0. tidak)");scanf("%d",&mainlagi); // Permintaan apakah mau main lagi.

	} while (mainlagi==1);

	return 0;
}