#ifndef MAINBODY_H
#define MAINBODY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BOOLEAN.h"

#define Nil NULL
#define Nama(P) (P)->nama
#define Nilai(P) (P)->nilai
#define Next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef char infonama[100];

typedef struct tElmtList *address;
typedef struct tElmtList {
    infonama nama;
    infotype nilai;
    address next;
} NodeMahasiswa;

typedef struct {
    address First;
} List;

typedef enum {
    Nama,
    Nilai
} SortType;

typedef enum {
    ASC,
    DESC
} Sorting;

void CreateList (List *L);

address Alokasi (infonama nama, infotype nilai);
void DeAlokasi (address P);
boolean OverflowCheck(address P);
boolean DuplikasiCheck(List L, infotype X, infonama nama);

address SearchSpec (List L, infotype X, infonama nama);
address SearchPrecSpec (List L, infotype X, infonama nama);

void InsVFirst (List * L, infotype X, infonama nama);
void InsVLast (List * L, infotype X, infonama nama);

void InsertFirst (List * L, address P);
void InsertLast (List * L, address P);

void DelVFirst (List * L, infotype * X, infonama * nama);
void DelFirst (List * L, address * P);

void DelVLast (List * L, infotype * nilai, infonama * nama);
void DelLast (List * L, address * P);

void InsertAfter (List * L, address P, address Prec);
void DelP (List * L, infotype nilai, infonama nama);
void DelAfter (List * L, infotype * nilai, infonama * nama, address Prec);



infotype HitungElement(List L);
void PrintIsiList(List L);

void DelAll (List * L);

void CopyList(List L1, List *L2);
int IsEmpty(List L);
void CopyListNilai(List L, List *L2, infotype nilaiMin);

void PrintUrutList(List MyList, SortType sortBy, Sorting sort);
void SortListByName(List *L, int ascending);
void SortListByScore(List *MyList, int ascending);

#endif
