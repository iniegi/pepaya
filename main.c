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

void inputData(){
    char tempNama[50], tempAsal[50], tempNik[16], tempTelepon[15]; float tempLama; int tempKos;
    system("cls");
    printf("Masukkan nama            : "); scanf(" %[^\n]s", &tempNama);
    printf("Masukkan nomor telepon   : "); scanf(" %[^\n]s", &tempTelepon);
    printf("Asal                     : "); scanf(" %[^\n]s", &tempAsal);
    printf("Masukkan nik             : "); scanf(" %[^\n]s", &tempNik);
    printf("Lama Tinggal             : "); scanf("%f", &tempLama);
    tempKos = pilihKamar();
    temp = Baru(tempNama, tempAsal, tempNik, tempLama, tempTelepon, tempKos);
    temp->pointer = head;
    head = temp;
    system("pause");
    Menu();
}

void deleteNode(char nama[50]){
penghuni *cari = head, *prev = NULL;
if (cari != NULL && strcmp(cari->nama, nama) == 0){
    head = cari->pointer;
    free(cari);
    printf("Data berhasil dihapus!\n");
    return;
}

while (cari != NULL && strcmp(cari->nama, nama) != 0){
    prev = cari;
    cari = cari->pointer;
}

if (cari == NULL){
    printf("Data tidak ditemukan.\n");
    return;
}

prev->pointer = cari->pointer;
free(cari);
printf("Data berhasil dihapus!\n");
}

void cariNode(){
    penghuni *cari = head; int search = 0; int choice; int kos;
    char nama[50];
    system("cls");
    printf("Nama yang ingin dicari: ");
    scanf(" %[^\n]s", &nama);
    while (cari != NULL)
    {
        if (strcmp(cari->nama, nama) == 0){
            printf("\n+------------------------------------------+\n");
            printf("Nama               : %s \n", cari->nama);
            printf("Nomor Telepon      : %s \n", cari->telepon);
            printf("Asal               : %s \n", cari->asal);
            printf("NIK                : %s \n", cari->nik);
            printf("Lama Tinggal       : %3.0f tahun\n", cari->lama);
            printf("Kamar yang dipilih : ");
            if (cari->kos == 1)
                printf("Tipe A\n");
            if (cari->kos == 2)
                printf("Tipe B\n");
            if (cari->kos == 3)
                printf("Tipe C\n");
            if (cari->kos == 4)
                printf("Tipe D\n");
            if (cari->kos == 5)
                printf("Tipe E\n");
            printf("\n--HARGA PERBULAN : Rp %3.3f--\n", cari->lama * 100);
            printf("+--------------------------------------------+\n");

D, [4/13/2023 3:44 AM]
search = 1;
            break;
        }
        cari = cari->pointer;
    }
    if (search == 0)
    {
        printf("Nama tidak ditemukan.\n");
        system("pause");
        printList();
    }
    else if (search == 1)
    {
        printf("1. Print Data\n");
        printf("2. Ubah Data\n");
        printf("3. Keluar\n");
        printf("Input: "); scanf("%d", &choice);
        if (choice == 1)
        {
            FILE *cetak;
            cetak = fopen("PenghuniKos.txt", "w");
            fprintf(cetak, "+------------   PEPAYA KOS   ------------+\n");
            fprintf(cetak, "Nama               : %s\n", cari->nama);
            fprintf(cetak, "Nomor telepon      : %s\n", cari->telepon);
            fprintf(cetak, "Asal               : %s\n", cari->asal);
            fprintf(cetak, "NIK                : %s\n", cari->nik);
            fprintf(cetak, "Lama Tinggal       : %3.0f tahun\n", cari->lama);
            fprintf(cetak, "Kamar yang dipilih : ");
            if (cari->kos == 1)
                fprintf(cetak, "Tipe A\n\n");
            else if (cari->kos == 2)
                fprintf(cetak, "Tipe B\n\n");
            else if (cari->kos == 3)
                fprintf(cetak, "Tipe C\n\n");
            else if (cari->kos == 4)
                fprintf(cetak, "Tipe D\n\n");
            else if (cari->kos == 5)
                fprintf(cetak, "Tipe E\n\n");
            fprintf(cetak, "---JUMLAH YANG HARUS DIBAYAR: Rp %3.3f---\n", cari->lama * 100);
            fprintf(cetak, "+---------------------------------------+\n");
            fclose(cetak);
            printf("Data berhasil dicetak. \n");
            system("pause");
            Menu();
        }
        else if (choice == 2)
        {
            printf("\nData apa yang ingin dihapus?\n");
            printf("1. Nama\n");
            printf("2. Nomor telepon\n");
            printf("3. Asal\n");
            printf("4. NIK\n");
            printf("5. Lama Tinggal\n");
            printf("6. Kamar yang dipilih\n");
            printf("Input: "); scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Nama: "); scanf(" %[^\n]s", cari->nama);
                printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else if (choice == 2)
            {
                printf("Nomor telepon: "); scanf(" %[^\n]s", cari->telepon);
                printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else if (choice == 3)
            {
                printf("Asal: "); scanf(" %[^\n]s", cari->asal);
                printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else if (choice == 4)
            {
                printf("Nomor NIK: "); scanf(" %[^\n]s", cari->nik);

printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else if (choice == 5)
            {
                printf("Lama tinggal: "); scanf("%f", &cari->lama);
                printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else if (choice == 6)
            {
                kos = pilihKamar();
                cari->kos = kos;
                printf("Data berhasil diubah. \n"); system("pause"); printList();
            }
            else
                cariNode();
        }
        else if (choice == 3)
        {
            Menu();
        }
        else{
            printList();
        }
    }
}
