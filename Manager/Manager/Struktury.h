/** @file  */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

/** struktura listy jednokierunkowej */
typedef struct nazwyPlikow {
	char* tab; ///< napis przechowawany w liscie (nazwa pliku)
	struct nazwyPlikow* next; ///< adres nastepnego elementu listy
}nazwyPlikow;

/** struktura listy jednokiernukowej */
typedef struct zawodnicy {
	char* nazwisko;  ///< napis przechowywany w liscie (nazwisko pilkarza)
	int moc; ///< punkty umiejetnosci pilkarza
	int wartosc; ///< wartosc rynkowa pilkarza
	struct zawodnicy* pNext;  ///< adres nastepnego pilkarza
}zawodnicy;


/** struktura listy jednokierunkowej (cyklicznej) */
typedef struct kluby {
	char* nazwa;  ///< napis przechowywany w liscie (nazwa klubu)
	char* trener; ///< napis przechowywany w liscie (nazwisko trenera)
	int budzet; ///< budzet zespolu
	int goleZ; ///< gole zdobyte
	int goleS; ///< gole stracone
	int bilans; ///< bilans bramkowy
	int pkt; ///< punkty
	int iloscMeczy; ///< ilosc rozegranych meczy
	struct kluby* next; ///< adres nastepnego klubu
	struct zawodnicy* zawHead; ///< adres pierwszego zawodnika z listy zawodnikow
}kluby;

/** struktura , w ktorej przechowywane sa dane o wybranym zespole */
typedef struct twojZespol {
	char* nazwa; ///< napis przechowywany w liscie (nazwa klubu)
	char* trener; ///< napis przechowywany w liscie (nazwisko trenera)
	int budzet; ///< budzet zespolu
	int goleZ; ///< gole zdobyte
	int goleS; ///< gole stracone
	int bilans; ///< bilans bramkowy
	int pkt; ///< punkty
	int iloscMeczy; ///< ilosc rozegranych meczy
	struct zawodnicy* zawHead; ///< adres pierwszego zawodnika z listy zawodnikow
}twojZespol;