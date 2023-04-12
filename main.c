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

void Menu(){
    int input;
    system("cls");
    printf("+---------------------------+\n");
    printf("SELAMAT DATANG DI KOS PEPAYA!\n");
    printf("+---------------------------+\n");
    printf("1. Pepaya Kos\n");
    printf("2. Data Penghuni\n");
    printf("3. Keluar\n\n");
    printf("Pilihan anda: "); scanf("%d", &input);
    printf("+--------------------------+\n");
    if (input == 1)
    {
        inputData();
    }
    else if (input == 2)
    {
        printList();
    }
    else if (input == 3)
    {
        exit(0);
    }
    else{
        Menu();
    }

}

int pilihKamar(){
    int input;
    printf("Pilihan Kamar:\n");
    if (batas[0])
        printf("1. Tipe A, kamar mandi dalam, lantai bawah\n");
    if (batas[1])
        printf("2. Tipe B, kamar mandi luar, lantai bawah\n");
    if (batas[2])
        printf("3. Tipe C, kamar mandi dalam, lantai atas\n");
    if (batas[3])
        printf("4. Tipe D, kamar mandi luar, lantai atas\n");
    if (batas[4])
        printf("5. Tipe E, kamar mandi dalam dan plus AC\n");
    printf("Pilihlah kamar anda: "); scanf("%d", &input);
    if (input == 1 && batas[0] > 0)
    {
        batas[0]--;
        return input;
    }
    else if (input == 2 && batas[1] > 0)
    {
        batas[1]--;
        return input;
    }
    else if (input == 3 && batas[2] > 0)
    {
        batas[2]--;
        return input;
    }
    else if (input == 4 && batas[3] > 0)
    {
        batas[3]--;
        return input;
    }
    else if (input == 5 && batas[4] > 0)
    {
        batas[4]--;
        return input;
    }
    else{
        printf("\nKamar sudah ditempati\n");
        pilihKamar();
    }
}
void printList(){
    int input = 0;
    system("cls");
    penghuni *read = head;
    while (read != NULL)
    {
        printf("\n+---------------------------------------+\n");
        printf("Nama               : %s \n", read->nama);
        printf("Nomor Telpon       : %s \n", read->telepon);
        printf("Asal               : %s \n", read->asal);
        printf("NIK                : %s \n", read->nik);
        printf("Lama Tinggal       : %3.0f Tahun\n", read->lama);
        printf("Kamar yang dipilih : ");
        if (read->kos == 1)
            printf("Tipe A, kamar mandi dalam, lantai bawah\n");
        if (read->kos == 2)
            printf("Tipe B, kamar mandi luar, lantai bawah\n");
        if (read->kos == 3)
            printf("Tipe C, kamar mandi dalam, lantai atas\n");
        if (read->kos == 4)
            printf("Tipe D, kamar mandi luar, lantai atas\n");
        if (read->kos == 5)
            printf("Tipe E, kamar mandi dalam dan plus AC\n");
        printf("\n--HARGA PERBULAN : Rp %3.3f\n", read->lama * 100);
        printf("+----------------------------------------+\n");
        read = read->pointer;
    }
    printf("1. Cari\n");
    printf("2. Urutkan\n");
    printf("3. Kembali\n");
    scanf("%d", &input);
    if (input == 1){
        cariNode();
    }
    else if (input == 2)
        sorting();
    else if (input == 3)
        Menu();
    else
        printList();

}
