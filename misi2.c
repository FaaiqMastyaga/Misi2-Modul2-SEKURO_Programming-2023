#include <stdio.h>

void buka_warung();
void mau_apa();
void tampilkan_menu();

int main(){
    int buka;
    int aksi;
    // buat variabel array untuk menyimpan menu
    
    do{
        buka_warung();
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
        // input nama pelanggan --> masukkan ke array pelanggan
        do{
            mau_apa();
            scanf("%d", &aksi);
            switch(aksi){
                case 1:
                    // lihat menu
                    tampilkan_menu();
                    printf("Klik enter untuk kembali");
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

void buka_warung(){
    printf("Halo Kang Roger! Silakan pilih salah satu opsi berikut:\n"
    "1. Buka warung (pelanggan masuk)\n"
    "2. Tutup warung (menampilkan riwayat penjualan sejak warung dibuka terakhir kali)\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void mau_apa(){
    printf("Halo {nama_pelanggan}! Silakan pilih salah satu opsi berikut:\n"
    "1. Lihat menu\n"
    "2. Beli makanan/minuman\n"
    "3. Keluar dari warung\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}

void tampilkan_menu(/*parameter menu berupa array*/){
    // gunakan perulangan untuk menampilkan elemen2 array : ID menu, nama menu, tipe menu (makanan/minuman), harga
}