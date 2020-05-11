#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include "Struktury.h"

void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf)
{
	nazwyPlikow* current = malloc(sizeof(nazwyPlikow));
	current->tab = buf;
	current->next = (*pHead);
	*pHead = current;
}

void pobierzNazwyPlikow(nazwyPlikow** pHead)
{
	FILE* plik = fopen("NazwyPilkow.txt", "r");
	if (plik)
	{
		int sizeofpliks = 12;
		for (int i = 0; i < sizeofpliks; i++) {
			char* i = malloc(10 * sizeof(i));
			if (!feof(plik)) {


				if(fscanf(plik, "%s", i));
				//printf("%s\n", i);
				zaladujNazwyPlikowDoListy(pHead, i);

			}

		}
		fclose(plik);
	}
}

void pokaz(nazwyPlikow* pHead)
{
	if (pHead != NULL)
	{
		printf("%s\n", pHead->tab);
		pokaz(pHead->next);
	}
	else
	{
		return;
	}
}


void usunNazwyPlikowDoListy(nazwyPlikow** pHead)
{
	nazwyPlikow* tmp = NULL;
	while (*pHead != NULL) {
		tmp = (*pHead)->next;
		free(*pHead);
		*pHead = tmp;
	}

}


void pobierzKluby(kluby** glowa, nazwyPlikow* pHead) {
	if (pHead) {
		FILE* plik;
		if((plik = fopen(pHead->tab, "r"))!=NULL){
			if (plik) {
				kluby* current = malloc(sizeof(kluby));
				int size = 10;
				char* nazwa = malloc(10 * sizeof(size));
				char* trener = malloc(10 * sizeof(size));
				int budzet = 0;
				if(fscanf(plik, "%s", nazwa));
				if(fscanf(plik, "%s", trener));
				if(fscanf(plik, "%d", &budzet));
				if(current->nazwa = nazwa);
				current->trener = trener;
				current->budzet = budzet;
				current->pkt = 0;
				current->goleZ = 0;
				current->goleS = 0;
				zawodnicy* zawHead = NULL;
				for (int i = 0; i < 18; i++) {
					zawodnicy* tmp = malloc(sizeof(zawodnicy));
					char* i = malloc(10 * sizeof(i));
					int moc = 0;
					int wartosc = 0;
					if (!feof(plik)) {
						if(fscanf(plik, "%s", i));
						if(fscanf(plik, "%d", &moc));
						if(fscanf(plik, "%d", &wartosc));
						tmp->nazwisko = i;
						tmp->moc = moc;
						tmp->wartosc = wartosc;
						tmp->pNext = (zawHead);
						zawHead = tmp;
					}
				}
				current->zawHead = zawHead;
				current->next = (*glowa);
				*glowa = current;
				fclose(plik);
				pobierzKluby(glowa, pHead->next);
			}
		}
	}
}

void wypiszZawodnikow(zawodnicy* zawHead) {
	if (zawHead!=NULL) {
		printf("%s\n", zawHead->nazwisko);
		printf("%d\n", zawHead->moc);
		printf("%d\n", zawHead->wartosc);
		wypiszZawodnikow(zawHead->pNext);
	}
	else {
		return;
	}
}

void wypiszKlub(kluby* glowa) {
	if (glowa) {
		printf("%s\n", glowa->nazwa);
		printf("%s\n", glowa->trener);
		printf("%d\n", glowa->budzet);
		printf("%d\n", glowa->pkt);
		printf("%d\n", glowa->goleZ);
		printf("%d\n", glowa->goleS);
		wypiszZawodnikow(glowa->zawHead);
		wypiszKlub(glowa->next);
	}
	else {
		return;
	}
}
