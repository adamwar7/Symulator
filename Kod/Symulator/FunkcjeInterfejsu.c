#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define ODJ(a, b)  (a - b)
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struktury.h"
#include "ZwalnianiePamieci.h"
#include "FunkcjeInterfejsu.h"
#include "Pobieranie.h"
#include "Symulacja.h"

void wypiszRynek(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void kup(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void rules(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("                    Your players :\n------------------------------------------------------------------\n");
	char* nazwisko = "name";
	char* moc = "power";
	char* wartosc = "price";
	printf("%20s  %6s  %9s\n", nazwisko, moc, wartosc);
	printf("------------------------------------------------------------------\n");
	while (zawHead != NULL) {
		printf("%20s  ", zawHead->nazwisko);
		printf("%5d  ", zawHead->moc);
		printf("%10d\n", zawHead->wartosc);
		zawHead = zawHead->pNext;
	}
	printf("\n\nBack [1]\n\nEnter number below:\n------------------\n");
	char i = '0';
	while (i != '1') {
		if (scanf("%c", &i));
		if (i == '1') {
			team(rynekHead, twojHead, glowa, stanSezonu);
		}

	}
}

void wypiszTabele(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	if (stanSezonu != 15)
		system("cls");
	kluby* current = glowa;
	kluby* nowy = NULL;
	while (current->next != glowa) {
		kluby* help = malloc(sizeof(kluby));
		kluby* tmp = nowy;
		help->nazwa = current->nazwa;
		help->trener = current->trener;
		help->budzet = current->budzet;
		help->pkt = current->pkt;
		help->iloscMeczy = current->iloscMeczy;
		help->bilans = current->bilans;
		help->goleZ = current->goleZ;
		help->goleS = current->goleS;
		help->zawHead = NULL;
		if (nowy == NULL) {
			help->next = NULL;
			nowy = help;
		}
		else {
			if (current->pkt > nowy->pkt) {
				help->next = nowy;
				nowy = help;
			}
			else {
				while ((tmp->next != NULL) && !(current->pkt > tmp->next->pkt&& current->pkt <= tmp->pkt))
					tmp = tmp->next;
				if (tmp->next == NULL) {
					help->next = NULL;
					tmp->next = help;
				}
				else {
					help->next = tmp->next;
					tmp->next = help;
				}
			}
		}
		current = current->next;
	}
	kluby* help = malloc(sizeof(kluby));
	kluby* tmp = nowy;
	help->nazwa = current->nazwa;
	help->trener = current->trener;
	help->budzet = current->budzet;
	help->pkt = current->pkt;
	help->iloscMeczy = current->iloscMeczy;
	help->bilans = current->bilans;
	help->goleZ = current->goleS;
	help->goleS = current->goleS;
	help->zawHead = NULL;
	if (nowy == NULL) {
		help->next = NULL;
		nowy = help;
	}
	else {
		if (current->pkt > nowy->pkt) {
			help->next = nowy;
			nowy = help;
		}
		else {
			while ((tmp->next != NULL) && !(current->pkt > tmp->next->pkt&& current->pkt <= tmp->pkt))
				tmp = tmp->next;
			if (tmp->next == NULL) {
				help->next = NULL;
				tmp->next = help;
			}
			else {
				help->next = tmp->next;
				tmp->next = help;
			}
		}
	}
	kluby* tmp2 = nowy;
	int i = 1;
	printf("                      Schedule\n");
	printf("-----------------------------------------------------\n");
	printf("Place      Team    G   Pts  Bil  Gsc  Gls\n");
	printf("-----------------------------------------------------\n");
	while (tmp2) {
		printf("%3d. %10s  %3d  %3d  %3d  %3d  %3d\n", i, tmp2->nazwa, tmp2->iloscMeczy, tmp2->pkt, tmp2->bilans, tmp2->goleZ, tmp2->goleS);
		tmp2 = tmp2->next;
		i++;
	}
	tmp2 = nowy;
	zwolnijTabele(&nowy);
	if (stanSezonu != 15) {
		printf("\nBack [1]\n");
		char liczba = '0';
		printf("Enter number below\n");
		printf("------------------\n");
		while (liczba != '1') {
			if (scanf("%c", &liczba));
		}
		if (liczba == '1') {
			team(rynekHead, twojHead, glowa, stanSezonu);
		}
	}
}

void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf(" Club:   %15s\n", twojHead->nazwa);
	printf("Manager: %15s\n", twojHead->trener);
	printf("Budget:  %15d\n\n", twojHead->budzet);
	printf("Back to main menu [1]\n");
	printf("Players [2]\n");
	printf("League [3]\n\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	while (liczba != '1' && liczba != '2' && liczba != '3') {
		if (scanf("%c", &liczba));
	}
	switch (liczba) {
	case '1':
		menu(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '2':
		wypiszZawodnikow(rynekHead, twojHead->zawHead, twojHead, glowa, stanSezonu);
		break;
	case '3':
		wypiszTabele(rynekHead, twojHead, glowa, stanSezonu);
		break;
	}

}

void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("Continue [1]\n");
	printf("Team [2]\n");
	printf("Transfers [3]\n");
	printf("Rules [4]\n");
	printf("Exit [5]\n\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	while (liczba != '1' && liczba != '2' && liczba != '3'
		&& liczba != '4' && liczba != '5') {
		if (scanf("%c", &liczba));
	}
	switch (liczba) {
	case '1':
		rozgrywka(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '2':
		team(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '3':
		wypiszRynek(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '4':
		rules(rynekHead, twojHead, glowa, stanSezonu);
		break;
	case '5':
		break;
	}
}


void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("Simulate a match [1]\n");
	printf("Simulate entire season [2]\n");
	printf("Back to main menu [3]\n\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	kluby* current = glowa;
	while (liczba != '1' && liczba != '2' && liczba != '3') {
		if (scanf("%c", &liczba));
	}
	switch (liczba) {
	case '1':
		stanSezonu++;
		symulujKolejke(current, stanSezonu);
		current = current->next;
		aktualizujZespol(twojHead, current);
		if (stanSezonu == 15)
			sSezonu(stanSezonu, rynekHead, twojHead, glowa);
		rozgrywka(rynekHead, twojHead, current, stanSezonu);
		break;
	case '2':
		symulujSezon(current, glowa, stanSezonu);
		current = glowa;
		aktualizujZespol(twojHead, current);
		stanSezonu = 15;
		if (stanSezonu == 15)
			sSezonu(stanSezonu, rynekHead, twojHead, glowa);
		break;
	case '3':
		menu(rynekHead, twojHead, current, stanSezonu);
		break;
	}
}

kluby* wybierzZespol(kluby* glowa) {
	printf("Welome in game 'Football Mangarer' created by Adam Warzecha\n");
	printf("Start [1]\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	while (liczba != '1') {
		if (scanf("%c", &liczba));
	}

	system("cls");
	printf("Select your team from the list below:\n");
	if (glowa) {
		printf("%10s\n", glowa->nazwa);
		kluby* current = glowa;
		while (current->next != glowa) {
			printf("%10s\n", current->next->nazwa);
			current = current->next;
		}
	}
	char tab[20] = { '0' };
	printf("\nEnter choosen name below\n------------------------\n");
	while (TRUE) {
		if (scanf("%s", &tab));
		if (glowa) {
			kluby* tmp = glowa;
			if ((stricmp(tab, tmp->nazwa)) == 0) {
				return tmp;
			}
			else {
				while (tmp->next != glowa) {
					if ((stricmp(tab, tmp->next->nazwa)) == 0) {
						return tmp->next;
					}
					tmp = tmp->next;
				}
			}
		}
	}
}

void udanyZakup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("Successful player purchase!\n\n");
	printf("Enter '1' below to back to main manu\n------------------------------------\n");
	char i = '0';
	while (i != '1') {
		if (scanf("%c", &i));
		switch (i) {
		case '1':
			menu(rynekHead, twojHead, glowa, stanSezonu);
			break;
		}
	}
}

void nieudanyZakup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("Unsuccessful player purchase, you bought to much players or you dont have enough money\n\n");
	printf("Enter '1' below to back to main manu\n------------------------------------\n");
	char i = '0';
	while (i != '1') {
		if (scanf("%c", &i));
		switch (i) {
		case '1':
			menu(rynekHead, twojHead, glowa, stanSezonu);
			break;
		}
	}
}
void kup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("enter player name below or '1' to back\n---------------------------\n");

	char tab[20] = { '0' };
	while (TRUE) {
		if (scanf("%s", &tab));
		if (tab[0] == '1') {
			wypiszRynek(rynekHead, twojHead, glowa, stanSezonu);
			return;
		}
		if (rynekHead) {
			zawodnicy* tmp = rynekHead;
			kluby* tym = glowa;
			if ((stricmp(tab, tmp->nazwisko)) == 0) {
				int size = 0;
				zawodnicy* p = tmp->pNext;
				while (twojHead->nazwa != tym->nazwa) {
					tym = tym->next;
				}
				while (tym->zawHead->pNext != NULL) {
					size++;
					tym->zawHead = tym->zawHead->pNext;
				}
				if ((tmp->wartosc <= twojHead->budzet) && (size < 21)) {
					twojHead->budzet -= tmp->wartosc;
					tym->budzet -= tmp->wartosc;
					tym->zawHead->pNext = tmp;
					rynekHead = p;
					tym->zawHead->pNext->pNext = NULL;
					udanyZakup(rynekHead, twojHead, glowa, stanSezonu);
					break;

				}
				else {
					nieudanyZakup(rynekHead, twojHead, glowa, stanSezonu);
					break;
				}
			}
			else {
				while (tmp->pNext != NULL) {
					zawodnicy* p = tmp;
					zawodnicy* temp = tmp->pNext;
					if ((stricmp(tab, temp->nazwisko)) == 0) {
						int size = 0;
						while (twojHead->nazwa != tym->nazwa) {
							tym = tym->next;
						}
						while (tym->zawHead->pNext != NULL) {
							tym->zawHead = tym->zawHead->pNext;
							size++;
						}
						if ((temp->wartosc <= twojHead->budzet) && (size < 21)) {
							twojHead->budzet -= temp->wartosc;
							tym->budzet -= tmp->wartosc;
							tym->zawHead->pNext = temp;
							if (temp->pNext != NULL)
								p->pNext = temp->pNext;
							tym->zawHead->pNext->pNext = NULL;
							udanyZakup(rynekHead, twojHead, glowa, stanSezonu);
							break;
						}
						else {
							nieudanyZakup(rynekHead, twojHead, glowa, stanSezonu);
							break;
						}
					}
					tmp = tmp->pNext;
				}
				if (tmp->pNext == NULL)
					printf("Wrong name!\n");
			}
		}
	}
}

void wypiszRynek(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("                  available players :\n------------------------------------------------------------------\n");
	char* nazwisko = "name";
	char* moc = "power";
	char* wartosc = "price";
	zawodnicy* help = rynekHead;
	printf("%20s  %5s  %10s\n", nazwisko, moc, wartosc);
	printf("------------------------------------------------------------------\n");
	if (rynekHead == NULL)
		printf("\n\n               No available players");
	while (help != NULL) {
		printf("%20s  ", help->nazwisko);
		printf("%5d  ", help->moc);
		printf("%10d\n", help->wartosc);
		help = help->pNext;
	}
	printf("\nYours budget: %d\n\n", twojHead->budzet);
	printf("\n\nBuy [1]\nBack [2]\n\nEnter number below:\n------------------\n");
	char i = '0';
	while (i != '1' && i != '2') {
		if (scanf("%c", &i));
		switch (i) {
		case '1':
			kup(rynekHead, twojHead, glowa, stanSezonu);
			break;
		case '2':
			menu(rynekHead, twojHead, glowa, stanSezonu);
			break;
		}
	}
}

void rules(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("Rules:\n----------------------------------------------\n");
	printf("1. You can buy a player from market only if you have enough budget\n");
	printf("2. After simulation you can see results by checking league\n");
	printf("3. After simulation you will recive +125000 money if you win or +65000 if you draw\n   If you will symulate entire season you will recive money for everymatch\n");
	printf("4. If season ends, progress in league is being reset\n");
	printf("5. Have fun :)\n\n\n");
	printf("Enter '1' below to back to main menu\n----------------------------------------------\n");
	char i = '0';
	while (i != '1') {
		if (scanf("%c", &i));
		if (i == '1') {
			menu(rynekHead, twojHead, glowa, stanSezonu);
			break;
		}
	}
}
