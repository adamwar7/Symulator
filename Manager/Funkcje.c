#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include "Struktury.h"

void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead, char* buf)
{
	nazwyPlikow* current = malloc(sizeof(nazwyPlikow));
	current->tab = buf;
	current->next = (*pHead);
	*pHead = current;
}

void pobierzNazwyPlikow(nazwyPlikow** pHead)
{
	FILE* plik = fopen("NazwyPilkow.txt", "r");
	if (plik)
	{
		int sizeofpliks = 12;
		for (int i = 0; i < sizeofpliks; i++) {
			char* i = malloc(10 * sizeof(i));
			if (!feof(plik)) {


				fscanf(plik, "%s", i);
				//printf("%p, %p\n", pHead, *pHead);
				//printf("%s\n", i);
				zaladujNazwyPlikowDoListy(pHead, i);
			}
		}
		fclose(plik);
	}
}

void pokaz(nazwyPlikow* l)
{
	if (l != NULL)
	{
		printf("%s\n", l->tab);
		pokaz(l->next);
	}
	else
	{
		return;
	}
}


void usunNazwyPlikowDoListy(nazwyPlikow** pHead)
{
	nazwyPlikow* tmp = NULL;

	while (*pHead != NULL) {
		tmp = (*pHead)->next;
		free(*pHead);
		*pHead = tmp;
	}

}
