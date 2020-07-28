#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define TRUE 1
#define ODJ(a, b)  (a - b)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struktury.h"
#include "FunkcjeInterfejsu.h"

void aktualizuj(twojZespol* twojHead, kluby* glowa) {
	twojHead->nazwa = glowa->nazwa;
	twojHead->trener = glowa->trener;
	twojHead->budzet = glowa->budzet;
	twojHead->pkt = glowa->pkt;
	twojHead->goleZ = glowa->goleZ;
	twojHead->goleS = glowa->goleS;
	twojHead->bilans = glowa->bilans;
	twojHead->iloscMeczy = glowa->iloscMeczy;
}
void aktualizujZespol(twojZespol* twojHead, kluby* glowa) {
	kluby* tmp = glowa;
	while (TRUE) {
		if (glowa) {
			if ((stricmp(twojHead->nazwa, tmp->nazwa)) == 0) {
				aktualizuj(twojHead, tmp);
				return;
			}
			else {
				while (tmp->next != glowa) {
					if ((stricmp(twojHead->nazwa, tmp->next->nazwa)) == 0) {
						aktualizuj(twojHead, tmp->next);
						return;
					}
					tmp = tmp->next;
				}
			}
		}
		aktualizuj(twojHead, tmp);
		return;
	}
}
int sumujMoce(zawodnicy* zawHead) {
	int suma = 0;
	while (zawHead) {
		suma += zawHead->moc;
		zawHead = zawHead->pNext;
	}
	return suma;
}

int losujGole(int min, int max)
{
	int tmp;
	if (max >= min)
		max -= min;
	else
	{
		tmp = ODJ(min, max);
		min = max;
		max = tmp;
	}
	return max ? (rand() % max + min) : min;
}

void symulujMecz(kluby* glowa, kluby* drugaGlowa) {
	int a = sumujMoce(glowa->zawHead);
	int b = sumujMoce(drugaGlowa->zawHead);
	char ktoraWieksza;
	int roznica = 0;
	int zero = 0;
	int jeden = 1;
	int dwa = 2;
	int trzy = 3;
	int cztery = 4;
	int piec = 5;
	int goleA = 0;
	int goleB = 0;
	if (a - b > 0) {
		ktoraWieksza = 'a';
		roznica = ODJ(a, b);
	}
	else if (a - b == 0) {
		ktoraWieksza = 'c';
	}
	else {
		ktoraWieksza = 'b';
		roznica = ODJ(b, a);
	}
	if (roznica < 25) {
		goleA = losujGole(zero, piec);
		goleB = losujGole(zero, piec);
	}
	else if (25 <= roznica < 75) {
		if (ktoraWieksza == 'a') {
			goleA = losujGole(jeden, piec);
			goleB = losujGole(zero, piec);
		}
		else {
			goleB = losujGole(jeden, piec);
			goleA = losujGole(zero, piec);
		}
	}
	else if (75 <= roznica < 125) {
		if (ktoraWieksza == 'a') {
			goleA = losujGole(dwa, piec);
			goleB = losujGole(zero, piec);
		}
		else {
			goleB = losujGole(dwa, piec);
			goleA = losujGole(zero, piec);
		}
	}
	else if (125 <= roznica < 175) {
		if (ktoraWieksza == 'a') {
			goleA = losujGole(trzy, piec);
			goleB = losujGole(zero, piec);
		}
		else {
			goleB = losujGole(trzy, piec);
			goleA = losujGole(zero, piec);
		}
	}
	else {
		if (ktoraWieksza == 'a') {
			goleA = losujGole(cztery, piec);
			goleB = losujGole(zero, piec);
		}
		else {
			goleB = losujGole(cztery, piec);
			goleA = losujGole(zero, piec);
		}
	}
	glowa->goleZ += goleA;
	glowa->goleS += goleB;
	glowa->bilans += ODJ(goleA, goleB);
	drugaGlowa->goleZ += goleB;
	drugaGlowa->goleS += goleA;
	drugaGlowa->bilans += ODJ(goleB, goleA);
	if (goleA > goleB) {
		glowa->pkt += 3;
		glowa->budzet += 125000;
	}
	else if (goleA == goleB) {
		glowa->pkt += 1;
		glowa->budzet += 65000;
		drugaGlowa->pkt += 1;
		drugaGlowa->budzet += 65000;
	}
	else {
		drugaGlowa->pkt += 3;
		drugaGlowa->budzet += 125000;
	}
	glowa->iloscMeczy += 1;
	drugaGlowa->iloscMeczy += 1;
	printf("%12s  %2d ", glowa->nazwa, goleA);
	printf("-");
	printf(" %2d  %12s\n", goleB, drugaGlowa->nazwa);
}


void symulujKolejke(kluby* glowa, int stanSezonu) {
	system("cls");
	kluby* current = glowa;
	kluby* tmp = glowa;
	printf("              Round %d\n", stanSezonu);
	printf("-------------------------------------\n\n");
	while (current->next->next != glowa) {
		symulujMecz(tmp, tmp->next);
		tmp = tmp->next->next;
		current = current->next->next;
	}
	symulujMecz(tmp, tmp->next);
	printf("\n\n\n");
	printf("Enter '1' to continue\n-------------------------------------\n");
	char liczba = '0';
	while (liczba != '1') {
		if (scanf("%c", &liczba));
	}
}

void symulujSezon(kluby* glowa, kluby* end, int stanSezonu) {
	int roundWorks = stanSezonu;
	roundWorks++;
	kluby* current = glowa;
	while (current->next != glowa && current->next != end) {
		symulujKolejke(current, roundWorks);
		current = current->next;
		roundWorks++;
		if (roundWorks == 16) {
			break;
		}
	}
}

void sSezonu(int stanSezonu, zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa) {
	system("cls");
	printf("The season is over, progress in league is being reset\n-----------------------------------------------------\n");
	printf("                       Results:\n\n\n");
	wypiszTabele(rynekHead, twojHead, glowa, stanSezonu);
	printf("\n\n");
	printf("Start new season [1]\n");
	printf("Exit [2]\n\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	if (stanSezonu == 15) {
		kluby* current = glowa;
		while (current->next != glowa) {
			current->pkt = 0;
			current->goleZ = 0;
			current->goleS = 0;
			current->bilans = 0;
			current->iloscMeczy = 0;
			current = current->next;
		}
		current->pkt = 0;
		current->goleZ = 0;
		current->goleS = 0;
		current->bilans = 0;
		current->iloscMeczy = 0;
	}
	stanSezonu = 0;
	while (liczba != '1' && liczba != '2') {
		if (scanf("%c", &liczba));
	}
	switch (liczba) {
	case '1':
		menu(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '2':
		break;
	}
}
