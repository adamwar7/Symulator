#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include "Struktury.h"


void zaladujNazwyPlikowDoListy(nazwyPlikow** pHead,char* buf) {
	if (*pHead) {
		nazwyPlikow* current = malloc(sizeof(nazwyPlikow));
		current->tab = buf;
		current->next = (*pHead);
		*pHead = current;
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
			zaladujNazwyPlikowDoListy(&pHead,buf);			
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

