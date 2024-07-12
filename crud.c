#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "validasi.c"

// void gotoxy(int x, int y)
// {
//     //COORD coord = {x, y};
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }

// void add_book(){
//     FILE* book = fopen("bacaan.txt","a");
//     char inp;
//     char judul[50], penulis[50], genre[50], sinopsis[200], cerita[1000];    

//     gotoxy(13,11);printf("Judul\t\t: "); strcpy(judul,valName(judul));
//     gotoxy(13,13);printf("Penulis\t\t: "); strcpy(penulis,valName(penulis));
//     gotoxy(13,15);printf("Genre\t\t: "); strcpy(genre,valName(genre));
//     gotoxy(13,17);printf("Sinopsis\t\t: "); scanf("%[^\n]", &sinopsis);
//     gotoxy(13,19);printf("Cerita\t\t: "); scanf("%[^\n]", &cerita);

    
//     // gotoxy(34,17); sinopsis=getch();
//     // gotoxy(34,19); cerita=getch();

    
//     fprintf(book,"%s#%s#%s#%s#%s\n",judul,penulis,genre,sinopsis,cerita);
//     fclose(book);
//     printf("Data Berhasil Ditambahkan\n");
// }

// void add_reader(){
//   FILE *reader;
//   reader = fopen("reader.txt", "a");
//   gotoxy(24, 15);
//   printf("NAMA       : ");
//   inputnama(nama);
//   gotoxy(24, 17);
//   printf("NIM        : ");
//   inputnim(nim);
//   for (int j = 0; j > -9; j++)
//   {

//     gotoxy(24, 19);
//     printf("GENRE   : ");
//     inputjurus(jurusan);
//     for (int i = 0; i < 8; i++)
//     {
//       if (strcmp(jurusan, jurusan3[i]) == 0)
//       {
//         ada++;
//       }
//     }
//     if (ada > 0)
//     {
//       break;
//     }
//     else
//     {
//       gotoxy(61, 19);
//       printf("                      ");
//     }
//   }

//   gotoxy(24, 21);
//   printf("NOMOR HP   : ");
//   inputnomor(nomor);
//   gotoxy(24, 23);
//   printf("ALAMAT     : ");
//   inputalamat(alamat);
//   fprintf(reader, "%s\n%s\n%s\n%s\n%s\n\n", nama, nim, jurusan, nomor, alamat);
//   fclose(reader);

// }

// void main(){
//     add_book();
// }


// int a = 0;
//     FILE *bacaan;
//     bacaan = fopen("bacaan.txt", "a");
//     gotoxy(24, 15);
//     printf("JUDUL           :")
//     scanf("%[^\n]", inpjudul);
//     getchar();
//     gotoxy(24, 17);
//     printf("PENULIS        : ");
//     scanf("%[^\n]", &inppenulis);
//     getchar();
//     for (int j = 0; j > -9; j++)
//     {

//         gotoxy(24, 19);
//         printf("GENRE   : ");
//         gets(inpgenre);
//         for (int i = 0; i < 8; i++)
//         {
//         if (strcmp(inpgenre, genre1[i]) == 0)
//         {
//             a++;
//         }
//         }
//         if (a > 0)
//         {
//         break;
//         }
//         else
//         {
//         gotoxy(61, 19);
//         printf("genre tidak sesuai");
//         }
//     }
//     gotoxy(24, 21);
//     printf("SINOPSIS       : ");
//     gets(inpsinopsis[]);
//     if(inpsinopsis > [50]){
//         printf("\n\t\t");
//     }

//     gotoxy(24, 23);
//     printf("CERITA        : ");
//     gets(inppenulis);
//     getchar();
    
//     fprintf(bacaan, "%s#%s#%s#%s#%s\n",inpjudul,inppenulis,inpgenre,inpsinopsis,inpcerita);
//     fclose(bacaan);
//     printf("Data berhasil ditambahkan");



void update_recom(){
    system("cls");
    char jdlbuku[100],karya[100];
    char tamp_jdlbuku[100][100],tamp_karya[100][100];
    int pilih,idx = -1,i = 0;
    printf("1.Update Judul\n2.Update Karya\nPilih : ");scanf("%d",&pilih); 
    if(pilih == 1){
        FILE* recom = fopen("recom.txt","r");
        printf("Cari judul sebelumnya : ");strcpy(jdlbuku,addjudul(jdlbuku));
        while(fscanf(recom,"%[^$]$%[^\n]\n",&tamp_jdlbuku[i],&tamp_karya[i]) != EOF){
            if(strcmp(jdlbuku,tamp_jdlbuku[i]) == 0){
                idx = i;
            }
            i++;
        }
        fclose(recom);
        if(idx != -1){
            printf("\n");
            printf("Input JUDUL BUKU : ");strcpy(jdlbuku,addjudul(jdlbuku));
            FILE* recom2 = fopen("recom.txt","w");
            for(int j = 0; j < i; j++){
                if(idx == j){
                    fprintf(recom2,"%s$%s\n",jdlbuku,tamp_karya[j]);
                    printf("%s\n%s\n",jdlbuku,tamp_karya[j]);
                }
                else{
                    fprintf(recom2,"%s$%s\n",tamp_jdlbuku[j],tamp_karya[j]);
                }
            }
            fclose(recom2);
            printf("\nData Berhasil Di Update\n");
            Sleep(2000);
            system("cls");
            menu();
        }
        else{
            printf("\nData Tidak Ditemukan\n");
            Sleep(2000);
            system("cls");
            menu();
        }
    }
    else if(pilih == 2){
        FILE* recom = fopen("recom.txt","r");
        printf("Cari judul sebelumnya : ");strcpy(jdlbuku,addjudul(jdlbuku));
        while(fscanf(recom,"%[^$]$%[^\n]\n",&tamp_jdlbuku[i],&tamp_karya[i]) != EOF){
            if(strcmp(jdlbuku,tamp_jdlbuku[i]) == 0){
                idx = i;
            }
            i++;
        }
        fclose(recom);
        if(idx != -1){
            printf("\n");
            printf("Input KARYA : ");strcpy(karya,addpenulis(karya));
            FILE* recom2 = fopen("recom.txt","w");
            for(int j = 0; j < i; j++){
                if(idx == j){
                    fprintf(recom2,"%s$%s\n",tamp_jdlbuku[j],karya);
                }
                else{
                    fprintf(recom2,"%s$%s\n",tamp_jdlbuku[j],tamp_karya[j]);
                }
            }
            fclose(recom2);
            printf("\nData Berhasil Di Update\n");
            Sleep(2000);
            system("cls");
            menu();
        }
        else{
            printf("\nData Tidak Ditemukan\n");
            Sleep(2000);
            system("cls");
            menu();
        }
    }

    else{
        update();
    }
}
