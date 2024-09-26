#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


struct Student {
    char usn[15];        
    char name[50];       
    char mobile[15];     
};


void inputStudentDetails(struct Student *s) {
    printf("Enter USN: ");
    scanf("%s", s->usn);
    printf("Enter Name: ");
    scanf(" %[^\n]s", s->name); 
    printf("Enter Mobile Number: ");
    scanf("%s", s->mobile);
}


void displayStudentDetails(struct Student s) {
    printf("\nStudent Details:\n");
    printf("USN: %s\n", s.usn);
    printf("Name: %s\n", s.name);
    printf("Mobile Number: %s\n", s.mobile);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    do {
        if (studentCount < MAX_STUDENTS) {
            inputStudentDetails(&students[studentCount]);
            studentCount++;
        } else {
            printf("Maximum student limit reached.\n");
            break;
        }

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        displayStudentDetails(students[i]);
    }

    return 0;
}
