#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "../header/mainbody.h"

// prosedur membuat list
void CreateList (List *L) 
{
    First(*L) = Nil;
}

// function alokasi mengembalikan addrress yang sudah dialokasi
address Alokasi (infonama nama, infotype nilai)
{
	address P;
	
	P = (address) malloc (sizeof (NodeMahasiswa));

	if (P != Nil) {
        strcpy(Nama(P), nama);
		Nilai(P) = nilai;
		Next(P) = Nil;
	}
	return (P);
}

// prosedur dealokasi
void DeAlokasi (address P)
{
	if (P != Nil)
	{
		free (P);
	}
}

// function overflow dan underflow check
boolean UnderAndOverflowCheck(address P)
{
    if(P == Nil){
        return true;
    } else {
        return false;
    }
}

// function duplikasi check
boolean DuplikasiCheck(List L, infotype X, infonama nama)
{
    address P;
    boolean found =  false;
    
    P = First(L);
    while ((P != Nil) && (!found))
    {
        if (Nilai(P) == X && strcmp(Nama(P), nama) == 0 || strcmp(Nama(P), nama) == 0){	
            found = true;
            printf("========================\n");
            printf("== Element Sudah Ada! ==\n");
            printf("========================\n");
        }
        else{	
            P = Next(P);	
        }
    }
    
    return (found);
}

// function search spesifik mengembalikan address yang dicari
address SearchSpec (List L, infotype X, infonama nama)
{
	address P;
	boolean found =  false;
    
	P = First(L);
	while ((P != Nil) && (!found))
	{
		if (Nilai(P) == X && strcmp(Nama(P), nama) == 0){	
            found = true; 	
        }
		else{	
            P = Next(P);	
        }
	}
	
	return (P);
}

// function search predecessor spesifik mengembalikan address sebelum address yang dicari
address SearchPrecSpec (List L, infotype X, infonama nama)
{
	address Prec, P;
	boolean found=false;

	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		if (Nilai(P) == X && strcmp(Nama(P), nama) == 0){	
            found = true;	
        }
		else
		{
            Prec = P;
            P = Next(P);
		}
	}
	if (found) {	
        return (Prec);		
    } 
    else {	
        return (Nil);
    }
}

// prosedur insert first mengalokasikan dulu
void InsVFirst (List * L, infotype nilai, infonama nama)
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Alokasi(nama, nilai);

	if(!UnderAndOverflowCheck(P)){
        InsertFirst(L, P);
	}
}

// prosedur insert last mengalokasikan dulu
void InsVLast (List * L, infotype nilai, infonama nama)
{
	address P;
	
	P = Alokasi(nama, nilai);

    if(!UnderAndOverflowCheck(P)){
        InsertLast(L, P);
	}
}

