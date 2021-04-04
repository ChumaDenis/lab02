#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
struct personal {
    char surname[10];
    char name[10];
    struct DateOfBirth {
        int day;
        int month;
        int year;
    } Date;
    int marks[3];
    struct personal *next;
} ;



//----------------------------------------------------------------------------------------------------------------------
int main() {
    FILE *input;
    input = fopen("input.txt", "r");
    if (!input) return 1;
    struct personal *pCurrent = (struct personal *) malloc(sizeof(struct personal));
    struct personal *pStart = (struct personal *) malloc(sizeof(struct personal));

    pStart->next = NULL;
    while (!feof(input)) {
        ScanPersonalDate(pCurrent, input);
        if (pStart->next == NULL) {
            pStart = pCurrent;
        }
        if (!feof(input)) {
            struct personal *pp = (struct personal *) malloc(sizeof(struct personal));
            pCurrent->next = pp;
            pCurrent = pp;
        }

    }
    ToNULL(pCurrent);
    fclose(input);
    input = NULL;
    Tab(pStart);

    pCurrent = pStart;
    while (pCurrent->next != NULL) {
        struct personal *pp = pCurrent;
        pCurrent = pCurrent->next;
        if (!((pp->Date.month == 9) || (pp->Date.month == 10) || (pp->Date.month == 11))) {
            DeleteElem(pStart, pp);
        }

    }

    pStart = BubbleSort(pStart);
    printf("Sorted list of those born in autumn.\n");
    Tab(pStart);

    int cont = 0;
    printf("Enter num:");
    scanf_s("%i", &cont);
    switch (cont) {
        case 1: {
            AddStudent(pStart, input);
            start = BubbleSort(pStart);
            break;
        };
        case 2: {
            start = DeleteStudent(pStart);
            break;
        };
        default:
            return 3;
    }
    if (cont == 1) {
        printf("list after adding one element:\n");
        Tab(pStart);
    } else if (cont == 2) {
        printf("List after deleting elements by attribute:\n");
        Tab(pStart);
    }
    return 0;
}