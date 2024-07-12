#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "validasi.c"

#define handle GetStdHandle(STD_OUTPUT_HANDLE)

//======================== PROTOTYPE ====================================

void bingkai_awal(int x, int y, int panjang, int lebar, int text, int bg);
void book();
void loading();
void welcome(int x,int y);
void menu();
void kotak_admin();
void menu_admin();
void recom_cerita();
void tambah_recom();
void baca_recom_admin();
void baca_recom_user();
void update_recom();
void delete_recom();
void admin_cerita();
void tambah_cerita();
void baca_cerita_admin();
void baca_cerita_user();
void user_awal();
void tambah_user();
void login();
void paket();
void menu_user();
void create_ulasan();
void baca_ulasan();
void about();


//======================== VARIABLE =====================================
int tekan = 1;
int esc;
int pilih;
char inpjudul[50];
char inppenulis[50];
char inpgenre[50];
char inpcerita1[2000];
char inpcerita2[2000];
char inpcerita3[2000];
char genre1[8][100] = {"Fiksi", "Misteri", "Triller", "Horor", "Fantasi", "Romantis", "Komedi", "Petualangan"};
char inpnama[50];
char inpnohp[50];
char inpusername[50];
char inppassword[50];
char inpumur[50];
char jdlbuku[100];
char karya[100];
char tamp_jdlbuku[100][100];
char tamp_karya[100][100];
int saldo;


void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(handle, coord); 
}

int text = 7, background = 0;
void textcolor(int new_color)
{
    SetConsoleTextAttribute(handle, new_color + background * 16);
    text = new_color;
}

void backgroundcolor(int new_color)
{
    SetConsoleTextAttribute(handle, text + new_color * 16);
    background = new_color;
}

void setcolor(int text, int background){
    SetConsoleTextAttribute(handle, background * 16 + text);
}

void bingkai_awal(int x, int y, int panjang, int lebar, int text, int bg)
{
    for (int i = 0; i <= panjang; i++)
    {
        
        for (int j = 0; j <= lebar; j++)
        {
            
            if (i == 0  || i == panjang || j == 0 || j == lebar)
            {
                gotoxy(x + i, y + j);
                textcolor(text);
                printf("%c", 219);
            }
            else
            {
                gotoxy(x + i, y + j);
                backgroundcolor(bg);
                printf(" ");
            }
        }
    }
}

void clearScreen()
{
    system("cls");
}

