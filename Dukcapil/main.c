#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Penambahan header time untuk menampilkan waktu

//Variabel Global
struct kartukeluarga
{
    char nokk[15],alamat[50],rt_rw[20],kodepos[20],kel[20],kec[20],kab[20],prov[20];
    char nama[50],nik[15],jkelamin[20],tmp_lahir[20],tgl_lahir[20],agama[20],pendidikan[20],pekerjaan[20],goldar[5];
    char status[20],tgl_kawin[20],peran[20],wn[20],paspor[20],kitap[20],nayah[50],nibu[50];
}kk,arrkk[500],temp;

struct aktakelahiran
{
    char noakta[25],tgl_lahir[20];
    char nama[50],anak[10],jkelamin[20],tmp_lahir[20],nayah[50],nibu[50];
}akl;

struct kartupenduduk
{
    char nik[25],tgl_lahir[15],rt_rw[10],kel[25],kec[30],gol[5];
    char nama[50],tmp_lahir[30],jenis[10],alamat[30],agama[10],status[15],kwg[5],pekerjaan[20];
}ktp;

struct aktakematian
{
    char noakta[25],anak[10],jkelamin[20];
    char nama[50],tmp_lahir[20],tgl_lahir[20],tmp_mati[20],tgl_mati[20],nayah[50],nibu[50];
}ak;

FILE *fp;
int i,j,n,pilih;

int main()
{
    int x,y;
    char header[]="----------- Selamat Datang di Dukcapil Assistant -----------\n\n";

    Login_Page: //set point untuk digunakan dengan fungsi goto
    for(x=0; header[x]!=NULL; x++) //algoritma untuk menampilkan tulisan bergerak
    {
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++)
        {}
    }
    printf("Silahkan Login atau Registrasi untuk melanjutkan\n");
    printf("1. Registrasi\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Pilih : ");
    scanf("%d",&pilih);
    if(pilih==1)
    {
        char pw_save[20],un_save[20];
        fp = fopen("login.txt", "a+"); //menambahkan output kedalam file yang sudah ada dan membuat baru jika belum ada
        printf("\n=======Registrasi=======\n");
        printf("Masukkan username : ");
        scanf("%s",&un_save);
        printf("Masukkan password : ");
        scanf("%s",&pw_save);
        fprintf(fp, "%s %s\n", un_save,pw_save);
        fclose(fp);
    }
    else if(pilih==2)
    {
        char password[20], username[20];
        int isLoggenin = 0;

        fp = fopen("Login.txt", "r"); //membaca isi file
        printf("\n=========Log in=========\n");
        printf("Masukkan username : ");
        scanf("%s",&username);
        printf("Masukkan password : ");
        scanf("%s",&password);
        printf("\n");
        while(!feof(fp)){ //membaca isi file hingga berhenti jika menemukan akhir dari file
            char un[20];
            char pw[20];
        fscanf(fp,"%s %s\n",un,pw);
        if(strcmp(username, un) == 0 && strcmp(password,pw) == 0){
        isLoggenin = 1;
            }
        }
        if(isLoggenin==1){
        printf("login berhasil!\n");
        }
        else{
        printf("login gagal!\n");
        system("pause");
        system("cls");
        goto Login_Page; //kembali ke tampilan awal
        }
        fclose(fp);
    }
    else return 0;

    Pilih_Layanan:
    pilih=0;
    system("pause");
    system("cls");
    printf("----------- Selamat Datang di Dukcapil Assistant -----------\n\n");
    printf("Silahkan Memilih Layanan :\n");
    printf("1. Pembuatan Kartu Keluarga\n");
    printf("2. Pembuatan Akta Kelahiran\n");
    printf("3. Pembuatan Kartu Tanda Penduduk\n");
    printf("4. Pembuatan Akta Kematian\n");
    printf("5. Pengecekan Data\n");
    printf("6. Log Out\n");
    printf("Pilih : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
        case 1:
        system("cls");
        buatkk();
        goto Pilih_Layanan;

        case 2:
        system("cls");
        buatakl();
        goto Pilih_Layanan;

        case 3:
        system("cls");
        buatktp();
        goto Pilih_Layanan;

        case 4:
        system("cls");
        buatak();
        goto Pilih_Layanan;

        case 5:
        system("cls");
        cekdata();
        goto Pilih_Layanan;

        default:
        system("cls");
        goto Login_Page;
    }
}

