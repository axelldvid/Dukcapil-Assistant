#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct kartukeluarga
{
    char nokk[15],alamat[50],rt_rw[20],kodepos[20],kel[20],kec[20],kab[20],prov[20];
    char nama[50],nik[15],jkelamin[10],tmp_lahir[20],tgl_lahir[20],agama[20],pendidikan[20],pekerjaan[20],goldar[5];
    char status[20],tgl_kawin[20],peran[20],wn[20],paspor[20],kitap[20],nayah[50],nibu[50];
}kk,arrkk[500],temp;

FILE *fp;
int i,j,n=2,pilih;
char nokk[20],nama[50], alamat[30], tgl_lahir[15], tmp_lahir[30], status[15], pekerjaan[25];

void login()
{
    char pw_save[20],un_save[20];
    int isLoggenin = 0;

    fp = fopen("login.txt", "a+");
    printf("=======Registrasi=======\n");
    printf("Masukkan NIK : ");
    scanf("%s",&un_save);
    fprintf(fp, "%s\n", un_save);
    fclose(fp);
    fp = fopen("Login.txt", "r");
    char password[20], username[20];
    printf("=========Log in=========\n");
    printf("Masukkan NIK : ");
    scanf("%s",&username);
    while(!feof(fp)){
    char un[20];
    fscanf(fp,"%s\n",un);
     if(strcmp(username, un) == 0)
       isLoggenin = 1;
    }
     if(isLoggenin==1){
       printf("login berhasil!");
     }
      else{
       printf("login gagal!");
      }
    fclose(fp);
}
void nomorkk()
{
    int Digit2;
    char digit1[10];
    char digit2[10],digit3[10];
    char randnum[10]="0123456789";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(strcmp(kk.prov,"Jawa Barat")==0) strcpy(digit1,"327322");
    else if(strcmp(kk.prov,"DKI Jakarta")==0) strcpy(digit1,"317406");
    else if(strcmp(kk.prov,"Sulawesi Selatan")==0) strcpy(digit1,"737102");
    else if(strcmp(kk.prov,"Lampung")==0) strcpy(digit1,"180319");
    else strcpy(digit1,"110321");

    Digit2=(tm.tm_mday*10000)+((tm.tm_mon+1)*100)+(tm.tm_year+1900-2000);
    sprintf(digit2,"%d",Digit2);

    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        digit3[i]=randnum[rand()%(sizeof(randnum)-1)];
    }
    digit3[5]=0;
    strcat(kk.nokk,digit1);
    strcat(kk.nokk,digit2);
    strncat(kk.nokk,digit3,5);
    fprintf(fp,"%s",kk.nokk);
}

