#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mainbody.h"

int main()
{
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);

    List kumpulanList[2];
    List *MyList;
    List *ListTujuan;
    int pilihList;

    infotype nilai, tempNilai, jumlahMhs, nilMin;
    infonama nama, tempNama;
    address P, Prec;
    int pil = 0;
    char y = 'N';

    CreateList(&kumpulanList[0]);
    CreateList(&kumpulanList[1]);

    do {
        printf("\n===========================");
        printf("\nPilih List yang diinginkan :\n");
        printf("===========================\n");
        printf("1. List1\n");
        printf("2. List2\n");
        printf("3. Keluar\n");
        printf("Masukan Pilihan Anda : ");
        scanf("%d", &pilihList);
        
        if (pilihList == 3) {
            return 0;
        } else if (pilihList < 1 || pilihList > 3) {
            printf("Pilihan tidak valid! Silakan pilih kembali.\n");
            continue;
        }
    
        MyList = &kumpulanList[pilihList - 1];

        printf("\nList yang dipilih: List%d\n", pilihList);
        printf("========================= \n");
        PrintIsiList(*MyList);
    
        while (1) {
            printf("\nPilihlah Menu Berikut dibawah ini : \n");
            printf("1.  Tambah Awal Data                    9. Copy List \n");    
            printf("2.  Tambah Akhir Data                   10. Copy List Berdasarkan Nilai \n");
            printf("3.  Hapus Awal Data                      11. Hitung Jumlah Data \n");
            printf("4.  Hapus Akhir Data                     12. Lihat Daftar Data\n");
            printf("5.  Tambah Tengah Data                   13. Hapus Semua Data \n");
            printf("6.  Hapus Sesuai info                    14. Keluar\n");
            printf("7.  Hapus Setelah Alamat \n");
            printf("8.  Urutkan Mahasiswa\n");

            printf("\nPilihanmu : ");
            scanf("%d", &pil);
            printf("\n========================= \n");
    
            switch (pil) {
                case 1:
                    do {
                        printf("Masukan Nama : ");
                        scanf("%s", nama);
                        printf("Masukan Nilai : ");
                        scanf("%d", &nilai);
                    } while (DuplikasiCheck(*MyList, nilai, nama));
    
                    InsVFirst(MyList, nilai, nama);
                    printf("======================== \n");
                    break;
    
                case 2:
                    do {
                        printf("Masukan Nama : ");
                        scanf("%s", nama);
                        printf("Masukan Nilai : ");
                        scanf("%d", &nilai);
                    } while (DuplikasiCheck(*MyList, nilai, nama));
    
                    InsVLast(MyList, nilai, nama);
                    printf("======================== \n");
                    break;
    
                case 3:
                    DelVFirst(MyList, &tempNilai, &tempNama);
                    printf("Element Awal List Berhasil Dihapus, Nama = %s, Nilai = %d \n", tempNama, tempNilai);
                    printf("======================== \n");
                    break;
    
                case 4:
                    DelVLast(MyList, &tempNilai, &tempNama);
                    printf("Element Akhir List Berhasil Dihapus, Nama = %s, Nilai = %d \n", tempNama, tempNilai);
                    printf("======================== \n");
                    break;
    
                case 12:
                    PrintIsiList(*MyList);
                    break;
                
                case 13:
                    printf("Apakah yakin ingin menghapus semua element List? Y/N \n");
                    scanf(" %c", &y);
                    if (y == 'Y' || y == 'y') {
                        DelAll(MyList);
                    }
                    break;
                
                case 14:
                    printf("Kembali ke pemilihan List.\n");
                    printf("========================\n");
                    break;
                
                default:
                    printf("Pilihan tidak valid!\n");
                    break;
            }
    
            if (pil == 14) break;
        }
    } while (1);    
    
    return 0;
}
