/** @file */
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
/** Funkcja dodaje na poczatek listy nazwe pliku (iteracyjnie). Funkcja alokuje pamiec.
@param[in,out]  pHead adres nazwy pliku (poczatkowo jest nullptr)
@param buf nazwa pliku, ktora ma byc wstawiona do listy
*/
void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf);

/** Funkcja pobiera z pliku nazwe pliku a nastepnie przekazuje ta nazwe funkcji zaladujNazwyPlikowDoListy. Funkcja alokuje pamiec.
@param[in,out]  pHead adres pliku (poczatkowo jest nullptr)
*/
void pobierzNazwyPlikow(nazwyPlikow** pHead);

/** Funkcja dodaje na poczatek listy zawodnika (iteracyjnie). Funkcja alokuje pamiec.
@param[in,out]  rynekHead adres zawodnika z rynku transferowego (poczatkowo jest nullptr)
@param i nazwisko zawodnika, ktory ma byc wstawiona do listy
@param a moc zawodnika, ktora ma byc wstawiona do listy
@param b wartosc zawodnika, ktora ma byc wstawiona do listy
*/
void zaladujRezerwowych(zawodnicy** rynekHead, char* i, int a, int b);

/** Funkcja pobiera z pliku zawodnikow a nastepnie przekazuje pobrane dane do funkcji zaladujRezerwowych. Funkcja alokuje pamiec.
@param[in,out] rynekHead adres zawodnika z rynku transferowego (poczatkowo jest nullptr)
*/
void pobierzRynek(zawodnicy** rynekHead);

/** Funkcja pobiera z plikow wszystkie dane o klubach w sposob rekurencyjny. Funkcja alokuje pamiec. Funkcja zapisuje dane do listy cyklicznej.
@param[in,out] glowa adres klubu (poczatkowo jest nullptr)
@param pHead adres, w ktorym jest zapisana nazwaPliku, z ktorego pobieramy dane
*/
void pobierzKluby(kluby** glowa, nazwyPlikow* pHead);

/** Funkcja, pobiera dane klubu, ktory wybralismy do struktury naszego zespolu. Funkcja alokuje pamiec.
@param glowa adres wybranego klubu w strukturze z klubami
@return adres naszego zespolu w strukturze z naszym klubem
*/
twojZespol* zapiszSwojZespol(kluby* glowa);