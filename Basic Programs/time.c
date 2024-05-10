/*
1. b) Define a structure called Time containing 3 integer members (Hour, Minute, Second).
Develop a menu driven program to perform the following by writing separate function for
each operation:
    i) Read(T): To read time.
    ii) Display(T): To display time.
    iii) Update(T): To Update time.
    iv) Add(T1, T2): Add two time variables.
    
Note: Update function increments the time by one second and returns the new time (if the increment
results in 60 seconds, then the second member is set to zero and minute member is incremented
by one. If the result is 60 minutes, the minute member is set to zero and the hour member is
incremented by one. Finally, when the hour becomes 24, Time should be reset to zero. While
adding two time variables, normalize the resultant time value as in the case of update function.

Note: Illustrate the use of pointer to pass time variable to different functions.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for time
typedef struct time {
    int hour, minute, second; // Hour, Minute, Second
} time;

// Function to create a time variable
time *createTime() {
    time *newTime = (time *) malloc(sizeof(time));
    if (newTime == NULL) {
        printf("\nMemory could not be dynamically allocated for the time variable!\n");
        exit(1);
    }
    newTime -> hour = newTime -> minute = newTime -> second = 0;
    return newTime;
}

// Function to read time
void readTime(time *t) {
    printf("\nEnter the time in HH:MM:SS format: \n");
    scanf("%d %d %d", &(t -> hour), &(t -> minute), &(t -> second));
    while (t -> hour > 23 || t -> minute > 59 || t -> second > 59) {
        printf("\nInvalid time entered! Enter the time again: ");
        scanf("%d %d %d", &(t -> hour), &(t -> minute), &(t -> second));
    }
}

// Function to display time
void displayTime(time *t) {
    printf("\nThe entered time in HH::MM:SS format are: \n");
    printf("%d:%d:%d\n", t -> hour, t -> minute, t -> second);
}

// Function to update time by one second
void updateTime(time *t) {
    (t -> second)++;
    if (t -> second >= 60) {
        t -> second = 0;
        (t -> minute)++;
    }
    if (t -> minute >= 60) {
        t -> minute = 0;
        (t -> hour)++;
    }
    if (t -> hour >= 24) {
        t -> hour = 0;
    }
    displayTime(t);
}

// Function to add two time variables
void addTime(time *t1, time *t2) {
    time *t3 = createTime();
    t3 -> second = t1 -> second + t2 -> second;
    if (t3 -> second >= 60) {
        t3 -> second -= 60;
        (t3 -> minute)++;
    }
    t3 -> minute += t1 -> minute + t2 -> minute;
    if (t3 -> minute >= 60) {
        t3 -> minute -= 60;
        (t3 -> hour)++;
    }
    t3 -> hour += t1 -> hour + t2 -> hour;
    if (t3 -> hour >= 24) {
        t3 -> hour %= 24;
    }
    displayTime(t3);
}

int main() {
    // Create time variables
    time *t1 = createTime();
    time *t2 = createTime();
    int option;
    do {
        // Menu-driven interface
        printf("\nChoose any one of the following options:\n"
        "1. Read time\n"
        "2. Display time\n"
        "3. Update time\n"
        "4. Add times\n"
        "5. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                readTime(t1);
                readTime(t2);
                break;
            case 2:
                displayTime(t1);
                displayTime(t2);
                break;
            case 3:
                updateTime(t1);
                updateTime(t2);
                break;
            case 4:
                addTime(t1, t2);
                break;
            case 5:
                printf("\nExiting program!\n");
                free(t1); // Free dynamically allocated memory
                free(t2);
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 5);
    return 0;
}