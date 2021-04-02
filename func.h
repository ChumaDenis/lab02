#ifndef MAIN_C_FUNC_H
#define MAIN_C_FUNC_H

//----------------------------------------------------------------------------------------------------------------------
//Displays one of the table elements
void TabElem ();
//----------------------------------------------------------------------------------------------------------------------
//Zeroes the pointer(pp) to the personal structure
void ToNULL(struct personal* pp);
//----------------------------------------------------------------------------------------------------------------------
//Removes one item from the student list
//The first(pStart) is a pointer to the head of the list
//The second(delete) is a pointer to the item we want to delete
void DeleteElem (struct personal* pStart, struct personal * delete);
//----------------------------------------------------------------------------------------------------------------------
//Displays a table of elements
void Tab(struct personal *pStart);
//----------------------------------------------------------------------------------------------------------------------
//Swaps the next two elements pointed to by pCurrent
//Returns a pointer to the next item from pCurrent
struct personal * swap(struct personal *pCurrent);
//----------------------------------------------------------------------------------------------------------------------
//Sorts the list by bubble method by last name
//The function returns a pointer to the head of the sorted list
struct personal * BubbleSort (struct personal * pStart);
//----------------------------------------------------------------------------------------------------------------------
//The function reads data about the student
//Pointer (p) indicates the list item in which the data will be written
//Input pointer:
//If input == NULL , then we enter data from the console
//Else reading data comes from a file
void ScanPersonalDate (struct personal * pCurrent, FILE * input);
//----------------------------------------------------------------------------------------------------------------------
//Adds a new item (personal information about the student) to the end of the list
//We pass the second value(input) in order to use the ScanPersonalDate () function
void AddStudent (struct personal * pStart, FILE* input);
//----------------------------------------------------------------------------------------------------------------------
//Removes items from the list by attribute (if the first and second score is 3)
//Returns a pointer to the head of the list
struct personal * DeleteStudent(struct personal * pStart);
//----------------------------------------------------------------------------------------------------------------------


#endif //MAIN_C_FUNC_H
