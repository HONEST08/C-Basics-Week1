#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Student {
    char name[50];
    int studentNo;
    int math, english, computer;
    int total;
    float average;
    char grade;
};

struct Student students[MAX];
int count = 0;
void addStudent();
void viewStudents();
void searchStudent();
void calculateResults();
void saveToFile();

int main() {
    int choice;

    do {
        printf("\n==============================\n");
        printf(" STUDENT MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Results\n");
        printf("5. Save Results to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateResults(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}
void addStudent() {
    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Student Number: ");
    scanf("%d", &students[count].studentNo);

    printf("Math Marks: ");
    scanf("%d", &students[count].math);

    printf("English Marks: ");
    scanf("%d", &students[count].english);

    printf("Computer Marks: ");
    scanf("%d", &students[count].computer);

    count++;
    printf("Student added successfully!\n");
}
void viewStudents() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n-------------------------------------------------------\n");
    printf("Name\t\tStudent No\tMath\tEnglish\tComputer\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %d\t%d\t%d\t%d\n",
               students[i].name,
               students[i].studentNo,
               students[i].math,
               students[i].english,
               students[i].computer);
    }
}
void searchStudent() {
    int num, found = 0;

    printf("Enter Student Number: ");
    scanf("%d", &num);

    for (int i = 0; i < count; i++) {
        if (students[i].studentNo == num) {
            printf("\nStudent Found\n");
            printf("Name: %s\n", students[i].name);
            printf("Student Number: %d\n", students[i].studentNo);
            printf("Math: %d\n", students[i].math);
            printf("English: %d\n", students[i].english);
            printf("Computer: %d\n", students[i].computer);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}
void calculateResults() {
    for (int i = 0; i < count; i++) {
        students[i].total = students[i].math +
                            students[i].english +
                            students[i].computer;

        students[i].average = students[i].total / 3.0;

        if (students[i].average >= 80)
            students[i].grade = 'A';
        else if (students[i].average >= 70)
            students[i].grade = 'B';
        else if (students[i].average >= 60)
            students[i].grade = 'C';
        else if (students[i].average >= 50)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }

    printf("\nResults Calculated:\n");

    for (int i = 0; i < count; i++) {
        printf("\nName: %s\n", students[i].name);
        printf("Total: %d\n", students[i].total);
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
    }
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "Name: %s\n", students[i].name);
        fprintf(fp, "Student No: %d\n", students[i].studentNo);
        fprintf(fp, "Math: %d\n", students[i].math);
        fprintf(fp, "English: %d\n", students[i].english);
        fprintf(fp, "Computer: %d\n", students[i].computer);
        fprintf(fp, "Total: %d\n", students[i].total);
        fprintf(fp, "Average: %.2f\n", students[i].average);
        fprintf(fp, "Grade: %c\n\n", students[i].grade);
    }

    fclose(fp);
    printf("Saved to students.txt successfully!\n");
}