void book(int x, int y)
{
    bingkai_awal(0, 0, 165, 42, 12, 14);
    gotoxy(x, y);    printf("       .--.           .---.        .-.\n");
    gotoxy(x, y + 1);printf("   .---|--|   .-.     | A |  .---. |~|    .--.\n");
    gotoxy(x, y + 2);printf(".--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
    gotoxy(x, y + 3);printf("|%%%%|NT2|oc|===| |~~|%%%%| C |--|   |_|~|CATS|  |___|-.\n");
    gotoxy(x, y + 4);printf("|  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
    gotoxy(x, y + 5);printf("|  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
    gotoxy(x, y + 6);printf("|  |   |yu|   |_|__|  |   |__|   | | |    |  |___| |\n");
    gotoxy(x, y + 7);printf("|~~|===|--|===|~|~~|%%%%|~~~|--|:::|=|~|----|==|---|=|\n");
    gotoxy(x, y + 8);printf("^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");

    loading();

    gotoxy(75,40);
    printf("WAIT FOR A SECOND");
    Sleep(700);

    welcome(45,4);


}

void loading()
{
    textcolor(6);
    for (int a = 1, b = 1; a <= 100; a++)
    {
        gotoxy(80, 28);
        printf("Loading %d%%", a);
        Sleep(15);
        if (a % 2 == 0)
        {
            gotoxy(b + 60, 30);
            printf("%c", 219);
            Sleep(20);
            b++;
        }
    }

    
}

void welcome(int x, int y)
{
    bingkai_awal(0, 0, 165, 42, 12, 14);
    textcolor(1);
    for (int i = 0; i < 16; i++)
    {
        setcolor(i,14);
    
    gotoxy(x, y);    printf("                          %c%c%c%c                                           \n",219,219,219,219);Sleep(5);
    gotoxy(x, y + 1);printf("                            %c%c%c                                           \n",219,219,219);Sleep(5);
    gotoxy(x, y + 2);printf("  %c%c%c%c%c %c%c%c %c%c%c%c%c  %c%c%c%c%c%c   %c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 3);printf("   %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 4);printf("   %c%c%c  %c%c%c  %c%c%c  %c%c%c%c%c%c%c   %c%c%c  %c%c%c      %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 5);printf("    %c%c%c%c%c%c%c%c%c%c%c   %c%c%c       %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 6);printf("     %c%c%c%c %c%c%c%c     %c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c%c%c %c%c%c %c%c%c%c%c  %c%c%c%c%c%c\n\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    
    gotoxy(x, y + 9); printf("  %c%c%c%c%c                          %c%c%c%c%c                                %c%c \n",219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 10);printf("   %c%c%c                            %c%c%c                                %c%c%c   \n",219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 11);printf(" %c%c%c%c%c%c%c        %c%c%c%c%c%c        %c%c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c%c%c        %c%c%c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 12);printf("   %c%c%c        %c%c%c    %c%c%c    %c%c%c   %c%c%c  %c%c%c  %c%c%c      %c%c%c   %c%c%c  %c%c%c      %c%c%c    \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 13);printf("   %c%c%c        %c%c%c    %c%c%c    %c%c%c   %c%c%c  %c%c%c%c%c%c%c   %c%c%c%c%c%c%c   %c%c%c  %c%c%c       %c%c%c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 14);printf("   %c%c%c %c%c%c    %c%c%c    %c%c%c    %c%c%c   %c%c%c  %c%c%c      %c%c%c  %c%c%c   %c%c%c  %c%c%c          %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 15);printf("    %c%c%c%c%c       %c%c%c%c%c%c        %c%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c %c%c%c%c%c     %c%c%c%c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);

    gotoxy(x, y + 19); printf("                                   %c%c%c                     %c%c%c%c%c\n",219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 20);printf("                                                            %c%c%c \n",219,219,219);Sleep(5);
    gotoxy(x, y + 21);printf(" %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c   %c%c%c%c%c%c      %c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c%c%c%c%c  \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 22);printf("  %c%c%c  %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c      %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c   %c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 23);printf("  %c%c%c  %c%c%c  %c%c%c      %c%c%c  %c%c%c      %c%c%c  %c%c%c%c%c%c%c  %c%c%c        %c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 24);printf("  %c%c%c  %c%c%c  %c%c%c      %c%c%c  %c%c%c      %c%c%c  %c%c%c      %c%c%c  %c%c%c   %c%c%c %c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 25);printf("  %c%c%c%c%c%c%c  %c%c%c%c%c      %c%c%c%c%c%c       %c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c     %c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 26); printf("  %c%c%c                              %c%c%c                            \n",219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 27);printf("  %c%c%c                         %c%c%c  %c%c%c \n",219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(x, y + 28);printf(" %c%c%c%c%c                         %c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    }

    
    textcolor(12);
    char awal[100] = "PRESS ENTER TO CONTINUE!";

    gotoxy(70, 40);
    for (int d = 0; d < awal[d] != 0; d++)
    {
        printf("%c", awal[d]);
        Sleep(50);
    }


    int a = 0;
    do
    {
    char k;
    k=getch();
    if(k == 13){
        menu();
    } else
    {
        gotoxy(120,40);
        printf("INVALID!");
        Sleep(300);
        gotoxy(120,40);
        printf("          ");
        Sleep(300);
        gotoxy(120,40);
        printf("INVALID!");
        a++;
    }
    } while (a != 0);
                                                                                                             
}

void menu(){
    
    clearScreen();
    bingkai_awal(0, 0, 165, 42, 12, 14);

    textcolor(12);
    gotoxy(40,8); printf("%c%c%c%c%c                       %c%c%c%c%c                 %c%c%c%c%c               %c%c%c%c     %c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,9); printf("  %c%c%c                         %c%c%c                   %c%c%c                 %c%c%c    %c%c%c  %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,10); printf("  %c%c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c %c%c%c%c%c     %c%c%c%c%c   %c%c%c%c%c%c%c    %c%c%c%c%c%c   %c%c%c    %c%c%c    \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,11); printf("  %c%c%c  %c%c%c %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c  %c%c%c     %c%c%c      %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c  %c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,12);printf("  %c%c%c  %c%c%c %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c%c%c%c        %c%c%c%c%c   %c%c%c  %c%c%c  %c%c%c%c%c%c%c   %c%c%c    %c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,13);printf("  %c%c%c  %c%c%c %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c  %c%c%c         %c%c%c  %c%c%c  %c%c%c  %c%c%c       %c%c%c    %c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);
    gotoxy(40,14);printf(" %c%c%c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c%c %c%c%c%c%c    %c%c%c%c%c%c  %c%c%c%c %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);Sleep(5);

    bingkai_awal(20,27,20,5,4,11);
    bingkai_awal(58,27,20,5,12,11);
    bingkai_awal(92,27,20,5,12,11);
    bingkai_awal(125,27,20,5,12,11);
    gotoxy(27,29);
    printf("Admin");
    gotoxy(66,29);
    printf("User");
    gotoxy(100,29);
    printf("About");
    gotoxy(132,29);
    printf("Exit");


    while ((pilih = getch()) != 13)
    {
        if (pilih == 77)
        {
            if (tekan == 1)
            {
                tekan = 2;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,4,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
            } else if (tekan == 2){
                tekan = 3;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,4,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
            } else if (tekan == 3){
                tekan = 4;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,4,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
            } else if (tekan == 4)
            {
                tekan = 1;
                bingkai_awal(20,27,20,5,4,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
            }
            
        } else if (pilih == 75) {
            if (tekan == 4)
            {
                tekan = 3;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,4,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");              
                
            } else if (tekan == 3) {
                tekan = 2;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,4,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
        } else if (tekan == 2)
        {
                tekan = 1;
                bingkai_awal(20,27,20,5,4,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,12,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit"); 
        }else if (tekan == 1)
        {
                tekan = 4;
                bingkai_awal(20,27,20,5,12,11);
                bingkai_awal(58,27,20,5,12,11);
                bingkai_awal(92,27,20,5,12,11);
                bingkai_awal(125,27,20,5,4,11);
                gotoxy(27,29);
                printf("Admin");
                gotoxy(66,29);
                printf("User");
                gotoxy(100,29);
                printf("About");
                gotoxy(132,29);
                printf("Exit");
        }
        

        } 

        
    }
        if(tekan == 1){
            clearScreen();
            kotak_admin();
        } else if (tekan == 2)
        {
            clearScreen();
            user_awal();
        } else if (tekan == 3)
        {
            clearScreen();
            about();
        } else if (tekan == 4)
        {
            exit(0);
        }
        
        
    
}

void kotak_admin(){
    
    char codead[30] = "16122004";
    char code[30];
    int a = 1;

    bingkai_awal(0, 0, 165, 42, 12, 14);

    gotoxy(40,5); printf(".-. .-')               _ .-') _     ('-.          ('-.     _ .-') _  _   .-')                 .-') _ \n");Sleep(5);
    gotoxy(40,6); printf("\\  ( OO )             ( (  OO) )  _(  OO)        ( OO ).-.( (  OO) )( '.( OO )_              ( OO ) )\n");Sleep(5);
    gotoxy(40,7); printf(",--. ,--.  .-'),-----. \\     .'_ (,------.       / . --. / \\     .'_ ,--.   ,--.) ,-.-') ,--./ ,--,' \n");Sleep(5);
    gotoxy(40,8); printf("|  .'   / ( OO'  .-.  ',`'--..._) |  .---'       | \\-.  \\  ,`'--..._)|   `.'   |  |  |OO)|   \\ |  |\\ \n");Sleep(5);
    gotoxy(40,9); printf("|      /, /   |  | |  ||  |  \\  ' |  |         .-'-'  |  | |  |  \\  '|         |  |  |  \\|    \\|  | )\n");Sleep(5);
    gotoxy(40,10);printf("|     ' _)\\_) |  |\\|  ||  |   ' |(|  '--.       \\| |_.'  | |  |   ' ||  |'.'|  |  |  |(_/|  .     |/ \n");Sleep(5);
    gotoxy(40,11);printf("|  .   \\    \\ |  | |  ||  |   / : |  .--'        |  .-.  | |  |   / :|  |   |  | ,|  |_.'|  |\\    |  \n");Sleep(5);
    gotoxy(40,12);printf("|  |\\   \\    `'  '-'  '|  '--'  / |  `---.       |  | |  | |  '--'  /|  |   |  |(_|  |   |  | \\   |  \n");Sleep(5);
    gotoxy(40,13);printf("`--' '--'      `-----' `-------'  `------'       `--' `--' `-------' `--'   `--'  `--'   `--'  `--'  \n");Sleep(5);

    gotoxy(13,27);printf("      _ _\n");Sleep(5);
    gotoxy(13,28);printf(" .-. | | |\n");Sleep(5);
    gotoxy(13,29);printf(" |M|_|A|N|\n");Sleep(5);
    gotoxy(13,30);printf(" |A|a|.|.|<\\n");Sleep(5);
    gotoxy(13,31);printf(" |T|r| | | \\\n");Sleep(5);
    gotoxy(13,32);printf(" |H|t|M|Z|  \\   \n");Sleep(5);
    gotoxy(13,33);printf(" | |!| | |   \\>   \n");Sleep(5);
    gotoxy(13,34);printf("------------------\n");Sleep(5);


    gotoxy(135,27);printf("      _ _\n");Sleep(5);
    gotoxy(135,28);printf(" .-. | | |\n");Sleep(5);
    gotoxy(135,29);printf(" |M|_|A|N|\n");Sleep(5);
    gotoxy(135,30);printf(" |A|a|.|.|<\\n");Sleep(5);
    gotoxy(135,31);printf(" |T|r| | | \\\n");Sleep(5);
    gotoxy(135,32);printf(" |H|t|M|Z|  \\   \n");Sleep(5);
    gotoxy(135,33);printf(" | |!| | |   \\>   \n");Sleep(5);
    gotoxy(135,34);printf("-----------------\n");Sleep(5);
   

    bingkai_awal(58,20,50,5,12,14);

    int y = 0;
    while(1){
    gotoxy(63,23);
    printf("Masukkan kode admin : ");
    gotoxy(85,23);
    addpass(code);

    if (strcmp(code,codead) == 0)
    {
        y = 1;
        break;
    } else
    {

        gotoxy(85,23);
        printf("INVALID CODE!");
        Sleep(300);
        gotoxy(85,23);
        printf("               ");
        Sleep(300);
        gotoxy(85,23);
        printf("INVALID CODE!");
        Sleep(300);
        gotoxy(85,23);
        printf("               ");
    }
    y++;
    }

    if(y == 1){
        gotoxy(56,29);
        loading();
        menu_admin();
    }
    
}

void menu_admin(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(8, 4, 150, 34, 12, 11);

    textcolor(4);
    gotoxy(16,8); printf("     ______  _______        ______  _____   ______    ____   ____  \n");Sleep(10);
    gotoxy(16,9); printf("    |      \\/       \\   ___|\\     \\|\\    \\ |\\     \\  |    | |    | \n");Sleep(10);
    gotoxy(16,10);printf("   /          /\\     \\ |     \\     \\ \\    \\| \\     \\ |    | |    | \n");Sleep(10);
    gotoxy(16,11);printf("  /     /\\   / /\\     ||     ,_____/|\\|    \\  \\     ||    | |    | \n");Sleep(10);
    gotoxy(16,12);printf(" /     /\\ \\_/ / /    /||     \\--'\\_|/ |     \\  |    ||    | |    |");Sleep(10);
    gotoxy(16,13);printf("|     |  \\|_|/ /    / ||     /___/|   |      \\ |    ||    | |    | \n");Sleep(10);
    gotoxy(16,14);printf("|     |       |    |  ||     \\____|\\  |    |\\ \\|    ||    | |    | \n");Sleep(10);
    gotoxy(16,15);printf("| \\___\\       |____|  /|____ '     /| |____||\\_____/||\\___\\_|____| \n");Sleep(10);
    gotoxy(16,16);printf("| |    |      |    | / |    /_____/ | |    |/ \\|   ||| |    |    | \n");Sleep(10);
    gotoxy(16,17);printf(" \\|____|      |____|/  |____|     | / |____|   |___|/ \\|____|____| \n");Sleep(10);
    gotoxy(16,18);printf("    \\(          )/       \\( |_____|/    \\(       )/      \\(   )/   \n");Sleep(10);
    gotoxy(16,19);printf("     '          '         '    )/        '       '        '   '    \n");Sleep(10);

    textcolor(4);
    gotoxy(14,23);printf("      _____        _____        ______  _______    ____  _____   ______ \n");Sleep(10);
    gotoxy(14,24);printf("  ___|\\    \\   ___|\\    \\      |      \\/       \\  |    ||\\    \\ |\\     \\  \n");Sleep(10);
    gotoxy(14,25);printf(" /    /\\    \\ |    |\\    \\    /          /\\     \\ |    |  \\    \\| \\     \\ \n");Sleep(10);
    gotoxy(14,26);printf("|    |  |    ||    | |    |  /     /\\   / /\\     ||    |  \\|    \\  \\     |\n");Sleep(10);
    gotoxy(14,27);printf("|    |__|    ||    | |    | /     /\\ \\_/ / /    /||    |   |     \\  |    |");Sleep(10);
    gotoxy(14,28);printf("|    .--.    ||    | |    ||     |  \\|_|/ /    / ||    |   |      \\ |    |\n");Sleep(10);
    gotoxy(14,29);printf("|    |  |    ||    | |    ||     |       |    |  ||    |   |    |\\ \\|    |\n");Sleep(10);
    gotoxy(14,30);printf("|____|  |____||____|/____/||\\____\\       |____|  /|____|   |____||\\_____/|\n");Sleep(10);
    gotoxy(14,31);printf("|    |  |    ||    /    | || |    |      |    | / |    |   |    |/ \\|   ||\n");Sleep(10);
    gotoxy(14,32);printf("|____|  |____||____|____|/  \\|____|      |____|/  |____|   |____|   |___|/\n");Sleep(10);
    gotoxy(14,33);printf("  \\(      )/    \\(    )/       \\(          )/       \\(       \\(       )/  \n");Sleep(10);
    gotoxy(14,34);printf("   '      '      '    '         '          '         '        '       '   \n");Sleep(10);

    bingkai_awal(105,8,38,4,4,14);
    bingkai_awal(105,15,38,4,12,14);
    bingkai_awal(105,23,38,4,12,14);
    bingkai_awal(105,31,38,4,12,14);
    gotoxy(120,10);
    printf("REKOMENDASI");
    gotoxy(122,17);
    printf("CERITA");
    gotoxy(122,25);
    printf("ULASAN");
    gotoxy(120,33);
    printf("EXIT ADMIN");


    while ((pilih = getch()) != 13)
    {
        if (pilih == 80)
        {
            if (tekan == 1)
            {
                tekan = 2;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,4,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN");             
                
            } else if (tekan == 2){
                tekan = 3;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,4,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN"); 
            } else if (tekan == 3){
                tekan = 4;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,4,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN");  
            } else if (tekan == 4)
            {
                tekan = 1;
                bingkai_awal(105,8,38,4,4,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN"); 
            }
            
        } else if (pilih == 72) {
            if (tekan == 4)
            {
                tekan = 3;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,4,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN");                 
                
            } else if (tekan == 3) {
                tekan = 2;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,4,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN");   
        } else if (tekan == 2)
        {
                tekan = 1;
                bingkai_awal(105,8,38,4,4,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,12,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN");  
        } else if (tekan == 1)
        {
                tekan = 4;
                bingkai_awal(105,8,38,4,12,14);
                bingkai_awal(105,15,38,4,12,14);
                bingkai_awal(105,23,38,4,12,14);
                bingkai_awal(105,31,38,4,4,14);
                gotoxy(120,10);
                printf("REKOMENDASI");
                gotoxy(122,17);
                printf("CERITA");
                gotoxy(122,25);
                printf("ULASAN");
                gotoxy(120,33);
                printf("EXIT ADMIN"); 
        }
        

        } 
        
    }
        if(tekan == 1){
            clearScreen();
            recom_cerita();
        } else if (tekan == 2)
        {
            clearScreen();
            admin_cerita();
        } else if (tekan == 3)
        {
            clearScreen();
            baca_ulasan();
        } else if (tekan == 4)
        {
            clearScreen();
            menu();
        }
           
}

void recom_cerita(){
    int a;
    char pilih_ma[50];
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(88, 7, 54, 28, 12, 11);
    bingkai_awal(84, 11, 50, 26, 12, 14);

    


    textcolor(4);
    gotoxy(15, 20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247);
    gotoxy(15, 22);
    printf("                REKOMENDASI BUKU                 ");
    gotoxy(15, 24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247);
    textcolor(12);
    gotoxy(85, 14);
    printf("                [1]. TAMBAH REKOMENDASI          ");
    gotoxy(85, 16);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(85, 18);
    printf("                [2]. LIHAT REKOMENDASI           ");
    gotoxy(85, 20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(85, 22);
    printf("                [3]. EDIT REKOMENDASI            ");
    gotoxy(85, 24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(85, 26);
    printf("                [4]. HAPUS REKOMENDASI           ");
    gotoxy(85, 28);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    
    gotoxy(3,40);
    printf("TEKAN ESC UNTUK KEMBALI");
    
    gotoxy(86, 31);
    printf("Masukan pilihan : ");
    valPilihEmpat(pilih_ma);

    

    // while ((a = getch()) != 27)
    // {
    //     gotoxy(37,40);
    //     printf("");
    //     if(a == 27){
    //     menu_admin();
    //     }
    // }

    int pilih_recom;
    pilih_recom=atoi(pilih_ma);

   
    if (pilih_recom == 1)
    {
        tambah_recom();
    } else if(pilih_recom == 2){
        clearScreen();
        baca_recom_admin();
    } else if (pilih_recom == 3)
    {
        clearScreen();
        update_recom();
    } else if (pilih_recom == 4)
    {
        clearScreen();
        delete_recom();
    }

    
    
    
}

void tambah_recom(){
    char jdlbuku[100];
    char karya[100];
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(48, 14, 73, 18, 12, 11);
    bingkai_awal(55, 18, 58, 18, 12, 14);

    gotoxy(60, 23);
    printf("JUDUL BUKU\t: ");
    gotoxy(60, 24);
    printf("___________________________________________");
    gotoxy(60, 26);
    printf("KARYA\t: ");
    gotoxy(60, 27);
    printf("___________________________________________");

    gotoxy(75,23);
    addjudul(jdlbuku);
    gotoxy(75,26);
    addpenulis(karya);

    FILE *recom;
    recom = fopen("recom.txt","a");
    fprintf(recom, "%s#%s\n",jdlbuku,karya);
    fclose(recom);

    textcolor(2);
    gotoxy(75,30);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(75,30);
    printf("                       ");
    Sleep(300);
    gotoxy(75,30);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(75,30);
    printf("                       ");
    recom_cerita();

}

void baca_recom_admin(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(35,10,45,27,12,14);
    bingkai_awal(80,10,45,27,12,14);

    char jdlbuku[50][50];
    char karya[50][50];
    int a = 0;
    int pemisah = 0;

    gotoxy(36,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(50,13);
    printf("JUDUL");
    gotoxy(100,13);
    printf("KARYA");

    FILE *recom = fopen("recom.txt","r");
    while(fscanf(recom,"%[^#]#%[^\n]\n",jdlbuku[a],karya[a]) != EOF){
        gotoxy(50,18+pemisah);
        printf("%s\n",jdlbuku[a]);
        gotoxy(95,18+pemisah);
        printf("%s\n",karya[a]);
        a++;
        pemisah += 2;
    }
    fclose(recom);

    gotoxy(3,40);
    printf("TEKAN ESC UNTUK KEMBALI");

    int kosong = 0;
    do
    {
    char k;
    k=getch();
    if(k == 27){
        recom_cerita();
    } else
    {
        gotoxy(120,40);
        printf("INVALID!");
        Sleep(300);
        gotoxy(120,40);
        printf("          ");
        Sleep(300);
        gotoxy(120,40);
        printf("INVALID!");
        kosong++;
    }
    } while (kosong != 0);

        // esc=getch();
        // if(esc == 27){
        //     recom_cerita();
        // }

        
}

void update_recom(){
    system("cls");
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(35,12,45,8,12,14);
    bingkai_awal(75,12,45,8,12,14);

    int pilih,idx = -1,i = 0;

    gotoxy(42,16);
    printf("[ 1. ] Update Judul");
    gotoxy(82,16);
    printf("[ 2. ] Update Karya");
    gotoxy(70,24);
    printf("Pilih : "); scanf("%d",&pilih);
    
    if(pilih == 1){
        FILE* recom = fopen("recom.txt","r");
        gotoxy(60,27);
        printf("Cari judul sebelumnya : ");addjudul(jdlbuku);
        while(fscanf(recom,"%[^#]#%[^\n]\n",&tamp_jdlbuku[i],&tamp_karya[i]) != EOF){
            if(strcmp(jdlbuku,tamp_jdlbuku[i]) == 0){
                idx = i;
            }
            i++;
        }
        fclose(recom);
        if(idx != -1){
            printf("\n");
            gotoxy(60,30);
            printf("Input JUDUL BUKU : ");addjudul(jdlbuku);
            FILE* recom2 = fopen("recom.txt","w");
            for(int j = 0; j < i; j++){
                if(idx == j){
                    fprintf(recom2,"%s#%s\n",jdlbuku,tamp_karya[j]);
                }
                else{
                    fprintf(recom2,"%s#%s\n",tamp_jdlbuku[j],tamp_karya[j]);
                }
            }
            fclose(recom2);
            textcolor(2);
            Sleep(500);
            gotoxy(63,38);
            printf("Data Berhasil Di Update");
            Sleep(500);
            gotoxy(63,38);
            printf("                       ");
            Sleep(500);
            gotoxy(63,38);
            printf("Data Berhasil Di Update");
            Sleep(200);
            gotoxy(63,38);
            printf("                        ");
            Sleep(2000);
            recom_cerita();
        }
        else{
            textcolor(4);
            Sleep(500);
            gotoxy(63,38);
            printf("Data Tidak Ditemukan");
            Sleep(500);
            gotoxy(63,38);
            printf("                       ");
            Sleep(500);
            gotoxy(63,38);
            printf("Data Tidak Ditemukan");
            Sleep(200);
            gotoxy(63,38);
            printf("                        ");
            Sleep(2000);
            recom_cerita();
        }
    }
    else if(pilih == 2){
        FILE* recom = fopen("recom.txt","r");
        gotoxy(60,27);
        printf("Cari judul sebelumnya : ");addjudul(jdlbuku);
        while(fscanf(recom,"%[^#]#%[^\n]\n",&tamp_jdlbuku[i],&tamp_karya[i]) != EOF){
            if(strcmp(jdlbuku,tamp_jdlbuku[i]) == 0){
                idx = i;
            }
            i++;
        }
        fclose(recom);
        if(idx != -1){
            printf("\n");
            gotoxy(60,30);
            printf("Input KARYA : ");addpenulis(karya);
            FILE* recom2 = fopen("recom.txt","w");
            for(int j = 0; j < i; j++){
                if(idx == j){
                    fprintf(recom2,"%s#%s\n",tamp_jdlbuku[j],karya);
                }
                else{
                    fprintf(recom2,"%s#%s\n",tamp_jdlbuku[j],tamp_karya[j]);
                }
            }
            fclose(recom2);
            textcolor(2);
            Sleep(500);
            gotoxy(63,38);
            printf("Data Berhasil Di Update");
            Sleep(500);
            gotoxy(63,38);
            printf("                       ");
            Sleep(500);
            gotoxy(63,38);
            printf("Data Berhasil Di Update");
            Sleep(200);
            gotoxy(63,38);
            printf("                        ");
            Sleep(2000);
            recom_cerita();
        }
        else{
            textcolor(4);
            Sleep(500);
            gotoxy(63,38);
            printf("Data Tidak Ditemukan");
            Sleep(500);
            gotoxy(63,38);
            printf("                       ");
            Sleep(500);
            gotoxy(63,38);
            printf("Data Tidak Ditemukan");
            Sleep(200);
            gotoxy(63,38);
            printf("                        ");
            Sleep(2000);
            recom_cerita();
        }
    }

    else{
        update_recom();
    }
}


void delete_recom(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(45,24,70,10,12,11);
    bingkai_awal(50,20,60,9,12,14);
    char jdlbuku[100];
    char tamp_jdlbuku[100][100],tamp_karya[100][100];
    int idx = -1,i = 0;
    FILE* data = fopen("recom.txt","r");

    gotoxy(55,23);
    printf("Input Judul yang ingin di Hapus : ");addjudul(jdlbuku);
    while(fscanf(data,"%[^#]#%[^\n]\n",&tamp_jdlbuku[i],&tamp_karya[i]) != EOF){
        if(strcmp(jdlbuku,tamp_jdlbuku[i]) == 0){
            idx = i;
        }
        i++;
    }
    fclose(data);
    if(idx == -1){
        textcolor(4);
        gotoxy(69,26);
        printf("Data Tidak Ditemukan");
        Sleep(500);
        gotoxy(69,26);
        printf("                    ");
        Sleep(500);
        gotoxy(69,26);
        printf("Data Tidak Ditemukan");
        recom_cerita();
    }
    else{
        FILE* data2 = fopen("recom.txt","w");
        for(int j = 0; j < i; j++){
            if(idx != j){
                fprintf(data2,"%s#%s\n",tamp_jdlbuku[j],tamp_karya[j]);
            }
        }
        fclose(data2);
            textcolor(4);
            Sleep(500);
            gotoxy(69,26);
            printf("Data Berhasil di Hapus");
            Sleep(500);
            gotoxy(69,26);
            printf("                       ");
            Sleep(500);
            gotoxy(69,26);
            printf("Data Berhasil di Hapus");
            Sleep(2000);
            recom_cerita();
    }
}

void admin_cerita(){
    int a;
    char pilih_cerita[50];
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(88, 7, 54, 22, 12, 11);
    bingkai_awal(84, 11, 50, 21, 12, 14);

    textcolor(4);
    gotoxy(15, 20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247);
    gotoxy(15, 22);
    printf("                MENU CERITA                 ");
    gotoxy(15, 24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247);
    textcolor(12);
    gotoxy(85, 14);
    printf("                [1]. TAMBAH CERITA          ");
    gotoxy(85, 18);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(85, 20);
    printf("                [2]. LIHAT CERITA           ");
    gotoxy(85, 24);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(3,40);
    printf("TEKAN ESC UNTUK KEMBALI");
    gotoxy(86, 26);
    printf("Masukan pilihan : ");
    valPilihDua(pilih_cerita);

    int pilih_mc;
    pilih_mc=atoi(pilih_cerita);

    
    // a=getch();
    // if(a == 27){
    //     menu_admin();
    // }
    
    if (pilih_mc == 1)
    {
        clearScreen();
        tambah_cerita();
    } else if(pilih_mc == 2){
        clearScreen();
        baca_cerita_admin();
    }
    
}

void tambah_cerita(){
    int a = 0;
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(12,6,130,30,12,14);

    gotoxy(18,10);
    printf("JUDUL       : ");
    addjudul(inpjudul);
    gotoxy(18,12);
    printf("PENULIS     : ");
    addpenulis(inppenulis);
    
    for (int j = 0; j < 9; j++)
    {
    gotoxy(18,14);
    printf("GENRE       : ");
    addgenre(inpgenre);
    for (int i = 0; i < 9; i++)
    {
      if (strcmp(inpgenre, genre1[i]) == 0)
      {
        a++;
      }
    }
    if (a > 0)
    {
      break;
    }
    else
    {
      gotoxy(31, 14);
      printf("                         ");
    }
  }
    
    gotoxy(18,16);
    printf("CERITA      : ");
    addcerita(inpcerita1);
    gotoxy(32,18);
    addcerita(inpcerita2);
    gotoxy(32,20);
    addcerita(inpcerita3);

    FILE *bacaan;
    bacaan = fopen("bacaan.txt","a");
    fprintf(bacaan, "%s#%s#%s#%s#%s#%s\n",inpjudul,inppenulis,inpgenre,inpcerita1,inpcerita2,inpcerita3);
    fclose(bacaan);

    textcolor(2);
    gotoxy(50,30);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(50,30);
    printf("                       ");
    Sleep(300);
    gotoxy(50,30);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(50,30);
    printf("                       ");

    gotoxy(3,40);
        printf("TEKAN ESC UNTUK KEMBALI");
        esc=getch();
        if(esc == 27){
            menu_admin();
        }


}

void tabel_halaman_admin(int halamanad){
    char inpjudul[50][50];
    char inppenulis[50][50];
    char inpgenre[50][50];
    char inpcerita1[200][50];
    char inpcerita2[200][50];
    char inpcerita3[200][50];
    int a = 0;
    int pemisah = 0;

    FILE *bacaan = fopen("bacaan.txt","r");
    while(fscanf(bacaan,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",inpjudul[a],inppenulis[a],inpgenre[a],inpcerita1[a],inpcerita2[a],inpcerita3[a]) != EOF){
        if(halamanad == 1 && a < 3){
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;
        } else if (halamanad == 2 && a >= 3 && a < 6)
        {
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;
        } else if (halamanad == 3 && a >= 6 && a < 9)
        {
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;

        }        
        a++;
    }
    fclose(bacaan);
}


void baca_cerita_admin(){
   bingkai_awal(0, 0, 165, 42, 12, 14);

    int halaman = 1;
    char inp;
    tabel_halaman_admin(halaman);
    gotoxy(75,35);printf("< 1 / 3 >");
    gotoxy(5,40);
    printf("ESC untuk kembali");
    while((inp=getch()) != 13){
        if (inp == 27)
        {
            admin_cerita();
        }
        
        if( inp == 77 ){
            if(halaman == 1){
                halaman = 2;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 2 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 2){
                halaman = 3;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 3 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 3){
                halaman = 1;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 1 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }
        }else if( inp == 75){
            if(halaman == 1){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 3;
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 3 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 3){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 2;
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 2 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 2){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 1;
                tabel_halaman_admin(halaman);
                gotoxy(75,35);printf("< 1 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }
        }
    }

    
}



void user_awal(){
    char pilih[50];
    bingkai_awal(0, 0, 165, 42, 12, 14);

    bingkai_awal(40,18,25,6,12,14);
    gotoxy(47,21);
    printf("1. SIGN IN");

    bingkai_awal(95,18,25,6,12,14);
    gotoxy(102,21);
    printf("2. SIGN UP");

    gotoxy(55,10);
    printf("BELUM PUNYA AKUN? SILAKAN SIGN UP TERLEBIH DAHULU");

    gotoxy(65,35);
    printf("Masukkan Pilihan Anda : "); 
    valPilihDuaUser(pilih);

    int pilih_akun;
    pilih_akun=atoi(pilih);

    if(pilih_akun == 1){
        login();
    } else if (pilih_akun == 2)
    {
        tambah_user();
    } 

    

}

void tambah_user(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(7,6,50,25,12,14);

    textcolor(4);
    gotoxy(75,8); printf("             (`-')  (`-')  _(`-')  _ (`-')      (`-')  _  \n");Sleep(10);
    gotoxy(75,9); printf(" _        <-.(OO )  ( OO).-/(OO ).-/ ( OO).->   ( OO).-/  \n");Sleep(10);
    gotoxy(75,10);printf(" \\-,-----.,------,)(,------./ ,---.  /    '._  (,------. \n");Sleep(10);
    gotoxy(75,11);printf("  |  .--./|   /`. ' |  .---'| \\ /`.\\ |'--...__) |  .---' \n");Sleep(10);
    gotoxy(75,12);printf(" /_) (`-')|  |_.' |(|  '--. '-'|_.' |`--.  .--'(|  '--.  ");Sleep(10);
    gotoxy(75,13);printf(" ||  |OO )|  .   .' |  .--'(|  .-.  |   |  |    |  .--' \n");Sleep(10);
    gotoxy(75,14);printf("(_'  '--'\\|  |\\  \\  |  `---.|  | |  |   |  |    |  `---. \n");Sleep(10);
    gotoxy(75,15);printf("   `-----'`--' '--' `------'`--' `--'   `--'    `------' \n");Sleep(10);

    gotoxy(70,19);printf(" (`-')  _                                           <-. (`-')_ (`-')     \n");Sleep(10);
    gotoxy(70,20);printf(" (OO ).-/  _         _             .->        .->      \\( OO) )( OO).->  \n");Sleep(10);
    gotoxy(70,21);printf("/ ,---.   \\-,-----. \\-,-----.(`-')----. ,--.(,--.  ,--./ ,--/ /    '._  \n");Sleep(10);
    gotoxy(70,22);printf(" | \\ /`.\\   |  .--./  |  .--./( OO).-.  '|  | |(`-')|   \\ |  | |'--...__)\n");Sleep(10); 
    gotoxy(70,23);printf(" '-'|_.' | /_) (`-') /_) (`-')( _) | |  ||  | |(OO )|  . '|  |)`--.  .--'\n");Sleep(10); 
    gotoxy(70,24);printf("(|  .-.  | ||  |OO ) ||  |OO ) \\|  |)|  ||  | | |  \\|  |\\    |    |  |   \n");Sleep(10); 
    gotoxy(70,25);printf(" |  | |  |(_'  '--'\\(_'  '--'\\  '  '-'  '\\  '-'(_ .'|  | \\   |    |  |   \n");Sleep(10); 
    gotoxy(70,26);printf(" `--' `--'   `-----'   `-----'   `-----'  `-----'   `--'  `--'    `--' \n");Sleep(10);                                          

    gotoxy(10,10);
    printf("NAMA\t\t: ");
    gotoxy(10,11);
    printf("________________________________________");
    gotoxy(10,14);
    printf("UMUR\t\t: ");
    gotoxy(10,15);
    printf("________________________________________");
    gotoxy(10,18);
    printf("NO TELEPON\t: ");
    gotoxy(10,19);
    printf("________________________________________");
    gotoxy(10,22);
    printf("USERNAME\t: ");
    gotoxy(10,23);
    printf("________________________________________");
    gotoxy(10,26);
    printf("PASSWORD\t: ");
    gotoxy(10,27);
    printf("________________________________________");

    gotoxy(28,10);
    addnama(inpnama);
    gotoxy(28,14);
    valUmur(inpumur);
    gotoxy(28,18);
    addnotelp(inpnohp);
    gotoxy(28,22);
    addusername(inpusername);
    gotoxy(28,26);
    addpass(inppassword);

    FILE *reader;
    reader = fopen("reader.txt", "a");
    fprintf(reader, "%s#%d#%s#%s#%s\n",inpnama,inpumur,inpnohp,inpusername,inppassword);
    fclose(reader);

    textcolor(2);
    gotoxy(38,40);
    printf("Data berhasil disimpan");
    Sleep(250);
    gotoxy(38,40);
    printf("                       ");
    Sleep(250);
    gotoxy(38,40);
    printf("Data berhasil disimpan");
    Sleep(250);
    gotoxy(38,40);
    printf("                       ");

    paket();

}

void login(){
    int sama = 0;
    int index = 0;
    char inpusername[50];
    char inppassword[50];
    char tamp_user[50];
    char tamp_pass[50];
    char tamp_nama[50];
    char tamp_no[50];
    char tamp_umur[50];

    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(50,15,50,15,12,14);

    gotoxy(52,20);
    printf("USERNAME\t: ");
    gotoxy(52,21);
    printf("________________________________________");
    gotoxy(52,24);
    printf("PASSWORD\t: ");
    gotoxy(52,25);
    printf("________________________________________");

    gotoxy(67,20);
    addusername(inpusername);
    gotoxy(67,24);
    addpass(inppassword);

    FILE *reader;
    reader = fopen("reader.txt", "r");
    while(fscanf(reader, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", &tamp_nama,&tamp_umur,&tamp_no,&tamp_user,&tamp_pass) != EOF){

        if (strcmp(inpusername,tamp_user) == 0 && strcmp(inppassword,tamp_pass) == 0)
        {
            sama++;
            break;
        } else
        {
            gotoxy(60,36);
            printf("Username / Password Salah");
            Sleep(300);
            gotoxy(60,36);
            printf("                          ");
            Sleep(300);
            gotoxy(60,36);
            printf("Username / Password Salah");
            Sleep(300);
            gotoxy(60,36);
            printf("                          ");
            login();
        }
        }
        
        index++;
        getch();
    if(sama != 0){
        textcolor(2);
        Sleep(250);
        gotoxy(65,37);
        printf("Anda Berhasil Login");
        Sleep(250);
        gotoxy(65,37);
        printf("                    ");
        Sleep(250);
        gotoxy(65,37);
        printf("Anda Berhasil Login");
        Sleep(250);
        gotoxy(65,37);
        printf("                    ");
        menu_user();
    } 
    fclose(reader);
}

void paket(){
    char pkt[50];
    char byr[50];
    int tamp_bayar;
    int hrg;
    int a = 0;
    
    bingkai_awal(0, 0, 165, 42, 12, 14);
  
    bingkai_awal(14,18,25,12,12,14);
    gotoxy(26,21);
    printf("1");
    gotoxy(24,23);
    printf("HARI");
    gotoxy(15,25);
    textcolor(11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(22,28);
    textcolor(4);
    printf("RP. 3.000");
    bingkai_awal(42,18,25,12,12,14);
    gotoxy(55,21);
    printf("3");
    gotoxy(53,23);
    printf("HARI");
    gotoxy(43,25);
    textcolor(11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(50,28);
    textcolor(4);
    printf("RP. 5.000");
    bingkai_awal(70,18,25,12,12,14);
    gotoxy(83,21);
    printf("7");
    gotoxy(81,23);
    printf("HARI");
    gotoxy(71,25);
    textcolor(11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(79,28);
    textcolor(4);
    printf("RP. 10.000");
    bingkai_awal(98,18,25,12,12,14);
    gotoxy(111,21);
    printf("30");
    gotoxy(109,23);
    printf("HARI");
    gotoxy(99,25);
    textcolor(11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(107,28);
    textcolor(4);
    printf("RP. 20.000");
    bingkai_awal(126,18,25,12,12,14);
    gotoxy(139,21);
    printf("90"); 
    gotoxy(138,23);
    printf("HARI");
    gotoxy(127,25);
    textcolor(11);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(135,28);
    textcolor(4);
    printf("RP. 30.000");

    gotoxy(65,40);
    printf("PILIH PAKET : ");
    valPilihLima(pkt);

    int plh_pkt;
    plh_pkt=atoi(pkt);
    
    if (plh_pkt == 1)
    {
        hrg = 3000;
    } else if (plh_pkt == 2)
    {
        hrg = 5000;
    } else if (plh_pkt == 3)
    {
        hrg = 10000;
    } else if (plh_pkt == 4)
    {
        hrg = 20000;
    } else if (plh_pkt == 5)
    {
        hrg = 30000;
    } 

    clearScreen();
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(10,10,50,28,12,14);
    gotoxy(30, 15);
    printf("PEMBAYARAN");
    gotoxy(22,20);
    printf("Total Harga : Rp. %d", hrg);

    int y = 0;
    while(1){
    gotoxy(28,21);
    printf("Bayar : Rp. ");
    valuang(byr);
    tamp_bayar=atoi(byr);
    
    FILE *uang1 = fopen("uang.txt","r");
    while(fscanf(uang1,"%d\n", &saldo) != EOF){
        saldo += tamp_bayar;
    }
    fclose(uang1);

    FILE *inpUang =  fopen("uang.txt","w");
    fprintf(inpUang, "%d",saldo);
    fclose(inpUang);
    if (hrg == tamp_bayar)
    {
        y = 1;
        break;
    } else if (hrg != tamp_bayar)
    {
        textcolor(4);
        gotoxy(40,21);
        printf("Masukkan uang pas!");
        Sleep(250);
        gotoxy(40,21);
        printf("                  ");
        gotoxy(40,21);
        printf("Masukkan uang pas!");
        Sleep(250);
        gotoxy(40,21);
        printf("                  ");
    }
        y++;
    }
    

    if (y == 1)
    {
        
        int pb;
        char mb[50];
        gotoxy(22,24);
        printf("Pilih Metode Pembayaran : ");
        gotoxy(28,26);
        printf("1. DANA");
        gotoxy(28,27);
        printf("2. OVO");
        gotoxy(28,28);
        printf("3. SHOPEEPAY");
        gotoxy(28,29);
        printf("4. GOPAY");
        gotoxy(27,33);
        printf("pilih : ");scanf("%d",&pb);
        if (pb == 1)
        {
            strcpy(mb,"DANA");

        } else if (pb == 2)
        {
            strcpy(mb,"OVO");
        } else if (pb == 3)
        {
            strcpy(mb,"SHOPEEPAY");
        } else if (pb == 4)
        {
            strcpy(mb,"GOPAY");
        }

        
        bingkai_awal(100,10,50,28,12,14);
        gotoxy(120,14);
        printf("BOOK SHELF");
        gotoxy(110,18);
        printf("Pembelian Paket Premium");
        gotoxy(110,20);
        printf("Seharga %d", hrg);
        gotoxy(110,22);
        printf("Menggunakan metode pembayaran %s",mb);

        gotoxy(112,24);
        printf("Sedang di proses ..");
        Sleep(1000);
        gotoxy(131,24);
        printf(".");
        Sleep(1000);
        gotoxy(132,24);
        printf(".");
        Sleep(1000);
        gotoxy(133,24);
        printf(".");
        menu_user();
    }

    


    
    
}


void menu_user(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(8, 4, 49, 34, 12, 11);

    setcolor(4,14);
    gotoxy(77,8); printf("     ______  _______        ______  _____   ______    ____   ____  \n");Sleep(10);
    gotoxy(77,9); printf("    |      \\/       \\   ___|\\     \\|\\    \\ |\\     \\  |    | |    | \n");Sleep(10);
    gotoxy(77,10);printf("   /          /\\     \\ |     \\     \\ \\    \\| \\     \\ |    | |    | \n");Sleep(10);
    gotoxy(77,11);printf("  /     /\\   / /\\     ||     ,_____/|\\|    \\  \\     ||    | |    | \n");Sleep(10);
    gotoxy(77,12);printf(" /     /\\ \\_/ / /    /||     \\--'\\_|/ |     \\  |    ||    | |    |");Sleep(10);
    gotoxy(77,13);printf("|     |  \\|_|/ /    / ||     /___/|   |      \\ |    ||    | |    | \n");Sleep(10);
    gotoxy(77,14);printf("|     |       |    |  ||     \\____|\\  |    |\\ \\|    ||    | |    | \n");Sleep(10);
    gotoxy(77,15);printf("| \\___\\       |____|  /|____ '     /| |____||\\_____/||\\___\\_|____| \n");Sleep(10);
    gotoxy(77,16);printf("| |    |      |    | / |    /_____/ | |    |/ \\|   ||| |    |    | \n");Sleep(10);
    gotoxy(77,17);printf(" \\|____|      |____|/  |____|     | / |____|   |___|/ \\|____|____| \n");Sleep(10);
    gotoxy(77,18);printf("    \\(          )/       \\( |_____|/    \\(       )/      \\(   )/   \n");Sleep(10);
    gotoxy(77,19);printf("     '          '         '    )/        '       '        '   '    \n");Sleep(10);

    setcolor(4,14);
    gotoxy(82,24);printf(" ____   ____          ______       ______        _____\n");Sleep(10);
    gotoxy(82,25);printf("|    | |    |     ___|\\     \\  ___|\\     \\   ___|\\    \\   \n");Sleep(10);
    gotoxy(82,26);printf("|    | |    |    |    |\\     \\|     \\     \\ |    |\\    \\ \n");Sleep(10);
    gotoxy(82,27);printf("|    | |    |    |    |/____/||     ,_____/||    | |    |\n");Sleep(10);
    gotoxy(82,28);printf("|    | |    | ___|    \\|   | ||     \\--'\\_|/|    |/____/");Sleep(10);
    gotoxy(82,29);printf("|    | |    ||    \\    \\___|/ |     /___/|  |    |\\    \\ \n");Sleep(10);
    gotoxy(82,30);printf("|    | |    ||    |\\     \\    |     \\____|\\ |    | |    |\n");Sleep(10);
    gotoxy(82,31);printf("|\\___\\_|____||\\ ___\\|_____|   |____ '     /||____| |____|\n");Sleep(10);
    gotoxy(82,32);printf("| |    |    || |    |     |   |    /_____/ ||    | |    |\n");Sleep(10);
    gotoxy(82,33);printf(" \\|____|____| \\|____|_____|   |____|     | /|____| |____|\n");Sleep(10);
    gotoxy(82,34);printf("    \\(   )/      \\(    )/       \\( |_____|/   \\(     )/   \n");Sleep(10);
    gotoxy(82,35);printf("     '   '        '    '         '    )/       '     ' \n");Sleep(10);
                  

    bingkai_awal(12,8,38,4,4,14);
    bingkai_awal(12,15,38,4,12,14);
    bingkai_awal(12,23,38,4,12,14);
    bingkai_awal(12,31,38,4,12,14);
    gotoxy(23,10);
    printf("BACA REKOMENDASI");
    gotoxy(27,17);
    printf("BACA CERITA");
    gotoxy(27,25);
    printf("BUAT ULASAN");
    gotoxy(28,33);
    printf("LOGOUT");

    while ((pilih = getch()) != 13)
    {
        if (pilih == 80)
        {
            if (tekan == 1)
            {
                tekan = 2;
                    bingkai_awal(12,8,38,4,12,14);
                    bingkai_awal(12,15,38,4,4,14);
                    bingkai_awal(12,23,38,4,12,14);
                    bingkai_awal(12,31,38,4,12,14);
                    gotoxy(23,10);
                    printf("BACA REKOMENDASI");
                    gotoxy(27,17);
                    printf("BACA CERITA");
                    gotoxy(27,25);
                    printf("BUAT ULASAN");
                    gotoxy(28,33);
                    printf("LOGOUT");            
                
            } else if (tekan == 2){
                    tekan = 3;
                    bingkai_awal(12,8,38,4,12,14);
                    bingkai_awal(12,15,38,4,12,14);
                    bingkai_awal(12,23,38,4,4,14);
                    bingkai_awal(12,31,38,4,12,14);
                    gotoxy(23,10);
                    printf("BACA REKOMENDASI");
                    gotoxy(27,17);
                    printf("BACA CERITA");
                    gotoxy(27,25);
                    printf("BUAT ULASAN");
                    gotoxy(28,33);
                    printf("LOGOUT"); 
            } else if (tekan == 3){
                    tekan = 4;
                    bingkai_awal(12,8,38,4,12,14);
                    bingkai_awal(12,15,38,4,12,14);
                    bingkai_awal(12,23,38,4,12,14);
                    bingkai_awal(12,31,38,4,4,14);
                    gotoxy(23,10);
                    printf("BACA REKOMENDASI");
                    gotoxy(27,17);
                    printf("BACA CERITA");
                    gotoxy(27,25);
                    printf("BUAT ULASAN");
                    gotoxy(28,33);
                    printf("LOGOUT");  
            } else if (tekan == 4)
            {
                    tekan = 1;
                    bingkai_awal(12,8,38,4,4,14);
                    bingkai_awal(12,15,38,4,12,14);
                    bingkai_awal(12,23,38,4,12,14);
                    bingkai_awal(12,31,38,4,12,14);
                    gotoxy(23,10);
                    printf("BACA REKOMENDASI");
                    gotoxy(27,17);
                    printf("BACA CERITA");
                    gotoxy(27,25);
                    printf("BUAT ULASAN");
                    gotoxy(28,33);
                    printf("LOGOUT"); 
            }
            
        } else if (pilih == 72) {
            if (tekan == 4)
            {
                tekan = 3;
                bingkai_awal(12,8,38,4,12,14);
                bingkai_awal(12,15,38,4,12,14);
                bingkai_awal(12,23,38,4,4,14);
                bingkai_awal(12,31,38,4,12,14);
                gotoxy(23,10);
                printf("BACA REKOMENDASI");
                gotoxy(27,17);
                printf("BACA CERITA");
                gotoxy(27,25);
                printf("BUAT ULASAN");
                gotoxy(28,33);
                printf("LOGOUT");                  
                
            } else if (tekan == 3) {
                tekan = 2;
                bingkai_awal(12,8,38,4,12,14);
                bingkai_awal(12,15,38,4,4,14);
                bingkai_awal(12,23,38,4,12,14);
                bingkai_awal(12,31,38,4,12,14);
                gotoxy(23,10);
                printf("BACA REKOMENDASI");
                gotoxy(27,17);
                printf("BACA CERITA");
                gotoxy(27,25);
                printf("BUAT ULASAN");
                gotoxy(28,33);
                printf("LOGOUT");  
        } else if (tekan == 2)
        {
                tekan = 1;
                bingkai_awal(12,8,38,4,4,14);
                bingkai_awal(12,15,38,4,12,14);
                bingkai_awal(12,23,38,4,12,14);
                bingkai_awal(12,31,38,4,12,14);
                gotoxy(23,10);
                printf("BACA REKOMENDASI");
                gotoxy(27,17);
                printf("BACA CERITA");
                gotoxy(27,25);
                printf("BUAT ULASAN");
                gotoxy(28,33);
                printf("LOGOUT"); 
        } else if (tekan == 1)
        {
                tekan = 4;
                bingkai_awal(12,8,38,4,12,14);
                bingkai_awal(12,15,38,4,12,14);
                bingkai_awal(12,23,38,4,12,14);
                bingkai_awal(12,31,38,4,4,14);
                gotoxy(23,10);
                printf("BACA REKOMENDASI");
                gotoxy(27,17);
                printf("BACA CERITA");
                gotoxy(27,25);
                printf("BUAT ULASAN");
                gotoxy(28,33);
                printf("LOGOUT"); 
        }
        

        }         
    }

    if(tekan == 1){
            clearScreen();
            baca_recom_user();
        } else if (tekan == 2)
        {
            clearScreen();
            baca_cerita_user();
        } else if (tekan == 3)
        {
            clearScreen();
            create_ulasan();
        } else if (tekan == 4)
        {
            menu();
        }
        
        

}

void baca_recom_user(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(35,10,45,27,12,14);
    bingkai_awal(80,10,45,27,12,14);

    char jdlbuku[50][50];
    char karya[50][50];
    int a = 0;
    int pemisah = 0;

    gotoxy(36,15);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoxy(50,13);
    printf("JUDUL");
    gotoxy(100,13);
    printf("KARYA");

    FILE *recom = fopen("recom.txt","r");
    while(fscanf(recom,"%[^#]#%[^\n]\n",jdlbuku[a],karya[a]) != EOF){
        gotoxy(50,18+pemisah);
        printf("%s\n",jdlbuku[a]);
        gotoxy(95,18+pemisah);
        printf("%s\n",karya[a]);
        // printf("\t%s\t\t%s\n\n",jdlbuku[a],karya[a]);
        a++;
        pemisah += 2;
    }
    fclose(recom);

    gotoxy(3,40);
        printf("TEKAN ESC UNTUK KEMBALI");
        esc=getch();
        if(esc == 27){
            menu_user();
        }
}

void tabel_halaman(int halaman){
    char inpjudul[50][50];
    char inppenulis[50][50];
    char inpgenre[50][50];
    char inpcerita1[200][50];
    char inpcerita2[200][50];
    char inpcerita3[200][50];
    int a = 0;
    int pemisah = 0;

    FILE *bacaan = fopen("bacaan.txt","r");
    while(fscanf(bacaan,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",inpjudul[a],inppenulis[a],inpgenre[a],inpcerita1[a],inpcerita2[a],inpcerita3[a]) != EOF){
        if(halaman == 1 && a < 3){
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;
        } else if (halaman == 2 && a >= 3 && a < 6)
        {
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;
        } else if (halaman == 3 && a >= 6 && a < 9)
        {
            gotoxy(73,6+pemisah);
            printf("%s\n",inpjudul[a]);
            gotoxy(71,7+pemisah);
            printf("%s\n",inppenulis[a]);
            gotoxy(73,8+pemisah);
            printf("%s\n",inpgenre[a]);
            gotoxy(30,10+pemisah);
            printf("%s\n",inpcerita1[a]);
            gotoxy(30,11+pemisah);
            printf("%s\n",inpcerita2[a]);
            gotoxy(30,12+pemisah);
            printf("%s\n",inpcerita3[a]);
            pemisah += 10;

        }        
        a++;
    }
    fclose(bacaan);
}


void baca_cerita_user(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    int halaman = 1;
    char inp;
    tabel_halaman(halaman);
    gotoxy(75,35);printf("< 1 / 3 >");
    gotoxy(5,40);
    printf("ESC untuk kembali");
    while((inp=getch()) != 13){
        if(inp == 27){
            menu_user();
        }
        if( inp == 77 ){
            if(halaman == 1){
                halaman = 2;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 2 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 2){
                halaman = 3;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 3 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 3){
                halaman = 1;
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 1 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }
        }else if( inp == 75){
            if(halaman == 1){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 3;
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 3 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 3){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 2;
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 2 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }else if(halaman == 2){
                system("cls");
                bingkai_awal(0, 0, 165, 42, 12, 14);
                halaman = 1;
                tabel_halaman(halaman);
                gotoxy(75,35);printf("< 1 / 3 >");
                gotoxy(5,40);
                printf("ESC untuk kembali");
            }
        } else if(inp == 27){
            menu();
        }
    }
}


void create_ulasan(){
    char ulas1[255];
    char ulas2[200];
    bingkai_awal(0, 0, 165, 42, 12, 14);
    bingkai_awal(25,20,120,10,12,11);
    bingkai_awal(30,23,110,8,12,14);

    gotoxy(75,9);
    printf("SILAKAN BERIKAN ULASAN ANDA");
    gotoxy(35,25);
    printf("=> ");addcerita(ulas1);
    gotoxy(38,27);addcerita(ulas2);

    FILE *ulasan;
    ulasan = fopen("ulasan.txt","a");
    fprintf(ulasan, "%s#%s\n",ulas1,ulas2);
    fclose(ulasan);

    textcolor(2);
    gotoxy(88,40);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(88,40);
    printf("                       ");
    Sleep(300);
    gotoxy(88,40);
    printf("Data berhasil disimpan");
    Sleep(300);
    gotoxy(88,40);
    printf("                       ");

    gotoxy(3,40);
        printf("TEKAN ESC UNTUK KEMBALI");
        esc=getch();
        if(esc == 27){
            menu_user();
        }
}

void baca_ulasan(){
    bingkai_awal(0, 0, 165, 42, 12, 14);
    char ulas1[50][80];
    char ulas2[50][80];
    int a = 0;
    int pemisah = 0;

    FILE *ulasan = fopen("ulasan.txt","r");
    while(fscanf(ulasan,"%[^#]#%[^\n]\n",ulas1[a],ulas2[a]) != EOF){
        gotoxy(25,10+pemisah);
        printf("%s\n",ulas1[a]);
        gotoxy(25,11+pemisah);
        printf("%s\n",ulas2[a]);
        a++;
        pemisah+=4;
    }
    fclose(ulasan);

    gotoxy(3,40);
        printf("TEKAN ESC UNTUK KEMBALI");
        esc=getch();
        if(esc == 27){
            menu_admin();
        }
}

void about(){
    int q;
    bingkai_awal(0, 0, 165, 42, 12, 14);

    setcolor(4,14);
    gotoxy(50,5); printf("   ('-.    .-. .-')                            .-') _   \n");Sleep(100);
    gotoxy(50,6); printf("  ( OO ).-.\\  ( OO )                          (  OO) )  \n");Sleep(100);
    gotoxy(50,7);printf("  / . --. / ;-----.\\  .-'),-----.  ,--. ,--.  /     '._ \n");Sleep(100);
    gotoxy(50,8);printf("  | \\-.  \\  | .-.  | ( OO'  .-.  ' |  | |  |  |'--...__)\n");Sleep(100);
    gotoxy(50,9);printf(".-'-'  |  | | '-' /_)/   |  | |  | |  | | .-')'--.  .--'");Sleep(100);
    gotoxy(50,10);printf(" \\| |_.'  | | .-. `. \\_) |  |\\|  | |  |_|( OO )  |  |   \n");Sleep(100);
    gotoxy(50,11);printf("  |  .-.  | | |  \\  |  \\ |  | |  | |  | | `-' /  |  | \n");Sleep(100);
    gotoxy(50,12);printf("  |  | |  | | '--'  /   `'  '-'  '('  '-'(_.-'   |  |  \n");Sleep(100);
    gotoxy(50,13);printf("  `--' `--' `------'      `-----'   `-----'      `--'\n");Sleep(100);

    textcolor(12);
    char tentang[200] = "\tTentang Book Shelf. Selamat datang! Book Shelf ini adalah program sederhana yang terdapat Admin dan User.";
    char tentang2[200] = "Dimana Admin dapat menambah dan mengedit rekomendasi dan juga cerita. Admin juga dapat membaca ulasan yang di buat oleh User.";
    char tentang3[200] = "Kemudian ada User, didalam nya ada fitur sign in dan sign up. User dapat membaca rekomendasi dan cerita yang tersedia didalam";
    char tentang4[200] = "halaman user, User juga dapat memberikan ulasan yang nantinya dikirim ke admin. Dan yang terakhir adalah about, yaitu fitur ";
    char tentang5[200] = "yang menampilkan beberapa informasi tentang progam yang sedang dijalankan ini. SELAMAT MENGGUNAKAN!!";

    for (int d = 0; d < strlen(tentang); d++)
    {
        Sleep(25);
        gotoxy(25 + d, 20);
        printf("%c", tentang[d]);
    }
    Sleep(500);
    gotoxy(20,22);
    printf("%s",tentang2);
    Sleep(500);
    gotoxy(20,24);
    printf("%s",tentang3);
    Sleep(500);
    gotoxy(20,26);
    printf("%s",tentang4);
    Sleep(500);
    gotoxy(20,28);
    printf("%s",tentang5);


    gotoxy(3,40);
    printf("TEKAN ESC UNTUK KEMBALI");
    

    int a = 0;
    do
    {
    char k;
    k=getch();
    if(k == 13){
        menu();
    } else
    {
        gotoxy(120,40);
        printf("INVALID!");
        Sleep(300);
        gotoxy(120,40);
        printf("          ");
        Sleep(300);
        gotoxy(120,40);
        printf("INVALID!");
        a++;
    }
    } while (a != 0);
    

}

// void main(){
//     book();
//     // about();
//     //admin_cerita();
//     //user_awal();
// }
