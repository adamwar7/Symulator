#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struktury.h"
void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf)
{
	nazwyPlikow* current = malloc(sizeof(nazwyPlikow));
	current->tab = buf;
	current->next = (*pHead);     //zapis do jednokierunkowej
	*pHead = current;
}

void pobierzNazwyPlikow(nazwyPlikow** pHead) {
	FILE* plik = fopen("NazwyPilkow.txt", "r");
	if (plik)
	{
		int sizeofpliks = 16;
		for (int i = 0; i < sizeofpliks; i++) {
			char* i = malloc(10 * sizeof(i));
			if (!feof(plik)) {


				if (fscanf(plik, "%s", i));
				//printf("%s\n", i);
				zaladujNazwyPlikowDoListy(pHead, i);

			}

		}
		fclose(plik);
	}
}

void zaladujRezerwowych(zawodnicy** rynekHead, char* i, int a, int b) {
	zawodnicy* nowy = malloc(sizeof(zawodnicy));
	nowy->nazwisko = i;
	nowy->moc = a;
	nowy->wartosc = b;       //zapis do jednokierunkowej
	nowy->pNext = (*rynekHead);
	*rynekHead = nowy;
}

void pobierzRynek(zawodnicy** rynekHead) {
	FILE* plik;
	if ((plik = fopen("Rynek.txt", "r")) != NULL) {
		int size = 10;
		int moc = 0;
		int wartosc = 0;
		while (!feof(plik)) {
			char* nazwisko = malloc(size * sizeof(nazwisko));
			if (fscanf(plik, "%s", nazwisko));
			if (fscanf(plik, "%d", &moc));
			if (fscanf(plik, "%d", &wartosc));
			zaladujRezerwowych(rynekHead, nazwisko, moc, wartosc);
		}
		fclose(plik);
	}
}

void pobierzKluby(kluby** glowa, nazwyPlikow* pHead) {
	if (pHead) {
		FILE* plik;
		if ((plik = fopen(pHead->tab, "r")) != NULL) {   //do odczytu
			if (plik) {
				kluby* nowy = malloc(sizeof(kluby));   //alokacja
				int size = 10;
				char* nazwa = malloc(10 * sizeof(size));  //alokacja
				char* trener = malloc(10 * sizeof(size)); //alokacja
				int budzet = 0;
				if (fscanf(plik, "%s", nazwa));
				if (fscanf(plik, "%s", trener));
				if (fscanf(plik, "%d", &budzet));
				nowy->nazwa = nazwa;
				nowy->trener = trener;
				nowy->budzet = budzet;
				nowy->pkt = 0;
				nowy->goleZ = 0;
				nowy->goleS = 0;
				nowy->bilans = 0;
				nowy->iloscMeczy = 0;
				zawodnicy* zawHead = NULL;
				for (int i = 0; i < 18; i++) {
					zawodnicy* tmp = malloc(sizeof(zawodnicy));   //alokacja
					char* i = malloc(10 * sizeof(i)); //alokacja
					int moc = 0;
					int wartosc = 0;
					if (!feof(plik)) {
						if (fscanf(plik, "%s", i));
						if (fscanf(plik, "%d", &moc));
						if (fscanf(plik, "%d", &wartosc));
						tmp->nazwisko = i;
						tmp->moc = moc;
						tmp->wartosc = wartosc;
						tmp->pNext = (zawHead);
						zawHead = tmp;
					}
				}
				nowy->zawHead = zawHead;   //zapis do cyklicznej
				if (*glowa == NULL) {
					*glowa = nowy;

				}
				else
				{
					nowy->next = (*glowa)->next;
				}
				(*glowa)->next = nowy;
			}
			fclose(plik);
			pobierzKluby(glowa, pHead->next);
		}
	}
}

twojZespol* zapiszSwojZespol(kluby* glowa) {
	twojZespol* twojHead = malloc(sizeof(twojZespol));
	twojHead->nazwa = glowa->nazwa;
	twojHead->trener = glowa->trener;
	twojHead->budzet = glowa->budzet;
	twojHead->pkt = glowa->pkt;
	twojHead->goleZ = glowa->goleZ;
	twojHead->goleS = glowa->goleS;
	twojHead->bilans = glowa->bilans;
	twojHead->iloscMeczy = glowa->iloscMeczy;
	twojHead->zawHead = glowa->zawHead;
	return twojHead;
}