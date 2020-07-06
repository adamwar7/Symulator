#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf);

void pobierzNazwyPlikow(nazwyPlikow** pHead);

void usunNazwyPlikowDoListy(nazwyPlikow** pHead);

void zaladujRezerwowych(zawodnicy** rynekHead, char* i, int a, int b);

void pobierzRynek(zawodnicy** rynekHead);

void pobierzKluby(kluby** glowa, nazwyPlikow* pHead);

void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void zwolnijTabele(kluby** tabela);

void wypiszTabele(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void wypiszKlub(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void aktualizuj(twojZespol* twojHead, kluby* glowa);

void aktualizujZespol(twojZespol* twojHead, kluby* glowa);

int sumujMoce(zawodnicy* zawHead);

int losujGole(int min, int max);

void symulujMecz(kluby* glowa, kluby* drugaGlowa);

void symulujKolejke(kluby* glowa);

void symulujSezon(kluby* glowa, kluby* end);

void sSezonu(int stanSezonu, zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);

void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

twojZespol* zapiszSwojZespol(kluby* glowa);

kluby* wybierzZespol(kluby* glowa);

void start();

void swap(kluby** glowa, kluby** secondGlowa);

void posortuj(kluby** glowa);

void kup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void wypiszRynek(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void rules(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

void usunListeZawodnikow(zawodnicy* rynekHead);

void usunKluby(kluby* glowa);

void usunTwojZespol(twojZespol** twojHead);