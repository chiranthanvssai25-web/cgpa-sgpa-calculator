#include <stdio.h>

int gradePoint(int marks) {
    if (marks >= 90) return 10;
    else if (marks >= 80) return 9;
    else if (marks >= 70) return 8;
    else if (marks >= 60) return 7;
    else if (marks >= 50) return 6;
    else if (marks >= 45) return 5;
    else if (marks >= 40) return 4;
    else return 0; // Fail
}

float calculateSGPA(int n) {
    int credits[20], marks[20], gp;
    float totalCreditPoints = 0, totalCredits = 0;

    printf("\n--- Enter Subject Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("Enter Marks: ");
        scanf("%d", &marks[i]);
        printf("Enter Credits: ");
        scanf("%d", &credits[i]);

        gp = gradePoint(marks[i]);
        totalCreditPoints += gp * credits[i];
        totalCredits += credits[i];
    }

    return totalCreditPoints / totalCredits;
}

int main() {
    int semCount, n;
    float sgpa[20], total = 0, totalCredits = 0, semCredits;

    printf("Enter total number of semesters completed: ");
    scanf("%d", &semCount);

    for (int i = 0; i < semCount; i++) {
        printf("\n--- Semester %d ---\n", i + 1);

        printf("Enter number of subjects: ");
        scanf("%d", &n);

        sgpa[i] = calculateSGPA(n);

        printf("Enter total semester credits: ");
        scanf("%f", &semCredits);

        total += sgpa[i] * semCredits;
        totalCredits += semCredits;

        printf("SGPA for Semester %d = %.2f\n", i + 1, sgpa[i]);
    }

    float cgpa = total / totalCredits;
    printf("\n===============================\n");
    printf(" Final CGPA = %.2f\n", cgpa);
    printf("===============================\n");

    return 0;
}
