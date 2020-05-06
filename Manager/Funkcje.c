#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include "Struktury.h"


nazwyPlikow* zaladujNazwyPlikowDoListy(nazwyPlikow** pHead) {
	if (!pHead) {
		pHead = (nazwyPlikow*)malloc(sizeof(nazwyPlikow));
		return pHead;
		printf("chuj");
	}
	else {
		nazwyPlikow* current = pHead;
		while (current->next != NULL)
		current = current->next;
		current->next = (nazwyPlikow*)malloc(sizeof(nazwyPlikow));
		printf("cipa");
		return current->next;
	}
}

void pobierzNazwyPlikow(nazwyPlikow** pHead) {
	FILE* plik = fopen("NazwyPilkow.txt","r");
	if (plik) {
		const int size = 20;
		char buf[20] = { 0 };
		while (!feof(plik)) {
			fgets(buf, size, plik);
			//printf("%s\n", buf);
			nazwyPlikow* wezel = zaladujNazwyPlikowDoListy(pHead);
			wezel->tab = buf;
			wezel->next = NULL;
		}
		fclose(plik);
	}
}




void pokaz(nazwyPlikow* l) {
	if (l != NULL) {
		printf("%s ", l->tab);
		pokaz(l->next);
	}
	else {
		printf("pHead jest NULLEM :(\n");
	}
}

