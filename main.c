#include "main.h"

int main(){
    char choice = '0';
    
    while(choice != '3'){
        printMenu();
        choice = getch();
        if(choice == '1'){
            coder();
        }
        else if(choice == '2'){
            decoder();
        }
    }

    return 0;
}

//fonction pour coder un message
void coder(){
    char motCle[TAILLE_MAX] = "\0";
    char chaine[TAILLE_MAX] = "\0";
    char chaineCodee[TAILLE_MAX] = "\0";
    int j = 0, i = 0;

    system("cls");
    printf("Saisissez le mot cle : ");
    lire(motCle, TAILLE_MAX);
    printf("Saisissez le message a coder (max %d) : ", TAILLE_MAX);
    lire(chaine, TAILLE_MAX);

    strcpy(chaineCodee, chaine);
    while(chaine[j] != '\0'){
        while(i < strlen(motCle)){
            if(chaine[j] == '\0'){break;}
            if(chaine[j] == ' '){chaineCodee[j] = ' ';}
            else{
                if(chaine[j] + motCle[i] - ('a' - 1) <= 'z'){
                    chaineCodee[j] = chaine[j] + motCle[i] - ('a' - 1);
                }
                else{
                    //cas ou la somme des lettres depasse le z, on refais du debut de lalphabet
                    chaineCodee[j] = chaine[j] + motCle[i] - ('a' - 1) - 26;
                }
            }
            i++;
            j++;
        }
        i = 0;
    }
    printf("\n\nLe message code est :\n%s\n\n", chaineCodee);
    //ce message permet un copie colle pour une transmission de messages plus rapide
    printf("Le message code pour la communication est :\n%s%s%d\n\n\n", motCle, chaineCodee, strlen(motCle));
    system("Pause");
}

//fonction pour decoder un messsage
void decoder(){
    char motCle[TAILLE_MAX] = "\0";
    char chaine[TAILLE_MAX] = "\0";
    char chaineDecodee[TAILLE_MAX] = "\0";
    char chaineInit[TAILLE_MAX] = "\0";
    char choice = '0';
    int j = 0, i = 0, chiffre = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    while(choice != '2' && choice != '1'){
        printf("Voulez vous utiliser la methode classique (1) ou boost (2) ?");
        choice = getch();
    }
    system("cls");
    if(choice == '1'){
        //on demande a lutilisateur separement le mot cle et la chaine
        system("cls");
        printf("Saisissez le mot cle : ");
        lire(motCle, TAILLE_MAX);
        printf("Saisissez le message a decoder (max %d) : ", TAILLE_MAX);
        lire(chaine, TAILLE_MAX);
    }
    else{
        //on utilise la forme donne quand on code (pour la communication)
        printf("Saisir le message formate :");
        SetConsoleTextAttribute(hConsole, 16*0+15);
        lire(chaineInit, 3 * TAILLE_MAX);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        //on se place à la fin du message, ou il ya les numeros qui indiquent la taille du mot cle
        while(chaineInit[i] < '1' || chaineInit[i] > '9'){i++;}
        //on met chiffre = taille du mot cle
        while(chaineInit[i] >= '0' && chaineInit[i] <= '9'){
            chiffre = chiffre*j + chaineInit[i] - 48;
            i++;
            j = 10;
        }
        j = 0;
        i = 0;
        //on supprime les chiffres de la chaine
        while(chaineInit[i] < '1' || chaineInit[i] > '9'){i++;}
        chaineInit[i] = '\0';
        for(i = 0; i < chiffre; i++){
            motCle[i] = chaineInit[i];
        }
        while(chaineInit[i] != '\0'){
            chaine[i-chiffre] = chaineInit[i];
            i++;
        }
    }

    strcpy(chaineDecodee, chaine);
    while(chaine[j] != '\0'){
        while(i < strlen(motCle)){
            if(chaine[j] == '\0'){break;}
            if(chaine[j] == ' '){chaineDecodee[j] = ' ';}
            else{
                if(chaine[j] - motCle[i] + ('a' - 1) >= 'a'){
                    chaineDecodee[j] = chaine[j] - motCle[i] + 'a'-1;
                }
                else{
                    //cas ou la somme des lettres depasse le z, on refais du debut de lalphabet
                    chaineDecodee[j] = chaine[j] - motCle[i] + 'a'-1 + 26;
                }
            }
            i++;
            j++;
        }
        i = 0;
    }
    printf("\n\nLe message decode est : ");
    SetConsoleTextAttribute(hConsole, 16*0+15);
    printf("%s\n\n\n", chaineDecodee);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    system("Pause");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

//affichage du menu
void printMenu(){
    system("Mode Con Cols=74 Lines=26");
    system("color 0A");
    system("cls");
    printf("             888b     d888 8888888888 888b    888 888     888\n");
    printf("             8888b   d8888 888        8888b   888 888     888\n");
    printf("             88888b.d88888 888        88888b  888 888     888\n");
    printf("             888Y88888P888 8888888    888Y88b 888 888     888\n");
    printf("             888 Y888P 888 888        888 Y88b888 888     888\n");
    printf("             888  Y8P  888 888        888  Y88888 888     888\n");
    printf("             888   \"   888 888        888   Y8888 Y88b. .d88P\n");
    printf("             888       888 8888888888 888    Y888  \"Y88888P\"\n");
    printf("==========================================================================\n");
    printf("\n");
    printf(" ___                       _\n");
    printf("|_  |     ___    ___ ___ _| |___ ___\n");
    printf(" _| |_   |___|  |  _| . | . | -_|  _|\n");
    printf("|_____|         |___|___|___|___|_| \n");
    printf("\n");
    printf(" ___               _               _ \n");
    printf("|_  |     ___    _| |___ ___ ___ _| |___ ___ \n");
    printf("|  _|    |___|  | . | -_|  _| . | . | -_|  _|\n");
    printf("|___|           |___|___|___|___|___|___|_| \n");
    printf("\n");
    printf(" ___                     _ _   _ \n");
    printf("|_  |     ___    ___ _ _|_| |_| |_ ___ ___\n");
    printf("|_  |    |___|  | . | | | |  _|  _| -_|  _|\n");
    printf("|___|           |_  |___|_|_| |_| |___|_|\n");
    printf("                  |_|                     \n");
}

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

//fonction de saisie securisee
//permet des espaces dans les strings
int lire(char *chaine, int longueur){
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{
            viderBuffer();
        }
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}

// Pour compiler : gcc main.c -o main