#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct kartukeluarga
{
    char nokk[20],alamat[50],rt_rw[20],kodepos[20],kel[20],kec[20],kab[20],prov[20];
    char nama[50],nik[20],jkelamin[10],tmp_lahir[20],tgl_lahir[20],agama[20],pendidikan[20],pekerjaan[20],goldar[5];
    char status[20],tgl_kawin[20],peran[20],wn[20],paspor[20],kitap[20],nayah[50],nibu[50];
}kk,temp,arrkk[500];

FILE *fp;
int i,n;
char nokk[20];

void nomorkk1()
{
    char randnum[10]="0123456789";
    char newrandnum[10];

    strcpy(nokk,arrkk[0].nik);
    srand(time(NULL));
    nokk[strlen(nokk)-12]='\0';
    for(i=0;i<11;i++)
    {
        newrandnum[i]=randnum[rand()%(sizeof(randnum)-1)];
    }
    newrandnum[12]=0;
    strcat(nokk,newrandnum);
    printf("%s",nokk);
    fprintf(fp,"%s",nokk);
}




// Alternatif Nomor KK
void nomorkk2()
{
    int Digit2;
    char digit1[10]="327302";
    char digit2[10],digit3[10];
    char randnum[10]="0123456789";
    char digit4[2],digit5[2],digit6[2];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Digit2=(tm.tm_mday*10000)+((tm.tm_mon+1)*100)+(tm.tm_year+1900-2000);
    sprintf(digit2,"%d",Digit2);

    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        digit3[i]=randnum[rand()%(sizeof(randnum)-1)];
    }
    digit3[5]=0;
    strcat(nokk,digit1);
    strcat(nokk,digit2);
    strncat(nokk,digit3,5);

    printf("%s",nokk);
    fprintf(fp,"%s",nokk);
}


