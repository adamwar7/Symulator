#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead,char* buf);

void pobierzNazwyPlikow(nazwyPlikow** pHead);

void usunNazwyPlikowDoListy(nazwyPlikow** pHead);

void pobierzKluby(kluby** glowa, nazwyPlikow* pHead);

void wypiszKlub(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);

void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa);

int sumujMoce(zawodnicy* zawHead);

int losujGole(int min, int max);

void symulujMecz(kluby* glowa, kluby* drugaGlowa);

void symulujKolejke(kluby* glowa);

void symulujSezon(kluby* glowa);

void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);

void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);

kluby* wybierzZespol(kluby* glowa);

void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);

twojZespol* zapiszSwojZespol(kluby* glowa);

void start();

void swap(kluby* glowa, kluby* secondGlowa);

kluby* posortuj(kluby** glowa);

void CyklicznaNaJednokierunkowa(kluby** pHead);

void JednokierunkowaNaCykliczna(kluby** glowa);

void pobierzRynek(zawodnicy** rynekHead);

void zaladujRezerwowych(zawodnicy** rynekHead, char* i, int a, int b);

void wypiszRynek(zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa);


//Ma dodawaæ zawodnika do twojego zespolu i do glowniej listy zespolow oraz usuwac zawodnika z listy rynku;
void kup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);