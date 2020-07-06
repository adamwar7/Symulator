#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define ODJ(a, b)  (a - b)
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struktury.h"


void wypiszRynek(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void kup(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void rules(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int sSezonu);

void usunListeZawodnikow(zawodnicy* rynekHead) {
	zawodnicy* tmp = NULL;
	while(rynekHead->pNext != NULL) {
		tmp = rynekHead->pNext;
		free(rynekHead);
		rynekHead = tmp;
	}
}
void usunKluby(kluby* glowa) {
	zawodnicy* tmp = NULL;
	while (glowa->next != NULL) {
		tmp = glowa->next;
		usunListeZawodnikow(glowa->zawHead);
		free(glowa);
		glowa = tmp;
	}
}

void usunTwojZespol(twojZespol** twojHead) {
	usunListeZawodnikow((*twojHead)->zawHead);
	free(*twojHead);
}

void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf)
{
	nazwyPlikow* current = malloc(sizeof(nazwyPlikow));
	current->tab = buf;
	current->next = (*pHead);
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

void usunNazwyPlikowDoListy(nazwyPlikow** pHead)
{
	nazwyPlikow* tmp = NULL;
	while (*pHead != NULL) {
		tmp = (*pHead)->next;
		free(*pHead);
		*pHead = tmp;
	}

}

void zaladujRezerwowych(zawodnicy** rynekHead, char* i, int a, int b) {
	zawodnicy* nowy = malloc(sizeof(zawodnicy));
	nowy->nazwisko = i;
	nowy->moc = a;
	nowy->wartosc = b;
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
		if ((plik = fopen(pHead->tab, "r")) != NULL) {
			if (plik) {
				kluby* nowy = malloc(sizeof(kluby));
				int size = 10;
				char* nazwa = malloc(10 * sizeof(size));
				char* trener = malloc(10 * sizeof(size));
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
					zawodnicy* tmp = malloc(sizeof(zawodnicy));
					char* i = malloc(10 * sizeof(i));
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
				nowy->zawHead = zawHead;
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

void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("                    Your players :\n------------------------------------------------------------------\n");
	char* nazwisko = "name";
	char* moc = "power";
	char* wartosc = "price";
	printf("%20s  %5s  %10s\n", nazwisko, moc, wartosc);
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

void zwolnijTabele(kluby** tabela) {
	kluby* tmp = NULL;
	while (*tabela != NULL) {
		tmp = (*tabela)->next;
		free(*tabela);
		*tabela = tmp;
	}
}

void wypiszTabele(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
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

void wypiszKlub(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	if (glowa) {
		system("cls");
		printf("%s\n", glowa->nazwa);
		printf("%s\n", glowa->trener);
		printf("%d\n", glowa->budzet);
		printf("%d\n", glowa->pkt);
		printf("%d\n", glowa->goleZ);
		printf("%d\n", glowa->goleS);
		printf("Ilosc meczy:  %d\n", glowa->iloscMeczy);
		wypiszZawodnikow(rynekHead, glowa->zawHead, twojHead, glowa, stanSezonu);
		kluby* current = glowa;
		while (current->next != glowa) {
			printf("%s\n", current->next->nazwa);
			printf("%s\n", current->next->trener);
			printf("%d\n", current->next->budzet);
			printf("%d\n", current->next->pkt);
			printf("%d\n", current->next->goleZ);
			printf("%d\n", current->next->goleS);
			printf("Ilosc meczy:  %d\n", current->iloscMeczy);
			wypiszZawodnikow(rynekHead, current->next->zawHead, twojHead, glowa, stanSezonu);
			current = current->next;
		}
	}
	else {
		return;
	}
}
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
		glowa->budzet += 5000;
	}
	else if (goleA == goleB) {
		glowa->pkt += 1;
		glowa->budzet += 2500;
		drugaGlowa->pkt += 1;
		drugaGlowa->budzet += 2500;
	}
	else {
		drugaGlowa->pkt += 3;
		drugaGlowa->budzet += 5000;
	}
	glowa->iloscMeczy += 1;
	drugaGlowa->iloscMeczy += 1;
}


void symulujKolejke(kluby* glowa) {
	kluby* current = glowa;
	kluby* tmp = glowa;
	while (current->next->next != glowa) {
		symulujMecz(tmp, tmp->next);
		tmp = tmp->next->next;
		current = current->next->next;
	}
	symulujMecz(tmp, tmp->next);
}

void symulujSezon(kluby* glowa, kluby* end) {
	kluby* current = glowa;
	while (current->next != glowa && current->next != end) {
		symulujKolejke(current);
		current = current->next;
	}
}

void sSezonu(int stanSezonu, zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa) {
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
	system("cls");
	printf("The season is over, progress in league is being reset\n\n\n");
	printf("Start new season [1]\n");
	printf("Exit [2]\n\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
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
		symulujKolejke(current);
		current = current->next;
		aktualizujZespol(twojHead, current);
		stanSezonu++;
		if (stanSezonu == 15)
			sSezonu(stanSezonu, rynekHead, twojHead, glowa);
		rozgrywka(rynekHead, twojHead, current, stanSezonu);
		break;
	case '2':
		symulujSezon(current, glowa);
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

kluby* wybierzZespol(kluby* glowa) {
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



void start() {
	printf("Welome in game 'Football Mangarer' created by Adam Warzecha\n");
	printf("Start [1]\n");
	printf("Exit [2]\n");
	char liczba = '0';
	printf("Enter number below\n");
	printf("------------------\n");
	while (liczba != '1' && liczba != '2') {
		if (scanf("%c", &liczba));
	}
	switch (liczba) {
	case '1':
		return;
	case '2':
		exit(0);
		break;
	}
}

void swap(kluby** glowa, kluby** secondGlowa) {
	kluby* tmp = *glowa;
	glowa = secondGlowa;
	secondGlowa = tmp;

}

//void CyklicznaNaJednokierunkowa(kluby** pHead) {
//	if (*pHead) {
//		kluby* current = *pHead;
//		while (current->next != *pHead) {
//			current = current->next;
//		}
//		current->next = NULL;
//	}
//}
//
//void JednokierunkowaNaCykliczna(kluby** glowa) {
//	if (*glowa) {
//		kluby* current = *glowa;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = *glowa;
//	}
//}


void posortuj(kluby** glowa) {
	if (*glowa) {
		for (int i = 0; i < 15; i++) {
			kluby* current = *glowa;
			while (current->next != NULL) {
				if (current->pkt < current->next->pkt) {
					swap(&current, &current->next);
				}
				current = current->next;
			}
		}
	}
}

void kup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu) {
	system("cls");
	printf("enter player name below or '1' to back\n---------------------------\n");
	
	char tab[20] = { '0' };
	while (TRUE) {
		if (scanf("%s", &tab));
		if (tab[0]=='1')
			goto x;
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
				if ((tmp->wartosc <= twojHead->budzet) && (size<21)) {
					twojHead->budzet -= tmp->wartosc;
					tym->budzet -= tmp->wartosc;
					tym->zawHead->pNext = tmp;
					rynekHead = p;
					tym->zawHead->pNext->pNext = NULL;
				}
				goto x;
			}
			else {
				while (tmp->pNext != NULL) {
					zawodnicy* p = tmp;
					zawodnicy* temp =tmp->pNext;
					if ((stricmp(tab, temp->nazwisko)) == 0) {
						int size = 0;
						while (twojHead->nazwa != tym->nazwa) {
							tym = tym->next;
						}
						while (tym->zawHead->pNext != NULL) {
							tym->zawHead = tym->zawHead->pNext;
							size++;
						}
						if ((temp->wartosc <= twojHead->budzet) && (size<21)) {
							twojHead->budzet -= temp->wartosc;
							tym->budzet -= tmp->wartosc;
							tym->zawHead->pNext = temp;
							if (temp->pNext != NULL)
								p->pNext = temp->pNext;
							tym->zawHead->pNext->pNext = NULL;
						}
						goto x;
					}
					tmp = tmp->pNext;
				}
				if (tmp->pNext == NULL)
					printf("Wrong name!\n");
			}
		}
	}
x: menu(rynekHead, twojHead, glowa, stanSezonu);
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
			kup(rynekHead, twojHead, glowa,stanSezonu);
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
	printf("3. After simulation you will recive +5000 money if you win or +2500 if you draw\n   If you will symulate entire season you will recive money for everymatch\n");
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

