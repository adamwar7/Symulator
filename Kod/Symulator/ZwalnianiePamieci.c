#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Struktury.h"

void clear(zawodnicy* first)
{
	zawodnicy* current = first;
	zawodnicy* next = NULL;

	while (current != NULL && current->pNext != NULL)
	{
		next = current;
		current = current->pNext;
		free(next);

	}
}
void usunKluby(kluby** glowa) {
	kluby* tmp = NULL;
	kluby* poczatek = (*glowa);
	while ((*glowa)->next != NULL) {
		tmp = (*glowa)->next;
		(*glowa)->next = tmp->next;
		free(tmp);
		zawodnicy* current = NULL;
		zawodnicy* abc = (*glowa)->zawHead;
		while (abc->pNext != NULL) {
			current = abc;
			abc = abc->pNext;
			free(current);
		}
		if ((*glowa)->next == poczatek) {
			(*glowa) = NULL;
			free(poczatek);
			break;
		}
		(*glowa) = (*glowa)->next;
	}
}


void usunTwojZespol(twojZespol** twojHead) {
	clear((*twojHead)->zawHead);
	free(*twojHead);
}

void usunRynek(zawodnicy** rynekHead) {
	zawodnicy* current = NULL;
	while ((*rynekHead)->pNext != NULL) {
		current = (*rynekHead);
		(*rynekHead) = (*rynekHead)->pNext;
		free(current);
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

void zwolnijTabele(kluby** tabela) {
	kluby* tmp = NULL;
	while (*tabela != NULL) {
		tmp = (*tabela)->next;
		free(*tabela);
		*tabela = tmp;
	}
}