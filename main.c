#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

FILE *file;
int jml, i;

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct data{
    int kode;
    char nama;
    char jenis;
    char fct;
    union {
        int tgl, bln, thn;
    };
    int stock;
    float harga;
};
struct data *obat;


void password()
{
    char username[100];
    char password[100];

    system("COLOR F4");

    PASS:
        gotoxy (40, 13);
        printf ("masukkan username :");
        scanf ("%s", username);
        gotoxy (40, 14);
        printf ("masukkan password :");
        fflush (stdin);

        char ch;
        int i = 0;
        while ((ch = (char)_getch()) != '\r')
        {
            password[i] = ch;
            printf("*");
            i++;
        }
        printf ("\n");

        if ((strcmp(username, "upinipinapin") == 0) && (strcmp(password, "cantik") == 0))
        {
            gotoxy (40, 16);
            printf ("selamat anda berhasil masuk\n\n\n\n\n\n");
        }
        else
        {
            gotoxy (30, 16);
            printf ("Password dan username salah... silahkan ulang lagi\n");
            system ("pause");
            system ("cls");
            goto PASS;
        }
}


tambah_obat()
{
    char save = 'y';

    printf ("          TAMBAH OBAT\n\n\n");
    printf ("MASUKKAN DATA OBAT DI BAWAH\n\n");
    printf ("Masukkan jumlah obat yang ingin di inputkan : ");
    scanf ("%d", &jml);
    fflush(stdin);

     // allocating memory for jml numbers of struct data
    obat = (struct data*) malloc(jml * sizeof(struct data));

    ord[i].numOfItem = jml;
    for (i = 0; i < jml; ++i){
        printf ("Data obat ke-%d \n", i + 1);
        printf ("Kode obat                  : ");
        scanf ("%d", &obat[i].kode);
        printf ("Nama obat                  : ");
        scanf ("%s", &obat[i].nama);
        printf ("Jenis obat                 : ");
        scanf ("%s", &obat[i].jenis);
        printf ("Pabrik obat                : ");
        scanf ("%s", &obat[i].fct);
        printf ("Tanggal masuk (dd mm yyyy) : ");
        scanf ("%d%d%d", &obat[i].tgl, &obat[i].bln, &obat[i].thn);
        printf ("Stock obat                 : ");
        scanf ("%d", &obat[i].stock);
        printf ("harga obat                 : ");
        scanf ("%f", &obat[i].harga);

        printf ("\n");
    }

    if (save == 'y' || save == 'Y')
    {
        file = fopen("dataObat.dat", "a+"); //selain file dapat ditulis file juga dapat dibaca
        fwrite(&obat[i], sizeof(struct data), 1, file); //Operator sizeof memberikan jumlah penyimpanan, dalam byte, yang diperlukan untuk menyimpan objek dari jenis operand

        if (fwrite != 0)
            printf("\nBerhasil disimpan\n");
        else
            printf("\npenyimpanan bermasalah");
        fclose(file);
    }
    i++;
}

lihat_obat()
{
    system ("cls");
    file = fopen ("dataObat", "r");

    for (k = 0; k < i; k++){
        printf ("data obat %d", obat[k].kode);

    }
}

int main()
{
    int choice;

    //variabel menu
    int menu, i;
    int read = 0;
    char nama[50];

    //program animasi
    int a, invoiceFound = 0;
    double b;
    char salam[] = "\t\t\t\t\t SELAMAT DATANG DI APOTEK TADIKA MESRA   ";
    int k, l;

    printf("\n\n\n");
    for (a = 0; salam[a] != NULL; a++)
    {
        printf("%c", salam[a]);
        for (b = 0; b <= 9999999; b++)
        {
        }
    }
    fflush(stdin);

    //password
    password();
    //tanggal();

    do{
        //tanggal();
        system("cls"); //membersihkan layar
        printf("\n\n\t\t\t\tMENU UTAMA\n");
        printf("\t\t1. Tambah data obat\n");
        printf("\t\t2. Lihat data obat\n");
        printf("\t\t3. Cari data obat\n");
        printf("\t\t4. Ubah data obat\n");
        printf("\t\t5. Urutkan data obat\n");
        printf("\t\t6. Hapus data obat\n");
        printf("\t\t7. Keluar\n");
        printf("\n\t\tMasukkan pilihan: ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            tambah_obat();
            getch();
            break;
        case 2:
            lihat_obat();
            getch();
            break;
        case 3:
            //ubah_obat();
            getch();
            break;
        case 4:
            //hapus_obat();
            getch();
            break;
        case 5:
            //urutkan_obat();
            getch();
            break;
        case 6:
            //tambah_obat();
            getch();
            break;
        case 7:
            printf("\n\nTerima kasih telah menggunakan program ini!");
            getch();
            break;
        default:
            printf("\n\nMaaf, pilihan yang anda masukkan salah. Silakan coba lagi.");
            getch();
            break;
        }
    }while(choice!=7);
    return 0;
}


