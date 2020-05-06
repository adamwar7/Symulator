#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct nazwyPlikow {
	char* tab;
	struct nazwyPlikow* next;
}nazwyPlikow;