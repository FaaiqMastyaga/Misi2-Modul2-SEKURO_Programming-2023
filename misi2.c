#include <stdio.h>

void buka_warung();

int main(){
    int buka;
    
    do{
        buka_warung();
        scanf("%d", &buka);
        if(buka == 2){
            // menutup warung
            // klik enter
            // clear terminal
            break;
        }else if(buka != 1){
            // pilihan tidak tersedia;
            // klik enter
            // clear terminal
            continue;
        }

    }while(buka != 2);

    return 0;
}

void buka_warung(){
    printf("Halo Kang Roger! Silakan pilih salah satu opsi berikut:\n"
    "1. Buka warung (pelanggan masuk)\n"
    "2. Tutup warung (menampilkan riwayat penjualan sejak warung dibuka terakhir kali)\n"
    "Masukkan nomor sesuai dengan pilihan Anda: ");
}