#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void loadFromFile();
void saveToFile();
void addStudent();
void displayStudents();
void searchStudent();
void sortStudentsByGPA();
int isDuplicate(int roll);
void flushInput();

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Sort Students by GPA");
        printf("\n5. Save and Exit");
        printf("\n=================================");
        printf("\nEnter choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Enter a number.\n");
            flushInput();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: sortStudentsByGPA(); break;
            case 5: 
                saveToFile(); 
                printf("\nData saved. Goodbye!\n");
                exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isDuplicate(int roll) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll) return 1;
    }
    return 0;
}

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nDatabase full!\n");
        return;
    }

    int temp_roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &temp_roll);
    flushInput();

    if (isDuplicate(temp_roll)) {
        printf("\nError: Roll Number already exists!\n");
        return;
    }

    students[student_count].roll_no = temp_roll;

    printf("Enter Name: ");
    fgets(students[student_count].name, sizeof(students[student_count].name), stdin);
    students[student_count].name[strcspn(students[student_count].name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(students[student_count].course, sizeof(students[student_count].course), stdin);
    students[student_count].course[strcspn(students[student_count].course, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &students[student_count].gpa);

    student_count++;
    printf("\nStudent added to memory successfully!\n");
}

void displayStudents() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-20s %-15s %-5.2f\n", 
               students[i].roll_no, students[i].name, students[i].course, students[i].gpa);
    }
}

void searchStudent() {
    int target;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &target);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == target) {
            printf("\nFound: %s | Course: %s | GPA: %.2f\n", 
                   students[i].name, students[i].course, students[i].gpa);
            return;
        }
    }
    printf("\nStudent not found.\n");
}

void sortStudentsByGPA() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].gpa < students[j+1].gpa) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    printf("\nStudents sorted by highest GPA. Choose Option 2 to view.\n");
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return;

    while (fread(&students[student_count], sizeof(Student), 1, fp) == 1) {
        student_count++;
    }
    fclose(fp);
}

void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) return;

    fwrite(students, sizeof(Student), student_count, fp);
    fclose(fp);
}
