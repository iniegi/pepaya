#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void SetColor(unsigned short);
void SetColor(unsigned short color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}

struct data
{
    char nama[50]; char asal[50]; char nik[16];
    float lama; char telepon[13]; int kos;
    struct data *pointer;
};

typedef struct data penghuni;
penghuni *head, *temp;

penghuni *Baru(char nama[50], char asal[50], char nik[16], int lama, char telepon[15], int kos)
{
    penghuni *penghuniBaru = malloc(sizeof(penghuni));
    strcpy(penghuniBaru->nama, nama);
    strcpy(penghuniBaru->asal, asal);
    strcpy(penghuniBaru->nik, nik);
    strcpy(penghuniBaru->telepon, telepon);
    penghuniBaru->lama = lama;
    penghuniBaru->kos = kos;
    penghuniBaru->pointer = NULL;
    return penghuniBaru;
}
int batas[5] = {1,1,1,1,1};

void login(){
    char username[20], pass[10];
    system("cls");
    printf("+---------------+");
    printf("\n      MASUK\n");
    printf("+---------------+\n");
    printf("Username: ");
    scanf(" %[^\n]",&username);
    printf("Password: ");
    scanf(" %[^\n]",&pass);

    if((strcmp(username,"admin")==0) && ((strcmp(pass,"cantik")==0) || (strcmp(pass,"ganteng")==0))){
        loading();
    }
    else{
        printf("Unknown username or password. Please try again.\n");
        system("pause");
        login();
    }
    int index = 0;
    char ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (index > 0) {
                printf("\b \b");
                index--;
            }
        } else {
            if (index < MAX_PASSWORD_LENGTH - 1) {
                printf("*");
                pass[index] = ch;
                index++;
            }
        }
    }
    password[index] = '\0';
}

void loading(){
    system("cls");
    int i;
    printf("\n");
    for (i = 0; i <= 27; i++){
        printf("Loading... %d%%", i);
        Sleep(50);
        printf("\r");
    }
    for (i = 27; i <= 52; i++){
        printf("Loading... %d%%", i);
        Sleep(100);
        printf("\r");
    }
    for (i = 52; i <= 70; i++){
        printf("Loading... %d%%", i);
        Sleep(250);
        printf("\r");
    }
    for (i = 70; i <= 85; i++){
        printf("Loading... %d%%", i);
        Sleep(100);
        printf("\r");
    }
    for (i = 85; i <= 100; i++){
        printf("Loading... %d%%", i);
        Sleep(50);
        printf("\r");
    }
    sleep(1);
    printf("Loading selesai.\n");
    sleep(1);
    printf("WELCOME!");
    sleep(1);
    Menu();
}