void nomorkk() //nomor kartu keluarga generator
{
    int Digit2;
    char digit1[10];
    char digit2[10],digit3[10];
    char randnum[10]="0123456789"; //deklarasi dan inisialisasi variabel yang akan diacak oleh program
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //digit1 berisikan 6 angka yang merupakan kode wilayah berdasarkan inputan provinsi kartu keluarga user
    if(strcmp(kk.prov,"Jawa Barat")==0) strcpy(digit1,"327322");
    else if(strcmp(kk.prov,"DKI Jakarta")==0) strcpy(digit1,"317406");
    else if(strcmp(kk.prov,"Sulawesi Selatan")==0) strcpy(digit1,"737102");
    else if(strcmp(kk.prov,"Lampung")==0) strcpy(digit1,"180319");
    else strcpy(digit1,"110321");
    //digit2 berisikan 6 angka lagi yang merupakan tanggal penginputan data (contoh 160622)
    Digit2=(tm.tm_mday*10000)+((tm.tm_mon+1)*100)+(tm.tm_year+1900-2000);
    sprintf(digit2,"%d",Digit2);
    //digit3 berisikan sisa 4 angka terakhir yang dirandom generate oleh program
    srand(time(NULL)); //fungsi untuk menyediakan seed(kombinasi) karakter yang akan terus berubah tiap waktu
    for(i=0;i<10;i++)
    {
        digit3[i]=randnum[rand()%(sizeof(randnum)-1)]; 
        //program mengisi angka secara acak yang diambil dari variabel randnum satu per satu kedalam variabel digit3
    }
    digit3[4]=0; //menetapkan jumlah karakter yang akan disimpan
    strcat(kk.nokk,digit1); //menyambungkan karakter dalam digit1 dengan kk.nokk 
    strcat(kk.nokk,digit2); //menyambungkan karakter dalam digit2 dengan kk.nokk
    strncat(kk.nokk,digit3,4); //menyambungkan karakter dalam digit3 dengan kk.nokk
    fprintf(fp,"%s\n",kk.nokk);
}