void nik()
{
    char digit1[n][10];
    char digit2[n][10],digit3[n][10],digit4[n][10];
    char randnum[10]={"0123456789"};
    char digit5[n][10];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    srand(time(NULL));

    if(strcmp(kk.prov,"Jawa Barat")==0) strcpy(digit1[i],"327322");
    else if(strcmp(kk.prov,"DKI Jakarta")==0) strcpy(digit1[i],"317406");
    else if(strcmp(kk.prov,"Sulawesi Selatan")==0) strcpy(digit1[i],"737102");
    else if(strcmp(kk.prov,"Lampung")==0) strcpy(digit1[i],"180319");
    else strcpy(digit1[i],"110321");

    memcpy(digit2[i],arrkk[i].tgl_lahir,2);
    digit2[i][2]='\0';
    memcpy(digit3[i],arrkk[i].tgl_lahir+3,2);
    digit3[i][2]='\0';
    memcpy(digit4[i],arrkk[i].tgl_lahir+8,2);
    digit4[i][2]='\0';


    for(j=0;j<10;j++)
    {
        digit5[i][j]=randnum[rand()%(sizeof(randnum)-1)];
    }
    digit5[i][4]=0;
    strcat(arrkk[i].nik,digit1[i]);
    strcat(arrkk[i].nik,digit2[i]);
    strcat(arrkk[i].nik,digit3[i]);
    strcat(arrkk[i].nik,digit4[i]);
    strncat(arrkk[i].nik,digit5[i],4);
    printf("%s\n",arrkk[i].nik);
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
        printf("Masukkan Jenis Kelamin : ");
        fgets(arrkk[i].jkelamin,10,stdin); strtok(arrkk[i].jkelamin,"\n");
        fflush(stdin);
        printf("Masukkan Tempat Lahir : ");
        fgets(arrkk[i].tmp_lahir,20,stdin); strtok(arrkk[i].tmp_lahir,"\n");
        fflush(stdin);
        printf("Masukkan Tanggal Lahir(31/12/1990) : ");
        fgets(arrkk[i].tgl_lahir,20,stdin); strtok(arrkk[i].tgl_lahir,"\n");
        fflush(stdin);
        printf("Masukkan NIK : "); nik();
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
    fprintf(fp,"Nomor Kartu Keluarga\t\t\t: "); nomorkk();
    fprintf(fp,"\nNama Kepala Keluarga\t\t\t: %s",kk.nama);
    fprintf(fp,"\nAlamat\t\t\t\t\t: %s",kk.alamat);
    fprintf(fp,"\nRT/RW\t\t\t\t\t\t: %s",kk.rt_rw);
    fprintf(fp,"\nKode Pos\t\t\t\t\t: %s",kk.kodepos);
    fprintf(fp,"\nDesa/Kelurahan\t\t\t\t: %s",kk.kel);
    fprintf(fp,"\nKecamatan\t\t\t\t\t: %s",kk.kec);
    fprintf(fp,"\nKabupaten/Kota\t\t\t\t: %s",kk.kab);
    fprintf(fp,"\nProvinsi\t\t\t\t\t: %s",kk.prov);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"\n\nAnggota Keluarga %d",i+1);
        fprintf(fp,"\nNama Lengkap\t\t\t\t: %s",arrkk[i].nama);
        fprintf(fp,"\nJenis Kelamin\t\t\t\t: %s",arrkk[i].jkelamin);
        fprintf(fp,"\nTempat Lahir\t\t\t\t: %s",arrkk[i].tmp_lahir);
        fprintf(fp,"\nTanggal Lahir\t\t\t\t: %s",arrkk[i].tgl_lahir);
        fprintf(fp,"\nNIK\t\t\t\t\t\t: %s",arrkk[i].nik);
        fprintf(fp,"\nAgama\t\t\t\t\t\t: %s",arrkk[i].agama);
        fprintf(fp,"\nPendidikan\t\t\t\t\t: %s",arrkk[i].pendidikan);
        fprintf(fp,"\nJenis Pekerjaan\t\t\t\t: %s",arrkk[i].pekerjaan);
        fprintf(fp,"\nGolongan Darah\t\t\t\t: %s",arrkk[i].goldar);
        fprintf(fp,"\nStatus Perkawinan\t\t\t\t: %s",arrkk[i].status);
        fprintf(fp,"\nTanggal Perkawinan\t\t\t: %s",arrkk[i].tgl_kawin);
        fprintf(fp,"\nStatus Hubungan Dalam Keluarga\t: %s",arrkk[i].peran);
        fprintf(fp,"\nKewarganegaraan\t\t\t\t: %s",arrkk[i].wn);
        fprintf(fp,"\nDokumen Imigrasi");
        fprintf(fp,"\n\tNo. Paspor\t\t\t\t: %s",arrkk[i].paspor);
        fprintf(fp,"\n\tNo. KITAP\t\t\t\t: %s",arrkk[i].kitap);
        fprintf(fp,"\nNama Orang Tua");
        fprintf(fp,"\n\tNama Ayah\t\t\t\t: %s",arrkk[i].nayah);
        fprintf(fp,"\n\tNama Ibu\t\t\t\t: %s",arrkk[i].nibu);
    }
    fprintf(fp,"\n=============================================================================================================================================================\n");
    fclose(fp);
    system("pause"); system("cls");
    printf("Data Anda Telah Disimpan\n");
}

