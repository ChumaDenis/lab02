#include "func.h"

//----------------------------------------------------------------------------------------------------------------------
void TabElem () {
    printf("==================================================================\n");
}
//----------------------------------------------------------------------------------------------------------------------
void ToNULL(struct personal* pp) {
    pp->next = NULL;
}
//----------------------------------------------------------------------------------------------------------------------
void DeleteElem (struct personal* pStart, struct personal * delete){
    int i = 0;
    struct personal *p = pStart;
    struct personal *pp;
    do{
    pp = p;
    p = p->next;
    }while(pp->next!=delete);
    pp->next = delete->next;
    free(delete);
}
//----------------------------------------------------------------------------------------------------------------------
void Tab(struct personal *pStart) {
    struct personal *pCurrent = pStart;
    TabElem();
    printf("||Surname\t||Name\t\t||Date of birth\t||Marks\t\t||\n");
    TabElem();
    while (p != NULL) {
        printf("||%10s\t||%10s\t||%2d.%2d.%d"
               "", pCurrent->surname, pCurrent->name, pCurrent->Date.day, pCurrent->Date.month, pCurrent->Date.year);
        printf("\t||%2d, %2d, %2d\t||\n", pCurrent->marks[0], pCurrent->marks[1], pCurrent->marks[2]);
        struct personal *p_Current = pCurrent->next;
        pCurrent = p_Current;
    }
    TabElem();
    printf("\n");
}
//----------------------------------------------------------------------------------------------------------------------
struct personal * swap(struct personal *pCurrent) {
    struct personal *tmp;
    tmp = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    tmp->next = tmp->next->next;
    pCurrent->next->next = tmp;
    return pCurrent->next;
}
//----------------------------------------------------------------------------------------------------------------------
struct personal * BubbleSort (struct personal * pStart) {
    struct personal *p_Current = pStart;
    while (1) {
        struct personal *pCurrent = (struct personal *) malloc(sizeof(struct personal));
        pCurrent->next = p_Current;
        int i = 0;
        while (pCurrent->next->next != NULL) {
            if (strcmp(pCurrent->next->surname, pCurrent->next->next->surname) > 0) {
                i = 1;
                if (pCurrent->next == p_Current) {
                    p_Current = swap(pCurrent);
                } else {
                    swap(pCurrent);
                }
            }
            pCurrent = pCurrent->next;
        }
        if (!i) {
            return p_Current;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void ScanPersonalDate (struct personal * pCurrent, FILE * input) {
    struct personal *AddListItem = pCurrent;
    if (!input) {
        scanf("%s %s", &(AddListItem->surname), &(AddListItem->name));
        scanf_s("%i %i %i", &(AddListItem->Date.day), &(AddListItem->Date.month), &(AddListItem->Date.year));
        scanf_s("%i %i %i", &AddListItem->marks[0], &AddListItem->marks[1], &AddListItem->marks[2]);
    } else {
        fscanf(input, "%s %s", &AddListItem->surname, &AddListItem->name);
        fscanf(input, "%d %d %d", &AddListItem->Date.day, &AddListItem->Date.month, &AddListItem->Date.year);
        fscanf(input, "%d %d %d", &AddListItem->marks[0], &AddListItem->marks[1], &AddListItem->marks[2]);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void AddStudent (struct personal * pStart, FILE* input) {
    struct personal *pCurrent = pStart;
    struct personal *AddListItem = (struct personal *) malloc(sizeof(struct personal));;
    printf("Enter personal information about the student you want to add:\n");
    ScanPersonalDate(AddListItem, input);
    while (pCurrent->next != NULL) {
        if (pCurrent->next != NULL) {
            pCurrent = pCurrent->next;
        }
    }
    pCurrent->next = AddListItem;
    ToNULL(AddListItem);
}
//----------------------------------------------------------------------------------------------------------------------
struct personal * DeleteStudent(struct personal * pStart) {
    struct personal *x = (struct personal *) malloc(sizeof(struct personal));
    x->next = pStart;
    struct personal *pCurrent = x;
    while (p != NULL) {
        struct personal *p_Current = p;
        if ((pCurrent->next->marks[0] == 3) && (pCurrent->next->marks[2] == 3)) {
            DeleteElem(pStart, p_Current->next);
        }
        pCurrent = pCurrent->next;
    }
    return x->next;
}
