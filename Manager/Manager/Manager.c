#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Struktury.h"
#include "Funkcje.h"


int main() {
	nazwyPlikow* pHead = NULL;
	kluby* glowa = NULL;
	zawodnicy* rynek = NULL;
	int stanSezonu = 0;
	pobierzRynek(&rynek);
	pobierzNazwyPlikow(&pHead);
	pobierzKluby(&glowa, pHead);
	start(glowa);
	twojZespol* twojHead = zapiszSwojZespol(wybierzZespol(glowa));
	usunNazwyPlikowDoListy(&pHead);
	menu(rynek,twojHead,glowa,stanSezonu);
	//usunListeZawodnikow(&rynek);
	usunTwojZespol(&twojHead);
//	usunKluby(&glowa);
	return 0;
}

