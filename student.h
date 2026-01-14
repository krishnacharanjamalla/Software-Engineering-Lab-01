#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100
#define SUBJECTS 5

typedef struct {
    char id[9];
    char name[50];

    int marks[SUBJECTS][2];     // [minor][major]
    int total;                  // total marks (out of 500)
    float percent;              // percentage

    int credits[SUBJECTS];      // credits for each subject
    char subGrade[SUBJECTS][3]; // grade per subject (O, A+, A...)

    char grade[3];              // overall grade (optional)
    float cgpa;                 // final CGPA
} student;

/* ---------- Preprocessing ---------- */
int ID_Check(char id[]);
int Name_Check(char name[]);
int Duplicate_Check(student s[], int count, char id[]);

/* ---------- String Functions ---------- */
int stringCompare(char a[], char b[]);
void stringCopy(char d[], char s[]);

/* ---------- Grading ---------- */
void assignGrade(student *s);          // overall grade (optional)
int gradePoint(char grade[]);           // NEW: grade → grade point

/* ---------- Display ---------- */
void display(student s[], int count);

#endif