void buatkk()
{
    fp=fopen("dataKK.txt","a+");

    fflush(stdin);
    printf("Masukkan Nama Kepala Keluarga : ");
    fgets(kk.nama,50,stdin); strtok(kk.nama,"\n");
    fflush(stdin);
    printf("Masukkan Alamat : ");
    fgets(kk.alamat,50,stdin); strtok(kk.alamat,"\n");
    fflush(stdin);
    printf("Masukkan RT/RW : ");
    fgets(kk.rt_rw,20,stdin); strtok(kk.rt_rw,"\n");
    fflush(stdin);
    printf("Masukkan Kodepos : ");
    fgets(kk.kodepos,20,stdin); strtok(kk.kodepos,"\n");
    fflush(stdin);
    printf("Masukkan Desa/Kelurahan : ");
    fgets(kk.kel,20,stdin); strtok(kk.kel,"\n");
    fflush(stdin);
    printf("Masukkan Kecamatan : ");
    fgets(kk.kec,20,stdin); strtok(kk.kec,"\n");
    fflush(stdin);
    printf("Masukkan Kabupaten/Kota : ");
    fgets(kk.kab,20,stdin); strtok(kk.kab,"\n");
    fflush(stdin);
    printf("Masukkan Provinsi : ");
    fgets(kk.prov,20,stdin); strtok(kk.prov,"\n");
    fflush(stdin); printf("\n");
    system("pause"); system("cls");

    printf("Masukkan Jumlah Anggota Keluarga : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\nAnggota Keluarga %d\n",i+1);
        printf("Masukkan Nama Lengkap : ");
        fgets(arrkk[i].nama,50,stdin); strtok(arrkk[i].nama,"\n");
        fflush(stdin);
        printf("Masukkan NIK : ");
        fgets(arrkk[i].nik,20,stdin); strtok(arrkk[i].nik,"\n");
        fflush(stdin);
        printf("Masukkan Jenis Kelamin : ");
        fgets(arrkk[i].jkelamin,10,stdin); strtok(arrkk[i].jkelamin,"\n");
        fflush(stdin);
        printf("Masukkan Tempat Lahir : ");
        fgets(arrkk[i].tmp_lahir,20,stdin); strtok(arrkk[i].nama,"\n");
        fflush(stdin);
        printf("Masukkan Tanggal Lahir : ");
        fgets(arrkk[i].tgl_lahir,20,stdin); strtok(arrkk[i].tgl_lahir,"\n");
        fflush(stdin);
        printf("Masukkan Agama : ");
        fgets(arrkk[i].agama,20,stdin); strtok(arrkk[i].agama,"\n");
        fflush(stdin);
        printf("Masukkan Pendidikan : ");
        fgets(arrkk[i].pendidikan,20,stdin); strtok(arrkk[i].pendidikan,"\n");
        fflush(stdin);
        printf("Masukkan Jenis Pekerjaan : ");
        fgets(arrkk[i].pekerjaan,20,stdin); strtok(arrkk[i].pekerjaan,"\n");
        fflush(stdin);
        printf("Masukkan Golongan Darah : ");
        fgets(arrkk[i].goldar,5,stdin); strtok(arrkk[i].goldar,"\n");
        fflush(stdin);
        printf("Masukkan Status Perkawinan : ");
        fgets(arrkk[i].status,20,stdin); strtok(arrkk[i].status,"\n");
        fflush(stdin);
        printf("Masukkan Tanggal Perkawinan : ");
        fgets(arrkk[i].tgl_kawin,20,stdin); strtok(arrkk[i].tgl_kawin,"\n");
        fflush(stdin);
        printf("Masukkan Status Hubungan Dalam Keluarga : ");
        fgets(arrkk[i].peran,20,stdin); strtok(arrkk[i].peran,"\n");
        fflush(stdin);
        printf("Masukkan Kewarganegaraan : ");
        fgets(arrkk[i].wn,20,stdin); strtok(arrkk[i].wn,"\n");
        fflush(stdin);
        printf("Masukkan Nomor Paspor : ");
        fgets(arrkk[i].paspor,20,stdin); strtok(arrkk[i].paspor,"\n");
        fflush(stdin);
        printf("Masukkan Nomor KITAP : ");
        fgets(arrkk[i].kitap,20,stdin); strtok(arrkk[i].kitap,"\n");
        fflush(stdin);
        printf("Masukkan Nama Ayah : ");
        fgets(arrkk[i].nayah,50,stdin); strtok(arrkk[i].nayah,"\n");
        fflush(stdin);
        printf("Masukkan Nama Ibu : ");
        fgets(arrkk[i].nibu,50,stdin); strtok(arrkk[i].nibu,"\n");
    }
    fprintf(fp,"\n======================================================================================================================================================================================================================================\n");
    fprintf(fp,"Nomor Kartu Keluarga : "); nomorkk1();
    fprintf(fp,"\nNama Kepala Keluarga : %s",kk.nama);
    fprintf(fp,"\nAlamat : %s",kk.alamat);
    fprintf(fp,"\nRT/RW : %s",kk.rt_rw);
    fprintf(fp,"\nKode Pos : %s",kk.kodepos);
    fprintf(fp,"\nDesa/Kelurahan : %s",kk.kel);
    fprintf(fp,"\nKecamatan : %s",kk.kec);
    fprintf(fp,"\nKabupaten/Kota : %s",kk.kab);
    fprintf(fp,"\nProvinsi : %s\n",kk.prov);
    fprintf(fp,"\nNo\tNama\t\t\tNIK\t\t\t\tJenis Kelamin\t\tTempat Lahir\t\tTanggal Lahir\t\tAgama\t\t\tPendidikan\t\t\tJenis Pekerjaan\t\tGolongan Darah");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"\n%d\t%s\t\t\t\t%s\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t%s\t\t\t\t%s\t\t%s",i+1,arrkk[i].nama,arrkk[i].nik,arrkk[i].jkelamin,arrkk[i].tmp_lahir,arrkk[i].tgl_lahir,arrkk[i].agama,arrkk[i].pendidikan,arrkk[i].pekerjaan,arrkk[i].goldar);
    }
    fprintf(fp,"\n\nNo\tStatus Perkawinan\t\t\tTanggal Perkawinan\t\tStatus Hubungan Dalam Keluarga\t\tKewarganegaraan\t\tNo. Paspor\t\tNo. KITAP\t\t\tNama Ayah\t\t\tNama Ibu");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"\n%d\t%s\t\t\t%s\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t%s\t\t%s\t\t\t%s\t\t%s",i+1,arrkk[i].status,arrkk[i].tgl_kawin,arrkk[i].peran,arrkk[i].wn,arrkk[i].paspor,arrkk[i].kitap,arrkk[i].nayah,arrkk[i].nibu);
    }
    fclose(fp);
}

int main()
{
    buatkk();
}
