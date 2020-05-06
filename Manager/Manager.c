#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include "Struktury.h"
#include "Funkcje.h"


int main() {
	nazwyPlikow* pHead = NULL;
    pobierzNazwyPlikow(pHead);
    pokaz(pHead);
	system("pause");
	return 0;
}

