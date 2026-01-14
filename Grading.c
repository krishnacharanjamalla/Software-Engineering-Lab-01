#include "student.h"

// ---------- Grade ----------
int gradePoint(char grade[]){
    if(stringCompare(grade,"O"))  return 10;
    if(stringCompare(grade,"A+")) return 9;
    if(stringCompare(grade,"A"))  return 8;
    if(stringCompare(grade,"B+")) return 7;
    if(stringCompare(grade,"B"))  return 6;
    if(stringCompare(grade,"C"))  return 5;
    if(stringCompare(grade,"D"))  return 4;
    return 0;   // F
}

// ---------- Subject-wise Grading ----------
void assignGrade(student *s){
    float sum = 0.0;
    int totalCredits = 0;
    int failed = 0;

    // Fixed credit scheme
    int credits[SUBJECTS] = {3, 4, 3, 3, 2};

    for(int i = 0; i < SUBJECTS; i++){

        // Subject total already stored in marks[i][0]
        int subjectTotal = s->marks[i][0];
        int gp;

        // Subject grade assignment
        if(subjectTotal >= 90){
            stringCopy(s->subGrade[i], "O");  gp = 10;
        }
        else if(subjectTotal >= 85){
            stringCopy(s->subGrade[i], "A+"); gp = 9;
        }
        else if(subjectTotal >= 75){
            stringCopy(s->subGrade[i], "A");  gp = 8;
        }
        else if(subjectTotal >= 65){
            stringCopy(s->subGrade[i], "B+"); gp = 7;
        }
        else if(subjectTotal >= 60){
            stringCopy(s->subGrade[i], "B");  gp = 6;
        }
        else if(subjectTotal >= 55){
            stringCopy(s->subGrade[i], "C");  gp = 5;
        }
        else if(subjectTotal >= 50){
            stringCopy(s->subGrade[i], "D");  gp = 4;
        }
        else{
            stringCopy(s->subGrade[i], "F");
            gp = 0;
            failed = 1;
        }

        //Only PASSED subjects contribute to CGPA
        if(gp > 0){
            sum += gp * credits[i];
            totalCredits += credits[i];
        }
    }

    // CGPA always exists
    s->cgpa = (totalCredits > 0) ? (sum / totalCredits) : 0.0;

    // Overall result
    if(failed){
        stringCopy(s->grade, "F");
        return;
    }

    // Overall grade from CGPA 
    if(s->cgpa >= 9.0)      stringCopy(s->grade,"O");
    else if(s->cgpa >= 8.5) stringCopy(s->grade,"A+");
    else if(s->cgpa >= 7.5) stringCopy(s->grade,"A");
    else if(s->cgpa >= 6.5) stringCopy(s->grade,"B+");
    else if(s->cgpa >= 6.0) stringCopy(s->grade,"B");
    else if(s->cgpa >= 5.5) stringCopy(s->grade,"C");
    else if(s->cgpa >= 5.0) stringCopy(s->grade,"D");
    else                    stringCopy(s->grade,"F");
}
