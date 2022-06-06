#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("pause");
    system("cls");
    Pilih_Layanan:
    printf("Silahkan Memilih Layanan :\n");
    printf("1. Pembuatan Kartu Keluarga\n");
    printf("2. Pembuatan Akta Kelahiran\n");
    printf("3. Pembuatan Kartu Tanda Penduduk\n");
    printf("4. Pembuatan Surat Kematian\n");
    printf("5. Pengecekan Data\n");
    printf("Pilih : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
        case 1:
        buatKK;
        break;

        case 2:
        //Program Pembuatan Akta
        break;

        case 3:
        //Program Pembuatan KTP
        break;

        case 4:
        //Program Pembuatan Surat Kematian
        break;

        case 5:
        //Program Pengecekan Data
        break;
    }
}
