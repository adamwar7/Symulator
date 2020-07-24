/** @file */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

/** Funkcja dodaje na poczatek listy nazwe pliku (iteracyjnie). Funkcja alokuje pamiec.
@param[in,out]  pHead adres nazwy pliku (poczatkowo jest nullptr)
@param buf nazwa pliku, ktora ma byc wstawiona do listy
*/
void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf);

/** Funkcja pobiera z pliku nazwe pliku a nastepnie przekazuje ta nazwe funkcji zaladujNazwyPlikowDoListy. Funkcja alokuje pamiec.
@param[in,out]  pHead adres pliku (poczatkowo jest nullptr)
*/
void pobierzNazwyPlikow(nazwyPlikow** pHead);

/** Funkcja usuwa wszystkie nazwy plikow z listy (od pocz¹tku, iteracyjnie).
@param[in,out] pHead adres pierwszej nazwy pliku w liscie
*/
void usunNazwyPlikowDoListy(nazwyPlikow** pHead);

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

/** Funkcja wypisuje zawodnikow i ich dane z naszego zespolu. Po wypisaniu zawodnikow i wprowadzeniu w konsoli '1' wywolamy
funkcje team, dzieki ktorej wrocimy do menu z naszym zespolem.
@param rynekHead adres listy rynku transferowego
@param[in,out] zawHead adres poczatku listy z zawodnikami, z ktorej bedziemy wypisywac zawodnikow
@param twojHead adres naszego klubu
@param glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozosta³o do konca sezonu
*/
void wypiszZawodnikow(zawodnicy* rynekHead, zawodnicy* zawHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

/** Funkcja usuwa wszystkie kluby z listy (od poczatku, iteracyjnie).
@param[in,out] tabela adres pierwszej nazwy klubu w liscie
*/
void zwolnijTabele(kluby** tabela);

/** Funkcja wypisuje obecna tabele ligowa i poszczegolne statystyki klubow. Funkcja alokuje pamiec. Sortuje tabele poprzez wstawianie.
Po wypisaniu tabeli, nastêpuje zwolnienie zaalokowanej pamieci.  Po wypisaniu zwolnieniu zaalokowanej pamieci i wprowadzeniu w konsoli '1' wywolamy
funkcje team, dzieki ktorej wrocimy do menu z naszym zespolem.
@param rynekHead adres listy rynku transferowego
@param twojHead adres naszego klubu
@param[in,out] glowa adres listy cyklicznej z klubami
@param stanSezonu parametr, ktory inforuje program ile meczy pozostalo do konca sezonu
*/
void wypiszTabele(zawodnicy* rynekHead, twojZespol* twojHead, kluby* glowa, int stanSezonu);

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
void symulujKolejke(kluby* glowa,int stanSezonu);

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

/** Funkcja, pobiera dane klubu, ktory wybralismy do struktury naszego zespolu. Funkcja alokuje pamiec.
@param glowa adres wybranego klubu w strukturze z klubami
@return adres naszego zespolu w strukturze z naszym klubem
*/
twojZespol* zapiszSwojZespol(kluby* glowa);

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
usunRynek(zawodnicy** rynekHead);