#ifndef TicTac_H
#define TicTac_H
#include "boolean.h"
#include <string.h>
#include "mesinstate.h"

void TulisTicTacToe (State S);
/*  I.S. S terdefinisi */
/*  F.S. State ditampilkan seperti matriks */

void newgame(int a, State *S);
/*  I.S. S sembarang, nilai a = 1 atau 2 */
/*  F.S. State S menjadi State awal permainan */

boolean validasiinput(State S, int x);
/*  Memvalidasi pada alamat x sudah terdaftar di state sebelumnya, bila terdaftar maka input tidak valid. */

State putar(State S);
/*  Fungsi memutar state 1x searah jarum jam    */

void rotatep(State *S,int flag);
/*  I.S. S sembarang    */
/*  F.S. Rotate sampai state terdefinisi di file eksternal   */

void backrotatep(State *S,int flag);
/*  I.S. S dalam keadaan terdefinisi di file eksternal  */
/*  F.S. Re-Rotate state terdefinisi ke bentuk semula   */

int rotateInput(int i, int flag);
/*  Rotate input agar sesuai dengan state   */
#endif
