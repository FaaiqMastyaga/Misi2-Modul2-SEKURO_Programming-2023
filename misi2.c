#include <stdio.h>
#include <stdlib.h>

void seller_view();
void customer_view();
void show_menu(int *id_menu, char (*nama_menu)[10], char (*kategori_menu)[10], int *harga_menu);

int main(){
    int buka;
    int aksi;
    char nama;
    int id_menu[10] = {1,2,3,4,5,6,7,8,9,10};
    char nama_menu[10][10] = {"Onigiri","Sake","Ramen","Dorayaki","Ocha","Sushi","Susu","Katsu","Miso","Matcha",};
    char kategori_menu[10][10] = {"Makanan","Minuman","Makanan","Makanan","Minuman","Makanan","Minuman","Makanan","Makanan","Minuman"};
    int harga_menu[10] = {7000, 10000, 15000, 5000, 8000, 6000, 8000, 20000, 18000, 10000};

    do{
        seller_view();
        scanf("%d", &buka);
        if(buka == 2){
            // menutup warung
            // klik enter
            // clear terminal
            break;
        }else if(buka != 1){
            printf("Pilihan tidak tersedia.\n"
            "Klik enter untuk kembali");
            // clear terminal
            continue;
        }
        scanf("%[^\n]", &nama);
        do{
            customer_view();
            scanf("%d", &aksi);
            switch(aksi){
                case 1:
                    printf("\n-----------------------------------------------------\n\n"
                        "Menampilkan menu\n");
                    show_menu(id_menu, nama_menu, kategori_menu, harga_menu);
                    printf("Klik enter untuk kembali");
                    getch();
                    system("cls");
                    break;
                case 2:
                    // beli makanan/minuman
                    // masukkan id menu --> masukkan id dan nama menu ke array pelanggan
                    // masukkan jumlah --> masukkan ke array pelanggan
                    // lakukan operasi perhitungan harga --> masukkan ke array pelanggan
                    break;
                case 3:
                    // keluar dari warung
                    break;
                default:
                    printf("Pilihan tidak tersedia.\n"
                    "Klik enter untuk kembali");
            }
        }while(aksi != 3);
    }while(buka != 2);
    // warung tutup
    // tampilkan riwayat penjualan hari ini (sejak program dijalankan)
    return 0;
}

void seller_view(){
    printf("Halo Kang Roger! Silakan pilih salah satu opsi berikut:\n"
    "1. Buka warung (pelanggan masuk)\n"
    "2. Tutup warung (menampilkan riwayat penjualan sejak warung dibuka terakhir kali)\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void customer_view(){
    printf("Halo {nama_pelanggan}! Silakan pilih salah satu opsi berikut:\n"
    "1. Lihat menu\n"
    "2. Beli makanan/minuman\n"
    "3. Keluar dari warung\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void show_menu(int *id_menu, char (*nama_menu)[10], char (*kategori_menu)[10], int *harga_menu){
    printf(
        "===============================================\n"
        "|| ID || Menu       || Kategori || Harga     ||\n"
        "===============================================\n");
    for(int i = 0; i < 10; i++){
        printf("|| %-2d |", *(id_menu+i));
        printf("| %-10s |", *(nama_menu+i));
        printf("| %-8s |", *(kategori_menu+i));
        printf("| Rp%-7d ||\n", *(harga_menu+i));
    }
    printf("===============================================\n");
}