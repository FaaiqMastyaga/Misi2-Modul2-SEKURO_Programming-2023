#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 4096

void seller_view();
void customer_view();
void show_menu(int *id_menu, char (*nama_menu)[10], char (*kategori_menu)[10], int *harga_menu);
int processing_transaction(int id, int jumlah, int *id_menu, char (*nama_menu)[10], char *kategori_menu[10], int *harga_menu);

int main(){
    // variabel array untuk menu
    int id_menu[10] = {1,2,3,4,5,6,7,8,9,10};
    char nama_menu[10][10] = {"Onigiri","Sake","Ramen","Dorayaki","Ocha","Sushi","Susu","Katsu","Miso","Matcha",};
    char kategori_menu[10][10] = {"Makanan","Minuman","Makanan","Makanan","Minuman","Makanan","Minuman","Makanan","Makanan","Minuman"};
    int harga_menu[10] = {7000, 10000, 15000, 5000, 8000, 6000, 8000, 20000, 18000, 10000};

    // variabel array untuk riwayat transaksi
    int total_transaksi = 0;
    char **riwayat_nama = malloc((total_transaksi+1) * sizeof(char*));
    int *riwayat_id = malloc((total_transaksi+1) * sizeof(int*));
    char **riwayat_menu = malloc((total_transaksi+1) * sizeof(char*));
    int *riwayat_jumlah = malloc((total_transaksi+1) * sizeof(int*));
    int *riwayat_harga = malloc((total_transaksi+1) * sizeof(int*));
    
    // inisiasi variabel lain
    int buka;
    int aksi;
    int jumlah;

    char nama[BUFFER_SIZE];
    int panjang_nama = 0;

    int id;

    do{
        seller_view();
        scanf("%d", &buka);
        if(buka == 2){
            // menutup warung
            break;
        }else if(buka != 1){
            printf("\nPilihan tidak tersedia.\n");
            continue;
        }

        printf("-------------------------------------------------\n"
        "Masukkan nama Anda: ");
        scanf(" %[^\n]", &nama);
        // fgets(nama, BUFFER_SIZE, stdin);
        panjang_nama = strlen(nama);
        do{
            customer_view();
            scanf("%d", &aksi);
            switch(aksi){
                case 1: /*lihat menu*/
                    show_menu(id_menu, nama_menu, kategori_menu, harga_menu);
                    break;
                case 2: /*beli makanan minuman*/
                    total_transaksi ++;
                    riwayat_nama = realloc(riwayat_nama, (total_transaksi+1) * sizeof(char*));
                    riwayat_nama[total_transaksi] = malloc(panjang_nama * sizeof(char*));

                    strcpy(riwayat_nama[total_transaksi], nama);
                    printf("-------------------------------------------------\n");
                    printf("Masukkan id menu : ");
                    scanf("%d", &id);
                    printf("Masukkan jumlah yang ingin dibeli : ");
                    scanf("%d", &jumlah);

                    int harga = processing_transaction(id, jumlah, id_menu, nama_menu, kategori_menu, harga_menu);
                    printf("Total harga = %d", harga);

                    printf("\nPermintaan Anda sedang diproses\n");
                    

                    // masukkan id menu --> masukkan id dan nama menu ke array pelanggan
                    // masukkan jumlah --> masukkan ke array pelanggan
                    // lakukan operasi perhitungan harga --> masukkan ke array pelanggan

                    break;
                case 3: /*keluar dari warung*/
                    break;
                default:
                    printf("Pilihan tidak tersedia.\n");
            }
        }while(aksi != 3);
    }while(buka != 2);
    // warung tutup
    // tampilkan riwayat penjualan hari ini (sejak program dijalankan)
    return 0;
}

void seller_view(){
    printf("-------------------------------------------------\n"
    "Halo Kang Roger!\nSilakan pilih salah satu opsi berikut:\n"
    "1. Buka warung (pelanggan masuk)\n"
    "2. Tutup warung (menampilkan riwayat penjualan)\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void customer_view(){
    printf("-------------------------------------------------\n"
    "Silakan pilih salah satu opsi berikut:\n"
    "1. Lihat menu\n"
    "2. Beli makanan/minuman\n"
    "3. Keluar dari warung\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void show_menu(int *id_menu, char (*nama_menu)[10], char (*kategori_menu)[10], int *harga_menu){
    printf("-----------------------------------------------\n"
        "Menampilkan menu\n\n"
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
    printf("\nKembali ke pilihan awal\n");
}

int processing_transaction(int id, int jumlah, int *id_menu, char (*nama_menu)[10], char *kategori_menu[10], int *harga_menu){
    for(int i = 0; i < 10; i++){
        if(id == *(id_menu+i)){
            int harga;
            return (jumlah)*(*(harga_menu+i));
        }
    }
}