void nik() //nomor nik generator
{
    char digit1[n][10];
    char digit2[n][10],digit3[n][10],digit4[n][10];
    char randnum[10]={"0123456789"};
    char digit5[n][10];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    srand(time(NULL));
    //digit1 berisikan 6 angka kode wilayah berdasarkan inputan tempat lahir user pada kartu keluarga
    if(strcmp(arrkk[i].tmp_lahir,"Bandung")==0) strcpy(digit1[i],"327322");
    else if(strcmp(arrkk[i].tmp_lahir,"Jakarta Selatan")==0) strcpy(digit1[i],"317406");
    else if(strcmp(arrkk[i].tmp_lahir,"Makassar")==0) strcpy(digit1[i],"737102");
    else if(strcmp(arrkk[i].tmp_lahir,"Lampung")==0) strcpy(digit1[i],"180319");
    else strcpy(digit1[i],"110321");
    
    memcpy(digit2[i],arrkk[i].tgl_lahir,2);
    digit2[i][2]='\0';
     //digit2 berisikan 2 angka tanggal lahir yang diambil dari variabel tgl_lahir user (contoh 16/06/2022 diambil 16)
    memcpy(digit3[i],arrkk[i].tgl_lahir+3,2); 
    digit3[i][2]='\0';
    //digit3 berisikan 2 angka bulan lahir yang diambil dari variabel tgl_lahir user (contoh 16/06/2022 diambil 06)
    memcpy(digit4[i],arrkk[i].tgl_lahir+8,2); 
    digit4[i][2]='\0';
    //digit4 berisikan 2 angka tahun lahir yang diambil dari variabel tgl_lahir user (contoh 16/06/2022 diambil 22)


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
    int x;
    double y;
    char header[]="----------- Selamat Datang di Layanan Pembuatan Kartu Keluarga -----------";
    for(x=0; header[x]!=NULL; x++){
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    printf("\n--------------- Silahkan Untuk Mengisi Data-Data di Bawah ---------------\n\n");

    fp=fopen("Data KK.txt","a+");
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
        fgets(arrkk[i].jkelamin,20,stdin); strtok(arrkk[i].jkelamin,"\n");
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
    nomorkk();
    fprintf(fp,"%s\n",kk.nama);
    fprintf(fp,"%s\n",kk.alamat);
    fprintf(fp,"%s\n",kk.rt_rw);
    fprintf(fp,"%s\n",kk.kodepos);
    fprintf(fp,"%s\n",kk.kel);
    fprintf(fp,"%s\n",kk.kec);
    fprintf(fp,"%s\n",kk.kab);
    fprintf(fp,"%s\n\n",kk.prov);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s\n",arrkk[i].nama);
        fprintf(fp,"%s\n",arrkk[i].jkelamin);
        fprintf(fp,"%s\n",arrkk[i].tmp_lahir);
        fprintf(fp,"%s\n",arrkk[i].tgl_lahir);
        fprintf(fp,"%s\n",arrkk[i].nik);
        fprintf(fp,"%s\n",arrkk[i].agama);
        fprintf(fp,"%s\n",arrkk[i].pendidikan);
        fprintf(fp,"%s\n",arrkk[i].pekerjaan);
        fprintf(fp,"%s\n",arrkk[i].goldar);
        fprintf(fp,"%s\n",arrkk[i].status);
        fprintf(fp,"%s\n",arrkk[i].tgl_kawin);
        fprintf(fp,"%s\n",arrkk[i].peran);
        fprintf(fp,"%s\n",arrkk[i].wn);
        fprintf(fp,"%s\n",arrkk[i].paspor);
        fprintf(fp,"%s\n",arrkk[i].kitap);
        fprintf(fp,"%s\n",arrkk[i].nayah);
        fprintf(fp,"%s\n",arrkk[i].nibu);
    }
    fprintf(fp,"================================================\n");
    fclose(fp);
    printf("Data Anda Telah Disimpan\n");
}

void noakl() //nomor akta kelahiran generator
{
    int Digit3;
    char digit1[10];
    char digit2[10],digit3[10],digit4[10];
    char randnum1[10]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char randnum2[10]="0123456789";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
   
    if(strcmp(akl.tmp_lahir,"Bandung")==0) strcpy(digit1,"3273-");
    else if(strcmp(akl.tmp_lahir,"Jakarta Selatan")==0) strcpy(digit1,"3174-");
    else if(strcmp(akl.tmp_lahir,"Makassar")==0) strcpy(digit1,"7371-");
    else if(strcmp(akl.tmp_lahir,"Lampung")==0) strcpy(digit1,"1803-");
    else strcpy(digit1,"1321-");

    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        digit2[i]=randnum1[rand()%(sizeof(randnum1)-1)];
    }
    digit2[2]=0;
    strcat(digit2,"-");


    Digit3=(tm.tm_mday*1000000)+((tm.tm_mon+1)*10000)+(tm.tm_year+1900);
    sprintf(digit3,"%d",Digit3);
    strcat(digit3,"-");


    for(i=0;i<10;i++)
    {
        digit4[i]=randnum2[rand()%(sizeof(randnum2)-1)];
    }
    digit4[4]=0;
    strcat(akl.noakta,digit1);
    strcat(akl.noakta,digit2);
    strcat(akl.noakta,digit3);
    strncat(akl.noakta,digit4,4);
    fprintf(fp,"%s ",akl.noakta);

}

