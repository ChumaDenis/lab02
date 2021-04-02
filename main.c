#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct personal
{
    char surname[10];
    char name[10];
    struct DateOfBirth
    {
        int day;
        int month;
        int year;
    } Date;
    int marks[3];
    struct personal * next;
} ;


//----------------------------------------------------------------------------------------------------------------------
//Displays one of the table elements
void TabElem ()
{
    printf("==================================================================\n");
}
//----------------------------------------------------------------------------------------------------------------------
//Zeroes the pointer(pp) to the personal structure
void ToNULL(struct personal* pp)
{
    pp->next=NULL;
}
//----------------------------------------------------------------------------------------------------------------------
//Removes one item from the student list
//The first(pStart) is a pointer to the head of the list
//The second(delete) is a pointer to the item we want to delete
void DeleteElem (struct personal* pStart, struct personal * delete)
{
    int i=0;
    struct personal * p= pStart;
    struct personal * pp;
    do
    {
        pp=p;
        p= p->next;
    } while(pp->next!=delete);
    pp->next=delete->next;
    free(delete);
}
//----------------------------------------------------------------------------------------------------------------------
//Displays a table of elements
void Tab(struct personal *pStart)
{
    struct personal* pCurrent= pStart;
    TabElem ();
    printf("||Surname\t||Name\t\t||Date of birth\t||Marks\t\t||\n");
    TabElem ();
    while(p!=NULL)
    {
        printf("||%10s\t||%10s\t||%2d.%2d.%d"
               "", pCurrent->surname, pCurrent->name, pCurrent->Date.day, pCurrent->Date.month, pCurrent->Date.year);
        printf("\t||%2d, %2d, %2d\t||\n", pCurrent->marks[0], pCurrent->marks[1], pCurrent->marks[2]);
        struct personal * p_Current = p->next;
        pCurrent=p_Current;
    }
    TabElem ();
    printf("\n");
}
//----------------------------------------------------------------------------------------------------------------------
//Swaps the next two elements pointed to by pCurrent
//Returns a pointer to the next item from pCurrent
struct personal * swap(struct personal *pCurrent)
{
    struct personal* tmp;
    tmp = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    tmp->next = tmp->next->next;
    pCurrent->next->next = tmp;
    return pCurrent->next;
}
//----------------------------------------------------------------------------------------------------------------------
//Sorts the list by bubble method by last name
//The function returns a pointer to the head of the sorted list
struct personal * BubbleSort (struct personal * pStart)
{
    struct personal *p_Current=pStart;
    while(1)
    {
        struct personal *pCurrent=(struct personal *) malloc(sizeof(struct personal));
        pCurrent->next = p_Current;
        int i=0;
        while (pCurrent->next->next !=NULL)
        {
            if (strcmp(pCurrent->next->surname, pCurrent->next->next->surname) > 0)
            {
                i = 1;
                if(pCurrent->next == p_Current)
                {
                    p_Current=swap(pCurrent);
                }
                else
                {
                    swap(pCurrent);
                }
            }
            pCurrent = pCurrent->next;
        }
        if(!i)
        {
            return p_Current;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
//The function reads data about the student
//Pointer (p) indicates the list item in which the data will be written
//Input pointer:
//If input == NULL , then we enter data from the console
//Else reading data comes from a file
void ScanPersonalDate (struct personal * pCurrent, FILE * input)
{
    struct personal * AddListItem=pCurrent;
    if(!input)
    {
        scanf("%s %s", &(AddListItem->surname), &(AddListItem->name));
        scanf_s("%i %i %i", &(AddListItem->Date.day), &(AddListItem->Date.month), &(AddListItem->Date.year));
        scanf_s("%i %i %i", &AddListItem->marks[0], &AddListItem->marks[1], &AddListItem->marks[2]);
    }
    else
    {
        fscanf(input, "%s %s", &AddListItem->surname, &AddListItem->name);
        fscanf(input, "%d %d %d", &AddListItem->Date.day, &AddListItem->Date.month, &AddListItem->Date.year);
        fscanf(input, "%d %d %d", &AddListItem->marks[0], &AddListItem->marks[1], &AddListItem->marks[2]);
    }
}
//----------------------------------------------------------------------------------------------------------------------
//Adds a new item (personal information about the student) to the end of the list
//We pass the second value(input) in order to use the ScanPersonalDate () function
void AddStudent (struct personal * pStart, FILE* input)
{
    struct personal * pCurrent = pStart;
    struct personal * AddListItem=(struct personal *) malloc(sizeof(struct personal));;
    printf("Enter personal information about the student you want to add:\n");
    ScanPersonalDate(AddListItem, input);
    while(pCurrent->next!=NULL)
    {
        if(pCurrent->next!=NULL)
        {
            pCurrent=pCurrent->next;
        }
    }
    pCurrent->next=AddListItem;
    ToNULL(AddListItem);
}
//----------------------------------------------------------------------------------------------------------------------
//Removes items from the list by attribute (if the first and second score is 3)
//Returns a pointer to the head of the list
struct personal * DeleteStudent(struct personal * pStart)
{
    struct personal *x=(struct personal *) malloc(sizeof(struct personal));
    x->next = pStart;
    struct personal *pCurrent=x;
    while(p!=NULL)
    {
        struct personal * p_Current=p;
        if((pCurrent->next->marks[0]==3)&&(pCurrent->next->marks[2]==3))
        {
            DeleteElem(pStart, p_Current->next);
        }
        pCurrent= pCurrent->next;
    }
    return x->next;
}
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
    input=NULL;
    Tab(pStart);

    pCurrent = pStart;
    while (pCurrent->next != NULL) {
        struct personal *pp = pCurrent;
        pCurrent = pCurrent->next;
        if (!((pp->Date.month == 9) || (pp->Date.month == 10) || (pp->Date.month == 11))) {
            DeleteElem(pStart, pp);
        }

    }

    pStart=BubbleSort(pStart);
    printf("Sorted list of those born in autumn.\n");
    Tab(pStart);

    int cont=0;
    printf("Enter num:");
    scanf_s("%i", &cont);
    switch (cont)
    {
        case 1:
            {
                AddStudent(pStart, input);
                start=BubbleSort(pStart);
                break;
            };
        case 2:
            {
                start=DeleteStudent(pStart);
                break;
            };
        default:
                return 3;
    }
    if(cont==1)
    {
        printf("list after adding one element:\n");
        Tab(pStart);
    }
    else if (cont==2)
    {
        printf("List after deleting elements by attribute:\n");
        Tab(pStart);
    }
    return 0;
}