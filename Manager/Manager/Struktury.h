#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct nazwyPlikow {
	char* tab;
	struct nazwyPlikow* next;
}nazwyPlikow;

typedef struct zawodnicy {
	char* nazwisko;
	int moc;
	int wartosc;
	struct zawodnicy* pNext;
}zawodnicy;



typedef struct kluby {
	char* nazwa;
	char* trener;
	int budzet;
	int goleZ;
	int goleS;
	int bilans;
	int pkt;
	int iloscMeczy;
	struct kluby* next;
	struct zawodnicy* zawHead;
}kluby;

typedef struct twojZespol {
	char* nazwa;
	char* trener;
	int budzet;
	int goleZ;
	int goleS;
	int bilans;
	int pkt;
	int iloscMeczy;
	struct zawodnicy* zawHead;
}twojZespol;