void buatakl()
{
    int x;
    double y;
    char header[]="----------- Selamat Datang di Layanan Pembuatan Akta Kelahiran -----------";
    for(x=0; header[x]!=NULL; x++){
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    printf("\n--------------- Silahkan Untuk Mengisi Data-Data di Bawah ---------------\n\n");

    fp=fopen("Data Akta Kelahiran.txt","a+");
    fflush(stdin);
    printf("Masukkan Nama Lengkap : ");
    fgets(akl.nama,50,stdin); strtok(akl.nama,"\n");
    fflush(stdin);
    printf("Anak Ke : ");
    fgets(akl.anak,10,stdin); strtok(akl.anak,"\n");
    fflush(stdin);
    printf("Masukkan Jenis Kelamin : ");
    fgets(akl.jkelamin,20,stdin); strtok(akl.jkelamin,"\n");
    fflush(stdin);
    printf("Masukkan Tempat Lahir : ");
    fgets(akl.tmp_lahir,20,stdin); strtok(akl.tmp_lahir,"\n");
    fflush(stdin);
    printf("Masukkan Tanggal Lahir(31/12/1990): ");
    fgets(akl.tgl_lahir,20,stdin); strtok(akl.tgl_lahir,"\n");
    fflush(stdin);
    printf("Masukkan Nama Ayah : ");
    fgets(akl.nayah,50,stdin); strtok(akl.nayah,"\n");
    fflush(stdin);
    printf("Masukkan Nama Ibu : ");
    fgets(akl.nibu,50,stdin); strtok(akl.nibu,"\n");
    fflush(stdin);

    noakl();
    fprintf(fp,"%s %s %s %s %s %s %s\n",akl.nama,akl.anak,akl.jkelamin,akl.tmp_lahir,akl.tgl_lahir,akl.nayah,akl.nibu);
    fclose(fp);
}

void buatktp(){
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
    printf("Masukkan NIK  : ");
    fgets(ktp.nik, 25, stdin);
    strtok(ktp.nik, "\n");
    fflush(stdin);
    printf("Masukkan Nama : ");
    fgets(ktp.nama, 50, stdin);
    strtok(ktp.nama, "\n");
    printf("Masukkan Tempat lahir : ");
    fgets(ktp.tmp_lahir, 30, stdin);
    strtok(ktp.tmp_lahir, "\n");
    printf("Masukkan Tanggal lahir(31/12/1990) : ");
    fgets(ktp.tgl_lahir, 15, stdin);
    strtok(ktp.tgl_lahir, "\n");
    printf("Masukkan Jenis Kelamin : ");
    fgets(ktp.jenis, 10, stdin);
    strtok(ktp.jenis, "\n");
    fflush(stdin);
    printf("Masukkan Alamat : ");
    fgets(ktp.alamat, 30, stdin);
    strtok(ktp.alamat, "\n");
    fflush(stdin);
    printf("Masukkan RT/RW : ");
    fgets(ktp.rt_rw, 10, stdin);
    strtok(ktp.rt_rw, "\n");
    fflush(stdin);
    printf("Masukkan Kel/Desa : ");
    fgets(ktp.kel, 25, stdin);
    strtok(ktp.kel, "\n");
    fflush(stdin);
    printf("Masukkan Kecamatan : ");
    fgets(ktp.kec, 30, stdin);
    strtok(ktp.kec, "\n");
    printf("Masukkan Agama : ");
    fgets(ktp.agama, 10, stdin);
    strtok(ktp.agama, "\n");
    printf("Masukkan Status Perkawinan : ");
    fgets(ktp.status, 15, stdin);
    strtok(ktp.status, "\n");
    printf("Masukkan Kewarganegaraan : ");
    fgets(ktp.kwg, 5, stdin);
    strtok(ktp.kwg, "\n");
    printf("Masukkan Pekerjaan : ");
    fgets(ktp.pekerjaan, 20, stdin);
    strtok(ktp.pekerjaan, "\n");
    printf("Masukkan Gol. Darah : ");
    fgets(ktp.gol, 5, stdin);
    strtok(ktp.gol, "\n");
    fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",ktp.nik,ktp.nama,ktp.tmp_lahir,ktp.tgl_lahir,ktp.jenis,ktp.alamat,ktp.rt_rw,ktp.kel,ktp.kec,ktp.agama,ktp.status,ktp.kwg,ktp.pekerjaan,ktp.gol);
    printf("-------- Terima Kasih Sudah Mengisi Data-Data --------\n");
    fclose(fp);
}


void buatak(){
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
    printf("Masukkan Nama : ");
    fgets(ak.nama, 50, stdin);
    strtok(ak.nama, "\n");
    fflush(stdin);
    printf("Anak ke : ");
    fgets(ak.anak, 10, stdin);
    strtok(ak.anak, "\n");
    fflush(stdin);
    printf("Masukkan Jenis Kelamin : ");
    fgets(ak.jkelamin, 20, stdin);
    strtok(ak.jkelamin, "\n");
    printf("Masukkan Tempat lahir : ");
    fgets(ak.tmp_lahir, 20, stdin);
    strtok(ak.tmp_lahir, "\n");
    printf("Masukkan Tanggal lahir(31/12/1990) : ");
    fgets(ak.tgl_lahir, 20, stdin);
    strtok(ak.tgl_lahir, "\n");
    printf("Masukkan Tempat meninggal : ");
    fgets(ak.tmp_mati, 20, stdin);
    strtok(ak.tmp_mati, "\n");
    printf("Masukkan Tanggal meninggal(31/12/1990) : ");
    fgets(ak.tgl_mati, 20, stdin);
    strtok(ak.tgl_mati, "\n");
    printf("Masukkan Nama Ayah : ");
    fgets(ak.nayah, 50, stdin);
    strtok(ak.nayah, "\n");
    printf("Masukkan Nama Ibu : ");
    fgets(ak.nibu, 50, stdin);
    strtok(ak.nibu, "\n");
    noak();
    fprintf(fp, "%s %s %s %s %s %s %s %s %s\n", ak.nama, ak.anak, ak.jkelamin, ak.tmp_lahir, ak.tgl_lahir,ak.tmp_mati,ak.tgl_mati,ak.nayah,ak.nibu);

    printf("\n\n------------------ Terima Kasih Sudah Mengisi Data-Data ------------------\n");
    fclose(fp);
}

void noak() //nomor akta kematian generator
{
    int Digit3;
    char digit1[10];
    char digit2[10],digit3[10],digit4[10];
    char randnum1[10]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char randnum2[10]="0123456789";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(strcmp(ak.tmp_mati,"Bandung")==0) strcpy(digit1,"3273-");
    else if(strcmp(ak.tmp_mati,"Jakarta Selatan")==0) strcpy(digit1,"3174-");
    else if(strcmp(ak.tmp_mati,"Makassar")==0) strcpy(digit1,"7371-");
    else if(strcmp(ak.tmp_mati,"Lampung")==0) strcpy(digit1,"1803-");
    else strcpy(digit1,"1321-");

    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        digit2[i]=randnum1[rand()%(sizeof(randnum1)-1)];
    }
    digit2[2]=0;
    strcat(digit2,"-");


    Digit3=(tm.tm_mday*1000000)+((tm.tm_mon+1)*10000)+(tm.tm_year+1900);
    sprintf(digit3,"%d",Digit3);
    strcat(digit3,"-");


    for(i=0;i<10;i++)
    {
        digit4[i]=randnum2[rand()%(sizeof(randnum2)-1)];
    }
    digit4[4]=0;
    strcat(ak.noakta,digit1);
    strcat(ak.noakta,digit2);
    strcat(ak.noakta,digit3);
    strncat(ak.noakta,digit4,4);
    fprintf(fp,"%s ",ak.noakta);

}

void cekdata()
{
    int x;
    double y;
    char header[]="----------- Selamat Datang di Layanan Pengecekan Data -----------";
    for(x=0; header[x]!=NULL; x++){
        printf("%c",header[x]);
        for(y=0; y<=33333333; y++){
      }
    }
    printf("\n--------------- Silahkan Untuk Mengisi Data-Data di Bawah ---------------\n\n");
    fflush(stdin);

    char cari[20],target[20],found;
    FILE *fp=NULL;

    pilih=0;
    n=0;
    fp=fopen("Data KTP.txt","r");
    fflush(stdin);
    printf("Masukkan NIK Yang Dicari : ");
    fgets(cari,20,stdin); strtok(cari,"\n");
    fflush(stdin);
    while(!feof(fp))
    {
        char data1[25],data2[50],data3[30],data4[15],data5[10],data6[30],data7[10],data8[25],data9[30],data10[10],data11[15],data12[5],data13[15],data14[5];
        fscanf(fp,"%s\n",data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12,data13,data14);
        if(strcmp(cari,data1)==0) found=1;
    }
    if(found==1)printf("NIK %s ditemukan\n",cari);
    else printf("NIK %s tidak ditemukan\n",cari);
    fclose(fp);
}
