/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Asus
 */

#include "school.h"
#include <stdio.h>
#include "school.h"
 List_t studentList;

 int main()

{


	ErrorState_t result = List_init(&studentList);
    if (result != SUCCESS) {
        printf("List initialization failed!\n"); fflush(stdout);
        return 1;
}


    while(1) {

        printf("\nMenu:\n"); 	fflush(stdout);
        printf("1. Insert Student\n"); fflush(stdout);
        printf("2. Edit Student\n");	fflush(stdout);
        printf("3. Update Scores\n"); fflush(stdout);
        printf("4. Print Student List\n"); fflush(stdout);
        printf("5. List Size\n"); fflush(stdout);
        printf("6. Delete Student\n"); fflush(stdout);
        printf("7. Quit\n"); fflush(stdout);
        printf("Select an option: "); fflush(stdout);

        int choice;
        scanf("%d", &choice); fflush(stdin);

        switch (choice) {
            case 1: {
                ListEntry_t student;
                printf("Enter Student ID: "); fflush(stdout);
                scanf("%hhu", &student.ID);  fflush(stdin);
                printf("Enter Name: "); fflush(stdout);
                scanf("%s", student.Name); fflush(stdin);
                printf("Enter Age: "); fflush(stdout);
                scanf("%hhu", &student.age); fflush(stdin);
                printf("Enter Math Degree: "); fflush(stdout);
                scanf("%hhu", &student.degress.math_deg); fflush(stdin);
                printf("Enter English Degree: "); fflush(stdout);
                scanf("%hhu", &student.degress.english_deg); fflush(stdin);
                printf("Enter Arabic Degree: "); fflush(stdout);
                scanf("%hhu", &student.degress.arabic_deg); fflush(stdin);

                result = List_insertStudent(&studentList, &student);

                if (result == SUCCESS) {
                    printf("Student inserted successfully!\n");  fflush(stdout);
                } else {
                    printf("Failed to insert student!\n");  fflush(stdout);
                }
                break;
            }

            case 2: {
                printf("Enter Student ID to edit: ");  fflush(stdout);
                u32 studentID;
                scanf("%hhu", &studentID); fflush(stdin);
                result = List_editStudent(&studentList, studentID);

                if (result == SUCCESS) {
                    printf("Student information updated!\n"); fflush(stdout);
                } else {
                    printf("Failed to update student information!\n"); fflush(stdout);
                }
                break;
            }

            case 3: {
                printf("Enter Student ID to update scores: "); fflush(stdout);
                u32 studentID;
                scanf("%hhu", &studentID); fflush(stdin);
                result = List_updateScore(&studentList, studentID);

                if (result == SUCCESS) {
                    printf("Student scores updated!\n"); fflush(stdout);
                } else {
                    printf("Failed to update student scores!\n"); fflush(stdout);
                }
                break;
            }

            case 4: {
                result = List_printList(&studentList);
                break;
            }

            case 5: {
                u32 size;
                result = List_listSize(&studentList, &size);

                if (result == SUCCESS) {
                    printf("List size: %u\n", size);  fflush(stdout);
                } else {
                    printf("Failed to get list size!\n");  fflush(stdout);
                }
                break;
            }

            case 6: {
                printf("Enter Student ID to delete: ");  fflush(stdout);
                u32 studentID;
                scanf("%hhu", &studentID); fflush(stdin);
                result = List_deleteStudent(&studentList, studentID);

                if (result == SUCCESS) {
                    printf("Student deleted successfully!\n"); fflush(stdout);
                } else {
                    printf("Failed to delete student!\n"); fflush(stdout);
                }
                break;
            }

            case 7: {
                result = List_freeList(&studentList);
                if (result == SUCCESS) {
                    printf("List freed successfully!\n"); fflush(stdout);
                } else {
                    printf("Failed to free the list!\n");  fflush(stdout);
                }
                return 0;
            }

            default:
                printf("Invalid option. Please select a valid option.\n");  fflush(stdout);
                break;
        }

    }
    return 0;
}
