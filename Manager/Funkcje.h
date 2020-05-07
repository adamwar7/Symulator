#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


nazwyPlikow* zaladujNazwyPlikowDoListy(nazwyPlikow** pHead,char* buf);


void pobierzNazwyPlikow(nazwyPlikow** pHead);


void pokaz(nazwyPlikow* head);