#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to store student data
struct Student {
    char name[NAME_LENGTH];
    int grade;
};

// Array to store student records
struct Student students[MAX_STUDENTS];
int student_count = 0; // Keeps track of the number of students

// Function to add a new student
void add_student() {
    if (student_count < MAX_STUDENTS) {
        printf("Enter student name: ");
        getchar(); // To consume the newline left by previous input
        fgets(students[student_count].name, NAME_LENGTH, stdin);
        students[student_count].name[strcspn(students[student_count].name, "\n")] = '\0';  // Remove newline character

        printf("Enter student grade: ");
        scanf("%d", &students[student_count].grade);
        student_count++;
        printf("Student added successfully!\n");
    } else {
        printf("Cannot add more students. Maximum capacity reached.\n");
    }
}

// Function to update grade for a student
void update_grade() {
    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter the name of the student to update grade: ");
    getchar(); // To consume the newline left by previous input
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    // Search for the student
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Enter new grade for %s: ", students[i].name);
            scanf("%d", &students[i].grade);
            printf("Grade updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to display all student records
void display_all() {
    if (student_count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\nAll Student Records:\n");
    printf("Name\t\tGrade\n");
    printf("--------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t\t%d\n", students[i].name, students[i].grade);
    }
    printf("--------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add New Student\n");
        printf("2. Update Student Grade\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                update_grade();
                break;
            case 3:
                display_all();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}