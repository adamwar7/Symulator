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

/** Funkcja wypisuje zawodnikow i ich dane z naszego zespolu. Po wypisaniu zawodnikow i wprowadzeniu w konsoli '1' wywolamy
funkcje team, dzieki ktorej wrocimy do menu z naszym zespolem.
@param rynekHead adres listy rynku transferowego
@param[in,out] zawHead adres poczatku listy z zawodnikami, z ktorej bedziemy wypisywac zawodnikow
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozosta³o do konca sezonu
*/
void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja wypisuje obecna tabele ligowa i poszczegolne statystyki klubow. Funkcja alokuje pamiec. Sortuje tabele poprzez wstawianie.
Po wypisaniu tabeli, nastêpuje zwolnienie zaalokowanej pamieci.  Po wypisaniu zwolnieniu zaalokowanej pamieci i wprowadzeniu w konsoli '1' wywolamy
funkcje team, dzieki ktorej wrocimy do menu z naszym zespolem.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param[in,out] glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void wypiszTabele(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja, ktora jest menu naszego zespolu, podczas wywolania tej funckji mozemy wywolac inne funkcje, dzieki ktorym,
zobaczymy aktualna tabele, naszych zawodnikow czy wrocimy do menu glownego.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void team(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja, ktora przedstawia glowne menu rozgrywki, mozemy podczas wywolania tej funkcji przez do symulacji, menu naszego zespolu,
rynku transferowego, zasad gry, b¹dz wyjscia z gry.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void menu(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja, w ktorej podczas wywolania mozemy symulowac mecz lub caly sezon albo wrocic do menu glownego.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void rozgrywka(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja, w wywolaniu ktorej, wybieramy zespol.
@param glowa adres listy cyklicznej z klubami
*/
kluby* wybierzZespol(kluby* glowa);

/** Funkcja, ktora umozliwia zakup zawodnika z listy transferowej do naszego zespolu.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void kup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja odpowiada za wypisanie listy z zawodnikami do kupienia.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void wypiszRynek(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja wypisuje najwazniesze informacje o rozgrywce.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void rules(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja informuje gracza o nieudanym zakupie pilkarza i pozwala wrocic do menu glownego.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void nieudanyZakup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja informuje gracza o udanym zakupie pilkarza i pozwala wrocic do menu glownego.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void udanyZakup(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);
