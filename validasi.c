#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#define handle GetStdHandle(STD_OUTPUT_HANDLE)

char *addnama(char *nama);
char *addpass(char *pass);
char *addusername(char *user);
char *addjudul(char *judul);
char *addpenulis(char *penulis);
char *addgenre(char *genre);
char *addcerita(char *cerita);
char *addnotelp(char *telp);
void menu_admin();

void posisi(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(handle, coord); 
}


char *addnama(char *nama) {
    char inp;
    char kumpulan[20] = {};
    char idx = 0;

    while( (inp = getch())  != 13 || idx <= 5) {
        if( idx <= 18 && (((idx == 0 || kumpulan[idx-1] == ' ') && (inp >= 'A' && inp <= 'Z') )  
        || (idx > 0 && (inp >= 'a' && inp <= 'z') && (inp != kumpulan[idx-1] || inp != kumpulan[idx-2]) 
        && kumpulan[idx-1] != ' ')        
        || idx > 2 && inp == 32 && kumpulan[idx-1] != 32
        )){
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
        }else if(inp == 8 && idx != 0){
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
        }
    }
    strcpy(nama,kumpulan);
    return nama;
}

char *addpass(char *pass)
{
    char input;
    char tamp[100] = {};
    int index = 0;

    while ((input = getch()) != 13 || index < 8)
    {
        if (index < 9 && index < 10 && input != 13 && input != 8 && input != 32 && input >= '0' && input <= '8')
        {
            printf("*", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
        }
    }
    return strcpy(pass, tamp);
}

char *addusername(char *user) {
    char inp;
    char kumpulan[20] = {};
    char idx = 0;

    while( (inp = getch())  != 13 || idx <= 10) {
        if( idx <= 10 && ((idx == 0 && (inp >= 'a' && inp <= 'z'))  || (idx > 0 &&  (inp != kumpulan[idx-1] || inp != kumpulan[idx-2]) && ( (inp >= 'a' && inp <= 'z') || idx > 2 && inp != 32 && (kumpulan[idx-1] != 32)
        ))) ){
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
        }else if(inp == 8 && idx != 0){
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
        }
    }
    strcpy(user,kumpulan);
    return user;
}


char *addjudul(char *judul)
{
    char inp;
    char kumpulan[20] = {};
    char idx = 0;

    while( (inp = getch())  != 13 || idx <= 3) {
        if( idx <= 25 && (((idx == 0 || kumpulan[idx-1] == ' ') && (inp >= 'A' && inp <= 'Z') )  
        || (idx > 0 && (inp >= 'a' && inp <= 'z') && (inp != kumpulan[idx-1] || inp != kumpulan[idx-2]) 
        && kumpulan[idx-1] != ' ')        
        || idx > 2 && inp == 32 && kumpulan[idx-1] != 32
        )){
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
        }else if(inp == 8 && idx != 0){
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
        }
    }
    strcpy(judul,kumpulan);
    return judul;
}

char *addpenulis(char *penulis)
{
    char inp;
    char kumpulan[20] = {};
    char idx = 0;

    while( (inp = getch())  != 13 || idx <= 4) {
        if( idx <= 18 && (((idx == 0 || kumpulan[idx-1] == ' ') && (inp >= 'A' && inp <= 'Z') )  
        || (idx > 0 && (inp >= 'a' && inp <= 'z') && (inp != kumpulan[idx-1] || inp != kumpulan[idx-2]) 
        && kumpulan[idx-1] != ' ')        
        || idx > 2 && inp == 32 && kumpulan[idx-1] != 32
        )){
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
        }else if(inp == 8 && idx != 0){
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
        }
    }
    strcpy(penulis,kumpulan);
    return penulis;
}

char *addgenre(char *genre) 
{
  char input;
  int index = 0;
  while ((input = getch()) != 13  || genre[index - 1] == ' ')
  {
    if ((index == 0 && (input >= 'A' && input <= 'Z') && (input != genre[index - 1] || input != genre[index - 2]) 
    || (input >= 'a' && input <= 'z') && (input != genre[index - 1] || input != genre[index - 2]) 
    || (genre[index - 1] != ' ' && input == ' ' && index != 0)) && index < 21)
    {
      printf("%c", input);
      genre[index] = input;
      index++;
    }
    else if (input == 8 && index != 0)
    {
      printf("\b \b");
      genre[index] = input;
      index--;
    }
  }
  genre[index] = '\0';
  return genre;
}

char *addcerita(char *cerita)
{
    char inp;
    char kumpulan[100] = {};
    char idx = 0;

    while( (inp = getch())  != 13 ) {
        if( idx < 98 && ((idx == 0 && (inp >= 'A' && inp <= 'Z'))  || (idx > 0 &&  (inp != kumpulan[idx-1]) 
        && ( ((inp >= 'a' && inp <= 'z') || (inp >= 'A' && inp <= 'Z')) 
        || idx > 2 && inp == 32 && (kumpulan[idx-1] != 32) || idx > 0 && inp == '.' || inp == ','
        ))) ){
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
        }else if(inp == 8 && idx != 0){
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
        }
    }

    strcpy(cerita,kumpulan);
    return cerita;
}

char* valUmur(char *umur){
    char tamp_umur[100] = {};
    char input;
    int idx = 0;
    while((input = getch()) && idx < 2){
        if(idx < 3 && (input >= '1' && input <= '9' || input == '0' && idx != 0)){
            printf("%c",input);
            tamp_umur[idx] = input;
            idx++;
        }
        else if(input == 8 && idx != 0){
            printf("\b \b");
            idx--;
            tamp_umur[idx] = '\0';
        }
 }
    return strcpy(umur,tamp_umur);
}

char *valuang(char *uang)
{
    char d;
    char input1[100];
    int index = 0;
    while ((d = getch()) != 13 || index < 4)
    {
        if (index < 5 && (d >= '0' && d <= '9' && index > 0 || d >= '1' && d <= '9' && index == 0))
        {
            printf("%c", d);
            input1[index] = d;
            index++;
        }
        else if (d == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            input1[index] = '\0';
        }
    }
    return strcpy(uang,input1);


}

char *valPilihDua(char* pilih)
{
    char inputan;
    char tamp[100] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 1)
    {
        if (index < 1 && index==0 &&(inputan >= '1' && inputan <= '2' ))
        {
            printf("%c", inputan);
            tamp[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        } else if (inputan == 27)
        {
            menu_admin();
        }
    }
    strcpy(pilih, tamp);
}

char *valPilihDuaUser(char* pilih)
{
    char inputan;
    char tamp[100] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 1)
    {
        if (index < 1 && index==0 &&(inputan >= '1' && inputan <= '2' ))
        {
            printf("%c", inputan);
            tamp[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        } 
        
    }
    strcpy(pilih, tamp);
}

char *valPilihEmpat(char* pilih)
{
    char inputan;
    char tamp[100] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 1)
    {
        if (index < 1 && index==0 &&(inputan >= '1' && inputan <= '4' ))
        {
            printf("%c", inputan);
            tamp[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
        else if (inputan == 27)
        {
            menu_admin();
        }
         
        
    }
    strcpy(pilih, tamp);
}

char *valPilihLima(char* pilih)
{
    char inputan;
    char tamp[100] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 1)
    {
        if (index < 1 && index==0 &&(inputan >= '1' && inputan <= '5' ))
        {
            printf("%c", inputan);
            tamp[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    strcpy(pilih, tamp);
}

char *addulasan(char *ulasan)
{
    int apaaja = 0;
    char inp;
    char kumpulan[500];
    char idx = 0;

    while((inp = getch()) !=13) {
        if(((idx == 0 && (inp >= 'A' && inp <= 'Z'))  || (idx > 0 &&  (inp != kumpulan[idx-1]) && ( ((inp >= 'a' && inp <= 'z') || (inp >= 'A' && inp <= 'Z'))  || idx > 2 && inp == 32 && (kumpulan[idx-1] != 32) || idx > 0 && inp == '.' || inp == ','))) ){
            if (idx == 95 )
            {
                posisi(38+apaaja,27);
                apaaja++;
                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
             
            } else{

                printf("%c", inp);
                kumpulan[idx] = inp;
                idx++;
                
            }
            
        }else if(inp == 8 && idx != 0){
                 apaaja--;
            if (apaaja == -1)
            {
                posisi(133-apaaja,25);
                printf("\b \b");
                kumpulan[idx-1] = '\0';
                idx--;
            } else
            {
            printf("\b \b");
            kumpulan[idx-1] = '\0';
            idx--;
            }
            
            
        }
    }

    strcpy(ulasan,kumpulan);
    return ulasan;
}



// char *addsinopsis(char *sinop[])
// {
//     char inp;
//     char kumpulan[] = {};
//     int idx = 0;
//     int i = 0;

//     while( (inp = getch())  != 13) {
//         if(idx == 20){
//             posisi(32,18 + i);
//             i++;
//         }

//         // if(((idx == 0 && (inp >= 'A' && inp <= 'Z'))  || (idx > 0 &&  (inp != kumpulan[idx-1] || 
//         // inp != kumpulan[idx-2]) && ( ((inp >= 'a' && inp <= 'z') || (inp >= 'A' && inp <= 'Z')) 
//         // || idx > 2 && inp == 32 && (kumpulan[idx-1] != 32)  
//         // ))) ){
//                 printf("%c", inp);
//                 kumpulan[idx] = inp;
//                 idx++;
//         // }else if(inp == 8 && idx != 0){
//         //     printf("\b \b");
//         //     kumpulan[idx-1] = '\0';
//         //     idx--;
//         // }
//     }
//     strcpy(sinop,kumpulan);
//     return sinop;
// }






char* addnotelp(char* telp){
    int index=0;
    char inp;
    while((inp=getch())!=13 || index < 11 || index > 14 || telp[index-1] == ' ')
    {
        if( index < 14 && ((inp=='0' && index==0 || inp== '8' && index==1 || 
        inp== '1' && index==2 || inp== '2' && index==2 || inp== '3' && index==2 || inp== '5' && index==2) ||
        (inp >= '1' && inp <= '9') && inp != '4' && inp != '5' && inp != '6' && telp[index-1]== '1' ||
        (inp == '1' || inp == '2') && telp[index-1]== '2' ||
        (inp == '2' || inp == '3' || inp == '8') && telp[index-1]== '3' ||
        (inp >= '0' && inp <= '9') && telp[index-1]== '5' ||
        (inp >= '0' && inp <= '9') && index > 3))   
        {
            printf("%c", inp);
            telp[index]=inp;
            index++;
        }else if(inp == 8 && index != 0){
            printf("\b \b");
            index--;
            telp[index] = '\0';
        }
        }
    return telp;    
}



