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
/** Funkcja aktualizuje nasz zespol, pobiera dane o klubie, ktory wybralismy.
@param twojHead adres naszego zespolu
@param glowa adres listy cyklicznej z klubami
*/
void aktualizuj(twojZespol* twojHead, kluby* glowa);

/** Funkcja szuka naszego klubu w liscie cyklicznej z klubami i przekazuje adres naszego klubu funkcji aktualizuj.
@param twojHead adres naszego zespolu
@param glowa adres listy cyklicznej z klubami
*/
void aktualizujZespol(twojZespol* twojHead, kluby* glowa);

/** Funkcja sumuje moce kazdego z zawodnikow i zwraca sume mocy wszystkich zawodnikow
@param zawHead adres poczatku listy z zawodnikami
@return suma mocy zawodnikow w zespole
*/
int sumujMoce(zawodnicy* zawHead);

/** Funkcja losuje gole na podstawie mocy zespolu i zwraca ilosc goli strzelonych.
@param min minimalny przedzial
@param max maksymalny przedzial
@return ilosc goli
*/
int losujGole(int min, int max);

/** Funkcja odpowiada za symulowanie pojedynczego meczu.
@param glowa adres pierwszego zespolu
@param drugaGlowa adres drugiego zespolu
*/
void symulujMecz(kluby* glowa, kluby* drugaGlowa);

/** Funkcja symuluje cala kolejke, tak aby kazdy klub gral z kazdym.
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void symulujKolejke(kluby* glowa, int stanSezonu);

/** Funkcja, ktora symuluje caly sezon, po zakonczeniu symulacji zostaje wywolana funkcja sSezonu.
@param glowa adres listy cyklicznej z klubami
@param end adres listy cyklicznej z klubami, do ktorego beda odbywaly sie symulacje
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void symulujSezon(kluby* glowa, kluby* end, int stanSezonu);

/** Funkcja, ktora wypisuje stan rozgrywek po zakonczeniu sezonu i daje mozliwosc zaczecia nowego sezonu lub zamkniecia gry.
@param stanSezonu parametr, który inforuje program ile meczy pozostalo do konca sezonu
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
*/
void sSezonu(int stanSezonu, zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa);