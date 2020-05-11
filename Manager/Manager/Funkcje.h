#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead,char* buf);


void pobierzNazwyPlikow(nazwyPlikow** pHead);

void pokaz(nazwyPlikow* pHead);

void usunNazwyPlikowDoListy(nazwyPlikow** pHead);

void pobierzKluby(kluby** glowa, nazwyPlikow* pHead);

void wypiszKlub(kluby* glowa);

void wypiszZawodnikow(kluby* glowa);