// prosedur insert first berdasarkan address
void InsertFirst (List * L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

// prosedur insert last berdasarkan address
void InsertLast (List * L, address P)
{
	address Last;

	Last = First(*L);

	while (Next(Last) != Nil)
	{
		Last = Next(Last);
	}

	Next(Last) = P;
}

// prosedur delete first mengembalikan nilai dan nama yang dihapus
void DelVFirst (List * L, infotype * X, infonama * nama)
{
    address P;

    DelFirst(L, &P);

    if(!UnderAndOverflowCheck(P)){
        *X = Nilai(P);
        strcpy(*nama, Nama(P));
        DeAlokasi(P);
    }
}

// prosedur delete first berdasarkan address mengembalikan address yang dihapus
void DelFirst (List * L, address * P)
{
	address temp;

	temp = First(*L);
	if(!UnderAndOverflowCheck(temp)){
		(*P) = Alokasi(Nama(temp), Nilai(temp));

		First(*L) = Next(temp);
		DeAlokasi(temp);
	}
}

// prosedur delete last mengembalikan nilai dan nama yang dihapus
void DelVLast (List * L, infotype * nilai, infonama * nama)
{
    address P;

    DelLast(L, &P);

    if(!UnderAndOverflowCheck(P)){
        *nilai = Nilai(P);
        strcpy(*nama, Nama(P));
        DeAlokasi(P);
    }
}

// prosedur delete last berdasarkan address mengembalikan address yang dihapus
void DelLast (List * L, address * P)
{
	address Prec, temp;

	temp = First(*L);

	while (Next(temp) != Nil)
	{
		temp = Next(temp);
	}

	Prec = SearchPrecSpec((*L), Nilai(temp), Nama(temp));

	if(!UnderAndOverflowCheck(temp)){
		(*P) = Alokasi(Nama(temp), Nilai(temp));

		Next(Prec) = Nil;
		DeAlokasi(temp);
	}
}

// prosedur insert after berdasarkan address dan address predecessor
void InsertAfter (List * L, address P, address Prec)
{
	address temp;

	temp = First(*L);
	
	while (temp != Prec)
	{
		temp = Next(temp);
	}

	Next(P) = Next(temp);
	Next(temp) = P;
}

// prosedur delete spesifik berdasarkan nilai dan nama
void DelP (List * L, infotype nilai, infonama nama)
{
	address P, prec;
	
	 /* Algoritma */
	P = SearchSpec((*L), nilai, nama);
	prec = SearchPrecSpec((*L), Nilai(P), Nama(P));

	if(prec == Nil){
		DelFirst(L, &P);
	}else {
		Next(prec) = Next(P);
		DeAlokasi(P);
	}
}

// prosedur delete after berdasarkan address dan address predecessor
void DelAfter (List * L, infotype * nilai, infonama * nama, address Prec)
{
	address temp;

	if (Next(Prec) == Nil)
	{
		printf("Tidak ada element list berikutnya!\n");
	}

    if (Prec != Nil && Next(Prec) != Nil) {
        temp = Next(Prec);
        *nilai = Nilai(temp);
        strcpy(*nama, Nama(temp));
        
        Next(Prec) = Next(temp);
        DeAlokasi(temp);
    }
}

infotype HitungElement(List L)
{
	address P;
	int count = 0;

	P = First(L);
	while (P != Nil) {
		count++;
		P = Next(P);
	}

	return count;
}

// prosedur print isi list
void PrintIsiList (List L)
{
	address P;

	if(First(L) == Nil){
		printf("List Kosong!\n");
	} else {
		P = First(L);
		while (P != Nil) {
			printf("%s, %d -> ", Nama(P), Nilai(P));
			P = Next(P); 
		}
		printf("NULL \n");
	}

    printf("======================== \n");
}

// prosedur delete all
void DelAll (List * L)
{
	address PDel, temp;
	
	PDel = First(*L);

	while (!UnderAndOverflowCheck(PDel))
	{
		temp = PDel;
		PDel = Next(PDel);
		DeAlokasi(temp);
	}

	First(*L) = Nil;

    printf("\n======================== \n");
	printf("Berhasil Menghapus Semua Element List!\n");
}

// prosedur copy list
void CopyList(List L1, List *L2)
{
    address P, P2, temp;

    if (First(L1) == Nil) {
        printf("List 1 Kosong!\n");
        return;
    }

    // Kosongkan L2 terlebih dahulu sebelum menyalin
    DelAll(L2);

    P = First(L1);
    while (P != Nil) {
        P2 = Alokasi(Nama(P), Nilai(P));

        if (P2 != Nil && !UnderAndOverflowCheck(P2)) {
            if (First(*L2) == Nil) {
                First(*L2) = P2;
            } else {
                temp = First(*L2);
                while (Next(temp) != Nil) {
                    temp = Next(temp);
                }
                Next(temp) = P2;
            }
        }
        
        P = Next(P);
    }
    printf("======================== \n");
    printf("Berhasil Menyalin List!\n");
	printf("======================== \n");
}


// copy list ke list lain berdasarkan nilai tertentu
void CopyListNilai(List L1, List *L2, infotype minNilai)
{
    address P, P2, temp;

    if (First(L1) == Nil) {
        printf("List 1 Kosong!\n");
        return;
    }

    // Kosongkan L2 terlebih dahulu sebelum menyalin
    DelAll(L2);

    P = First(L1);
    while (P != Nil) {
        // Hanya salin jika Nilai(P) > minNilai
        if (Nilai(P) > minNilai) {
            P2 = Alokasi(Nama(P), Nilai(P));

            if (P2 != Nil && !UnderAndOverflowCheck(P2)) {
                if (First(*L2) == Nil) {
                    First(*L2) = P2;
                } else {
                    temp = First(*L2);
                    while (Next(temp) != Nil) {
                        temp = Next(temp);
                    }
                    Next(temp) = P2;
                }
            }
        }

        P = Next(P);
    }

    printf("======================== \n");
    printf("Berhasil Menyalin List dengan nilai > %d!\n", minNilai);
    printf("======================== \n");
}

// prosedur sort list berdasarkan nama
void SortListByName(List *L, int ascending) {
    int IsEmpty(List L) {
        return (First(L) == Nil);
    }

    address P, Q;
    infonama tempNama;
    infotype tempNilai;

    for (P = First(*L); P != NULL; P = Next(P)) {
        for (Q = Next(P); Q != NULL; Q = Next(Q)) {
            if ((ascending && strcmp(Nama(P), Nama(Q)) > 0) ||
                (!ascending && strcmp(Nama(P), Nama(Q)) < 0)) {
                // Swap Data
                strcpy(tempNama, Nama(P));
                tempNilai = Nilai(P);

                strcpy(Nama(P), Nama(Q));
                Nilai(P) = Nilai(Q);

                strcpy(Nama(Q), tempNama);
                Nilai(Q) = tempNilai;
            }
        }
    }
}

// prosedur sort list berdasarkan nilai
void SortListByScore(List *L, int ascending) {
    int IsEmpty(List L) {
        return (First(L) == Nil);
    }

    address P, Q;
    infonama tempNama;
    infotype tempNilai;

    for (P = First(*L); P != NULL; P = Next(P)) {
        for (Q = Next(P); Q != NULL; Q = Next(Q)) {
            if ((ascending && Nilai(P) > Nilai(Q)) ||
                (!ascending && Nilai(P) < Nilai(Q))) {
                // Swap Data
                strcpy(tempNama, Nama(P));
                tempNilai = Nilai(P);

                strcpy(Nama(P), Nama(Q));
                Nilai(P) = Nilai(Q);

                strcpy(Nama(Q), tempNama);
                Nilai(Q) = tempNilai;
            }
        }
    }
}



// prosedur urut list
void PrintUrutList(List MyList, SortType sortBy, Sorting sort) 
{
    if (First(MyList) == Nil) {
        printf("List kosong!\n");
        return;
    }

    List SortedList;
    CreateList(&SortedList);
    CopyList(MyList, &SortedList);

    address P, Q;

    for (P = First(SortedList); P != Nil; P = Next(P)) {
        for (Q = Next(P); Q != Nil; Q = Next(Q)) {
            int swap = 0;

			if (sort == ASC) {
				if (sortBy == Nilai) {
					if (Nilai(P) > Nilai(Q)) swap = 1;
				} else if (sortBy == Nama) {
					if (strcmp(Nama(P), Nama(Q)) > 0) swap = 1;
				}
			} else if (sort == DESC)
			{
				if (sortBy == Nilai) {
					if (Nilai(P) < Nilai(Q)) swap = 1;
				} else if (sortBy == Nama) {
					if (strcmp(Nama(P), Nama(Q)) < 0) swap = 1;
				}
			}

            if (swap) {
                int tempNilai = Nilai(P);
                char tempNama[50];

                strcpy(tempNama, Nama(P));

                Nilai(P) = Nilai(Q);
                strcpy(Nama(P), Nama(Q));

                Nilai(Q) = tempNilai;
                strcpy(Nama(Q), tempNama);
            }
        }
    }

	if (sort == ASC) {
		printf("Hasil Ascending : \n");
		PrintIsiList(SortedList);
	} else if (sort == DESC)
	{
		printf("Hasil Descending : \n");
		PrintIsiList(SortedList);
	}
}
