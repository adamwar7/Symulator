#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Struktury.h"
#include "ZwalnianiePamieci.h"
#include "FunkcjeInterfejsu.h"
#include "Pobieranie.h"
#include "Symulacja.h"


int main() {
	nazwyPlikow* pHead = NULL;
	kluby* glowa = NULL;
	zawodnicy* rynek = NULL;
	int stanSezonu = 0;
	pobierzRynek(&rynek);
	pobierzNazwyPlikow(&pHead);
	pobierzKluby(&glowa, pHead);
	twojZespol* twojHead = zapiszSwojZespol(wybierzZespol(glowa));
	menu(rynek, twojHead, glowa, stanSezonu);
	usunRynek(&rynek);
	usunTwojZespol(&twojHead);
	usunNazwyPlikowDoListy(&pHead);
	usunKluby(&glowa);
	return 0;
}