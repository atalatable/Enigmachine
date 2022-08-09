#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <windows.h>
#include    <conio.h>

#define     TAILLE_MAX  500

void gotoLigCol(int lig, int col);
void viderBuffer();
int lire(char *chaine, int longueur);
void printMenu();
void coder();
void decoder();