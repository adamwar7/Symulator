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

/**Funkcja ktora usuwa liste zawodnikow w klubie.
@param rynekHead adres listy jednokierunkowej z zawodnikami
*/
void clear(zawodnicy* rynekHead);

/** Funkcja, ktora usuwa wszystkie kluby z listy jednokierunkowej cyklicznej. Przed usunieciem danego klubu wywolywana jest funkcja
usunListeZawodnikow, ktora dla ka¿dego klubu usuwa jego zawodnikow.
@param glowa adres listy cyklicznej jednokierunkowej z klubami
*/
void usunKluby(kluby** glowa);

/** Funkcja, ktora usuwa zaalokowana pamiec w strukturze twojZespol.
@param twojHead adres naszej struktury
*/
void usunTwojZespol(twojZespol** twojHead);

/** Funkcja, usuwa zaalokowana pamiec dla zawodnikow z listy rezerwowych.
@param rynekHead poczatek listy jednokierunkowej z zawodnikami
*/
void usunRynek(zawodnicy** rynekHead);

/** Funkcja usuwa wszystkie nazwy plikow z listy (od pocz¹tku, iteracyjnie).
@param[in,out] pHead adres pierwszej nazwy pliku w liscie
*/
void usunNazwyPlikowDoListy(nazwyPlikow** pHead);

/** Funkcja usuwa wszystkie kluby z listy (od poczatku, iteracyjnie).
@param[in,out] tabela adres pierwszej nazwy klubu w liscie
*/
void zwolnijTabele(kluby** tabela);