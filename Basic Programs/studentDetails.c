/*
1. a) Define a structure called Student with the members: Name, Reg_no, marks in 3 tests and
average_ marks.
Develop a menu driven program to perform the following by writing separate function for each
operation: 
    i) Read information of N students.
    ii) Display student’s information.
    iii) To calculate the average of best two test marks of each student.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for student information
typedef struct student {
    char studentName[10];           // Name of the student
    char registrationNumber[10];    // Registration number of the student
    int subjectMarks[3];            // Marks in 3 tests
    float averageMarks;             // Average of best two test marks
} student;

// Function to read information of N students
void read(student *s, int n) {
    printf("\nEnter the information of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nFor student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s[i].studentName);
        printf("Enter registration number: ");
        scanf("%s", s[i].registrationNumber);
        printf("Enter marks in 3 tests:\n");
        printf("Subject 1: ");
        scanf("%d", &(s[i].subjectMarks[0]));
        printf("Subject 2: ");
        scanf("%d", &(s[i].subjectMarks[1]));
        printf("Subject 3: ");
        scanf("%d", &(s[i].subjectMarks[2]));
    }
}

// Function to display student's information
void display(student *s, int n) {
    printf("\nThe information of %d students is as follows:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nFor student %d:\n", i + 1);
        printf("Name: %s\n", s[i].studentName);
        printf("Registration number: %s\n", s[i].registrationNumber);
        printf("Marks in 3 tests:\n");
        printf("Subject 1: %d\n", s[i].subjectMarks[0]);
        printf("Subject 2: %d\n", s[i].subjectMarks[1]);
        printf("Subject 3: %d\n", s[i].subjectMarks[2]);
    }
}

// Function to calculate the average of the best two test marks of each student
void average(student *s, int n) {
    printf("\nThe average of the best two test marks of each student are:\n");
    for (int i = 0; i < n; i++) {
        // Sort the marks in ascending order
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2 - j; k++) {
                if (s[i].subjectMarks[k] > s[i].subjectMarks[k + 1]) {
                    int temp = s[i].subjectMarks[k];
                    s[i].subjectMarks[k] = s[i].subjectMarks[k + 1];
                    s[i].subjectMarks[k + 1] = temp;
                }
            }
        }
        // Calculate the average of the best two test marks
        s[i].averageMarks = (s[i].subjectMarks[1] + s[i].subjectMarks[2]) / 2.0;
        printf("For student %d:\n", i + 1);
        printf("Average of best two test marks: %.2f\n", s[i].averageMarks);
    }
}

int main() {
    int n, option;
    // Ask for the number of students
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    // Allocate memory for array of students
    student *s = (student *) malloc(n * sizeof(student));
    do {
        // Menu-driven interface
        printf("\nChoose any one of the following options:\n"
        "1. Read information of N students.\n"
        "2. Display student's information.\n"
        "3. Calculate the average of the best two marks of each student.\n"
        "4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                read(s, n);
                break;
            case 2:
                display(s, n);
                break;
            case 3:
                average(s, n);
                break;
            case 4:
                printf("\nExiting program!\n");
                free(s); // Free dynamically allocated memory
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 4);
    return 0;
}