void ktp(){
    char nik[25], rt_rw[10], kel[25], kec[25], kwg[5], agama[10], gol[2], jenis[10];
    int x;
    double y;
    char header[]="----------- Selamat Datang di Layanan KTP -----------";

    fp = fopen("Data Ktp.txt", "a+");
    for(x=0; header[x]!=NULL; x++){
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    printf("\n----- Silahkan Untuk Mengisi Data-Data di Bawah -----\n");
    fflush(stdin);
    printf("NIK\t\t  : ");
    fgets(nik, 25, stdin);
    strtok(nik, "\n");
    fflush(stdin);
    printf("Nama\t\t  : ");
    fgets(nama, 50, stdin);
    strtok(nama, "\n");
    printf("Tempat lahir\t  : ");
    fgets(tmp_lahir, 30, stdin);
    strtok(tmp_lahir, "\n");
    printf("Tanggal lahir\t  : ");
    fgets(tgl_lahir, 15, stdin);
    strtok(tgl_lahir, "\n");
    printf("Jenis Kelamin\t  : ");
    fgets(jenis, 10, stdin);
    strtok(jenis, "\n");
    fflush(stdin);
    printf("Alamat\t\t  : ");
    fgets(alamat, 30, stdin);
    strtok(alamat, "\n");
    fflush(stdin);
    printf("RT/RW\t\t  : ");
    fgets(rt_rw, 10, stdin);
    strtok(rt_rw, "\n");
    printf("Kel/Desa\t  : ");
    fgets(kel, 25, stdin);
    strtok(kel, "\n");
    printf("Kecamatan\t  : ");
    fgets(kec, 30, stdin);
    strtok(kec, "\n");
    printf("Agama\t\t  : ");
    fgets(agama, 10, stdin);
    strtok(agama, "\n");
    printf("Status Perkawinan : ");
    fgets(status, 15, stdin);
    strtok(status, "\n");
    printf("Kewarganegaraan\t  : ");
    fgets(kwg, 5, stdin);
    strtok(kwg, "\n");
    printf("Pekerjaan\t  : ");
    fgets(pekerjaan, 15, stdin);
    strtok(pekerjaan, "\n");
    printf("Gol. Darah\t  : ");
    fgets(gol, 2, stdin);
    strtok(gol, "\n");
    fprintf(fp, "=====================================================\n");
    fprintf(fp, "NIK\t\t  : %s\nNama\t\t  : %s\nTempat lahir\t  : %s\n", nik, nama, tmp_lahir);
    fprintf(fp, "Tanggal lahir\t  : %s\nJenis Kelamin\t  : %s\nAlamat\t\t  : %s\n", tgl_lahir, jenis, alamat);
    fprintf(fp, "RT/RW\t\t  : %s\nKel/Desa\t  : %s\nKecamatan\t  : %s\nAgama\t\t  : %s\nStatus Perkawinan : %s\n", rt_rw, kel, kec, agama, status);
    fprintf(fp, "Kewarganegaraan\t  : %s\nPekerjaan\t  : %s\nGol. Darah\t  : %s\n", kwg, pekerjaan, gol);
    fprintf(fp, "=====================================================\n\n");

    printf("-------- Terima Kasih Sudah Mengisi Data-Data --------\n");
    fclose(fp);
}

void ak(){
    char nama[50], tempat[30], tanggal[30], tahun[20], tgllahir[60], alamatlengkap[100];
    int x;
    double y;
    char header[]="----------- Selamat Datang di Layanan Pembuatan Akta Kematian -----------";

    fp = fopen("Data Akta Kematian.txt", "a+");
    for(x=0; header[x]!=NULL; x++){
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    printf("\n--------------- Silahkan Untuk Mengisi Data-Data di Bawah ---------------\n\n");
    fflush(stdin);
    printf("Nama\t\t\t  : ");
    fgets(nama, 50, stdin);
    strtok(nama, "\n");
    fflush(stdin);
    printf("Tempat lahir\t\t  : ");
    fgets(tmp_lahir, 30, stdin);
    strtok(tmp_lahir, "\n");
    printf("Tanggal lahir(huruf)\t  : ");
    fgets(tgllahir, 60, stdin);
    strtok(tgllahir, "\n");
    printf("Tempat meninggal\t  : ");
    fgets(tempat, 30, stdin);
    strtok(tempat, "\n");
    printf("Tanggal meninggal(huruf)  : ");
    fgets(tanggal, 30, stdin);
    strtok(tanggal, "\n");
    printf("tahun meninggal(huruf)\t  : ");
    fgets(tahun, 20, stdin);
    strtok(tahun, "\n");
    fflush(stdin);
    printf("Alamat Lengkap\t\t  : ");
    fgets(alamatlengkap, 100, stdin);
    strtok(alamatlengkap, "\n");
    fprintf(fp, "====================================================================\n");
    fprintf(fp, "Nama\t\t  : %s\nTempat lahir\t  : %s\nTanggal lahir\t  : %s\n", nama, tmp_lahir, tgllahir);
    fprintf(fp, "Tempat Meninggal  : %s\nTanggal Meninggal : %s\n", tempat, tanggal, tahun);
    fprintf(fp, "Tahun Meninggal\t  : %s\nAlamat Meninggal  : %s\n", tahun, alamatlengkap);
    fprintf(fp, "====================================================================\n\n");

    printf("\n\n------------------ Terima Kasih Sudah Mengisi Data-Data ------------------\n");
    fclose(fp);
}

void pd(){
    int x;
    double y;
    char header1[]="----------- Mohon Maaf Layanan Pencarian Data Dalam Perbaikan -----------\n";
    char header2[]="----------------------------- Terima Kasih ------------------------------\n";
    for(x=0; header1[x]!=NULL; x++){
        printf("%c",header1[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    for(x=0; header2[x]!=NULL; x++){
        printf("%c",header2[x]);
        for(y=0; y<=33333333; y++){
      }
    }
}

int main()
{
    login();
    Pilih_Layanan:
    system("pause");
    system("cls");
    printf("Silahkan Memilih Layanan :\n");
    printf("1. Pembuatan Kartu Keluarga\n");
    printf("2. Pembuatan Akta Kelahiran\n");
    printf("3. Pembuatan Kartu Tanda Penduduk\n");
    printf("4. Pembuatan Surat Kematian\n");
    printf("5. Pengecekan Data\n");
    printf("6. Exit\n");
    printf("Pilih : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
        case 1:
        system("cls");
        buatkk();
        goto Pilih_Layanan;

        case 2:
        //Program Pembuatan Akta
        goto Pilih_Layanan;

        case 3:
        system("cls");
        ktp();
        goto Pilih_Layanan;

        case 4:
        system("cls");
        ak();
        goto Pilih_Layanan;

        case 5:
        system("cls");
        pd();
        goto Pilih_Layanan;

        case 6:
        system("cls");
        break;
    }
}
