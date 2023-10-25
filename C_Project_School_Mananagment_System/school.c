/*
 * school.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Asus
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "school.h"
#include "ErrorState.h"


#define MAX_STUDENTS 100



ErrorState_t List_init(List_t* pl) {
    pl->pHead = pl->pTail = NULL;
    pl->ListSize = 0;
    return SUCCESS;
}

ErrorState_t List_insertStudent(List_t* pl, const ListEntry_t* pe) {
    if (pl->ListSize >= MAX_STUDENTS) {
        return OUT_OF_RANGE_ERR;
    }

    ListNode_t* newNode = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (newNode == NULL) {
        return NULL_PTR;
    }

    newNode->entry = *pe;
    newNode->pNext = NULL;
    newNode->pPrev = pl->pTail;

    if (pl->pTail == NULL) {
        pl->pHead = pl->pTail = newNode;
    } else {
        pl->pTail->pNext = newNode;
        pl->pTail = newNode;
    }

    pl->ListSize++;

    return SUCCESS;
}

ErrorState_t List_searchStudent(const List_t* pl, u8 copy_u8ID, ListNode_t** pFoundStudent) {
    ListNode_t* current = pl->pHead;
    while (current != NULL) {
        if (current->entry.ID == copy_u8ID) {
            *pFoundStudent = current;
            return SUCCESS;
        }
        current = current->pNext;
    }

    return OUT_OF_RANGE_ERR;
}

ErrorState_t List_deleteStudent(List_t* pl, u8 copy_u8ID) {
    ListNode_t* current = pl->pHead;
    ListNode_t* prev = NULL;

    while (current != NULL) {
        if (current->entry.ID == copy_u8ID) {
            if (prev == NULL) {
                // If the first node matches, update the head pointer
                pl->pHead = current->pNext;
            } else {
                // Update the previous node's next pointer to skip the current node
                prev->pNext = current->pNext;
            }

            if (current->pNext == NULL) {
                // If the deleted node is the last one, update the tail pointer
                pl->pTail = prev;
            }

            free(current);
            pl->ListSize--;
            return SUCCESS;
        }

        prev = current;
        current = current->pNext;
    }

    return OUT_OF_RANGE_ERR; // Student with the specified ID was not found
}

ErrorState_t List_editStudent(const List_t* pl, u8 copy_u8ID) {
    ListNode_t* foundStudent = NULL;
    ErrorState_t result = List_searchStudent(pl, copy_u8ID, &foundStudent);
    if (result != SUCCESS) {
        return result;
    }

    printf("Editing Student with ID %d:\n", foundStudent->entry.ID); fflush(stdout);
    printf("Enter new name: "); fflush(stdout);
    scanf("%s", foundStudent->entry.Name); fflush(stdin);
    printf("Enter new age: "); fflush(stdout);
    scanf("%hhu", &foundStudent->entry.age); fflush(stdin);

    return SUCCESS;
}

ErrorState_t List_updateScore( List_t* pl, u8 copy_u8ID) {
    ListNode_t* foundStudent = NULL;
    ErrorState_t result = List_searchStudent(pl, copy_u8ID, &foundStudent);
    if (result != SUCCESS) {
        return result;
    }

    // Implement the score update logic here
    printf("Updating scores for Student with ID %d:\n", foundStudent->entry.ID); fflush(stdout);
    printf("Enter new math degree: "); fflush(stdout);
    scanf("%hhu", &foundStudent->entry.degress.math_deg); fflush(stdin);
    printf("Enter new English degree: "); fflush(stdout);
    scanf("%hhu", &foundStudent->entry.degress.english_deg); fflush(stdin);
    printf("Enter new Arabic degree: "); fflush(stdout);
    scanf("%hhu", &foundStudent->entry.degress.arabic_deg); fflush(stdin);

    return SUCCESS;
}

ErrorState_t List_printList(const List_t* pl) {
    ListNode_t* current = pl->pHead;
    if (current == NULL) {
        printf("The list is empty.\n"); fflush(stdout);
        return SUCCESS;
    }

    printf("List of Students:\n"); fflush(stdout);
    while (current != NULL) {
        printf("Student ID: %d\n", current->entry.ID); fflush(stdout);
        printf("Name: %s\n", current->entry.Name); fflush(stdout);
        printf("Age: %d\n", current->entry.age); fflush(stdout);
        printf("Math Degree: %d\n", current->entry.degress.math_deg);  fflush(stdout);
        printf("English Degree: %d\n", current->entry.degress.english_deg); fflush(stdout);
        printf("Arabic Degree: %d\n", current->entry.degress.arabic_deg); fflush(stdout);
        printf("\n"); fflush(stdout);

        current = current->pNext;
    }

    return SUCCESS;
}

ErrorState_t  List_listSize(const List_t* pl ,u32 * pSize) {
    *pSize = pl->ListSize;
    return SUCCESS;
}

ErrorState_t List_freeList(List_t* pl) {
    ListNode_t* current = pl->pHead;
    while (current != NULL) {
        ListNode_t* next = current->pNext;
        free(current);
        current = next;
    }
    pl->pHead = pl->pTail = NULL;
    pl->ListSize = 0;
    return SUCCESS;
}
