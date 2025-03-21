#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "header/mainbody.h"

int main()
{
	// kamus data
	List L1, L2;
    CreateList(&L1);
    CreateList(&L2);

    List kumpulanList[2];
	List *MyList;
	List *ListTujuan;
    int pilihList, subPil;

	infotype nilai, tempNilai, jumlahMhs, nilMin;
	infonama nama, tempNama;
	address P, Prec;
	int pil = 0;
	char y = 'N';

	

	/* Program */
    CreateList(&kumpulanList[0]);
    CreateList(&kumpulanList[1]);
	


	do {
		printf("\n===========================");
		printf("\nPilih List yang diinginkan :\n");
		printf("===========================\n");
		printf("1. List 1\n");
		printf("2. List 2\n");
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
            printf("1.  Tambah Awal Data                   9. Copy List Data\n");    
            printf("2.  Tambah Akhir Data                  10. Hitung Jumlah Data \n");
            printf("3.  Hapus Awal Data                    11. Print List\n");
            printf("4.  Hapus Akhir Data                   12. Hapus Semua Data\n");
            printf("5.  Tambah Tengah Data                 13. Pilih List Lain \n");
            printf("6.  Hapus Sesuai Data   \n");
            printf("7.  Hapus After Data  \n");
            printf("8.  Urutkan Mahasiswa\n");

			printf("\nPilihan yang diinginkan : ");
			scanf("%d", &pil);
			printf("\n========================= \n");
	
			switch (pil) {
				case 1:
					do {
						printf("Masukan Nama : ");
						scanf("%s", &nama);
						printf("Masukan Nilai : ");
						scanf("%d", &nilai);
					} while (DuplikasiCheck(*MyList, nilai, nama));
		
					InsVFirst(MyList, nilai, nama);
					printf("======================== \n");
		
					break;
				case 2:
					do {
						printf("Masukan Nama : ");
						scanf("%s", &nama);
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
				case 5:
					PrintIsiList(*MyList);
					printf("Masukan Info Element Beforenya : \n");
					printf("Nama : ");
					scanf("%s", &tempNama);
					printf("Nilai : ");
					scanf("%d", &tempNilai);
		
					Prec = SearchSpec(*MyList, tempNilai, tempNama);
		
					if(Prec == Nil){
						printf("Element Tidak Ditemukan! \n");
						break;	
					}
		
					do {
						printf("======================== \n");
						printf("Masukan Isi Element Baru: \n");
						printf("Nama : ");
						scanf("%s", &nama);
						printf("Nilai : ");
						scanf("%d", &nilai);
					} while (DuplikasiCheck(*MyList, nilai, nama));
		
					P = Alokasi(nama, nilai);
		
					InsertAfter(MyList, P, Prec);
					printf("======================== \n");
		
					break;
				case 6:
					PrintIsiList(*MyList);
					printf("Masukan Element yang akan Dihapus : \n");
					printf("Nama : ");
					scanf("%s", &nama);
					printf("Nilai : ");
					scanf("%d", &nilai);
		
					DelP(MyList, nilai, nama);
					printf("Element Berhasil Dihapus!\n");
					printf("======================== \n");
		
					break;
				case 7:
					PrintIsiList(*MyList);
					printf("Masukan Element before yang akan Dihapus : \n");
					printf("Nama : ");
					scanf("%s", &nama);
					printf("Nilai : ");
					scanf("%d", &nilai);
		
					Prec = SearchSpec(*MyList, nilai, nama);
		
					DelAfter(MyList, &tempNilai, &tempNama, Prec);
					printf("Element After Berhasil Dihapus, Nama = %s, Nilai = %d \n", tempNama, tempNilai);
					printf("======================== \n");
		
					break;
				case 8:
					printf("Urutan Mahasiswa\n");
					printf("1. Berdasarkan Nama\n");
					printf("2. Berdasarkan Nilai\n");
					printf("Pilih: ");
					scanf("%d", &pil);

				if (pil == 1) {
					printf("Pilih Urutan:\n");
					printf("1. Ascending\n");
					printf("2. Descending\n");
					printf("Pilih: ");
					scanf("%d", &pil);

					if (pil == 1) {
						printf("Urutkan Berdasarkan Nama (Ascending)\n");
						printf("======================== \n");
						SortListByName(MyList, 1); // Perbaikan dengan fungsi sorting khusus
						PrintIsiList(*MyList);
					} else if (pil == 2) {
						printf("Urutkan Berdasarkan Nama (Descending)\n");
						printf("======================== \n");
						SortListByName(MyList, 0); // Perbaikan dengan fungsi sorting khusus
						PrintIsiList(*MyList);
					} else {
						printf("Pilihan tidak valid!\n");
					}
				}else if (pil == 2) {
					printf("Pilih Urutan:\n");
					printf("1. Ascending\n");
					printf("2. Descending\n");
					printf("Pilih: ");
					scanf("%d", &pil);
			
					if (pil == 1) {
						printf("Urutkan Berdasarkan Nilai (Ascending)\n");
						printf("======================== \n");
						SortListByScore(MyList, 1); // Fungsi sorting berdasarkan nilai
						PrintIsiList(*MyList);
					} else if (pil == 2) {
						printf("Urutkan Berdasarkan Nilai (Descending)\n");
						printf("======================== \n");
						SortListByScore(MyList, 0); // Fungsi sorting berdasarkan nilai
						PrintIsiList(*MyList);
					} else {
						printf("Pilihan tidak valid!\n");
					}
				} else {
					printf("Pilihan tidak valid!\n");
				}
					break;
			
				case 9:
				printf("\nPilih List Tujuan : \n");
				printf("1. List1\n");
				printf("2. List2\n");
				printf("Pilihanmu : ");
				scanf("%d", &pilihList);
				
				printf("\n======================== \n");
				printf("Peringatan!, Isi List Tujuan Akan Otomatis Terganti!\n");
				printf("Apakah yakin ingin melanjutkan? Y/N \n");
				scanf(" %c", &y);
				
				if (y == 'Y' || y == 'y') {
					ListTujuan = &kumpulanList[pilihList - 1];
					printf("\nPilih metode copy:\n");
					printf("1. Copy List secara keseluruhan\n");
					printf("2. Copy List berdasarkan nilai minimum\n");
					printf("Pilihanmu : ");
					scanf("%d", &subPil);
					
					if (subPil == 1) {
						CopyList(*MyList, ListTujuan);
					} else if (subPil == 2) {
						printf("Masukkan Nilai Minimum: ");
						scanf("%d", &nilMin);
						CopyListNilai(*MyList, ListTujuan, nilMin);
					} else {
						printf("Pilihan tidak valid!\n");
					}
				}

					break;
				
				case 10:
					jumlahMhs = HitungElement(*MyList);
					printf("Jumlah Mahasiswa Sebanyak : %d orang\n", jumlahMhs);
					printf("======================== \n");
		
					break;
				case 11:
					PrintIsiList(*MyList);
		
					break;
				case 12:
					printf("Apakah yakin ingin menghapus semua element List? Y/N \n");
					scanf("%s", &y);
					if(y == 'Y' || y == 'y'){
						DelAll(MyList);
					}else {
						break;
					}
		
					break;
			
				case 13:

					break;
				default:
					printf("Pilihan tidak valid!\n");
			}
	
			if (pil == 13) break;
		}
	} while (1);	
    
	return 0;
}